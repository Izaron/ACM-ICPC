# Regional Stage 2015 ![C++](https://img.shields.io/badge/language-C++-orange.svg) ![Java](https://img.shields.io/badge/language-Java-orange.svg) ![Progress](https://img.shields.io/badge/progress-720%2F800-green.svg)

## [First day](https://contest.yandex.ru/roiarchive/contest/2012/enter/)

| # | Task | Solution | Points | Note |
|---| ---- | -------- | -------- | ---- |
|A| hall | `hall.java` | ✓100 | System of math equations, simple linear search |
|B| prizes | `prizes.java` | ✓100 | Partial sums |
|C| river | `river.cpp` | ✓100 | Implicit treap |
|D| search | `search.java` | ✓100 | Ability to solve optimization problems |

## [Second day](https://contest.yandex.ru/roiarchive/contest/2012/enter/)

| # | Task | Solution | Points | Note |
|---| ---- | -------- | -------- | ---- |
|A| circle | `circle.cpp` | ✓100 | Simple math |
|B| forest | `forest.cpp` | ✓100 | Binary search (with overflows) |
|C| tiling | `tiling.cpp` | ✓100 | Dynamic programming on profile |
|D| transform | `transform.cpp` | ✗20 | Classic unsolvable problem with boring statement |

## Points to pass further

This stage was the qualification for the final stage

Points enough to pass to the final stage:

Grade | Points
--- | ---
<= 9 | 410
10 | 461
11 | 516

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
