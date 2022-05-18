#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;cin>>n;
	string s[100];
	for(int i =1;i<=n;i++){
		int temp = i;
		do{
			int num = temp%2;
			char snum = (num + '0');
			s[i] = snum + s[i];
			temp/=2;
		}while(temp!=0);
		reverse(s[i].begin(),s[i].end());
		cout<<s[i]<<endl;
	}
}
