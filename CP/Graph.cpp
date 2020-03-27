#include<bits/stdc++.h>
using namespace std;

void printGraphDFS(int **edges,int n ,int *vis,int st)
{
    cout<<st<<endl;
    vis[st]=1;
    for(int i=0;i<n;i++)
    {
        if(i==st)
        continue;
        if(edges[st][i]==1)
        {
            if(vis[i])
            continue;
            
          printGraphDFS(edges,n,vis,i);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        printGraphDFS(edges,n,vis,i);
    }
}
bool Haspath(int **edges,int n,int st,int en,int *vis)
{
     vis[st]=1;
    for(int i=0;i<n;i++)
    {
        if(i==st)
        continue;
        if(edges[st][i]==1)
        {
            if(vis[i])
            continue;
            if (i==en)
            {
                return true;
            }
          return Haspath(edges,n,i,en,vis);
        }
    }
    return false;
}
void Getpathbydfs(int **edges,int n,int st,int en,int *vis,int *path,int m=0)
{
    vis[st]=1;
    path[m]=st;
    m++;
    if(st==en)
    {
      for(int i=0;i<m;i++)
      {
          cout<<path[i]<<endl;
      }
    }
  for(int i=0;i<n;i++)
  {
   if(i==st)
   continue;

   if(edges[st][i]==1)
   {
       if(!vis[i])
       {
           Getpathbydfs(edges,n,i,en,vis,path,m);
       }
   }
  }

} 

 

void printGraphBFS(int **edges,int n,int *vis,int st)
{
    queue<int>vertices;
   vertices.push(st);
   vis[st]=1;
   while(!vertices.empty())
   {
       int s=vertices.front();
       vertices.pop();
       cout<<s<<endl;
       for(int i=0;i<n;i++)
       {
           if(i==st)
           continue;

           if(edges[s][i]==1&&(vis[i]!=1))
           {
               vertices.push(i);
               vis[i]=1;
           }
       }
   }

   for(int i=0;i<n;i++)
    {
        if(!vis[i])
        printGraphBFS(edges,n,vis,i);
    }
}
void Getpathbybfs(int **edges,int n,int st,int en,int *vis)
{
    map<int ,int>path;
    queue<int>vertices;
   vertices.push(st);
   vis[st]=1;
   while(!vertices.empty())
   {
       int s=vertices.front();
       vertices.pop();
       if(s==en)
       {
        while(s!=st)
        {
           int x=path[s];
           cout<<s<<endl;
           s=path[x];
           cout<<x<<endl;

        }
        
        break;

       }
       for(int i=0;i<n;i++)
       {
           if(i==st)
           continue;

           if(edges[s][i]==1&&(vis[i]!=1))
           {
               path[i]=s;
               vertices.push(i);
               vis[i]=1;
           }
       }
   }
//    for(auto it=path.begin();it!=path.end();it++)
//    {
//        cout<<it->first<<" "<<it->second<<endl;
//    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    int **edges=new int *[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int [n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }  
    }
    int a ,b,visi[n]={0};
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    int st,en,*path=new int [n];
    cin>>st>>en;
   // Getpathbydfs(edges,n,st,en,visi,path);
    Getpathbybfs(edges,n,st,en,visi);

    // bool r=Haspath(edges,n,st,en,visi);
    // if(r==true)
    // cout<<"YES";
    // else
    // cout<<"NO";
    

   // printGraphDFS(edges,n,visi,st);
    //printGraphBFS(edges,n,visi,st);
}