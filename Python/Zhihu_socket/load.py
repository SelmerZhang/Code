import requests
import re

def zhihu_login(account ,password):
    post_url={
        "phone_num": account,
        "password": password
    }