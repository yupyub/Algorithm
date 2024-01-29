import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
s = input()

prev = None
count = 0
ans = 0
for i in range(m):
    if s[i] == 'I':
        if prev == 'O':
            count += 1
            if count >= n:
                 ans += 1
        else:
            count = 0
        prev = 'I'
    else:
        if prev == 'O' or prev == None:
            count = -1
        prev = 'O'
print(ans)