#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>&p,pair<int,int> &p1)
{
return p.second<p1.second;
}
int main()
{

  vector<pair<int,int>>v;
  v.push_back(make_pair(1,2));
  v.push_back(make_pair(3,4));
  v.push_back(make_pair(0,6));
  v.push_back(make_pair(5,7));
  v.push_back(make_pair(8,9));
  v.push_back(make_pair(5,9));
 int s=1,lastfin=v[0].second;
  sort(v.begin(),v.end(),cmp);
  for(int i=1;i<v.size();i++)
  {
    if(v[i].first>=lastfin)
    {
    s++;
    lastfin=v[i].second;
    }  
  }
 cout<<s;


}