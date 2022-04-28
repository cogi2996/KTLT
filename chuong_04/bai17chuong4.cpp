#include<iostream>
using namespace std;

int N  , X[100],cot[100],d1[100] ,d2[100];
int a[100][100] = {0};
void xuat()
{
	for(int i = 1;i<=N;i++)
	{
		a[i][X[i]] = 1;
	}
	for(int i= 1;i<=N;i++)
	{
		for(int j = 1;j<=N;j++)
		{
			cout<<a[i][j]<< " ";
		}
		cout<<endl;
	}
}

void TRY(int i)
{
	if(i == N+1)
	{ 
		xuat();
		exit(0);
	}
	else
	{
	
	for(int j =1;j<=N;j++)
	{
		if(cot[j] == 1 &&  d1[i -j + N] == 1 && d2[i+j-1]==1)
		{
			X[i] = j;
			cot[j] = d1[i - j +N] = d2[i+j - 1] = 0;
		
				TRY(i+1);
	// backtrack
			cot[j] = d1[i - j +N] = d2[i+j - 1] = 1;
		}
		
	}	
	}

}

int main()
{
	cin>>N;
	for(int i = 0;i<=100;i++)
	{
		cot[i]=d1[i] = d2[i] = 1;
	}
	TRY(1);
	
}
