#include <bits/stdc++.h>
using namespace std;

 bool cmpp(const pair<int,int>&m1,const pair<int,int> &m2){

     double a = m1.first/m1.second;
     double b = m2.first/m2.second;
     return a>b;

 }


int knapsack(int w,vector<pair<int,int>> v)
{
    sort(v.begin(),v.end(),cmpp);
    
    int currw=0;
    int maxvalue=0;
    for(auto it=v.begin();it!=v.end();it++)
    {
        if(currw+it->second<=w)
        {
            currw=currw+it->second;
            maxvalue=maxvalue+it->first;
        }
        else
        {
            int m=w-currw;
          maxvalue += it->first * ((double)m/it->second);
        }
        
    }
    return maxvalue;
}

int main() {
	vector<pair<int,int>>v1;
    int n,v,w;

    // cin>>n;
    // while(n--)
    // {
    //     cin>>v>>w;
    //     v1.push_back(make_pair(v,w));
    // }
	v1.push_back(make_pair(120,30));
	v1.push_back(make_pair(100,20));
	v1.push_back(make_pair(60,10));
	
   int max,w1;
   cin>>w1;
   max=knapsack(w1,v1);
   cout<<"maximum value: \t"<<max;
}