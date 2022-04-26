#include <iostream>
using namespace std;

void TpToNhiPhan(int x)
{
    int a[100];
    int sl = 0;
    while (x != 0)
    {
        a[sl++] = x % 2;
        x /= 2;
    }

    int kq = 0;
    for (int i = sl - 1; i >= 0; i--)
    {
        kq = kq * 10 + a[i];
    }
    cout << "so da cho o dang nhi phan: " << kq << endl;
}

void TpToBatPhan(int x)
{
    int a[100];
    int sl = 0;
    while (x != 0)
    {
        a[sl++] = x % 8;
        x /= 8;
    }
    int kq = 0;
    for (int i = sl - 1; i >= 0; i--)
    {
        kq = kq * 10 + a[i];
    }
    cout << "So da cho o dang bat phan: " << kq << endl;
}

void TpToThapLucPhan(int x)
{
    string a = "0123456789ABCDEF";
    string kq;
    int archive[100];
    int sl = 0;
    while (x != 0)
    {
        archive[sl++] = x % 16;
        x /= 16;
    }
    for (int i = sl - 1; i >= 0; i--)
    {
        kq = kq + a[archive[i]];
    }
    cout<<"So can chuyen o dang thap luc phan: "<<kq;
}

int main()
{
    int x;
    cin >> x;
    TpToNhiPhan(x);
    TpToBatPhan(x);
    TpToThapLucPhan(x);
}