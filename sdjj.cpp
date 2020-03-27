#include<bits/stdc++.h>
using namespace std;

int main()
{
 int t;
 cin>>t;
 string a;
 while(t--)
 {
    cin>>a;
    int l=a.length();
    int arr[l];
     int j=0,m=0,n=0;
    arr[0]= 0;
    int i=1;
    while(i<l)
    {
        if(a[i]==a[j])
        {
            j++;
            arr[i]=j;
            i++;
        }
        else
        {
            if(j!=0)
            {
                j=arr[j-1];
            }
            else{
                arr[i]=0;
                i++;
            }
        }
        
    }
    for(int i=l-1;i>=0;i--)
    {
     if(a[i]=='I'){
     m=i;
     break;
     }
    }
    for(int i=l-1;i>=0;i--)
    {
     if(a[i]=='O'){
     n=i;
     break;
     }
    }

     w if(m!=0)
    cout<<arr[m];
    else 
    cout<<0;
 }
}
 	

