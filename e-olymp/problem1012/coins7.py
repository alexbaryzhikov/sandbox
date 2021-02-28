# Stack

s1 = input()
s2 = input()

n = int(s1.split(" ")[0])
coins = [int(x) for x in s2.split(" ")]


def explore(m):
    nums = [0] * len(coins)
    stack = []
    stack.append({
        "jmp": 0,
        "i": 0,
        "m": m,
        "k": (len(coins) - 1) * 2,
        "s": 0
    })

    while len(stack) > 0:
        args = stack.pop()

        if args["jmp"] == 0:
            if args["m"] == 0:
                if args["s"] == n:
                    return nums
            elif args["m"] == 1:
                for i in range(args["i"], len(coins)):
                    if args["s"] + coins[i] == n:
                        nums[i] = 1
                        return nums
            else:
                if args["m"] - 2 <= args["k"]:
                    nums[args["i"]] = 2
                    args["jmp"] = 1
                    stack.append(args)
                    stack.append({
                        "jmp": 0,
                        "i": args["i"] + 1,
                        "m": args["m"] - 2,
                        "k": args["k"] - 2,
                        "s": args["s"] + coins[args["i"]] * 2
                    })

        elif args["jmp"] == 1:
            if args["m"] - 1 <= args["k"]:
                nums[args["i"]] = 1
                args["jmp"] = 2
                stack.append(args)
                stack.append({
                    "jmp": 0,
                    "i": args["i"] + 1,
                    "m": args["m"] - 1,
                    "k": args["k"] - 2,
                    "s": args["s"] + coins[args["i"]]
                })
            else:
                nums[args["i"]] = 0

        elif args["jmp"] == 2:
            nums[args["i"]] = 0
            if args["m"] <= args["k"]:
                stack.append({
                    "jmp": 0,
                    "i": args["i"] + 1,
                    "m": args["m"],
                    "k": args["k"] - 2,
                    "s": args["s"]
                })

    return None


def solve():
    if sum(coins) * 2 < n:
        print(-1)
        return

    if sum(coins) * 2 == n:
        print(len(coins) * 2)
        return

    for i in range(1, len(coins) * 2 + 1):
        nums = explore(i)
        if nums != None:
            print(sum(nums))
            return

    print(0)


solve()
