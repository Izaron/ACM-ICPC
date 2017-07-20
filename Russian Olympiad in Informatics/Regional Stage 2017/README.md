# Regional Stage 2017 ![C++](https://img.shields.io/badge/language-C++-orange.svg) ![Java](https://img.shields.io/badge/language-Java-orange.svg) ![Progress](https://img.shields.io/badge/progress-699%2F801-green.svg)

## [First day](https://contest.yandex.ru/roiarchive/contest/4154/enter/)

| # | Task | Solution | Points | Note |
|---| ---- | -------- | -------- | ---- |
|A| building | `building.java` | ✓100 | Binary search or math |
|B| calc | `calc.cpp` | ✓100 | Greedy algorithms or simple dynamic programming |
|C| data | `data.java` | ✓101 | Graph theory, topological sorting |
|D| mining | - | ✗33 | Flows, Hall's marriage theorem |

## [Second day](https://contest.yandex.ru/roiarchive/contest/4155/enter/)

| # | Task | Solution | Points | Note |
|---| ---- | -------- | -------- | ---- |
|A| delivery | - | ✓100 | Binary search |
|B| linear |- | ✓100 | Stack/Deque, Binary search or two pointers |
|C| power | - | ✓100 | Sorting, Binary Tree or other data structure |
|D| qual | `qual.cpp` | ✗65 | Graph theory + a bunch of graph algos (Lowest Common Ancestor, Graph binary rising) |

## Points to pass further

This stage was the qualification for the final stage

Points enough to pass to the final stage:

Grade | Points
--- | ---
<= 9 | 473
10 | 550
11 | 621

## Fast compiling via the terminal

### Java

Firstly, either rename source file to Main.java or change in the code `class Main` -> `class %sourceFile%`

```
javac %sourceFile%.java
java %sourceFile%
```

### C++

```
g++ -std=c++11 %source%.cpp -o %source%
./%source%
```
