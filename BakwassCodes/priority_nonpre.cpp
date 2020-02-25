#include<bits/stdc++.h>
using namespace std;

class process
{
    public:
    int pid, at, bt, pr, ct, tat, wt;
};

bool compareat(process a, process b)
{
    return a.at < b.at;
}

bool comparepid(process a, process b)
{
    return a.pid < b.pid;
}

void swappro(process &a , process &b)
{
    int temp;
    temp = a.pid;
    a.pid = b.pid;
    b.pid = temp;
    
    temp = a.pr;
    a.pr = b.pr;
    b.pr = temp;

    temp = a.at;
    a.at = b.at;
    b.at = temp;
    
    temp = a.bt;
    a.bt = b.bt;
    b.bt = temp;
}

void prioritynp(process pro[] , int n)
{
    sort(pro , pro+n , compareat);

    int cmt = pro[0].at + pro[0].bt;
    pro[0].ct = cmt;
    
    for(int i=1; i<n; i++)
    {
        int minp = INT_MAX;
        int minpi = -1;
        for(int j=i; (i<n) && (pro[j].at <= cmt); j++)
        {
            if(pro[j].pr < minp)
            {
                minp = pro[j].pr;
                minpi = j;
            }
            else if (pro[j].pr == minp)
            {
                if(pro[j].at < pro[minpi].at)
                {
                    minp = pro[j].pr;
                    minpi = j;
                }
            }
            
        }

        swappro(pro[i] , pro[minpi]);

        cmt += pro[i].bt;
        pro[i].ct = cmt;
    }

    cout<<"GANTT CHART: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<pro[i].pid<<"  ||  ";
    }
    cout<<endl;

    sort(pro , pro+n ,comparepid);
    float avgtat =0 , avgwt =0;
    for(int i=0; i<n; i++)
    {
       pro[i].tat = pro[i].ct - pro[i].at;
       pro[i].wt = pro[i].tat - pro[i].bt;

       avgtat += pro[i].tat;
       avgwt += pro[i].wt;
    }

    avgtat /= (float)n;
    avgwt /= (float)n;

    cout<<"PID    PR    AT    BT    CT    TAT    WT"<<endl;
   for(int i=0; i<n; i++)
   {
      cout<<" "<<pro[i].pid<<"     "<<pro[i].pr<<"     "<<pro[i].at<<"     "<<pro[i].bt<<"     "<<pro[i].ct<<"     "<<pro[i].tat<<"    "<<pro[i].wt<<endl;
   }

   cout<<"Averge Turn Around Time: "<<avgtat<<endl;
   cout<<"Averge Waiting Time: "<<avgwt<<endl;
}

int main()
{
    int n;
    cout<<"Enter the number of process: ";
    cin>>n;
    process pro[n];
    for(int i=0; i<n; i++)
    {
        cout<<"For process "<<i+1<<" enter: "<<endl;
        cout<<"Process ID: ";
        cin>>pro[i].pid;
        cout<<"Arival Time: ";
        cin>>pro[i].at;
        cout<<"Burst Time: ";
        cin>>pro[i].bt; 
        cout<<"Priority: ";
        cin>>pro[i].pr;
    }

    prioritynp(pro , n);
    return 0;
}
