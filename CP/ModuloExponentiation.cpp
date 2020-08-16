#include<bits/stdc++.h>
using namespace std;

int pow(int a,int b,int c)
{
    if(b==0)
    return 1;
    if(a==0)
    return 0;

    long res;
    if(b%2==0)
    {
        long r1=pow(a,b/2,c);
        res=(r1*r1)%c;
    }
    else{
        long r1=pow(a,b-1,c);
        res=a%c;        
        res=(res*r1)%c;
    }
    return (int)((res+c)%c);
}

int main(){
   int a,b,c;
   cin>>a>>b>>c;

   cout<< pow(a,b,c)<<endl;
}