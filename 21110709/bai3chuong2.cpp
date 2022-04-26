#include <iostream>
using namespace std;

void addArr(int *a, int &n)
{
    cout << "Nhap so phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void addEle(int *a, int &n)
{
    cin >> a[n];
    n++;
}

void xoa(int *a, int &n)
{
    int b[100];
    cout << endl
         << "Nhap phan tu can xoa: ";
    int xoa;
    cin >> xoa;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (xoa != a[i])
        {
            b[temp++] = a[i];
        }
    }
    fill(a, a + n, 0);
    n = temp;
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

void xuatMang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void findPoint(int *a, int n)
{
    cout << "Nhap phan tu can tim kiem: ";
    int x;
    cin >> x;
    int begin = 0, end = n-1;
    int check = 0;
    while (begin <= end)
    {
        int middle = (begin + end) / 2;
        if (x == a[middle])
        {
           cout<<"Phan tu da cho co ton tai trong mang.";
           check = 0;
        }

        if (x < a[middle])
        {
            end = middle - 1;
        }
        else
        {
            begin = middle + 1;
        }
    }
    cout<<endl;
    if(check !=0) 
    {
        cout<<x<<" khong ton tai trong mang";
    }
}

int main()
{
    int chose;
    int a[100], n = 0;
    addArr(a, n);
    do
    {
        cin >> chose;
        switch (chose)
        {
        case 1:
            addEle(a, n);
            break;
        case 2:
            xoa(a, n);
            break;
        case 3:
            xuatMang(a, n);
            break;
        case 4:
            findPoint(a, n);
            break;
        default:
            break;
        }

    } while (chose);
}