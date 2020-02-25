#include<bits/stdc++.h>
using namespace std;


int main()
{
     int n,tq;
    cout<<"Enter no. of  processes\n";
    cin>>n;
    int pid[n],at[n],bt[n],ct[n],wt[n],tat[n],bt1[n];
    cout<<"Enter values\n";
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<".\n";
        cout<<"enter process id:";
        cin>>pid[i];
        cout<<"enter arrival time:";
        cin>>at[i];
        cout<<"enter burst time:";
        cin>>bt[i];
    }
    cout<<"Enter time quanta:";
    cin>>tq;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                swap(pid[j],pid[j+1]);
                swap(at[j],at[j+1]);
                swap(bt[j],bt[j+1]);
            }
            
        }
    }
    for(int i=0;i<n;i++)
      bt1[i]=bt[i];
    queue<int>ready_q,run_q;
    ready_q.push(pid[0]);
    run_q.push(pid[0]);
    int t;
    t=at[0]+tq;
    bt1[0]-=tq;
    while(1)
    {
        for(int i=0;i<n;i++)
        {
            while()
        }
    }
    
    



}