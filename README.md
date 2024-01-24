# 

# 项目名称：基于跳表实现的轻量级KV存储

## 项目简介

该项目是一个基于 C++ 的跳表（Skip List）实现的轻量级KV存储结构。跳表是一种有序数据结构，具有类似平衡树的查找效率，但实现相对简单。跳表通过在链表上增加多层索引，从而加速查询。每一层都是一个有序的链表，最底层的链表包含所有的元素。每个节点包含多个指向其他节点的指针，通过这些指针，跳表实现了快速的查找、插入和删除操作。

## 项目特点

1. **支持自定义比较器：** 用户可以根据需要定义元素的比较规则，使得跳表适用于不同的数据类型和排序要求。
2. **支持迭代器：** 提供了迭代器功能，方便遍历跳表中的元素。
3. **支持范围初始化和迭代器范围初始化：** 用户可以通过范围初始化或使用迭代器范围初始化跳表。
4. **重载操作符[]**：使容器使用起来更加灵活，类似于std::map。
5. **提供示例代码：** 在主函数中展示了几个使用跳表的示例，包括默认比较器、自定义比较器、范围初始化等。

## 使用方法

1. 将 `SkipListMap.h` 和 `SkipListMap.cpp` 两个文件放在同一目录下。

2. 使用 clang++ 编译器编译 `SkipListMap.cpp` 文件，生成可执行文件。

    ```bash
    clang++ -std=c++17 SkipListMap.cpp -o skip_list_map_example
    ```

3. 运行生成的可执行文件。

    ```bash
    /skip_list_map_example
    ```

## 示例输出

```cpp
1 ada
2 afasf13
3 12313
4 1gdgs3
————————————————————————————
0 1
1 1
————————————————————————————
7 3
4 9
1 2
————————————————————————————
7 3
4 9
1 2
```

## 项目结构

-   **SkipListMap.h：** 包含了`SkipListMap`的实现代码，定义了 `SkiplistMap` 类。
-   **SkipListMap.cpp：** 包含了主函数和示例代码，演示了如何使用`SkipListMap`的不同功能。
-   **skip_list_Map_example：** `SkipListMap.cpp`代码的二进制可执行文件
-   **SkipListSet.h：** 包含了`SkipListSet`的实现代码，定义了 `Skiplist` 类。
-   **SkipListSet.cpp：** 包含了主函数和示例代码，演示了如何使用`SkipListSet`的不同功能。
-   **skip_list_set_example：** `SkipListSet.cpp`代码的二进制可执行文件
-   **README.md：** 项目介绍
-   **README-en.md：** 项目英文介绍
-   **LICENSE：** 使用协议

**作者：** Zyoobn
**日期：** 2024/1/23
