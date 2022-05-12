#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[100];
	int le[100],chan[100];
	int n; cin>>n;
	int slchan =0 ,slle= 0;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]%2 == 0)
			chan[slchan++] = a[i];
		else
			le[slle++] =  a[i];
	}
	sort(chan,chan+slchan);
	sort(le,le+slle);
	int temp = 0;
	while(le[temp]<=chan[slchan-1])
	{
		temp++;
	}
	if(temp<slle)
	{
		cout<<le[temp];
	}
	else
		cout<<"khong co so le nao thoa man";
}
