#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int lna = a.size(),lnb = b.size();
	int c[100][100] ={0};
	for(int i = 0;i<lna;i++)
		c[0][i] = 0;
	for(int i =0;i<lnb;i++)
		c[i][0] =0;
	for(int i = 1;i<=lnb;i++)
	{
		for(int j =1;j<=lna;j++)
			if(b[i-1]==a[j-1])
				c[i][j] = c[i-1][j-1]+1;
			else 
				c[i][j] = max(c[i-1][j],c[i][j-1]);
	}
	cout<<c[lnb][lna];
}
