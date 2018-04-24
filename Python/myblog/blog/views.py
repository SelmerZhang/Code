from django.shortcuts import render
from   django.http import HttpResponse
# Create your views here.
from . import models
#后台代码


def index(request):
    #article = models.Article.objects.get(pk=1)
    articles = models.Article.objects.all()
    return render(request, "blog/index.html", {"articles" : articles})#后面的键值对是将数据传送到HTML中


def article_page(request, article_id):
    article = models.Article.objects.get(pk=article_id)
    return render(request, "blog/article_page", {"article": article})