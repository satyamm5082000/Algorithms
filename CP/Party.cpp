#include<bits/stdc++.h>
using namespace std;

int main()
{ 
    int budg, n;
   cin>>budg>>n;
   int exp[n],fun[n];
   for(int i=0;i<n;i++)
   {
       cin>>exp[i]>>fun[i];
   }

  int dp[n+1][budg+1],maxexp=0;
  for(int i=0;i<=n;i++)
  {
      for(int j=0;j<=budg;j++)
      {
          if(j<=5||i==0)
          dp[i][j]=0;
          else if(exp[i-1]<=j){
          int a=max(dp[i-1][j],dp[i-1][j-exp[i-1]]+fun[i-1]);
          dp[i][j]=a;    
          }
          else
          {
            dp[i][j]=dp[i-1][j];
          } 
        // cout<<dp[i][j]<<" ";
      }
      //cout<<endl;
  }
   int  maxfun=dp[n][budg],f=0;
    for(int i=6;i<=budg;i++)
    {
        if(dp[10][i]==maxfun){
        maxexp=i;
    break;
    }
        
    }

cout<<maxexp<<" "<<maxfun;



}