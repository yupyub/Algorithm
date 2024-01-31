import sys
input = sys.stdin.readline

N, M = [int(x) for x in input().split()]
password_map = {}
for i in range(N):
    link, password = input().strip().split()
    password_map[link] = password

for j in range(M):
    link = input().strip()
    print(password_map[link])