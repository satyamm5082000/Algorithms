#include<bits/stdc++.h>
using namespace std;


int main()
{
    int arr[5]={1 ,-1 ,2 ,2 ,2};
    long cost=0;
    int i=0,j;
    while(i<4)
    {
        j=i+1;
        while(j<4)
        {
          if((abs(arr[i])>abs(arr[j]))||(abs(arr[i])==abs(arr[j]))&&arr[i]>0)
          {
              break;
          }
          else j++;
        }
        cost+=(j-i)*arr[i] + (j*j - i*i)*arr[i];
              i=j;
    }
cout<<cost;
}