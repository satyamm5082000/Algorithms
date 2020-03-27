#include<bits/stdc++.h>
using namespace std;

int Moneyloot(int n,int *money,int *dp)
{

  if(n<=0)
  return 0;
   if(dp[n]>0)
   return dp[n];


  int m;
  int a=Moneyloot(n-2,money+2,dp)+money[0];
  int b=Moneyloot(n-1,money+1,dp);

  m=max(a,b);
 dp[n]=m;
  return m;

}
int main()
{
    int n;
    cin>>n;
    int money[n];
    for(int i=0;i<n;i++)
    {
        cin>>money[i];
    }
    int dp[n]={0};

    int maxloot;
    maxloot=Moneyloot(n,money,dp);
    cout<<maxloot;
}