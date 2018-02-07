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
        

    def parse(self, response): 
        item=Text5DouyuItem() 
        list_item=response.xpath("//div[@class='classify-classifyGroup-1lMJV']")
        for list in list_item:
            nickname=list.xpath("./div/div/p/text()").extract()[0]
            image_href=list.xpath("./div/img/@src").extract()[0]#获取img标签下的src链接

            item[nickname]=nicknme
            item[image_href]=image_href
            yield item
    
    def closed(self,reason):
        print("关闭爬虫，reason："+reason)
        self.web.quit()






        
        
        




