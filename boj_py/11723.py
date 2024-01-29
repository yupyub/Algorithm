import sys
input = sys.stdin.readline

count = int(input())
s = 0
for c in range(count):
    comm = input().split()
    if comm[0] == 'add':
        s |= 1 << int(comm[1])
    elif comm[0] == 'remove':
        s &= ~(1 << int(comm[1]))
    elif comm[0] == 'check':
        if s & (1 << int(comm[1])):
            print(1)
        else:
            print(0)
    elif comm[0] == 'toggle':
        s ^= (1 << int(comm[1]))
    elif comm[0] == 'all':
        s = (1 << 21) - 1
    elif comm[0] == 'empty':
        s = 0