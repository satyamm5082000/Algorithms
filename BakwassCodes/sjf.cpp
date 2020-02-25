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
   return a.getart() < b.getart();
}

bool comparePid(process a , process b)
{
   return a.getpid() < b.getpid();
}


void swapproc(process &a , process &b)
{
   int temp = a.getpid();
   a.setpid(b.getpid());
   b.setpid(temp);

   temp = a.getart();
   a.setart(b.getart());
   b.setart(temp);

   temp = a.getbt();
   a.setbt(b.getbt());
   b.setbt(temp);

   temp = a.getcmpt();
   a.setcmpt(b.getcmpt());
   b.setcmpt(temp);

}

void sjf(process proc[] , int n)
{

   sort(proc , proc +n , compareArt);

   int cmt = proc[0].getart() + proc[0].getbt();
   proc[0].setcmpt(cmt);
   for(int x=1; x<n; x++)
   {
      int minBt = INT_MAX;
      int minBtInd = -1;
      for(int i=x ; (i<n) && (proc[i].getart() < cmt) ; i++)
      {
         if(minBt > proc[i].getbt())
         {
            minBtInd = i;
            minBt = proc[i].getbt();
         }
         else if(minBt == proc[i].getbt())
         {
            if(proc[i].getart() < proc[minBtInd].getart())
            {
               minBtInd = i;
               minBt = proc[i].getbt();
            }
            else if(proc[i].getart() == proc[minBtInd].getart())
            {
               if(proc[i].getpid() < proc[minBtInd].getpid())
               {
                  minBtInd = i;
                  minBt = proc[i].getbt();
               }
            }
         }
      }

      swapproc(proc[x] , proc[minBtInd]);

      cmt += proc[x].getbt();
      proc[x].setcmpt(cmt);
   }

   cout<<"SEQUENCE: "<<endl;
   for(int i=0; i<n; i++)
   {
      cout<<proc[i].getpid()<<"  ||  ";
   }
   cout<<endl;

   sort(proc , proc+n , comparePid);
   float avgtat=0 , avgwt=0;
   for(int i=0; i<n; i++)
   {
      proc[i].settat(proc[i].getcmpt() - proc[i].getart());
      proc[i].setwt(proc[i].gettat() - proc[i].getbt());

      avgtat += proc[i].gettat();
      avgwt += proc[i].getwt();
   }

   avgtat /= (float)n;
   avgwt /= (float)n;

   cout<<"PID    AT    BT    CT    TAT    WT"<<endl;
   for(int i=0; i<n; i++)
   {
      cout<<" "<<proc[i].getpid()<<"     "<<proc[i].getart()<<"     "<<proc[i].getbt()<<"     "<<proc[i].getcmpt()<<"     "<<proc[i].gettat()<<"     "<<proc[i].getwt()<<endl;
   }

   cout<<"Averge Turn Around Time: "<<avgtat<<endl;
   cout<<"Averge Waiting Time: "<<avgwt<<endl;
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

   sjf(proc , n);
   return 0;
}
