#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>>v;
    int n;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<2;j++ )
        {
            cin>>n;
            v[i].push_back(n);
        }
    }
    for(int i=0;i<5;i++){
        cout<<v[i].size();
    }    
    
}