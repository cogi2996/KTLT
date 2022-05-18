#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;cin>>n;
	int f0 = 0,f1= 1;
	int fn = -199;
	for(int  i= 2;i<=n;i++)
	{
		fn = f0+f1;
		f0 = f1;
		f1 = fn;
	}
	if(n==0)
		cout<<f0;
	else if(n ==1)
		cout<<f1;
	else
		cout<<fn;
}
