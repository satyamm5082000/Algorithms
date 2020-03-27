#include<bits/stdc++.h>
using namespace std;


int Staircase(int n,int *output){

    if(n==0)
    return 1;
    if(n==1)
    return 1;
    if(n==2)
    return 2;
   if(output[n]>0)
   {
       return output[n];
   }
   int out=Staircase(n-1,output)+Staircase(n-2,output)+Staircase(n-3,output);

   output[n]=out;
  
  return out;

}

int main()
{
    int n;
    cin>>n;
    int output[n+1]={0};
    int noofways=Staircase(n,output);
    cout<<noofways;
}