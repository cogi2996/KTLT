#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x,n;
	cin>>x>>n;
	double s = 1;
	int temp  = 1;
	for(int i= 1;i<=n;i++)
	{
		s = s  + pow(-1,i)*pow(x,i)/(temp *= i);
	}
	
	cout<<round(s*100)/100;
}
