#include<bits/stdc++.h>
using namespace std;
#define n 6

void arrangeacctoarrival(int pid[n],int at[n],int bt[n])
{
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
}


void roundrobin(int pid[n],int at[n],int bt[n],int wt[n],int tat[n],int ct[n],int tq)
{ 
	int bt1[n]; 
	for (int i = 0 ; i < n ; i++) 
		bt1[i] = bt[i]; 

	int t = 0; 
	while (1) 
	{ 
		bool done = true; 

		for (int i = 0 ; i < n; i++) 
		{ 
			if (bt1[i] > 0) 
			{ 
				done = false; 

				if (bt1[i] > tq) 
				{ 
					t += tq; 
                    
					bt1[i] -= tq; 
				} 

				else
				{ 

					t = t + bt1[i]; 
                     ct[i]=t;

					wt[i] = t - bt[i]; 

					bt1[i] = 0; 

                    cout<<pid[i]<<" ";
				} 
                
			} 
			

		} 
		if (done == true) 
		break; 
	} 

  
     for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i];


	// for (int i=0; i<n; i++) 
	// { 
	// 	total_wt = total_wt + wt[i]; 
	// 	total_tat = total_tat + tat[i]; 
	// 	cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
	// 		<< wt[i] <<"\t\t " << tat[i] <<endl; 
	// } 

	// cout << "Average waiting time = "
	// 	<< (float)total_wt / (float)n; 
	// cout << "\nAverage turn around time = "
	// 	<< (float)total_tat / (float)n; 
}

int main() 
{ 
    int pid[n],at[n],bt[n],wt[n],tat[n],ct[n];
      
   int tq;
    cout<<"...Enter the process ID...\n"; 
    for(int i=0; i<n; i++) 
    { 
        cout<<"...Process "<<i+1<<"...\n"; 
        cout<<"Enter Process Id: "; 
        cin>>pid[i]; 
        cout<<"Enter Arrival Time: "; 
        cin>>at[i]; 
        cout<<"Enter Burst Time: "; 
        cin>>bt[i]; 
        wt[i]=0;
        tat[i]=0;
        ct[i]=0;
    } 
      cout<<"Enter time quanta:\n";
      cin>>tq;
      arrangeacctoarrival(pid,at,bt);
    cout<<"According to arrival ...\n"; 
    cout<<"Process ID\tArrival Time\tBurst Time\n"; 
    for(int i=0; i<n; i++) 
    {
        cout<<pid[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\n"; 
    } 
    roundrobin(pid,at,bt,wt,tat,ct,tq);
    cout<<"Final Result...\n"; 
    cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion time\n"; 
    for(int i=0; i<n; i++) 
    { 
        cout<<pid[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t"<<ct[i]<<"\n"; 
    } 
} 


