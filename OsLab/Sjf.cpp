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
            
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(bt[i]==bt[j])
            {
                if(at[i]>at[j])
                {
                swap(pid[i],pid[j]);
                swap(at[i],at[j]);
                swap(bt[i],bt[j]);  
                }
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
       int t=ct[i-1],p;
       int b=bt[i];
       for(int j=i;j<n;j++)
       {
           if(t>=at[j]&&b>=bt[j])
           {
               b=bt[j];
               p=j; 
           }
           
       }
       Gc.push_back(pid[p]);
       ct[p]=bt[p]+t;
       tat[p]=ct[p]-at[p];
       wt[p]=tat[p]-bt[p];
       swap(pid[p],pid[i]);
       swap(at[p],at[i]);
       swap(bt[p],bt[i]);
       swap(ct[p],ct[i]);
       swap(wt[p],wt[i]);
       swap(tat[p],tat[i]);  
    
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