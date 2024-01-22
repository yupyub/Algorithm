import sys
input = sys.stdin.readline


num = int(input())
s = input()
r = 1
ans = 0

for i in range(num):
    ans = (ans + (ord(s[i])-ord('a')+1) * r) % 1234567891
    r = (r * 31) % 1234567891
print(ans)