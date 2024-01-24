#include <iostream>
#include <vector>
#include "SkipList.h"
#include "SkipListMap.h"

struct cmp {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

int main() {
    {
        SkiplistMap<int, std::string> mp;
        mp.add(3, "12313");
        mp.add(2, "afasf13");
        mp.add(1, "ada");
        mp.add(4, "1gdgs3");
        for (auto &[kay, val] : mp) {
            std::cout << kay << ' ' << val << '\n';
        }
    }
    std::cout << "————————————————————————————" << '\n';
    {
        SkiplistMap<int, int> mp;
        mp[0]++;
        mp[1]++;
        for (auto &[kay, val] : mp) {
            std::cout << kay << ' ' << val << '\n';
        }
    }
    std::cout << "————————————————————————————" << '\n';
    {
        std::vector<std::pair<int, int>> a = {{1, 2}, {7, 3}, {4, 9}};
        SkiplistMap<int, int, cmp> mp(a.begin(), a.end());
        for (auto &[kay, val] : mp) {
            std::cout << kay << ' ' << val << '\n';
        }
    }
    std::cout << "————————————————————————————" << '\n';
    {
        auto cmp = [](const int& x, const int&y) {
            return x > y;
        };
        SkiplistMap<int, int, decltype(cmp)> mp({{1, 2}, {7, 3}, {4, 9}}, cmp);
        for (auto &[kay, val] : mp) {
            std::cout << kay << ' ' << val << '\n';
        }
    }
    return 0;
}