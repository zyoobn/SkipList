#ifndef SKIP_LIST_MAP_H
#define SKIP_LIST_MAP_H

#include <random>
#include <utility>
#include <functional>

template <typename K, typename V, typename Cmp = std::less<K>>
class SkiplistMap {
private:
    constexpr static int MAX_LEVEL = 30;
    constexpr static double PROBABILITY = 0.50;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> rd;

    struct SkipListNode {
        std::pair<K, V> val;
        SkipListNode** forward;
        SkipListNode(K k = K(), V v = V(), int maxLevel = MAX_LEVEL) : val({k, v}), forward(new SkipListNode*[maxLevel]) {
            for (int i = 0; i < maxLevel; ++i) {
                forward[i] = nullptr;
            }
        }
        ~SkipListNode() {
            delete []forward;
        }
    };

    Cmp less;
    int nowLevel;
    size_t _size;
    SkipListNode* head;
    SkipListNode* tail;

    int randomLevel() {
        int lv = 1;
        while (rd(gen) <= PROBABILITY && lv < MAX_LEVEL) {
            lv++;
        }
        return lv;
    }
public:
    class Iterator {
    private:
        SkipListNode* cur;
    public:
        Iterator(SkipListNode* node) : cur(node) {}

        //前置递增运算符
        Iterator& operator++() {
            cur = cur->forward[0];
            return *this;
        }
        //后置递增运算符
        Iterator operator++(int) {
            Iterator temp = cur;
            cur = cur->forward[0];
            return temp;
        }

        SkipListNode* operator->() const {
            return cur;
        }

        std::pair<K, V>& operator*() const {
            return cur->val;
        }

        bool operator!=(const Iterator& rhs) const {
            return cur != rhs.cur;
        }

        bool operator==(const Iterator& rhs) const {
            return cur == rhs.cur;
        }
    };

    SkiplistMap(Cmp _less = Cmp()) : rd(0, 1), nowLevel(1), head(new SkipListNode(K())), tail(new SkipListNode(K())),
                 _size(0), less(_less)
    {
        for (int i = 0; i < MAX_LEVEL; ++i) {
            head->forward[i] = tail;
        }
    }

    template <typename Iter>
    SkiplistMap(const Iter& first, const Iter& last, Cmp _less = Cmp()) : rd(0, 1), nowLevel(1), head(new SkipListNode(K())), tail(new SkipListNode(K())),
                 _size(0), less(_less)
    {
        for (int i = 0; i < MAX_LEVEL; ++i) {
            head->forward[i] = tail;
        }
        for (Iter it = first; it != last; ++it) {
            add(it->first, it->second);
        }
    }

    SkiplistMap(const std::initializer_list<std::pair<K, V>>& initList, Cmp _less = Cmp()) : rd(0, 1), nowLevel(1), head(new SkipListNode(K())), tail(new SkipListNode(K())),
                 _size(0), less(_less)
    {
        for (int i = 0; i < MAX_LEVEL; ++i) {
            head->forward[i] = tail;
        }

        for (auto &[kay, val] : initList) {
            add(kay, val);
        }
    }

    ~SkiplistMap() {
        delete head;
        delete tail;
    }

    Iterator find(const K& target) const {
        SkipListNode* cur = head;
        for (int i = nowLevel - 1; i >= 0; --i) {
            while (cur->forward[i] != tail && less((cur->forward[i]->val).first, target)) {
                cur = cur->forward[i];
            }
        }
        cur = cur->forward[0];
        if (cur != tail && (cur->val).first == target) {
            return Iterator(cur);
        }
        return end();
    }

    bool search(const K& target) const {
        return find(target) != end();
    }
    
    void add(const K& kay, const V& val = V()) {
        std::vector<SkipListNode*> update(MAX_LEVEL, head);
        SkipListNode* cur = head;
        for (int i = nowLevel - 1; i >= 0; --i) {
            while (cur->forward[i] != tail && less((cur->forward[i]->val).first, kay)) {
                cur = cur->forward[i];
            }
            update[i] = cur;
        }
        int lv = randomLevel();
        nowLevel = std::max(nowLevel, lv);
        SkipListNode* now = new SkipListNode(kay, val, lv);
        for (int i = 0; i < lv; ++i) {
            now->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = now;
        }
        _size++;
    }
    
    bool erase(const K& num) {
        std::vector<SkipListNode*> update(MAX_LEVEL, nullptr);
        SkipListNode* cur = head;
        for (int i = nowLevel - 1; i >= 0; --i) {
            while (cur->forward[i] != tail && less((cur->forward[i]->val).first, num)) {
                cur = cur->forward[i];
            }
            update[i] = cur;
        }
        cur = cur->forward[0];
        if (cur == tail || (cur->val).first != num) {
            return false;
        }
        for (int i = 0; i < nowLevel; ++i) {
            if (update[i]->forward[i] != cur) {
                break;
            }
            update[i]->forward[i] = cur->forward[i];
        }
        _size--;
        delete cur;
        while (nowLevel > 1 && head->forward[nowLevel - 1] == tail) {
            nowLevel--;
        }
        return true;
    }

    V& operator[](const K& kay) {
        if (!search(kay)) {
            add(kay);
        }
        return (*find(kay)).second;
    }

    size_t size() const {
        return _size;
    }

    Iterator begin() const {
        return Iterator(head->forward[0]);
    }
    Iterator end() const {
        return Iterator(tail);
    }
};

#endif