#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[100],b[100];
	int n; cin>>n;
	a[0] = -99999;
	a[n+1] = 999999;
	for(int i =1;i<=n;i++)
		cin>>a[i];
	for(int i =0 ;i<=n+1;i++){
		b[i] =1;
		for(int j =0;j<i;j++){
			if(a[j]< a[i]&&b[j]+1>b[i])
				b[i] = b[j] +1;
		}
	}
	cout<<b[n+1]-2;
}
