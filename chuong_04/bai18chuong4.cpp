#include<iostream>
using namespace std;
int n;
int a[100][100],d[100], b[100] = {0};
int i1 = 0;

int trung(int i,int j)
{
	int x = d[j] ;
	i--;
	for(i; i>=0;i--)
	{
		if(x == a[i][j])
			return 1;
	}
	return 0;
}

void duyetCH()
{
	int check = 0;
	for(int j = 0;j<n;j++)
	{
		if(trung(i1,j))
		{
			check = 1;
			break;
		}
	}
	if(check == 0)
	{
		for(int j = 0;j<n;j++)
		{
			a[i1][j] = d[j];
		}	
		i1++; 
	}	
}

void cauHinh(int k)
{
	if(k == n)
	{
		//duyetcauhinh
		duyetCH();
	}
	else
	{
		for(int i =0 ;i<n;i++)
		{
			if(b[i]==0)
			{
				d[k] = i;
				b[i] = 1;
				cauHinh(k+1);
				b[i] = 0;
			}
		
		}
	}
}

void xuat ()
{
	for(int i = 0;i<i1;i++)
	{
		for(int j = 0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	cin>>n;
	cauHinh(0);
	xuat();
	
}
