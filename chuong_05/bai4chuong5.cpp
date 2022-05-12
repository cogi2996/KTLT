#include<iostream>
using namespace std;

int layBit(int n,int k)
{
	return (n>>k) & 0x1;
}

void tatBit(int&n,int k)
{
	n = n &(~(0x1<<k));
}

void batBit (int &n,int k)
{
	n = n|(0x1<<k);
}

int main()
{
	int n,k;
	cin>>n>>k;
	int chose; cin>>chose;
	switch(chose)
	{
		case 1:
		{
			batBit(n,k);
			break;			
		}
		case 2:
			{
				cout<<layBit(n,k);
				break;
			}
		case 3:
			{
				tatBit(n,k);
				cout<<n;
				break;				
			}
	}
}
