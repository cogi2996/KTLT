#include<iostream>
using namespace std;
int a[100][100],b[100] = {0},c[100],cmin[100];
int N;
int MIN = 99999;
// 1 2 3 4 5 
void cinCost()
{
	cin>>N;
	for(int i= 0;i<N;i++)
	{
		for(int j =0;j<N;j++)
		{
			cin>>a[i][j];
		}
	}
}

void xuatCH()
{
//	cout<<"("<<MIN<<")";
	cout<<endl<<"Hanh trinh can di: ";
	for(int i = 0;i<N;i++)
	{
		cout<<cmin[i]<<" ";
	}
	cout<<endl;
}

void duyetCH()
{
	
//	int s = a[c[0]][c[0]];
int s = 0;
	int i = 0;
	int key =0;
	for(int j = 1 ;j<N;j++)
	{
		s+=a[c[i++]][c[j]];
		if(s>MIN)
		{
			key =1;
			break;
		}	
	}
	if(key == 0)
	{
		for(int k = 0;k<N;k++)
		{
			cmin[k]= c[k];
		}
		MIN = s;	
	}

}

void cauHinh(int k )
{
	if(k == N)
	{
		duyetCH();
	}
	else
	{
		for(int i = 0;i<N;i++)
		{
			if(b[i]==0)
			{
				b[i] = 1;
				c[k] = i;
				cauHinh(k+1);
				b[i] = 0;
			}
		}
	}
}
	
int main()
{
	cinCost();
	cauHinh(0);
	xuatCH();
}
