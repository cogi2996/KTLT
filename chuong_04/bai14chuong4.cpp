#include<iostream>
#include<string>
using namespace std;
// 1234
string s;
int n,a[100];
void HoanVi(int k);
int ktraTrung(int x,int k);
void xuat();
int main()
{
	getline(cin,s);
	n = s.length();
	HoanVi(0);
}

int ktraTrung(int x,int k)
{
	for(int j =0;j<k;j++)
	{
		if(x==a[j])
			return 1;
	}
	return 0;
}
void HoanVi(int k)
{
	if(k == n)
	{
		xuat();
		a[100] ={-1};
	}
	else
	{
		for(int i =0 ;i<n;i++)
		{
			if(!ktraTrung(i,k))
			{
				a[k] = i;
				HoanVi(k+1);
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

