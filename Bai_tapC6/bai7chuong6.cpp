#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[100];
	int n; cin>>n;
	int Max =-9999;
	for(int i= 0;i<n;i++)
		cin>>a[i];
	for(int i =0;i<n;i++)
	{
		int j = i+1;
		while(a[j]>a[i]&&j<n)
			j++;
		if(j<n){
			int tempS = 0;
			for(int k = i;k<j;k++)
				tempS+=a[k];
			if(tempS>Max)
				Max = tempS;
		}
	}
	cout<<Max;
}
