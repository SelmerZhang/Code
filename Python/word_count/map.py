import re

with open ("yun.txt") as f:
    words_box=[]
    for line in f:
        if re.match(r'[a-zA-Z0-9]',line):
            words_box.extend(line.strip().split())

for i in words_box:
    print(i)
