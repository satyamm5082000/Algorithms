#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bool sieveprime[n+1];
    for(int i=0;i<=n;i++)
    {
        sieveprime[i]=true;
    }
    sieveprime[0]=false;
    sieveprime[1]=false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(sieveprime[i]){
            sieveprime[i]=true;
            for(int j=i*i;j<=n;j=j+i)
            {
                sieveprime[j]=false;

            }
        } 
    }
    for(int i=0;i<=n;i++)
    {
        if(sieveprime[i]==true)
        cout<<i<<endl;
    }
   
}