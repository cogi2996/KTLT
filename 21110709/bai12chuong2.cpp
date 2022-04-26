#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
int checkPhuongAn(int i, int j, int a[175][175])
{
    i = i + j;
    int check = 0;
    for (int cot = 1; cot <= 5; cot++)
    {
        if (j != cot && a[i][cot] == 0)
        {
            check++;
        }
    }
    if (check == 4)
        return 1;
    return 0;
}

void TaoBang(int a[][175])
{
    for (int i = 35; i >= 0; i--)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i + j <= 35)
            {
                if (checkPhuongAn(i, j, a))
                {
                    a[i][j] = j;
                }
            }
        }
    }
}

void nguoiDi(int a[175][175], int &chose, int &sum)
{
    cout << "Nguoi chon: ";
    cin >> chose;
    sum += chose;
}
int dkwin(int chose, int sum, int a[175][175])
{
    // xet bang 35 thi win hoac doi phuong khong con duong de di
    if (sum == 35)
    {
        return 1;
    }
    //    1 2 3 4 5
    // 35  0 0 0 0 0
    // 34 1 0 0 0 0
    // 33 1 2 0 0 0
    if (chose - 1 == 0 && chose + 1 + sum <= 35)
    {
        return 0;
    }

    for (int i = chose - 1; i > 0; i--)
    {
        if (i + sum <= 35)
        {
            return 0;
        }
    }

    return 1;
}

void mayDi(int a[175][175], int chose, int &sum, int &chose1)
{
    // check xem co vuot 35 chua
    int check = 0;
    for (int i = 1; i <= 5; i++)
    {
        if (a[sum][i] != 0 && a[sum][i] != chose)
        {
            cout << "may chon: " << a[sum][i] << endl;
            chose1 = a[sum][i];
            sum = sum + a[sum][i];
            check = 1;
            break;
        }
    }

    int ranDom;
    srand(time(0));
    if (check == 0)
    {
        while (1)
        {
            ranDom = 1 + rand() % 5;
            if (ranDom != chose && ranDom + sum <= 35)
            {
                break;
            }
        }
        cout << "May chon: " << ranDom << endl;
        chose1 = ranDom;
        // cout<<"lua chon cua nguoi: "<<chose;
        sum = sum + ranDom;
    }
}

int ktraTrung(int chose1, int chose2)
{

    if (chose1 == chose2)
    {
        cout << "==>Lua chon khong hop le, vui long chon lai"<<endl;
        return 1;
    }
    return 0;
}

void ThuTu(int a[][175], int &sum, int &chose, int &chose1, int keyThuT)
{
    while (sum < 35)
    {
        if (keyThuT == 2)
        {
            nguoiDi(a, chose, sum);
            if(ktraTrung(chose,chose1))
            {   
                sum-=chose;
                continue;
            }
            if (dkwin(chose, sum, a))
            {
                cout << endl
                     << "==>Nguoi win";
                exit(0);
            }
        }
        keyThuT = 2;
        mayDi(a, chose, sum, chose1);
        if (dkwin(chose1, sum, a))
        {
            cout << endl
                 << "==>May win";
            exit(0);
        }
    }
}

int main()
{

    // lam day cac cho trong =  0
    int a[175][175] = {0};
    TaoBang(a);
    int chose = 0;
    int chose1 = 0;
    int sum = 0;
    int chosen = 0;
    do
    {
        cout << "[0]-EXIT" << endl;
        cout << "[1]-Nguoi di truoc" << endl;
        cout << "[2]-May di truoc" << endl;
        cin >> chosen;
        switch (chosen)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            ThuTu(a, chose, sum, chose1, 2);
            break;
        }
        case 2:
        {
            ThuTu(a, chose, sum, chosen, 0);
            break;
        }
        default:
        {
            cout << " ==> Lua chon khong hop le , hay chon lai" << endl;
        }
        }
    } while (chosen);
}