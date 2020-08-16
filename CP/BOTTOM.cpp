#include<bits/stdc++.h>
using namespace std;

void Dfs(vector<int>* edges,int*vis,int st,int n,stack<int> &Endvertices)
{
     vis[st] = 1;
    for (int i = 0; i < edges[st].size(); i++)
    {
            if (vis[edges[st][i]])
                continue;
               
           Dfs(edges,vis ,edges[st][i],n,Endvertices);
    }
    Endvertices.push(st);
}
void Dfs1(vector<int>* edgesOpp,vector<int> &v,int n,int st,int *vis)
{
    vis[st]=1;
    v.push_back(st);
    for(int i=0;i<edgesOpp[st].size();i++)
    {
        if(!vis[edgesOpp[st][i]]){
        Dfs1(edgesOpp,v,n,edgesOpp[st][i],vis);
        }
    }
}

vector<vector<int>> SCC(vector <int>*edges,vector<int>*edgesOpp,int *vis,int n)
{
    vector<vector<int>>components;
   stack<int> Endvertices;
   for(int i=0;i<n;i++)
   {
       if(!vis[i])
       {
           Dfs(edges,vis,i,n,Endvertices);
       }
   }
   for(int i=0;i<n;i++)
   {
       vis[i]=0;
   }
//    while(!Endvertices.empty())
//    {
//        cout<<Endvertices.top()<<endl;
//        Endvertices.pop();
//    }
   while(!(Endvertices.empty()))
   {
    int a=Endvertices.top();
    Endvertices.pop();
    if(!vis[a]){
    vector<int >v1;
    Dfs1(edgesOpp,v1,n,a,vis);
    components.push_back(v1);
    cout<<endl;
    }
   }
   return components;
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>*edges=new vector<int>[n];
    vector<int>*edgesOpp=new vector<int>[n];
    int edges1[n][n]={0};
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        edges1[a][b]=1;
        edges[a].push_back(b);
        edgesOpp[b].push_back(a);
    }

    int vis[n]={0};
  vector<vector<int>> components=SCC(edges,edgesOpp,vis,n);
    // for(int i=0;i<components.size();i++)
    // {
    //     for(int j=0;j<components[i].size();j++)
    //     {
    //         cout<<components[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
   






}