#include<bits/stdc++.h>
using namespace std;
int xet(int n){
    if(n==0)
        return 2;
    else if(n == 1)
        return 4;
    else if(n== 2)
        return 6;
    return xet(n-3)*2 + xet(n-2)*4 + xet(n-1)*6;
        
    }   
int main()
{
    int m; cin>>m;
    int n;
    while(xet(n)<=m)
        n++;
    cout<<n-1;
}
