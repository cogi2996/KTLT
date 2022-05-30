#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	getline(cin,s);
	n = s.size();
	int left = 1;
	int score = 0;
	for(int i =0;i<n;i++)
	{	
	
		if(s[i]=='V')
			score+=left++;
		else{
			left = 1;
		} 
	}
	cout<<score;
}
