n, m = input().split()
n = int(n)
m = int(m)

if m % 2 == 1:
    print(0)
    exit()

m /= 2

cnt = 0

d = {}
def dfs(v,sum):
    if sum < 0:
        return 0

    if (v,sum) in d:
        return d[(v,sum)]

    if v == 0 and sum == 0:
        d[(v,sum)] = 1
        return 1

    if v == 0 and sum != 0:
        d[(v,sum)] = 0
        return 0

    ans = 0

    for i in range(10):
        ans += dfs(v - 1, sum - i)

    d[(v,sum)] = ans

    return ans


print(dfs(n,m)**2)