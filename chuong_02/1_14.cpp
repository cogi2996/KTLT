#include <iostream>
using namespace std;

// tsTinhTien = tham so tinh tien
void LoangDoiXungY(int *x1, int *y1, int *x2, int *y2, int pause)
{
    int i = 1;
    while (1)
    {
        x2[i] = x1[i];
        y2[i] = -y1[i];
        if (i == pause)
            break;
        i++;
    }
}

void LoangDoiXungX(int *x3, int *y3, int *x4, int *y4, int pause)
{
    int i = 1;
    while (1)
    {
        x4[i] = -x3[i];
        y4[i] = y3[i];
        if (i == pause)
            break;
        i++;
    }
}

// lam mat tren
void Xhander(int arr[][300], int *x3, int *y3, int stepX,int stepY, int n, int count)
{
    int XcurLocal = n;
    int YcurLocal = n;
    int i = 1;
    int temp = 0;
    while (1)
    {
        arr[XcurLocal + x3[i]][YcurLocal + y3[i]] = arr[XcurLocal + x3[i] + stepX][YcurLocal + y3[i]+stepY];

        if (temp == count + 1)
        {
            break;
        }
        temp++;
        i++;
    }
}



int main()
{
    int n;
    cin >> n;
    int x0[100], y0[100];
    for (int i = 1; i <= n; i++)
    {
        x0[i] = -i;
        y0[i] = i;
    }
    int temp = 1;
    int arr[300][300] = {0};
    int i = 1;
    int XcurLocal = n + 1;
    int YcurLocal = 0;
    while (temp <= n * n)
    {

        for (int i = 1; i <= n; i++)
        {
            arr[XcurLocal + x0[i]][YcurLocal + y0[i]] = temp;
            temp++;
        }
        XcurLocal++;
        YcurLocal++;
    }

    // for (int i = 1; i <= 21; i++)
    // {
    //     for (int j = 1; j <= 25; j++)
    //     {
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }

    // BEN TRAI
    i = 1;
    int x1[100], y1[100], x2[100], y2[100], x3[100], y3[100], x4[100], y4[100];
    temp = -((n - 1) / 2 - 1);
    int tempY = temp - 2;
    int tamX = n, tamY = n;
    int xPause = -temp;
    while (1)
    {

        x1[i] = temp;
        if (temp > 0)
        {

            tempY--;
        }
        else
        {
            tempY++;
        }
        y1[i] = tempY;
        if (temp == xPause)
        {
            break;
        }
        temp++;
        i++;
        // if(temp == )
    }

    LoangDoiXungY(x1, y1, x2, y2, xPause * 2 + 1);

    // cout << endl;
    // for (int k = 1; k <= xPause * 2 + 1; k++)
    // {
    //     cout << y1[k] << " ";
    // }
    /////////////
    // for(int k = 0;k<=)
    int tempX = -(n - 1) / 2;
    tempY = tempX + 1;
    int pause = -(n - 1) / 2;
    i = 1;
    int keyIn = 0;
    int count = 0;
    while (1)
    {
        x3[i] = tempX;
        y3[i] = tempY;
        if (tempX == -1 || keyIn == 1)
        {
            keyIn = 1;
            tempX = tempX - 2;
        }
        tempX++;
        if (tempY > 0 && tempX == pause - 1)
        {
            break;
        }
        tempY++;
        i++;
        count++;
    }

    LoangDoiXungX(x3, y3, x4, y4, count + 1);
    // 	for(int j = 1;j<=count+1;j++)
    // {
    // 	cout<<x4[j]<<" ";
    // }
    // lam mat tren

    // lam mat tren
    // int arr[][300],int *x3,int y3,int step,int n,int count
    temp = arr[n][n];
    Xhander(arr, x3, y3, n,0, n, count);
    Xhander(arr, x4, y4, -n,0, n, count);
    Xhander(arr, x1, y1, 0,n, n, count);
    Xhander(arr, x2, y2, 0,-n, n, count);
    arr[n][n] = temp;

    for (int i = 1; i <= 2*n-1; i++)
    {
        for (int j = 1; j <=2*n-1; j++)
        {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
}