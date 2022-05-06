#include<bits/stdc++.h>
using namespace std;
int x[] = {-2,-2,-1,1,2,2,1,-1};
int y[] = {1,-1,-2,-2,-1,1,2,2};
int m  = 7,n = 7;
int main() {
	int x1,y1, x2,y2;
	cin>>x1>>y1>>x2>>y2;
	for(int i = 0;i<8;i++)
	{
		if(x1+x[i]==x2&&y1 + y[i] == y2&&x1+x[i]>=0&&x1+x[i]<8&&y1 + y[i]>=0&&y1 + y[i]<8 )
		{
			cout<<i+1;
			exit(0);
		}
	}
	cout<<0;
	return 0;
}
