#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin>>n;
	cin.ignore();
	int sum= 0;
	string s[100];
	for(int i =0;i<n;i++)
	{
		getline(cin,s[i]);
		int sumCheck =0,j =0 ,numCheck = 0;
		do{
			numCheck = numCheck*10 + (s[i][j] - '0');
			int num = s[i][j++] - '0';
			sumCheck += pow(num,s[i].size());
		}while(j<s[i].size());
		if(sumCheck == numCheck)
			sum += sumCheck;
	}
	cout<<sum;
}

