__author__="bobby"
import hashlib

def get_md5(url): #得到一个连接的哈希吗
    if isinstance(url , str):
        url = url .encode("utf-8")
    m = hashlib.md5()
    m.update(url)
    return m.hexdigest()

if __name__ == "__main__":
    print(get_md5("http://jobbole.com".encode("utf-8")))
