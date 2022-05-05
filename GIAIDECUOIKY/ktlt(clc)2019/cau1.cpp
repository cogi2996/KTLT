#include<bits/stdc++.h>
using namespace std;
string s[4];	

void addZero(int MAX)
{
	for(int i = 1;i<=3;i++ )
	{
			int count  = MAX - s[i].length();
		for(int j = 0;j<count;j++)
		{
			s[i] = '0' + s[i];
		}
	}
}

int main()
{
	getline(cin,s[1]);
	getline(cin,s[2]);
	getline(cin,s[3]);
	int MAX = max(s[1].size(),max(s[2].size(),s[3].size()));
	addZero(MAX);
	string m = s[1];	
	for(int i = 2;i<=3;i++)
	{
		int temp = 0,key =0 ;
		while(m[temp]>=s[i][temp++])
		{
			if(m[temp]!=s[i][temp++])
			{
				m = s[i];
				break;
			}
		}
	}
	int temp = 0;
	do
	{
		if(m[temp] != '0' )
		{
			for(int i = temp;i<m.size();i++)
				cout<<m[i];
		}
	}while(m[temp++] == '0');
}
