#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a = 0,b = 0,c = 0,d = 0;
	string temp;
	getline(cin,temp);
	for(int i =0 ;i<temp.length();i++)
	{
		if(temp[i]>='a'&&temp[i]<='z')
			a++;		
		else if(temp[i]>='A'&&temp[i]<='Z')
			b++;
		else if(temp[i] >='0'&&temp[i]<='9')
			c++;
		else 
			d++;
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<d;
}
