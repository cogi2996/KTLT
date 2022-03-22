#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int gtriOvuong(int Ibegin, int jbegin, int a[][100], int XdiemGiua, int YdiemGiua)
{
    int sum = 0;
    if (Ibegin < 0 || Ibegin >= 16 || jbegin < 0 || jbegin >= 16)
    {
        return -1;
    }
    for (int k1 = Ibegin; k1 <= Ibegin + 2; k1++)
    {
        for (int k2 = jbegin; k2 <= jbegin + 2; k2++)
        {
            if (k1 < 0 || k1 >= 16 || k2 < 0 || k2 >= 16)
            {
                continue;
            }
            if (k1 == XdiemGiua && k2 == YdiemGiua)
            {
                continue;
            }
            sum += a[k1][k2];
        }
    }
    return sum;
}

int ktra(int i, int j, int a[][100])
{
    if (gtriOvuong(i - 2, j - 2, a, i - 1, j - 1) != -1)
    {
        if (!(gtriOvuong(i - 2, j - 2, a, i - 1, j - 1) < 9 * 4))
        {
            return 0;
        }
    }

    if (gtriOvuong(i - 2, j, a, i - 1, j + 1) != -1)
    {
   

        if (!(gtriOvuong(i - 2, j, a, i - 1, j + 1) < 9 * 4))
        {
            return 0;
        }
    }

    if (gtriOvuong(i, j - 2, a, i + 1, j - 1) != -1)
    {

        if (!(gtriOvuong(i, j - 2, a, i + 1, j - 1) < 9 * 4))
        {
            return 0;
        }
    }

    if (gtriOvuong(i, j, a, i + 1, j + 1) != -1)
    {
        if (!(gtriOvuong(i, j, a, i + 1, j + 1) < 9 * 4))
        {
            return 0;
        }
    }
    return 1;
}

void sovle(int arr[][100],int ipause,int jpause)
{
    srand(time(0));
    int lucky = 0;
    int temp = 0;
    while (temp <= 30)
    {
    for (int i = 0; i < ipause; i++)
    {
        for (int j = 0; j < jpause; j++)
        {
            if (arr[i][j] == 9)
            {
                continue;
            }
            lucky = rand() % 2;
            // cout<<"("<<lucky<<")";
            if (lucky == 1)
            {
                if (ktra(i, j, arr))
                {
                    arr[i][j] = 9;
                    temp++;
                }
            }
        }
    }
    }
}

int main()
{
    int arr[100][100] = {0};
    int chose;
    cin >> chose;
    if (chose == 2)
    {
        sovle(arr,16,16);
          for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    }
    if(chose == 1)
    {
        sovle(arr,9,9);
     for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    }
    if(chose == 3)
    {
        sovle(arr,30,16);
         for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    }
    
  
    if(chose == 1)
    {
   
    }
}