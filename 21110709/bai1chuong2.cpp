#include <iostream>
using namespace std;

void nhap(int *arr, int &n, int &x)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Nhap x can tim kiem: " << endl;
    cin >> x;
}

void timKiem(int *arr, int n, int x)
{
    arr[n] = x;
    int i = 0;
    while (arr[i] != x)
    {
        i++;
    }
    if (i < n)
    {
        cout
            << "So da nhap co ton tai trong mang";
        exit(0);
    }
    else
    {
        cout
            << "So da nhap khong ton tai ";
    }
}

int main()
{
    int arr[100];
    int n, x;
    nhap(arr, n, x);
    timKiem(arr, n, x);
}