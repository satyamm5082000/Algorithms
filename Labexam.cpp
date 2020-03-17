#include<bits/stdc++.h>
using namespace std;
int max1(int x,int y)
{
    if(x>y)
    return x;
    else
    return y;
}
int main()
{
    int n;
    cin>>n;
    int va[n],wt[n];
    for(int i=0;i<n;i++)
    {
        cin>>va[i]>>wt[i];
    }
    int maxW,maxv;
    cin>>maxW;
    int Knap[n+1][maxW+1];
     for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=maxW;j++)
         {
             if(i==0||j==0)
             Knap[i][j]=0;
             else
             {
                 if(wt[i-1]<=j)
                 Knap[i][j]=max1(Knap[i-1][j],Knap[i-1][j-wt[i-1]]+va[i-1]);
                 else
                 Knap[i][j]=Knap[i-1][j];
                 
             }
         }
     }
     maxv=Knap[n][maxW];
     cout<<"Maximum value :"<<maxv;
}