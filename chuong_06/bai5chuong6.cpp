#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int a[100][100];
int b[100][100],c[100][100] = {0};

void nhap(int x,int y,int A[][100])
{
	for(int i = 0;i<x;i++)
		for(int j= 0;j<y;j++)
			cin>>A[i][j];
}

int main()
{	
	cin>>m>>n>>k;
	nhap(m,n,a);
	nhap(n,k,b);
	for(int i = 0;i<m;i++)
	{
			int icp = 0;
		for(int j= 0;j<k;j++)
		{
			int s =0;
			int jcp = 0;
			while(jcp<k){
				c[i][j] += a[i][jcp]*b[jcp++][icp];
			}
			icp++;
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
}

