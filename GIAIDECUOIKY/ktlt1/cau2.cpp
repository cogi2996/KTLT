#include<bits/stdc++.h>
using namespace std;
int layBit(int  n,int k)
{
	return (n>>k)&0x1;
}
int main(){
	int n,count = 0;
	cin>>n;
	for(int i =0 ;i<=31;i++){
		if(layBit(n,i)==1)
			count++;
	}
	cout<<count;
}
