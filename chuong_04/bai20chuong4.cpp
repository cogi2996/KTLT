#include<iostream>
#include<algorithm>
using namespace std;
int N,deep;
int a[100];
int Max = 0;
int c = 0;

void xuatCH()
{
	for(int i = 0;i<N;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int ktraHopLe()
{
	int trai = 0 ,phai = 0;
	for(int i =0 ;i<N;i++)
	{
		if(a[i] == 0)
			trai++;
		else
			phai++;
	}
	return trai-phai;
}

int checkPoint(int x)
{
	int trai = 0,phai = 0;
	for(int i = 0;i<=x;i++)
	{
		if(a[i] == 0)
			trai++;
	}
	for(int i = x+1;i<N;i++)
		if(a[i] ==1)
			phai++;
	return min(trai,phai);
}

void duyetCH()
{
	int key = 0;
	c=0;	
	for(int i = 0;i<N;i++)
	{
		if(ktraHopLe() != 0)
			break;
		if(a[0] == 1 || a[N-1] == 0)
			break;
		if(a[i]==a[i+1]-1&&i+1<N)
		{	
			c++;
			if(c == deep)
			{
				key = 0;
				break;
			}
			if(checkPoint(i)>deep)
			{
				key = 0;
				break;
			}
			else if(checkPoint(i)==deep)
			{
				key =1;
			}
		}
	}
	if(key==1)
	{
		xuatCH();
	}	
}

void nhiPhan(int k)
{
	if(k==N)
	{
		duyetCH();
	}
	else
	{
		for(int i = 0;i<=1;i++)
		{
			a[k] = i;
			nhiPhan(k+1);
		}
	}
}

int main()
{
	cin>>N>>deep;
	nhiPhan(0);
}
