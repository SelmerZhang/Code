import sys
from sys import stdin

dic = {}

for i in sys.stdin:
    i = i.strip()
    if i in dic.keys():
        dic[i] = dic[i] + 1
    else:
        dic[i] = 1
for key in dic.keys():
    print(key+" : "+dic.get(key))

