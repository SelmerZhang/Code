from django.shortcuts import render

# Create your views here.
def getform(request):
    # render(request, template_name, context=None, content_type=None, status=None, using=None):
    #template_name,是放置HTML文件的位置路径
    return render(request, "message/templates/message_form.html")

