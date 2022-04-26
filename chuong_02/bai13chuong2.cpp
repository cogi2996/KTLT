#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int gtriOvuong(int Ibegin, int jbegin, int a[][100], int XdiemGiua, int YdiemGiua, int ipause, int jpause)
{
    int sum = 0;
    if (Ibegin < 0 || Ibegin >= ipause || jbegin < 0 || jbegin >= jpause)
    {
        return -1;
    }
    for (int k1 = Ibegin; k1 <= Ibegin + 2; k1++)
    {
        for (int k2 = jbegin; k2 <= jbegin + 2; k2++)
        {
            if (k1 < 0 || k1 >= ipause || k2 < 0 || k2 >= jpause)
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

int ktra(int i, int j, int a[][100], int ipause, int jpause)
{
    if (gtriOvuong(i - 2, j - 2, a, i - 1, j - 1, ipause, jpause) != -1)
    {
        if (!(gtriOvuong(i - 2, j - 2, a, i - 1, j - 1, ipause, jpause) < 9 * 4))
        {
            return 0;
        }
    }

    if (gtriOvuong(i - 2, j, a, i - 1, j + 1, ipause, jpause) != -1)
    {

        if (!(gtriOvuong(i - 2, j, a, i - 1, j + 1, ipause, jpause) < 9 * 4))
        {
            return 0;
        }
    }

    if (gtriOvuong(i, j - 2, a, i + 1, j - 1, ipause, jpause) != -1)
    {
        if (!(gtriOvuong(i, j - 2, a, i + 1, j - 1, ipause, jpause) < 9 * 4))
        {
            return 0;
        }
    }

    if (gtriOvuong(i, j, a, i + 1, j + 1, ipause, jpause) != -1)
    {
        if (!(gtriOvuong(i, j, a, i + 1, j + 1, ipause, jpause) < 9 * 4))
        {
            return 0;
        }
    }

    if (gtriOvuong(i - 2, j - 1, a, i - 1, j, ipause, jpause) != -1)
    {
        if (!(gtriOvuong(i - 2, j - 1, a, i - 1, j, ipause, jpause) < 9 * 4))
        {
            return 0;
        }
    }

    if (gtriOvuong(i, j - 1, a, i + 1, j, ipause, jpause) != -1)
    {
        if (!(gtriOvuong(i, j - 1, a, i + 1, j, ipause, jpause) < 9 * 4))
        {
            return 0;
        }
    }

    if (gtriOvuong(i - 1, j - 2, a, i, j - 1, ipause, jpause) != -1)
    {
        if (!(gtriOvuong(i - 1, j - 2, a, i, j - 1, ipause, jpause) < 9 * 4))
        {
            return 0;
        }
    }

    if (gtriOvuong(i - 1, j , a, i, j + 1, ipause, jpause) != -1)
    {
        if (!(gtriOvuong(i - 1, j , a, i, j + 1, ipause, jpause) < 9 * 4))
        {
            return 0;
        }
    }
    return 1;
}

void NumbAround(int a[][100], int *x, int *y, int Ipause, int Jpause)
{
    int count = 0;
    for (int i = 0; i < Ipause; i++)
    {
        for (int j = 0; j < Jpause; j++)
        {
            if (a[i][j] == 9)
            {
                continue;
            }
            for (int k = 0; k < 8; k++)
            {
                if (i + x[k] >= Ipause || i + x[k] < 0 || j + y[k] >= Jpause || j + y[k] < 0)
                {
                    continue;
                }
                if (a[i + x[k]][j + y[k]] == 9)
                {
                    count++;
                }
            }
            a[i][j] = count;
            count = 0;
        }
    }
}

void sovle(int arr[][100], int ipause, int jpause,int bomp)
{
    srand(time(0));
    int lucky = 0;
    int temp = 0;
    while (temp <= bomp)
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
                    if (ktra(i, j, arr, ipause, jpause))
                    {
                        arr[i][j] = 9;
                        if (temp == bomp)
                        {
                            break;
                        }
                        temp++;
                    }
                }
            }
            if (temp == bomp)
            {
                break;
            }
        }
        cout << endl
             << temp << endl;
        if (temp == bomp)
        {
            break;
        }
    }
    int x[] = {-1, 0, 1, 0, -1, -1, 1, 1}, y[] = {0, 1, 0, -1, -1, 1, -1, 1};
    NumbAround(arr, x, y, ipause, jpause);
}

int main()
{
    int arr[100][100] = {0};
    int bomp = 0;
    int chose;
    cin >> chose;
    if (chose == 2)
    {
        sovle(arr, 16, 16,30);
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (chose == 1)
    {
        sovle(arr, 9, 9,10);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (chose == 3)
    {
        sovle(arr, 30, 16, 80);
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}