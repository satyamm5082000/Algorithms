#include<bits/stdc++.h>
using namespace std;

int maxpr(int *pr,int t,int n,int *at,int *ct)
{
    int maxpr=INT_MIN,in;
    for(int i=0;i<n;i++)
    {
        if(pr[i]>maxpr&&at[i]<=t&&ct[i]==0)
        {
            maxpr=pr[i];
            in=i;
        }
    }
    return in;
}

int main()
{
     int n;
    cout<<"Enter no. of  processes\n";
    cin>>n;
    int pid[n],at[n],bt[n],ct[n]={0},wt[n],tat[n],pr[n];
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
        cout<<"enter Priority:";
        cin>>pr[i];        
    }
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
            if(at[j]==at[j+1]&&pr[j]<pr[j+1])
            {
                 swap(pid[j],pid[j+1]);
                swap(at[j],at[j+1]);
                swap(bt[j],bt[j+1]);
            }
            
        }
    }
     vector<int>Gc;
    Gc.push_back(pid[0]);
    ct[0]=bt[0]+at[0];
    tat[0]=ct[0]-at[0];
    wt[0]=tat[0]-bt[0];
    int t=ct[0];
    for(int i=0;i<n;i++)
    {
        int x;
        x=maxpr(pr,t,n,at,ct);
        Gc.push_back(pid[x]);
        ct[x]=bt[x]+t;
        tat[x]=ct[x]+at[x];
        wt[x]=tat[x]-bt[x];
        t=ct[x];
    }
    cout<<"Gantt Chart: \n";
   for(int i=0;i<Gc.size();i++)
   {
       cout<<Gc[i];
       if(i<Gc.size()-1)
       cout<<"|";
   }
    cout<<"\nResult....\n";
    cout<<"Processid\tArrivaltime\tBursttime \tCompletiontime\tWaitingtime\tTurnaroundtime\n";
    for(int i=0;i<n;i++)
    {
        cout<<pid[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<ct[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
    }


}
