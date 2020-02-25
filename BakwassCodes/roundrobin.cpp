#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,tq;
	cout<<"Enter number of processes and time quanta"<<endl;
	cin>>n>>tq;
	//0-> id, 1-> arrival, 2-> burst, 3-> completion, 4-> turn around, 5->waiting time
	vector< vector<int> > data (n,vector<int>(6,0));
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the process ID, Arrival time, Burst time of the "<<i+1<<"th process"<<endl;
		cin>>data[i][0]>>data[i][1]>>data[i][2];	
	}
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			if(data[j][1] > data[j+1][1])
			{
				int temp;
				temp=data[j][0];
				data[j][0]=data[j+1][0];
				data[j+1][0]=temp;
				temp=data[j][1];
				data[j][1]=data[j+1][1];
				data[j+1][1]=temp;
				temp=data[j][2];
				data[j][2]=data[j+1][2];
				data[j+1][2]=temp;
			}
	queue<int> control;
	vector<bool> visited(n,false);
	vector<int> chart;
	int time=data[0][1],count=1;
	visited[0]=true;
	control.push(0);
	while(control.size()>0 || count<n)
	{
		if(control.size()==0)
		{
			time+=tq;
		}
		int next=time+tq;
		for(int i=1;i<n;i++)
		{
			if(data[i][1]<=next && !visited[i])
			{
				count++;
				control.push(i);
				visited[i]=true;
			}
		}
		int index=control.front();
		if(data[index][2] > 0)
			chart.push_back(data[index][0]);
		control.pop();
//		cout<<index<<endl;
		if(data[index][2] <= tq)
		{
			time+=data[index][2];
			data[index][3]=time;
			data[index][2]=0;
		}
		else if(data[index][2] >0)
		{
			time+=tq;
			data[index][2]-=tq;
			control.push(index);
		}
	}
	for(int i=0;i<n;i++)
	{
		data[i][5]=data[i][3]-data[i][2];
		data[i][4]=data[i][3]-data[i][1];
	}
	cout<<"Process ID\t Arrival Time\t Completion Time\t TAT\t Waiting Time\t"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<data[i][0]<<"\t\t "<<data[i][1]<<"\t\t "<<data[i][3]<<"\t\t "<<data[i][4]<<"\t\t "<<data[i][5]<<endl;
	}
	cout<<"Gantt Chart"<<endl;
	for(int i=0;i<chart.size();i++)
		cout<<chart[i]<<" ";
}
