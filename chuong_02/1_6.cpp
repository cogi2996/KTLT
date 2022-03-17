#include <iostream>
using namespace std;

void nhap(int *a, int &m, int *b, int &n)
{

    cout << "Nhap sl phan tu A: ";
    cin >> m;
    cout << "Nhap sl phan tu B: ";
    cin >> n;
    cout << endl
         << "Nhap cac phan tu mang A: ";
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    cout << "Nhap cac phan tu mang B: ";
    for (int j = 0; j < n; j++)
    {
        cin >> b[j];
    }
}

void scrat(int *a, int m, int *b, int n, int *c)
{

    int i = 0;
    int tempA = 0,tempB = 0;
    while (i < m + n)
    {
        if(i<1+(m-1)*2&&i%2==0)
        {
            c[i++] =a[tempA++];
        }
        else
        {
            c[i++] = b[tempB++];
        }
    }
}

void xuat(int *c,int sizeC)
{
    cout<<endl<<"Cac phan tu trong mang scrat a va b: ";
    for(int i = 0;i<sizeC;i++)
    {
        cout<<c[i]<<" ";
    }
}

int main()
{
    int a[100], b[100], c[200];
    int sizeA = 0, sizeB = 0;
    nhap(a, sizeA, b, sizeB);
    if (sizeA <= sizeB)
    {
        scrat(a, sizeA, b, sizeB, c);
    }
    else
    {
        scrat( b, sizeB,a, sizeA, c);
    }
    xuat(c,sizeA+sizeB);
}