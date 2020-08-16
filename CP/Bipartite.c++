#include<bits/stdc++.h>
using namespace std;

bool Bipartite(vector<int>*edges,int n)
{
    vector<int>v[2];
    vector<int>pending;
   v[0].push_back(0);
   pending.push_back(0);
   while(pending.size()>0)
   {
       int a=pending.back();
       pending.pop_back();
       int c=count(v[0].begin(),v[0].end(),a)>0?0:1;
       for(int i=0;i<edges[a].size();i++)
       {
           if(count(v[0].begin(),v[0].end(),edges[a][i])==0&&count(v[1].begin(),v[1].begin(),edges[a][i]))
           {
              v[1-c].push_back(edges[a][i]);
              pending.push_back(edges[a][i]);
           }
           else if(count(v[c].begin(),v[c].end(),edges[a][i])>0)
           {
              return false;
           }
       }
   }
   return true;
}

int main()
{
        int n,e;
    cin>>n>>e;
    vector<int>*edges=new vector<int>[n];
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    bool ans=Bipartite(edges,n);
    if(ans)
    cout<<"Yes";
    else
    cout<<"No";
}


