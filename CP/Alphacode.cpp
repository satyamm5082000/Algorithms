#include<bits/stdc++.h>
using namespace std;
// int decodings(int *in,int n)
// {
//     int *out=new int[n+1];
//     out[0]=1;
//     out[1]=1;

//     for(int i=2;i<=n;i++)
//     { 
//         out[i]=out[i-1];
//         if(in[i-2]*10+in[i-1]<=26)
//         {
//             out[i]+=out[i-2];
//         }
//     }
//     return out[n];
    
// }
long decodings(int *in,int n,long *arr)
{
    
  if(n==0){
  return 1;
  }

  if(n==1){
  return 1;
  }

  if(arr[n]>0){
  return arr[n];
  }

  long out =decodings(in,n-1,arr);
  if(in[n-2]*10+in[n-1]<=26){
  out+=decodings(in,n-2,arr);
  }

  arr[n]=out;
  return out;

}
int main()
{
  int n;
    cin>>n;
    int *in=new int[n];
    for(int i=0;i<n;i++)
    {
     
        cin>>in[i];
    }
     long arr[n+1]={0};
    long a=decodings(in,n,arr);
    cout<<a;
  
}