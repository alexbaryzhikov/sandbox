import random

n = random.randint(1, 10**9)
m = random.randint(1, 16)
coins = random.sample(range(1, 10**7), m)

print(f"{n} {m}")
print(" ".join(str(c) for c in coins))
