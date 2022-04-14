#include <iostream>
using namespace std;

void SumN(int n)
{
    int s = 0;
    long long temp = 0;
    for (int i = 1; i <= n; i++)
    {
        s = s + (temp = temp + i);
    }
    cout<<s;
}

int main()
{
    int n;
    cin >> n;
    SumN(n);
}