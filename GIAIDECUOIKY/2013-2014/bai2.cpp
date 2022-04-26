
#include<bits/stdc++.h> 
using namespace std;

int main()
{
string x;
getline(cin,x);	
string a[100];
int temp = 0,key  = 0;
for(int i  =0 ;i <= x.length();i++)
{
	
	if(x[i]!=' '&&x[i]!='\0')
	{
		a[temp]+=x[i];
		key = 1;
	}
	else if(key ==1 )
	{
		temp++;
		key = 0;
	}
}

for(int i = 0;i<temp -1;i++)
{
	reverse(a[i].begin(),a[i].end());
	cout<<a[i]<<" "; 
}

reverse(a[temp-1].begin(),a[temp - 1].end());
cout<<a[temp-1];
}
