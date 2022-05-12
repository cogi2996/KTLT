#include<bits/stdc++.h>
using namespace std;
int layBit(int n,int k)
{
	return (n>>k) & 0x1;
}
int main()
{
	int count = 0;
	int n; cin>>n; 
	int k = n; 
	while(k>=0)
	{
		if(layBit(n,k--) == 1)
			count++;
	}
	cout<<count;
}
