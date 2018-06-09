
from django.urls import path,include
from . import views

urlpatterns = [
    path("message/", views.getform),
]