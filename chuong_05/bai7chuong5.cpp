#include<bits/stdc++.h>
using namespace std;
int a[1000];
void eraDo(int n)
{
	for(int i =2;i<=sqrt(n);i++)
	{
		if(a[i])
		{
			for(int j= i*i;j<=n;j+=i)
			{
					a[j] = 0;
			}	
		}		
	}
}
int main()
{
fill(a,a+1000,1); 	
a[0] = 0;
a[1] = 0;
int  n;cin>>n;
eraDo(n);
for(int i= 0;i<=n;i++)
	if(a[i]==1)
		cout<<i<<" ";
}
