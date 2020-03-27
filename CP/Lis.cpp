#include<bits/stdc++.h>
using namespace std;

int Lis(int*in,int n)
{
    int out[n+1];
    out[0]=1;
    for(int i=0;i<n;i++)
    {
        out[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(in[j]>in[i])
            continue;

            int x=out[j]+1;
            if(x>out[i])
            out[i]=x;
        }
    }
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(out[i]>max)
        max=out[i];
    }

    return max;
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
    int a=Lis(in,n);
    cout<<a;

}