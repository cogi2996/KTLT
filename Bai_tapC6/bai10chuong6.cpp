#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	string x[100];
	getline(cin,s);
	int  sizeX = 0;
	//TU  DO HANH   PHUC
	for(int i =0;i<=s.size();i++)
	{
		if(s[i]!=' '&&s[i]!='\0'){
			x[sizeX]+= s[i];
		}
		else if(s[i-1] !=' '&&i-1>=0){
			reverse(x[sizeX].begin(),x[sizeX].end());
			cout<<x[sizeX]<< " " ;
			sizeX++;
		}
	}
}
