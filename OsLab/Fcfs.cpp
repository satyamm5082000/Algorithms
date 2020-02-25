#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter no. of  processes\n";
    cin>>n;
    int pid[n],at[n],bt[n],ct[n],wt[n],tat[n];
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
            if(at[j]==at[j+1]&&pid[j]>pid[j+1])
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
    for(int i=1;i<n;i++)
    {
       Gc.push_back(pid[i]);
       ct[i]=bt[i]+ct[i-1];
       tat[i]=ct[i]-at[i];
       wt[i]=tat[i]-bt[i];
    
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