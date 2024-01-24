# Project Name: Lightweight KV Storage Based on Skip List

## Project Overview

This project is a lightweight key-value (KV) storage structure implemented in C++ using Skip List. Skip List is an ordered data structure that combines the search efficiency of balanced trees with a relatively simple implementation. It accelerates searches by adding multiple levels of indexes on top of a linked list. Each level is a sorted linked list, and the bottom-level list contains all elements. Each node contains multiple pointers to other nodes, allowing Skip List to achieve fast lookup, insertion, and deletion operations.

## Key Features

1. **Customizable Comparators:** Users can define custom comparison rules for elements, making the Skip List suitable for different data types and sorting requirements.
2. **Iterator Support:** Iterator functionality is provided for easy traversal of elements in the Skip List.
3. **Support for Range Initialization and Iterator Range Initialization:** Users can initialize the Skip List using a range or iterator range.
4. **Overloaded Operator[]:** Enhances flexibility, allowing the container to be used similarly to `std::map`.
5. **Example Code Provided:** The main function demonstrates several use cases of the Skip List, including default comparators, custom comparators, and range initialization.

## Usage

1. Place `SkipListMap.h` and `SkipListMap.cpp` files in the same directory.

2. Compile the `SkipListMap.cpp` file using the clang++ compiler to generate an executable file.

    ```bash
    clang++ -std=c++17 SkipListMap.cpp -o skip_list_map_example
    ```

3. Run the generated executable file.

    ```bash
    ./skip_list_map_example
    ```

## Example Output

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
## Project Structure

-   **SkipListMap.h:** Contains the implementation code for `SkipListMap` and defines the `SkiplistMap` class.
-   **SkipListMap.cpp:** Contains the main function and example code demonstrating various functionalities of `SkipListMap`.
-   **skip_list_Map_example:** Binary executable file for the `SkipListMap.cpp` code.
-   **SkipListSet.h:** Contains the implementation code for `SkipListSet` and defines the `Skiplist` class.
-   **SkipListSet.cpp:** Contains the main function and example code for `SkipListSet`.
-   **skip_list_set_example:** Binary executable file for the `SkipListSet.cpp` code.
-   **README.md:** Project introduction.
-   **README-en.md:** Project introduction in English.
-   **LICENSE:** Usage license.
**Author:** Zyoobn **Date:** 2024/1/23
