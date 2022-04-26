#include <iostream>
using namespace std;
struct DATE
{
    int d, m, y;
};

bool NamNhuan(int y)
{
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

void ktraNN(int y, int *month)
{
    if (NamNhuan(y))
    {
        month[2] = 29;
    }
    else
    {
        month[2] = 28;
    }
}

void nhap(DATE &day)
{
    cout << "-Nhap ngay/thang/nam: ";
    cin >> day.d >> day.m >> day.y;
}

bool ktra(DATE day, int *month)
{
    return (day.d > 0 && day.d <= month[day.m] && day.m > 0 && day.m <= 12 && day.y > 0);
}

void nextDay(DATE day, int *month)
{
    int d = day.d, m = day.m, y = day.y;
    if (d + 1 > month[m])
    {
        if (m + 1 > 12)
        {
            y++;
            m = 1;
            d = 1;
        }
        else
        {
            d = 1;
            m++;
        }
    }
    else
    {
        d++;
    }
    cout<<endl << "Ngay ke tiep ngay da nhap: " << d << "/" << m << "/" << y;
}

int main()
{
    int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    DATE day;
    nhap(day);
    ktraNN(day.y, month);
    if (ktra(day, month))
    {
        cout << "==>Ngay/thang/nam da nhap hop le.";
    }
    else
    {
        cout << "==>Ngay/thang/nam da nhap khong hop le.";
        return 0;
    };
    nextDay(day, month);
}