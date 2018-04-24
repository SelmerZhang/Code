from django.contrib import admin
from .models import Article  #models 前面一定要加上点号，因为避免与下面的blog2重名

admin.site.register(Article)
