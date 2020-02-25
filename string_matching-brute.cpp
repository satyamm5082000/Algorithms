#include<bits/stdc++.h>
using namespace std;

void search_pattern(string a,string b)
{
    int x,y,j;
    x=a.length();
    y=b.length();
    for(int i=0;i<x-y;i++)
    {
        for( j=0;j<y;j++)
        {
            if(a[i+j]!=b[j])
            break;
        }
        if(j==y)
        {
            cout<<"pattern found from "<<i<<" to "<<i+y<<"."<<endl;
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

    search_pattern(s,s1);
}