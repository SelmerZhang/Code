# -*- coding: utf-8 -*-
import scrapy
from selenium import webdriver
from bs4 import BeautifulSoup
from text5_Douyu.items import Text5DouyuItem



class DouyuimageSpider(scrapy.Spider):
    name = 'DouyuImage'
    #allowed_domains = ['douyu.com']
    start_urls = ['https://yuba.douyu.com/allclassify/anchorlist/list/516']

    def __init__(self):
        super(DouyuimageSpider,self).__init__()
        self.web=webdriver.Chrome()
        # self.web.get(self.start_urls)
        # self.page = BeautifulSoup(self.web.page_source,"lxml")


        

    def parse(self, response):
        print("*"*50)
        print(response.url)
        self.web.get(response.url)
        print(type(self.web.page_source))

    #     item=Text5DouyuItem()
    #     list_item=response.xpath("//div[@class='classify-classifyGroup-1lMJV']/div")
    #     #list_item=soup.find_all("div",class_="classify-classifyGroup-1lMJV")#主页所有主播链接
    #     for list in list_item:
    #         nickname=list.xpath("//div[0]/p/text()").extract()[0]
    #         #nickname=list.find("div",class_="style-itemTex-EZ_Wl").p.text#主播姓名
    #         #image_href=list.find("img")["@src"]#获取img标签下的src链接
    #         image_href=list.xpath("//image/@src").extract()[0]
    #
    #         item[nickname]=nicknme
    #         item[image_href]=image_href
    #         yield item
    #
    # def closed(self,reason):
    #     print("关闭爬虫，reason："+reason)
    #     self.web.quit()






        
        
        




