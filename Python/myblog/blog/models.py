from django.db import models

# Create your models here.
class Article(models.Model):
    objects = models.Manager()
    title = models.CharField(max_length = 30, default="Title")
    content = models.TextField(null = True, max_length=100)

    def __str__(self):
        return self.title

