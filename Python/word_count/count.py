import re,collections
from collections import Counter
def get_words(file):
    with open (file) as f:
        words_box=[]
        for line in f:
                if re.match(r'[a-zA-Z0-9]',line):
                    words_box.extend(line.strip().split())
    return collections.Counter(words_box)

a=get_words('yun.txt')
print(a.most_common(10))