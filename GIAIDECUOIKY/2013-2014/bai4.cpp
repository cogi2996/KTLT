#include<bits/stdc++.h>
using namespace std;
int m,n;
int x[] = {-1,0,0,1};
int y[] = {0,-1,1,0};
int main()
{
	int a[100][100];
	cin>>m>>n;
	for(int i =0 ;i<m;i++)
	{
		for(int j =0;j<n;j++)
			cin>>a[i][j];
	}
	int Min = 99999,i1 =-1,j1 =-1;
	for(int i =0 ;i<m;i++)
	{
		for(int j =0;j<n;j++)
		{	
			int key = 1;
			for(int k = 0;k<4;k++)
				if(a[i+x[k]][j+y[k]]>=a[i][j]&&i+x[k]>=0&&i+x[k]<m&&j+y[k]>=0&&j+y[k]<n)
				{
					key = 0;
					break;
				}
			if(key == 1&&a[i][j]==min(a[i][j],Min)){
				Min = a[i][j];
				i1 = i;
				j1 = j;
			}
		}
	}
	if(Min>0)
		cout<<i1<<" "<<j1;
	else 
		cout<<-1;
}
