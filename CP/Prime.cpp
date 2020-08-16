#include<bits/stdc++.h>
using namespace std;

bool checkprime(int n)
{
    int c=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0){
         if(i*i==n)
        c+=1;
        else
        c+=2;
        }
    }
    if(c==2)
    return  true;
    else
    return false;
}


int main()
{
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(checkprime(i))
        cnt++;

    }
    cout<<cnt;
}

