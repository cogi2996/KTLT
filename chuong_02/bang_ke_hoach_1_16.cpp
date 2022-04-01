#include <iostream>
#include <algorithm>
using namespace std;

int truTu(int i, int temp, int start, int *Tu, int *Mau, int sizeNo, int a[][100], int &Long, int *locate, int &valc)
{
    int icp = i;
    int tempCP = temp;
    int check = 0;
    while (i > -1)
    {

        for (int j = 0; j < sizeNo; j++)
        {
            if (i == Tu[j] && temp == Mau[j])
            {
                a[start + locate[valc]][icp] = icp - i;
                locate[valc]++;
                a[start + locate[valc]][icp] = 0;
                locate[valc]++;
                check = 1;
                break;
            }
        }
        i--;
    }
    if (check == 1)
    {
        return 1;
    }
    return 0;
}

int truMau(int i, int temp, int start, int *Tu, int *Mau, int sizeNo, int a[][100], int &Long, int *locate, int &valc)
{
    int tempCP = temp;
    temp = temp - 1; 
    int check = 0;
    while (temp > -1)
    {

        for (int j = 0; j < sizeNo; j++)
        {
            if (Tu[j] == i && Mau[j] == temp)
            {
                a[start + locate[valc]][i] = 0;
                locate[valc]++;
                a[start + locate[valc]][i] = tempCP - temp;
                locate[valc]++;
                check = 1;
            }
        }
        temp--;
    }
    if (check == 1)
        return 1;
    return 0;
}

int truTuvaMau(int i, int temp, int start, int *Tu, int *Mau, int sizeNo, int a[][100], int &Long, int *locate, int &valc)
{
    int tempCP = temp;
    int iCP = i;
    temp--;
    i--;
    int chung = min(temp, i);
    int check = 0;
    while (chung > -1)
    {
        for (int j = 0; j < sizeNo; j++)
        {
            if (Tu[j] == i && Mau[j] == temp)
            {
                a[start + locate[valc]][iCP] = iCP - i;
                locate[valc]++;
                a[start + locate[valc]][iCP] = tempCP - temp;

                locate[valc]++;
                check = 1;
            }
        }
        chung--;
        temp--;
        i--;
    }
    Long = locate[valc];
    if (check == 1)
    {
        return 1;
    }
    return 0;
}

void taoBang(int a[][100], int n1, int n2)
{
    int TuAns[100], sizeNo = 0;
    int MauAns[100];
    TuAns[0] = 0;
    MauAns[0] = 0;
    sizeNo = 1;
    int temp = 0;
    int longMax = 0;
    int locate[100] = {0};
    int valc = 0;
    int count = 0;
    int sumLong = 0;
    int start = 0;
    int length = 0;
    while (temp <= n1)
    {
        start = length;
        longMax = 0;
        for (int i = 0; i < n2; i++)
        {
            int Long = 0;

            int x = truTu(i, temp, start, TuAns, MauAns, sizeNo, a, Long, locate, valc);
            int y = truMau(i, temp, start, TuAns, MauAns, sizeNo, a, Long, locate, valc);
            int z = truTuvaMau(i, temp, start, TuAns, MauAns, sizeNo, a, Long, locate, valc);
            // kiem tra xem co anh nao dong deu bang 0
            if (x == 0 && y == 0 && z == 0)
            {
                TuAns[sizeNo] = i;
                MauAns[sizeNo++] = temp;
                a[start + locate[valc]][i] = 0;
                locate[valc]++;
                a[start + locate[valc]][i] = 0;
            }
            valc++;
            if (Long > longMax)
            {
                longMax = Long;
            }
        }
        length += longMax;
        // lam day hang ngang -1
        for (int j = 0; j < n2; j++)
        {
            a[length][j] = -9999;
        }
        length++;

        fill(locate, locate + n2, 0);
        temp++;
    }
}
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int a[100][100] = {0};
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            a[i][j] = -9000;
        }
    }
    taoBang(a, n1, n2);
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}