#include<bits/stdc++.h>
using namespace std;
string x;
int non_trung(char s)
{
	for(int i =0;i<x.size();i++){
		if(s==x[i])
			return 0;
	}
	return 1;
}

int main()
{
	string s;
	getline(cin,s);
	for(int i =0;i<s.size();i++){
		if(non_trung(s[i]))
		{
			x+=s[i];
			int tempSize =0;
			for(int j =0;j<s.size();j++){
				if(x[x.size()-1] == s[j])
				tempSize++;
			}
			cout<<"'"<<s[i]<<"' co so lan xuat hien: "<<tempSize<<endl;
		}
	}
	
}
