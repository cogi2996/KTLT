#include<bits/stdc++.h>
using namespace std;
int a[100][100] = {0},m,n;
int x[] = {-2,-1,-1,-1,0,0,0,0,0,1,1,1,2};
int y[] = {0,-1,0,1,-2,-1,0,1,2,-1,0,1,0};
int camx[100],camy[100];
int main()
{
	int sl = 0;
	int cam[100];
	cin>>m>>n>>sl;
	for(int i = 0;i<sl;i++)
		cin>>camx[i]>>camy[i];
	int s = 0;

		for(int j1 =0 ;j1<sl;j1++)
		{
			int i = camx[j1];
			int j = camy[j1];
			for(int k = 0;k<13;k++)
			{
				if(a[i+x[k]][j+y[k]] !=1 && i+x[k]>=0&&i+x[k]<m&&j+y[k]>=0&&j+y[k]<n)
				{
					a[i+x[k]][j+y[k]]  =  1;
					s++;
				}
			}
		}
	
	cout<<s;
	
}
