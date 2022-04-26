#include<iostream>
#include<string>
using namespace std;
int  minA = 0,minCur = 0;
string x,y;
int a[500];
void lietke(int k);


int main()
{
	/*
	0123456
	CEACEEC
	AECECA
	*/
	getline(cin,x);
	getline(cin,y);	
	lietke(0);
	cout<<minA;
}

int checkXinY()
{
	int j = 0;
	for(int i = 0;i<x.length();i++)
	{
		if(a[i] == 1)
		{
			if(j==y.length())
				return 0;
			for(j;j<y.length();j++)
			{
				if(j == y.length() - 1&&x[i]!=y[j])
				{
					return 0;
				}
				if(x[i] == y[j])
				{
					j++;
					break;
				}
				
			}
		}
	}
	return 1;
}

void lietke(int k)
{
	if(k == x.length())
	{
		minCur = 0;
	if(checkXinY()==1)
		for(int i = 0 ;i<x.length();i++)
		{
			if(a[i]==1)
				minCur++;
		}
		if(minA<minCur)
			minA = minCur;
	}
	else
	{
		for(int i = 0;i<=1;i++)
		{
			a[k] = i ;
			lietke(k+1); 
		}
	}
}
