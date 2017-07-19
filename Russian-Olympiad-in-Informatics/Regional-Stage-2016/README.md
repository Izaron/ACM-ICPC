# Regional Stage 2016 ![C++](https://img.shields.io/badge/language-C++-orange.svg) ![Java](https://img.shields.io/badge/language-Java-orange.svg) ![Progress](https://img.shields.io/badge/progress-800%2F800-green.svg)

## [First day](https://contest.yandex.ru/roiarchive/contest/2169/enter/)

| # | Task | Solution | Points | Note |
|---| ---- | -------- | -------- | ---- |
|A| prizes | `prizes.java` | ✓100 | Two pointers |
|B| space | `space.java` | ✓100 | Binary search (with overflows) |
|C| strange | `strange.java` | ✓100 | Dynamic programming, some data structures |
|D| trains | `trains.cpp` | ✓100 | Binary search, convert monotonic operations with an array to O(log(n)) from O(n) |

## [Second day](https://contest.yandex.ru/roiarchive/contest/2170/enter/)

| # | Task | Solution | Points | Note |
|---| ---- | -------- | -------- | ---- |
|A| division | `division.java` | ✓100 | Simple math, nested linear searches |
|B| game | `game.java` | ✓100 | std::map/TreeMap, strong math |
|C| numbers | `numbers.java` | ✓100 | Dynamic programming |
|D| sequence | `sequence.java` | ✓100 | Nested ternary searches, number theory, std::set/TreeSet, math |

## Points to pass further

This stage was the qualification for the final stage

Points enough to pass to the final stage:

Grade | Points
--- | ---
<= 9 | 511
10 | 548
11 | 601

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
