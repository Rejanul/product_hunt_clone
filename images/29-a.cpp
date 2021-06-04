
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,x,counter=0,t=0,p1,p2,ribon;
    bool fluge=false;
    int arra[4];
    cin>>ribon;
    for(int i=0;i<3;i++)
    {
        cin>>arra[i];
    }
    sort(arra,arra+3);
    for(int f=0;f<3;f++){
    x=ribon;
    n=x/arra[f];
    cout<<"f  ="<<f<<endl;
    if((x%arra[f])==0)
    {
        cout<<n<<endl;
        return 0;
    }
    a=n*arra[f];
    cout<<"a ="<<a<<endl;
    b=ribon-a;
    if(f==0)
    {
        p1=1;
        p2=2;
    }
    else if(f==1)
    {
        p1=0;
        p2=2;
    }
    else if(f==2)
    {
        p1=0;
        p2=1;
    }
   cout<<"b ="<<b<<endl;
     if(b==arra[p1]||b==arra[p2])
       {
           n=n+1;
           cout<<n<<endl;
           return 0;
       }
    for(int j=1;j>0;j++)
    {
       c=a-arra[f]*j;
        b=ribon-c;
        cout<<" from loop c ="<<c<<"ARRA[F] "<<arra[f]<<"f"<<f<<endl;
        cout<<"from loop b ="<<b<<endl;
      if(c<arra[f])
      {
         cout<<"from break"<<endl;
          break;
      }
      for(int k=1;k>=0;k++)
      {
          for(int l=1;l>0;l++)
          {
              int sum=(arra[p1]*k)+(arra[p2]*l);
              if(sum>b)
              {
                  fluge=true;
                  break;
              }
              if(b==sum)
              {
                  n=n-j+k+l;
                  cout<<"double loop"<<endl;
                  cout<<n<<endl;
                  return 0;
              }
          }
          if(fluge==true)
          {
              break;
          }
      }
      fluge=false;
         if(((b%arra[p1])==0)||((b%arra[p2])==0))
       {
           if((b%arra[p1])==0)
           {
               n=n-j+(b/arra[p1]);
           }
           else if ((b%arra[p2])==0)
           {
               n=n-j+(b/arra[p2]);
           }

           cout<<"from loop n j"<<n<<" "<<j<<endl;
             cout<<n<<endl;
           return 0;
       }

    }

    }
}
