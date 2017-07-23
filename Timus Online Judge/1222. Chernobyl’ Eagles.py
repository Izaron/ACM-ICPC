// The solution of the problem was written by Izaron
// Date: 20:43:03   11 May 2015
// Execution time: 0.14

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

n = int(input())

m = []

for i in range(3005):
    m.append(0)

m[0] = 0
m[1] = 1
m[2] = 2
m[3] = 3
m[4] = 4
m[5] = 6

for i in range(6, n + 1):
    for a in range(1, 6):
        m[i] = max(m[i], m[i - a] * a)

print(m[n])