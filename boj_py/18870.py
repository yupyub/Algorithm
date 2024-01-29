import sys
input = sys.stdin.readline

n = int(input())
nums = [int(x) for x in input().split()]

s = list(set(nums))
s.sort()
idx_map = {x: idx for idx, x in enumerate(s)}

for x in nums:
    print(idx_map[x], end=' ')