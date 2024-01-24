#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <random>
#include <functional>

template <typename T, typename Cmp = std::less<T>>
class Skiplist {
private:
    constexpr static int MAX_LEVEL = 30;
    constexpr static double PROBABILITY = 0.50;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> rd;

    struct SkipListNode {
        T val;
        SkipListNode** forward;
        SkipListNode(T v, int maxLevel = MAX_LEVEL) : val(v), forward(new SkipListNode*[maxLevel]) {
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

        T& operator*() const {
            return cur->val;
        }

        bool operator!=(const Iterator& rhs) const {
            return cur != rhs.cur;
        }

        bool operator==(const Iterator& rhs) const {
            return cur == rhs.cur;
        }
    };

    Skiplist(Cmp _less = Cmp()) : rd(0, 1), nowLevel(1), head(new SkipListNode(T())), tail(new SkipListNode(T())),
                 _size(0), less(_less)
    {
        for (int i = 0; i < MAX_LEVEL; ++i) {
            head->forward[i] = tail;
        }
    }

    template <typename Iter>
    Skiplist(Iter first, Iter last, Cmp _less = Cmp()) : rd(0, 1), nowLevel(1), head(new SkipListNode(T())), tail(new SkipListNode(T())),
                 _size(0), less(_less)
    {
        for (int i = 0; i < MAX_LEVEL; ++i) {
            head->forward[i] = tail;
        }
        for (Iter it = first; it != last; ++it) {
            add(*it);
        }
    }

    Skiplist(std::initializer_list<T> initList, Cmp _less = Cmp()) : rd(0, 1), nowLevel(1), head(new SkipListNode(T())), tail(new SkipListNode(T())),
                 _size(0), less(_less)
    {
        for (int i = 0; i < MAX_LEVEL; ++i) {
            head->forward[i] = tail;
        }

        for (auto &i : initList) {
            add(i);
        }
    }

    ~Skiplist() {
        delete head;
        delete tail;
    }

    Iterator find(T target) {
        SkipListNode* cur = head;
        for (int i = nowLevel - 1; i >= 0; --i) {
            while (cur->forward[i] != tail && less(cur->forward[i]->val, target)) {
                cur = cur->forward[i];
            }
        }
        cur = cur->forward[0];
        if (cur != tail && cur->val == target) {
            return Iterator(cur);
        }
        return end();
    }

    bool search(T target) {
        return find(target) != end();
    }
    
    void add(T num) {
        std::vector<SkipListNode*> update(MAX_LEVEL, head);
        SkipListNode* cur = head;
        for (int i = nowLevel - 1; i >= 0; --i) {
            while (cur->forward[i] != tail && less(cur->forward[i]->val, num)) {
                cur = cur->forward[i];
            }
            update[i] = cur;
        }
        int lv = randomLevel();
        nowLevel = std::max(nowLevel, lv);
        SkipListNode* now = new SkipListNode(num, lv);
        for (int i = 0; i < lv; ++i) {
            now->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = now;
        }
        _size++;
    }
    
    bool erase(T num) {
        std::vector<SkipListNode*> update(MAX_LEVEL, nullptr);
        SkipListNode* cur = head;
        for (int i = nowLevel - 1; i >= 0; --i) {
            while (cur->forward[i] != tail && less(cur->forward[i]->val, num)) {
                cur = cur->forward[i];
            }
            update[i] = cur;
        }
        cur = cur->forward[0];
        if (cur == tail || cur->val != num) {
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

    size_t size() const {
        return _size;
    }

    Iterator begin() {
        return Iterator(head->forward[0]);
    }
    Iterator end() {
        return Iterator(tail);
    }
};

#endif
