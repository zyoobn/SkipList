#include <iostream>
#include <vector>
#include "SkipList.h"

struct cmp {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

int main() {
    {
        Skiplist<int> mp;
        mp.add(5);
        mp.add(3);
        mp.add(7);
        mp.add(2);
        for (auto &i : mp) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
        // 输出结果：2 3 5 7
    }

    {
        std::vector<int> a = {5, 3, 7, 2};
        Skiplist<int, std::greater<int>> mp(a.begin(), a.end());
        for (auto &i : mp) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
        // 输出结果：7 5 3 2
    }

    {
        Skiplist<int, cmp> mp{5, 3, 7, 2};
        for (auto &i : mp) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
        // 输出结果：7 5 3 2
    }

    {
        auto cmp = [] (const int& x, const int& y) {
            return x > y;
        };
        Skiplist<int, decltype(cmp)> mp({5, 3, 7, 2}, cmp);
        for (auto &i : mp) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
        // 输出结果：7 5 3 2
    }

    return 0;
}
