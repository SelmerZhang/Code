from django.contrib import admin

# Register your models here.
from . import models
class BlogAdmin(admin.ModelAdmin):
    list_display=('id', 'title','content')
admin.site.register(models.Ariticle)