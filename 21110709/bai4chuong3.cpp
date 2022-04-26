#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int s = 0;
    int temp = 1;
    // do phuc tap n
    for(int i = 1;i<= n;i++ )
    {
        s = s + (temp = temp *i );
    }
    cout<<s;
}