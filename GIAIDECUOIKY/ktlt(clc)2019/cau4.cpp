#include<bits/stdc++.h>>
using namespace std;
int x[] ={-1,0,1,0};
int y[] ={0,1,0,-1};
int a[100][100];
int main ()
{
	int m,n;
	cin>>m>>n;
	for(int  i= 0;i<m;i++)
	{
		for(int j= 0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	int key =1;
	int temp =9999;	
	int x1= -1,y1 = -1;
	for(int  i= 0;i<m;i++)
	{
		for(int j= 0;j<n;j++)
		{
			int point  = a[i][j];
			key = 1;
			for(int k = 0;k<4;k++)
			{
				if(point<=a[i+x[k]][j+y[k]]&&i+x[k]>=0&&i+x[k]<m&&j+y[k]>=0&&j+y[k]<n)
				{
					key = 0;
					break;	
				}	
			}
			if(key == 1)
			{
				if(temp>a[i][j])
				{
					temp = point;
					x1 = i;
					y1 = j;
				}
			}
		}
	}
	if(x1!=-1)
		cout<<x1<<" "<<y1;
	else
		cout<<-1;
}
