#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int,int>,int>&p,pair<pair<int,int>,int>&p1)
{
    return p.second <p1.second;
}
int checkparent(int x,int *parentarray)
{
   if(parentarray[x]==x)
   {
       return x;
   }
   return checkparent(parentarray[x],parentarray);
}


int main()
{
    int n,e,a,b,w;
    cin>>n>>e;
    vector<pair<pair<int,int>,int>>v;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>w;
        v.push_back(make_pair(make_pair(a,b),w));
    }
    sort(v.begin(),v.end(),cmp);
    
    vector<pair<pair<int,int>,int>>out;
    int parentarray[n];
    for(int i=0;i<n;i++)
    {
        parentarray[i]=i;
    }
   int c=0;
   
   for(int i=0;i<e;i++)
   {
      if(c==n-1)
      {
           break;
      }

      int x=v[i].first.first;
      int y=v[i].first.second;
      int w1=v[i].second;
      
      if(checkparent(x,parentarray)!=checkparent(y,parentarray))
       {
           out.push_back(make_pair(make_pair(x,y),w1));
           parentarray[y]=x;
           c++;
       }
   }
   
   for(int i=0;i<out.size();i++)
   {
       cout<<out[i].first.first<<" "<<out[i].first.second<<" "<<out[i].second<<endl;
   }



}