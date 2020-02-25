#include<iostream>

using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of Processes: ";  
    cin>>n;

    int a[n],b[n+1],x[n];
    int waiting[n],turnaround[n],completion[n];
    int i,j,smallest,count=0,time;
    double avg=0,tt=0,end;

    
    for(i=0; i<n; i++)
    {
        cout<<"For Process P"<<(i+1)<<": "<<endl;
        cout<<"Enter arrival time: ";
        cin>>a[i];
        cout<<"Enter burst time: ";
        cin>>b[i];
    }
    for(i=0; i<n; i++)
        x[i]=b[i];

    b[n]=INT_MAX;
    for(time=0; count!=n; time++)
    {
        smallest=n;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time)
            {
                if(b[i]<b[smallest] && b[i]>0)
                {
                    smallest = i;
                }
                else if (b[i] == b[smallest] && b[i]>0)
                {
                    if(a[i] < a[smallest])
                        smallest = i;
                }
                
            }
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            turnaround[smallest] = end - a[smallest];
            waiting[smallest] = turnaround[smallest] - x[smallest];
        }
    }
    cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<endl;
        avg += waiting[i];
        tt += turnaround[i];
    }
    cout<<"\n\nAverage waiting time ="<<(float)avg/n;
    cout<<"  Average Turnaround time ="<<(float)tt/n<<endl;
}
