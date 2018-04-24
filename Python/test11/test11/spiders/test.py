# -*- coding: utf-8 -*-
import scrapy
from selenium import webdriver
from bs4 import BeautifulSoup
import pdb
class TestSpider(scrapy.Spider):
    name = 'test'
    #allowed_domains = ['ios.com']
    start_urls = ['http://www.cnblogs.com/fnng/p/3160606.html']
    #pdb.set_trace()

    # def __init__(self):
    #     super(TestSpider, self).__init__()
    #     self.web = webdriver.Chrome()
    #
    #     self.web.get(self.start_urls)
    #     pdb.set_trace()
    #     self.page = BeautifulSoup(self.web.page_source, "lxml")
    #     print("--"*20)


    def parse(self, response):
        print("*"*40)
        # print(self.page)



