#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    int edges[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    int a,b,w;
    for(int i=0;i<e;i++)
    {
    cin>>a>>b>>w;
    edges[a][b]=w;
    edges[b][a]=w;
    }
    int path[n];
    int weightfromsource[n];
    for(int i=0;i<n;i++)
    {
        weightfromsource[i]=INT_MAX;
    }
    int visited[n]={0};
        int cnt=0;
        int src;
        path[0]=-1;
        weightfromsource[0]=0;
        while (1)
        {
            int min=INT_MAX;
          for(int j=0;j<n;j++)
          {
              if(weightfromsource[j]<min&&visited[j]==0){
              min=weightfromsource[j];
              src=j;
              }
          }
        cnt++;
        visited[src]=1;

          for(int i=0;i<n;i++)
          {
              if(edges[src][i]!=0&&visited[i]==0)
              {
                  if(weightfromsource[i]>edges[src][i]+weightfromsource[src]){
                  weightfromsource[i]=edges[src][i]+weightfromsource[src];
                  path[i]=src;
                  
                  }
              }
          }
       if(cnt==n-1)
       break;
        }
        for(int i=1;i<n;i++)
        {
            cout<<path[i]<<" "<<i<<" "<<weightfromsource[i]<<endl;
        }

    
}