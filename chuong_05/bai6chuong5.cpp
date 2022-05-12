#include<iostream>
using namespace std;
int try(int n){
		if(n==0)return 1;
		if(n==1)return 1;
		if(n%2==0){
			return try(n/2);
		}else{
			return try(n/2) + try(n+1);
		}
	}

int main()
{
int n;
cin>>n;
cout<<try(n);	
}
