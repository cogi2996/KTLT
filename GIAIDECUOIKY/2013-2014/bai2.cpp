#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s,token;
	getline(cin,s);
	int keyfirst = 0;
	stringstream ss(s);
	while(ss>>token)
	{
		reverse(token.begin(),token.end());
		if(keyfirst++!=0)
			token = " " +token ;
		cout<<token;
		token = "";
	}
}
