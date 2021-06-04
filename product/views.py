from django.shortcuts import render,redirect,get_object_or_404
from django.contrib.auth.decorators import login_required
from .models import product
from django.utils import timezone

def home(request):
    products = product.objects
    return render(request,'product/home.html',{'products': products})
@login_required(login_url='/account/signup')
def create(request):
    if request.method=='POST':
        if request.POST['title'] and request.POST['body'] and request.POST['url'] and request.FILES['icon'] and request.FILES['image'] :
            prodact = product()
            if request.POST['url'].startswith('http://') or request.POST['url'].startswith('https://'):
                prodact.url=request.POST['url']
            else:
                prodact.url = 'http://'+request.POST['url']

            prodact.title = request.POST['title']
            prodact.body = request.POST['body']
            prodact.url = request.POST['url']
            prodact.image = request.FILES['image']
            prodact.icon = request.FILES['icon']
            prodact.pub_date = timezone.datetime.now()
            prodact.hunter = request.user
            prodact.save()
            return redirect('/product/'+str(prodact.id))
            
        else:
            return render(request,'product/create.html',{'error':'all files must be include'})

    else:

        return render(request,'product/create.html')

def detail(request,product_id):
    prodact = get_object_or_404(product, pk=product_id)
    return render(request,'product/detail.html',{'product':prodact})

@login_required(login_url='/account/signup')
def upvote(request,product_id):
    if request.method=='POST':
        prodact = get_object_or_404(product, pk=product_id)
        prodact.vote_totals +=1
        prodact.save()
        return redirect('/product/'+str(prodact.id))