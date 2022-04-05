#include<iostream>
using namespace std;
int main()
{
    int  n ;
    cin>>n;
    double s = 0;
    int scp = 0;
    // do phuc tap n
    for(int i = 1;i<= n;i++)
    {
        scp = scp + i;
        s  = s + (float)1/(scp);
    }
    cout<<s;
}