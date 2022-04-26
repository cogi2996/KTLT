#include <iostream>
using namespace std;

struct SOPHUC
{
    int re, li;
};

void nhap(SOPHUC *arr, int &n)
{
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].re >> arr[i].li;
    }
}

SOPHUC tongSP(SOPHUC *arr, int n)
{
    SOPHUC tong;
    tong.re = 0;
    tong.li = 0;
    for (int i = 0; i < n; i++)
    {
        tong.re += arr[i].re;
        tong.li += arr[i].li;
    }
    return tong;
}

// aa' - bb' + (ab' + a'b)i
SOPHUC tich2SP(SOPHUC a, SOPHUC b)
{
    SOPHUC tich;
    tich.re = a.re * b.re - a.li * b.li;
    tich.li = a.re * b.li + b.re * a.li;
    return tich;
}

SOPHUC tichSP(SOPHUC *arr, int n)
{
    SOPHUC tich = tich2SP(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        tich = tich2SP(tich, arr[i]);
    }
    return tich;
}

int main()
{
    int n;
    SOPHUC arr[1000];
    nhap(arr, n);
    cout << "Tong cac so phuc: " << tongSP(arr, n).re << " " << tongSP(arr, n).li << endl;
    if (tichSP(arr, n).re >= 0)
    {
        cout << "Tich cac so phuc: " << tichSP(arr, n).li << "i + " << tichSP(arr, n).re;
    }
    else
    {
        cout << "Tich cac so phuc: " << tichSP(arr, n).li << "i - " << tichSP(arr, n).re;
    }
}