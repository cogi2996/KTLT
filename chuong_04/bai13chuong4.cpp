#include<iostream>
#include<string>
using namespace std;
string s;
int n,a[100];
void lietKe(int k);
void xuat();
int main()
{
	getline(cin,s);
	n = s.length();
	lietKe(0);
}

void lietKe(int k)
{
	if(k == n)
		xuat();
	else
	{
		for(int i = 0;i<=1;i++)
		{
			a[k] = i;
			lietKe(k+1); 			
		}
	}
}

void xuat()
{
	for(int i = 0;i<n;i++)
	{
		if(a[i]!=0)
		{
			cout<<s[i]<< " ";
		}
	}
	cout<<endl;
}
