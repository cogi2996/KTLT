#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s; getline(cin,s);
	int right = 0,left = s.size()-1;
	while(s[right] == s[left])
	{
		right++;
		left--;
		if(right>=left)
			break;
	}
	if(right>=left)
		cout<<"day la chuoi doi xung";
	else
		cout<<"day khong la chuoi doi xung";
}
