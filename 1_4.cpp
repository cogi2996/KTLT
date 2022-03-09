#include <iostream>
using namespace std;
struct DATE
{
    int d, m, y;
};

int ktraNN(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        return 1;
    }
    return 0;
}

void nhap(DATE &day)
{
    cout << "nhap ngay/thang/nam: ";
    cin >> day.d >> day.m >> day.y;
}

void xuat(DATE day)
{
    cout << "ngay/thang/nam da nhap: ";
    cout << day.d << "/" << day.m << "/" << day.y;
}

int disDay(DATE day1, DATE day2, int *ngay)
{
    int sumDay = 0;
    int ngay1 = day1.d, thang1 = day1.m, nam1 = day1.y;
    while (1)
    {
        if (ngay1 == day2.d && thang1 == day2.m && nam1 == day2.y)
            return sumDay;
        ktraNN(nam1);
        if (ngay1 + 1 <= ngay[thang1])
        {
            sumDay++;
            ngay1++;
        }
        else
        {
            sumDay++;
            ngay1 = 1;
            thang1++;
            if (thang1 == 13)
            {
                thang1 = 1;
                nam1++;
            }
        }
    }
    return sumDay;
}

int checkDay(DATE day, int *ngay)
{
    if (day.d <= 0 || day.d > ngay[day.m] || day.m <= 0 || day.m > 12 || day.y <= 0)
        return 0;
    return 1;
}

int main()
{
    int ngay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    DATE day1, day2;
    nhap(day1);
    if (!checkDay(day1, ngay))
    {
        cout << "Ngay/thang/nam khong hop le, hay nhap lai.";
        return 0;
    }
    xuat(day1);
    if (!checkDay(day1, ngay))
    {
        cout << "Ngay/thang/nam khong hop le, hay nhap lai.";
        return 0;
    }
    cout << endl;
    nhap(day2);
    cout << "Khoang cach giua hai ngay: " << disDay(day1, day2, ngay);
}