#include <iostream>
#include <string>
using namespace std;
int StoI(string x)
{
    int num = 0, sumNum = 0;
    for (int i = 0; i <= x.length(); i++)
    {
        if (!(x[i] <= '9' && x[i] >= '0'))
        {
            sumNum = sumNum + num;
            num = 0;
            if (x[i] != '\0')
            {
                x.erase(x.begin() + i);
                i--;
            }
        }
        else
        {
            num = num * 10 + (x[i] - '0');
        }
    }
    return sumNum;
}           
int main()
{
    string x;
    getline(cin, x);
    cout << StoI(x);
}