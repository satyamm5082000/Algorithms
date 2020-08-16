#include<bits/stdc++.h>
using namespace std;

int Coinchange(int n,int amount,int *coins)
{
    if(amount==0)
    return 1;
    if(n==0)
    return 0;

    if(amount<0)
    return 0;

  int x=Coinchange(n,amount-coins[0],coins);
  int y=Coinchange(n-1,amount,coins+1);
   
   return x+y;

}

int main()
{
  int amount;
  cin>>amount;
  int n;
  cin>>n;
  int coins[n];
  for(int i=0;i<n;i++)
  {
      cin>>coins[i];          
  }
  int noofways=Coinchange(n,amount,coins);


  cout<<noofways;

}