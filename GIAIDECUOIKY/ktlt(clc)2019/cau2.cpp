#include<iostream>
using namespace std;
int n;

struct PS
{
	int t,m;	
};

int main()
{
	PS ps[100];
	cin>>n;
	for(int i = 0;i<n;i++)
		cin>>ps[i].t>>ps[i].m;
	PS psMax  = ps[0];
	for(int i = 1;i<n;i++)
	{	
		float ss = psMax.t*ps[i].m - ps[i].t*psMax.m;
		ss = ss/(psMax.m*ps[i].m);
		if(ss<0)
			psMax = ps[i];
	}
	cout<<psMax.t<<" "<<psMax.m;
	
}
