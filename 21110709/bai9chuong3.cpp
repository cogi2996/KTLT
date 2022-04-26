#include <iostream>
using namespace std;

void nhapArr(int a[],int n)
{
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
}

void insertSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i], pos = i - 1;
        while (pos >= 0 && x > a[pos])
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

void xuatArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void insertX(int a[], int &n)
{
    int x;
    cin >> x;
    n = n + 1;
    a[n-1] = x;
    int  pos = n -2; 
    while(pos>=0&&x>a[pos])
    {
        a[pos + 1] = a[pos];
        pos--;
    }
    a[pos+1] = x;
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    nhapArr(a,n);
    insertSort(a, n);
    xuatArr(a, n);
    insertX(a,n);
    xuatArr(a,n);
}