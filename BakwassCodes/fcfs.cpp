#include<bits/stdc++.h>
using namespace std;

class process
{
   int pid , art , bt , cmpt , tat , wt;

   public:
   void setpid(int pid)
   {
      this->pid = pid;
   }
   void setart(int art)
   {
      this->art = art;
   }
   void setbt(int bt)
   {
      this->bt = bt;
   }
   void setcmpt(int cmpt)
   {
      this->cmpt = cmpt;
   }
   void settat(int tat)
   {
      this->tat = tat;
   }
   void setwt(int wt)
   {
      this->wt = wt;
   }


   int getpid()
   {
      return pid;
   }
   int getart()
   {
      return art;
   }
   int getbt()
   {
      return bt;
   }
   int getcmpt()
   {
      return cmpt;
   }
   int gettat()
   {
      return tat;
   }
   int getwt()
   {
      return wt;
   }

};

bool compareArt(process a , process b)
{   
    if(a.getart() == b.getart())
    {
        return a.getpid() < b.getpid();
    }
    else
    {
        return a.getart() < b.getart();
    }
    
}

bool comparePid(process a , process b)
{
   return a.getpid() < b.getpid();
}

void fcfs(process pro[] , int n)
{
    sort(pro , pro+n , compareArt);

    int temp;
    cout<<"GANTT CHART:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<pro[i].getpid()<<"  ||  ";
        if(i)
        {
            pro[i].setcmpt(temp + pro[i].getbt());
            temp = pro[i].getcmpt();
        }
        else
        {
            pro[i].setcmpt(pro[i].getart() + pro[i].getbt());
            temp = pro[i].getcmpt();
        }
        
    }
    cout<<endl;

    float avgtat =0 , avgwt =0;
    for(int i=0; i<n; i++)
    {
        pro[i].settat(pro[i].getcmpt() - pro[i].getart());
        pro[i].setwt(pro[i].gettat() - pro[i].getbt());
        avgtat += pro[i].gettat();
        avgwt += pro[i].getwt();
    }

    sort(pro , pro+n , comparePid);
    
    cout<<"PID   AT   BT   CMT   TAT   WT"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<" "<<pro[i].getpid()<<"    "<<pro[i].getart()<<"    "<<pro[i].getbt()<<"     "<<pro[i].getcmpt()<<"     "<<pro[i].gettat()<<"     "<<pro[i].getwt()<<endl;
    }

    avgtat = (float)avgtat/n;
    avgwt = (float)avgwt/n;
    cout<<"Average TAT: "<<avgtat<<endl;
    cout<<"Average WT: "<<avgwt<<endl;
}

int main()
{
   int n;
   cout<<"Enter Number of Process: ";
   cin>>n;
   process proc[n];
   int temp;
   for(int i=0; i<n; i++)
   {
      cout<<"For Process "<<i+1<<" Enter "<<endl;
      cout<<"Process ID: ";
      cin>>temp;
      proc[i].setpid(temp);
      cout<<"Arrival Time: ";
      cin>>temp;
      proc[i].setart(temp);
      cout<<"Burst Time: ";
      cin>>temp;
      proc[i].setbt(temp);
   }

   fcfs(proc , n);
   return 0;
}
