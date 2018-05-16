import re

def get_words(file):
    with open (file) as f:
        words_box=[]
        for line in f:
                if re.match(r'[a-zA-Z0-9]',line):
                    words_box.extend(line.strip().split())
    return words_box


def get_dict(li):
    dic = {}
    for i in li:
        if i in dic.keys():
            dic[i] = dic[i]+1
        else:
            dic[i]=1
    return dic


if __name__ == '__main__':
    a=get_words('yun.txt')#将内容装载入list
    s=get_dict(a)
    print(len(s))
    print(s)




