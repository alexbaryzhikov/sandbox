# Плавные числа

def solve_bf(n):
    t = [[[x]] for x in range(1, 10)]
    for _ in range(n - 1):
        new_t = []
        for row in t:
            new_row = []
            for num in row:
                if num[-1] - 1 >= 0:
                    new_row.append(num + [num[-1] - 1])
                new_row.append(num + [num[-1]])
                if (num[-1] + 1 < 10):
                    new_row.append(num + [num[-1] + 1])
            new_t.append(new_row)
        t = new_t
    return sum(len(row) for row in t)


def solve_dp(n):
    if n == 1:
        return 9
    t = [[0] * 10, [1] * 10]
    for _ in range(n - 1):
        t[0] = t[1]
        t[1] = [0] * 10
        t[1][0] = t[0][0] + t[0][1]
        for j in range(1, 9):
            t[1][j] = t[0][j-1] + t[0][j] + t[0][j+1]
        t[1][9] = t[0][8] + t[0][9]
    return sum(t[1][1:])


n = int(input())
print(solve_dp(n))
