#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int m, n;
    int a[100][100];
    int x[] = {0, 0, 1, -1};
    int y[] = {1, -1, 0, 0};
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int loi[100];
    int key = 0, keyTonTai = 0;
    int keyFirst = 0;
    int minLoi = -1111;
    int tdx,tdy;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            key = 0;
            for (int k = 0; k < 4; k++)
            {
                if (i + x[k] >= m || i + x[k] < 0 || j + y[k] < 0 || j + y[k] >= n)
                {
                    continue;
                }
                if (a[i][j] <= a[i + x[k]][j + y[k]])
                {
                    key = 1;
                    break;
                }
            }
            if (key == 0)
            {
                if (keyFirst == 0)
                {
                    minLoi = a[i][j];
                    tdx = i;
                    tdy = j;
                    keyFirst = 1;
                    continue;
                }
                if (a[i][j] < minLoi)
                {
                    minLoi = a[i][j];
                    tdx = i;
                    tdy = j;
                }
                keyTonTai = 1;
            }
        }
    }
    if (keyTonTai == 1)
    {
        cout<<tdx<<" "<<tdy;
        return 0;
    }
    else
    {
        cout<<-1;
        return 0;
    }
}