import sys
from collections import Counter
input = sys.stdin.readline

def dist(a, b):
    d = 0
    for i in range(4):
       if a[i] != b[i]:
           d += 1
    return d

def check(count1, count2):
    for k, v in count2.items():
        if count1[k] < v:
            return False
    return True

mbtis = ['ISTJ', 'ISFJ', 'INFJ', 'INTJ', 'ISTP', 'ISFP', 'INFP', 'INTP', 'ESTP', 'ESFP', 'ENFP', 'ENTP', 'ESTJ', 'ESFJ', 'ENFJ', 'ENTJ']
case_map = {}
for mbti1 in mbtis:
    for mbti2 in mbtis:
        for mbti3 in mbtis:
            tmp = [mbti1, mbti2, mbti3]
            tmp.sort()
            case_map[" ".join(tmp)] = dist(mbti1, mbti2) + dist(mbti2, mbti3) + dist(mbti1, mbti3)    

T = int(input())
for t in range(T):
    N = int(input())
    mbtis = input().strip().split()
    mbtis.sort()
    count1 = Counter(mbtis)
    ans = 99999
    for k, v in case_map.items():
        count2 = Counter(k.split())
        if check(count1, count2):
            ans = min(ans, v)
    print(ans)