#include<iostream>
#include<string>
using namespace std;
// 1234
string s;
int n,a[100],b[100]  ={0};
void HoanVi(int k);
void xuat();
int main()
{
	getline(cin,s);
	n = s.length();
	HoanVi(0);
}

void HoanVi(int k)
{
	if(k == n)
	{
		xuat();
	}
	else
	{
		for(int i =0 ;i<n;i++)
		{
			if(b[i]==0)
			{
				a[k] = i;
				b[i] = 1;
				HoanVi(k+1);
				b[i] = 0;
			}
		}
	}
}

void xuat()
{
	for(int i = 0;i<n;i++)
	{
		cout<<s[a[i]]<<" ";
	}
	cout<<endl;
}

