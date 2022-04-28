#include<iostream>
#include<stdlib.h>
#define SIZE 100
using namespace std;
int A[SIZE][SIZE] = {0},n = 6;
int X[] = {-2,-2,-1,1,2,2,1,-1};
int Y[] = {-1,1,2,2,1,-1,-2,-2};
int dem = 0;
void diTuan(int x,int y);
void xuat();
int main()
{
	diTuan(2,3);
}

void diTuan(int x,int y)
{
	dem++;
	A[x][y] = dem;
	if(dem == n*n)
	{
		xuat();
		exit(0);
	}
	for(int i =0;i<8;i++)
	{
		int xx = x +X[i];
		int yy = y + Y[i];
		if(xx >=0 && xx <n && yy>=0 && yy<n &&A[xx][yy]==0)
		{
			diTuan(xx,yy);	
		}
	}
	dem--;
	A[x][y] = 0;
}

void xuat()
{
	for(int i = 0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			cout<<A[i][j]<<" ";
		}
	cout<<endl;
	}
}
