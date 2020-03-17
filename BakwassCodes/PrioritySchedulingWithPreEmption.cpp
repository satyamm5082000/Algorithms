#include<bits/stdc++.h>

using namespace std;

struct process{
                int id;
                int AT;
                int BT, RBT;
                int CT;
                int TAT;
                int WT;
                bool visited;
                int priority;
                };

bool cmp(struct process a, struct process b)
{
    int r1 = a.AT;
    int r2 = b.AT;

    if(r1 == r2)
        return a.id < b.id;
    else
        return r1 < r2;
}

void schedule(process p[], int n)
{
    sort(p, p+n, cmp);

    int time = p[0].AT;
    int done = 0;

    cout<<"GANTT CHART : - \n\n|| ";

    while(done != n)
    {
        int hp = 0;
        int hpindex = -1;
        for(int i=0; i<n; i++)
        {
            if(p[i].AT <= time && !p[i].visited && p[i].priority > hp)
            {
                hp = p[i].priority;
                hpindex = i;
            }
        }
        if(hpindex != -1)
        {
            p[hpindex].RBT = p[hpindex].RBT - 1;
            time++;
            cout<<"P"<<p[hpindex].id<<" || ";
            if( p[hpindex].RBT == 0 )
            {
                p[hpindex].CT = time;
                p[hpindex].TAT = p[hpindex].CT - p[hpindex].AT;
                p[hpindex].WT = p[hpindex].TAT - p[hpindex].BT;
                done++;
                p[hpindex].visited = true;
            }
        }
        else
        {
            time++;
        }

    }

     //Display:-
    cout<<"\n\nAfter scheduling : -\n\n";
    cout<<"Id     "<<"AT     "<<"BT     "<<"Priority"<<" CT     "<<"TAT    "<<"WT     "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<p[i].id<<"      "<<p[i].AT<<"      "<<p[i].BT<<"       "<<p[i].priority<<"       "<<p[i].CT<<"      "<<p[i].TAT<<"      "<<p[i].WT<<endl;
    }

    //average TAT
    double avgtat = 0;
    for(int i=0; i<n;i++)
    {
        avgtat = avgtat + p[i].TAT;
    }

    avgtat = (double) avgtat/n;

    //average WT
    double avgWT = 0;
    for(int i=0; i<n; i++)
    {
        avgWT = avgWT + p[i].WT;
    }
    avgWT = (double) avgWT/n;

    cout<<"\nAverage TAT is "<<avgtat<<endl;
    cout<<"\nAverage WT is "<<avgWT<<endl;

}


int main()
{
    cout<<"Enter number of processes you want : ";
    int n;
    cin>>n;
    cout<<"Enter details of each process :-\n";
    process p[n] = {};

    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Process "<<i+1<<" details : - \n";
        cout<<"Process Id :  ";
        cin>>p[i].id;
        cout<<"Arrival time :  ";
        cin>>p[i].AT;
        cout<<"Burst time :  ";
        cin>>p[i].BT;
        cout<<"Priority :  ";
        cin>>p[i].priority;
        p[i].visited = false;
        p[i].RBT = p[i].BT;
    }
    //Display before scheduling
    cout<<"\nBefore Scheduling : - \n\n";
    cout<<"Id     "<<"AT     "<<"BT     "<<"Priority"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<p[i].id<<"      "<<p[i].AT<<"      "<<p[i].BT<<"      "<<p[i].priority<<endl;
    }

    schedule(p, n);


}
