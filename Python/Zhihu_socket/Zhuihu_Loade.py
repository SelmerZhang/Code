__author__="bobby"
import requests
import http.cookiejar as cookielib
import re
from bs4 import BeautifulSoup

session =requests.session()
session.cookies = cookielib.LWPCookieJar(filename="cookies.txt")
try:
    session.cookies.load(ignore_discard=True)
except:
    print("cookies未能加载")

agent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.139 Safari/537.36"
header = {
    "HOST": "www.zhihu.com",
    "Referer": "https://www.zhihu.com/",
    "User-Agent": agent #之间是短线短线！！！！，不是下划线
}


def get_xsrf():
    response = session.get("", headers=header)
    soup = BeautifulSoup(response.text, "html.parser")
    #print(soup.prettify())
    #xsrf = soup.find_all("input",{'name':'_xsrf'})
    xsrf = "b19682f3-6d28-4631-825f-822724dff803"
    return xsrf


def get_index():
    response = session.get("https://www.zhihu.com/signin", headers=header)
    with open("index_page.html","wb") as f:
        f.write(response.text.encode("utf-8"))
        print("网页写入成功")


def zhihu_login(account,passward):
    print("手机号码登录")
    post_url =  'https://www.zhihu.com/signin'
    post_date = {
        "xsrf" : get_xsrf(),
        "phone_nuber" : account,
        "passward" : passward
    }
    response_text = session.post(post_url, data=post_date, headers=header) #是data不是data！
    print("登录成功")
    session.cookies.save()




zhihu_login("18328020353","520lkl")
get_index()
