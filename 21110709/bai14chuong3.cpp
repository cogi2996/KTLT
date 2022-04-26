#include <iostream>
#include <algorithm>
using namespace std;

void nhap(int &n, int *arr, int &sl1, int &sl2, int &sl3)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
            sl1++;
        else if (arr[i] == 2)
            sl2++;
        else
            sl3++;
    }
    
}

void solve(int n, int arr[], int sl1, int sl2, int sl3)
{
    // do phuc tap n
    for (int i = 0; i < n; i++)
    {
        if (sl1 > 0)
        {
            if (arr[i] == 1)
            {
                sl1--;
                continue;
            }
            arr[i] = 1;
            sl1--;
        }
        else if (sl2 > 0)
        {
            if (arr[i] == 2)
            {
                sl2--;
                continue;
            }
            arr[i] = 2;
            sl2--;
        }
        else if (sl3 > 0)
        {
            if (arr[i] == 3)
            {
                sl3--;
                continue;
            }
            arr[i] = 3;
            sl3--;
        }
    }
}

void xuatArr(int n,int *a)
{
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n;
    int sl1 = 0, sl2 = 0, sl3 = 0;
    int arr[100];
    nhap(n, arr, sl1, sl2, sl3);
    solve(n, arr, sl1, sl2, sl3);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}