#include<bits/stdc++.h>
using namespace std;

void update(int in,int x,int n,int *fentree)
{
    for(;in<=n;in+=(in&(-in)))
    {
           fentree[in]+=x;
         //  cout<<fentree[in]<<endl;
    }
}
 int query(int a,int *fentree)
 {
     int sum=0;
     for(;a>0;a-=(a&(-a)))
     {
      sum+=fentree[a];
     }
     return sum;
 }

    
int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    int Fentree[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        update(i,arr[i],n,Fentree);
    }
    for(int i=1;i<=n;i++)
    {
        //cout<<Fentree[i]<<endl;
    }
    int x,y;
    cin>>x>>y;
    int s=query(y,Fentree)-query(x-1,Fentree);
    cout<<s;


}