# 

# Project Name: Lightweight Element Set Storage Based on Skip List Implementation

## Project Introduction

This project is a C++ implementation of Skip List. Skip List is an ordered data structure that has similar search efficiency to balanced trees but with a relatively simple implementation. Skip List accelerates searches by adding multiple levels of indices on top of a linked list. Each level is a sorted linked list, and the bottom-level list contains all the elements. Each node contains multiple pointers to other nodes, facilitating fast search, insertion, and deletion operations.

## Project Features

1. **Custom Comparator Support:** Users can define the comparison rules for elements based on their needs, making the Skip List suitable for different data types and sorting requirements.
2. **Iterator Support:** Iterator functionality is provided, facilitating the traversal of elements in the Skip List.
3. **Range Initialization and Iterator Range Initialization Support:** Users can initialize the Skip List using a range or an iterator range.
4. **Example Code Provided:** The main function demonstrates several use cases of the Skip List, including default comparators, custom comparators, and range initialization.

## Usage

1. Place `SkipList.h` and `SkipList.cpp` in the same directory.

2. Compile the `SkipList.cpp` file using the clang++ compiler to generate the executable file.

    ```bash
    clang++ -std=c++17 SkipList.cpp -o skip_list_example
    ```

3. Run the generated executable file.

    ```bash
    ./skip_list_example
    ```

## Example Output

```cpp
2 3 5 7 
7 5 3 2 
7 5 3 2 
7 5 3 2
```

## Project Structure

-   **SkipList.h**: Contains the implementation code for the Skip List, defining the Skiplist class.
-   **SkipList.cpp**: Contains the main function and example code, demonstrating how to use various features of the Skip List.
-   **skip_list_example**: The binary executable file.
-   **README.md**: Project introduction.
-   **LICENSE**: License agreement.
**Author**: Zyoobn
**Date**: 2024/1/23
