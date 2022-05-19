#include<bits/stdc++.h>
using namespace std;

int main()
{
	string x,y;
	getline(cin,x);
	getline(cin,y);
	int a[100][100];
	int m = x.size();
	int n = y.size();
	for(int i = 0;i<=m;i++)
		a[i][0] = 0;
	for(int i = 0;i<=n;i++)
		a[0][i] =0;
	for(int i =1;i<=m;i++)
	{
		for(int j = 1;j<=n;j++){
			if(x[i-1] == y[j-1]){
				a[i][j] = a[i-1][j-1] +1;
			}
			else
				a[i][j] = max(a[i][j-1],a[i-1][j]);
		}
	}
	
	int stop = a[m][n];
	string s;
	while(s.size()<stop)
	{
		if(x[m-1] == y[n-1]){
			s = x[m-1] + s;
			m--;
			n--;
		}
		else{
			int Max = max(a[m-1][n],a[m][n-1]);
			if(a[m-1][n]==Max){
				m = m-1;
			}
			else
				n = n-1;
		}
	}
	cout<<s;
}
