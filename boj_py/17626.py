import sys
input = sys.stdin.readline

min_pow_num = [4 for _ in range(50001)]
for i in range(225):
    num1 = i**2
    if num1 > 50000:
        continue
    min_pow_num[num1] = min(min_pow_num[num1], 1)
    for j in range(225):
        num2 = num1 + j**2
        if num2 > 50000:
            continue
        min_pow_num[num2] = min(min_pow_num[num2], 2)

N = int(input())
ans = min_pow_num[N]
for i in range(N):
    ans = min(ans, min_pow_num[i] + min_pow_num[N-i])
print(ans)