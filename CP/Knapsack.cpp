#include<bits/stdc++.h>
using namespace std;

int Knapsack(int n,int W,int *val,int *wt)
{
    if(n==0||W==0)
    return 0;
   int a;

    if(wt[n-1]<=W)
   {
       int x=Knapsack(n-1,W,val,wt);
        int y=Knapsack(n-1,W-wt[n-1],val,wt)+val[n-1];
        a=max(x,y);
   }
    else
    {
         a=Knapsack(n-1,W,val,wt);
    }

    return a;
}
int Knapsackitr(int n,int W,int *val,int *wt)
{
    int dp[n+1][W+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
            else if(wt[i-1]<=j)
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
            else 
            dp[i][j]=dp[i-1][j];

        }
    }

  return dp[n][W];
}

int main()
{
    int n;
    cin>>n;
    int val[n],wt[n];
    for(int i=0;i<n;i++)
    {
        cin>>val[i]>>wt[i];
    }
    int W;
    cin>>W;

    int maxv=Knapsack(n,W,val,wt);
    cout<<maxv;
}