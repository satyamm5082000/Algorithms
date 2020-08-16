#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
    return a;

    return gcd(b,a%b);
}
int main()
{
   int a;
   cin>>a;
   string b;
   cin>>b;
   int b1;

   int n=0,i=0;

   while(i<b.length())
   {

       n=(((n%a)*(10%a))+((int)b[i]%a))%a;
     i++;
   }

   b1=n;
   cout<<gcd(a,b1);
}







