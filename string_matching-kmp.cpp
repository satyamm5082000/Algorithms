#include<bits/stdc++.h>
using namespace std;

void counting_ps(string x,int p, int arr[])
{
    int j=0;
    arr[0]= 0;
    int i=1;
    while(i<p)
    {
        if(x[i]==x[j])
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
}

void search_pattern_kmp(string a,string b)
{
    int x,y;
    x=a.length();
    y=b.length();
    int arr[y];
   counting_ps(b,y,arr);
    int i=0,j=0;
    while(i<x)
    {
        if(b[j]==a[i])
        {
            i++;
            j++;
        }
        if(j==y)
        {
               cout<<"pattern found from "<<i-j<<" to "<<i-j+y<<"."<<endl;
               j=arr[j-1];
        }
        else if(i<x&& (b[j]!=a[i])){
            if(j!=0)
            j=arr[j-1];
            else 
            i++;
        }
    }
}

int main()
{
    string s,s1;
    cout<<"enter the string:"<<endl;
    cin>>s;
    cout<<"enter the pattern:"<<endl;
    cin>>s1;

    search_pattern_kmp(s,s1);
}