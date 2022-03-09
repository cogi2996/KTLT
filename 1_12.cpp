#include <iostream>
using namespace std;

struct PHANSO
{
    int tu, mau;
};

void nhap(PHANSO *arr, int &n)
{
    cout << "Nhap so luong phan tu mang: ";
    cin >> n;
    cout << "Nhap phan so: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].tu >> arr[i].mau;
    }
}

PHANSO tong2PS(PHANSO a, PHANSO b)
{
    PHANSO tong;
    tong.tu = a.tu * b.mau + b.tu * a.mau;
    tong.mau = a.mau * b.mau;
    return tong;
}

PHANSO tongPS(PHANSO *arr, int n)
{
    PHANSO tong = tong2PS(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        tong = tong2PS(tong, arr[i]);
    }
    return tong;
}

float hieu(PHANSO max, PHANSO x)
{
    float Hieu = (float)(max.tu * x.mau - x.tu * max.mau) / (max.mau * x.mau);
    return Hieu;
}

PHANSO maxPS(PHANSO *arr, int n)
{
    PHANSO max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (hieu(max, arr[i]) < 0) max = arr[i];
    }
    return max;
}

PHANSO minPS(PHANSO *arr, int n)
{
    PHANSO min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (hieu(min, arr[i]) > 0)
            min = arr[i];
    }
    return min;
}

void MangTang(PHANSO *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (hieu(arr[i], arr[j]) > 0)
            {
                PHANSO x  = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
            }
        }
    }
    cout<<endl;
}

void xuatMang(PHANSO *arr, int n)
{
    cout << "Mang sap xep tang dan: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].tu << "/" << arr[i].mau << endl;
    }
}

int main()
{
    PHANSO arr[1000];
    int n;
    nhap(arr, n);
    cout << "Tong cac phan tu: " << tongPS(arr, n).tu << "/" << tongPS(arr, n).mau << endl;
    cout << "Phan so lon nhat: " << maxPS(arr, n).tu << "/" << maxPS(arr, n).mau << endl;
    cout << "Phan so nho nhat: " << minPS(arr, n).tu << "/" << minPS(arr, n).mau;
    MangTang(arr, n);
    xuatMang(arr, n);
}