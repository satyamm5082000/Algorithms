#include <bits/stdc++.h> 
using namespace std; 
 
bool compare (const pair<int,int> p1, const pair<int,int> p2) 
{ 
	double a = (double)p1.first / p1.second; 
	double b = (double)p2.first / p2.second; 
	return a > b; 
} 


double fractionalKnapsack(int W, vector< pair<int,int> > v, int n) 
{ 
	
	sort(v.begin (), v.end (), compare); 

	int curW = 0;
	double final = 0.0; 


	for (int i = 0; i < n; i++) 
	{ 
		
		if (curW + v[i].second <= W) 
		{ 
			curW += v[i].second; 
			final += v[i].first; 
		} 

		else
		{ 
			int remain = W - curW; 
			final += v[i].first * ((double) remain / v[i].second); 
			break; 
		} 
	} 
 
	return final; 
} 


int main() 
{ 
    int n;
    cin>>n;

    vector< pair<int,int> > v;

    for (int i=0;i<n;i++)
    {
        int val,w;
        cin>>val>>w;

        v.push_back(make_pair (val,w));
    }
    

    int W;
    cin>>W;

	cout << "Maximum value = " << fractionalKnapsack(W, v, n)<<endl; 

	return 0; 
} 
