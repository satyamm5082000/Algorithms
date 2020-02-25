#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter no. of  processes\n";
    cin>>n;
    int pid[n],at[n],bt[n],ct[n]={0},wt[n]={0},tat[n]={0};
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
    int bt1[n];
    for(int i=0;i<n;i++)
    bt1[i]=bt[i];

    vector<int>Gc;
    int t,p=0,b,c=0,x;
    Gc.push_back(pid[0]);
    t=at[0]+1;
    bt1[0]=bt1[0]-1;
    while(1)
    {
        bool flag=true;
       b=bt1[p];
       x=t;
       for(int j=n-1;j>=0;j--)
       {
           flag=false;

           if(j!=p){
           if(at[j]<=t&&b>bt1[j]&&bt1[j]!=0)
           {
               bt1[j]--;
               b=bt1[j];
               p=j;
               t+=1;
               Gc.push_back(pid[p]);
           }
           }
       }
       if(t==x)
       {
               bt1[p]--;
               b=bt1[p];
               t+=1;
               Gc.push_back(pid[p]);

       }
       if(b==0){
           c++;
       ct[p]=t;
       tat[p]=ct[p]-at[p];
       wt[p]=tat[p]-bt[p]; 

       for(int k=0;k<n;k++)
       {
           if(bt1[k]!=0)
           p=k;
       }
       }
     for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(bt[i]==bt[j])
            {
                if(at[i]<at[j])
                {
                swap(pid[i],pid[j]);
                swap(at[i],at[j]);
                swap(bt[i],bt[j]);  
                }
            }
        }
    }
       if(c==n)
       break;
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