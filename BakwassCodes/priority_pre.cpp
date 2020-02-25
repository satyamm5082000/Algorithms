#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid, arrival, burst, comp, wait, tat, priority;
};
#define pr struct Process
bool cmpArrival(pr a, pr b)
{
    if(a.arrival == b.arrival)
    {
        if(a.priority == b.priority)
            return a.pid < b.pid;
        else
            return a.priority < b.priority;
    }
    else
        return a.arrival < b.arrival;
}
void schedule(pr arr[], int n)
{
    int t = 0, done = 0;
    int rem[n];
    for(int i = 0; i < n; i++)
        rem[i] = arr[i].burst;
    while(done != n)
    {
        int ind = -1;
        int hp = INT_MAX;
        int hpid = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(arr[i].arrival <= t && rem[i] > 0 && ((arr[i].priority < hp) || (arr[i].priority == hp && arr[i].pid < hpid)))
            {
                ind = i;
                hp = arr[i].priority;
                hpid = arr[i].pid;
            }
        }
        cout << "P" << arr[ind].pid << "  ";
        if(ind != -1)
        {
            rem[ind]--;
            if(rem[ind] == 0)
            {
                arr[ind].comp = t + 1;
                done++;
            }
        }
        t++;
    }
    cout << endl;
    for(int i = 0; i < n; i++)
        arr[i].tat = arr[i].comp - arr[i].arrival, arr[i].wait = arr[i].tat - arr[i].burst;
}
int main()
{
    int n;
    cin >> n;
    pr arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].pid >> arr[i].arrival >> arr[i].burst >> arr[i].priority;
    }

    printf("\nBefore Scheduling\n");
    printf("Process ID\tArrival\t\tBurst\t\tPriority\n");
    for(int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\n", arr[i].pid, arr[i].arrival, arr[i].burst, arr[i].priority);
    sort(arr, arr + n, cmpArrival);

    schedule(arr, n);

    double avgwait = 0, avgtat = 0;
    for(int i = 0; i < n; i++)
        avgtat += arr[i].tat, avgwait += arr[i].wait;
    avgwait /= (n * 1.0), avgtat /= (n * 1.0);


    printf("\nAfter Scheduling\n");

    printf("Process ID\tArrival\t\tBurst\t\tPriority\tCompletion\tTurnaround\tWait\n");
    for(int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", arr[i].pid, arr[i].arrival, arr[i].burst, arr[i].priority, arr[i].comp, arr[i].tat, arr[i].wait);
    printf("Average Turnaround Time: %f\n", avgtat);
    printf("Average Wait Time: %f\n", avgwait);
    return 0;
}
