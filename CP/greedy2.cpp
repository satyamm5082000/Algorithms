#include<bits/stdc++.h>
using namespace std;

return p.first.second<p1.first.second;
}
int main()
{
    
  vector<pair<pair<int,int>,int>>v;
  v.push_back(make_pair(make_pair(3,10),20));
  v.push_back(make_pair(make_pair(1,2),50));
  v.push_back(make_pair(make_pair(6,19),100));
  v.push_back(make_pair(make_pair(2,100),200));
  sort(v.begin(),v.end(),cmp);
  int maxpro[4];
  maxpro[0]=v[0].second;
  
  for(int i=1;i<4;i++)
  {
    for(int j=i-1;j>=0;j--)
    {
      if(v[j].first.second<=v[i].first.first)
      {
          maxpro[i]=maxpro[j]+v[i].second;
      }     
    }
  }

   cout<<maxpro[3];


}