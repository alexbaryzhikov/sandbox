n, m = map(int, input().split())
coins = list(map(int, input().split()))

was = [0] * m
ans = []


def check(s, count):
    if s == n and (len(ans) == 0 or count < len(ans)):
        ans.clear()
        for i in range(m):
            for _ in range(was[i]):
                ans.append(coins[i])


def find(i, s, count):
    if i == m:
        check(s, count)
        return
    was[i] = 0
    find(i + 1, s, count)
    was[i] = 1
    find(i + 1, s + coins[i], count + 1)
    was[i] = 2
    find(i + 1, s + coins[i] * 2, count + 2)


find(0, 0, 0)

if len(ans) > 0:
    print(len(ans))
elif sum(coins) * 2 < n:
    print(-1)
else:
    print(0)
