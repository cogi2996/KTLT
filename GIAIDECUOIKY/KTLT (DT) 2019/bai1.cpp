#include<bits/stdc++.h>
using namespace std;

int main() {
	int a = 2,b  =4,c = 6;
	int m;
	cin>>m;
	int f = 0;
	int temp = 2;
	while(f <= m)
	{
		f = f + (a*2+b*4+c*6);
		a = b;
		b = c;
		c = f;
		temp++;
	}
	if(m==2)
		cout<<0;
	else if(m==4)
		cout<<1;
	else if(m == 6)
		cout<<2;
	else
		cout<<--temp;
}

