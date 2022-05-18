#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[100];
	int n; cin>>n;
	for(int i= 0;i<n;i++)
		cin>>a[i];
	for(int i =0;i<n;i++)
	{
		int j = i+1;
		while(a[j]>a[i]&&j<n)
			j++;
		if(j<n&&j!=i+1){
			for(int k = i;k<j;k++)
				cout<<a[k]<<" ";
			cout<<endl;
		}
	}
}
