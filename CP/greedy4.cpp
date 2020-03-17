#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int,int>,int>&p,pair<pair<int,int>,int> &p1)
{
  double x=p.second/p.first.second;
  double y=p1.second/p1.first.second;
  return x>y&&p.first.first<p1.first.first;
}


int main()
{
    int n,d;
    n=3;
    cin>>d;
    vector<pair<pair<int,int>,int>>v;
    v.push_back(make_pair(make_pair(5,1),4));
    v.push_back(make_pair(make_pair(3,2),2));
    v.push_back(make_pair(make_pair(1,1),5));
   
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
    {
       cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second;
    }
 
      double t=0,c=0,x=0;
      
      for(int i=0;i<n;i++)
      {
          if(v[i].first.first>t&&x+v[i].second<=d)
          {
              t+=v[i].first.first;
              c+=v[i].first.second;
              x+=v[i].second;
          }
          else if(x+v[i].second>=d)
          {
              int m=d-x;
         c+=v[i].first.second*((double)m/v[i].second);
          }
      }
        cout<<c;
}