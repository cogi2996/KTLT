#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

void nhap(int &n, int k, vector<int> &v)
{
    cin >> n;
    cin >> k;
    cout << "nhap so luong soi tung dong: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

void aranger(int n, int k, vector<int> &v)
{

    int arr[100];
    for (int i = 0; i < v.size(); i++)
    {
        arr[i] = v[i];
    }
    sort(arr, arr + v.size());
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = arr[i];
    }
}

void solve(int n, int k, vector<int> &v)
{
    int i = 0;
    while (v.size() > 1)
    {
        aranger(n, k, v);
        if (v[v.size() - 1] > v[0])
        {
            v[v.size() - 1] = v[v.size() - 1] - v[0];
            v[0] = 2 * v[0];
        }
        for (int j = 0; j < v.size(); j++)
        {
            int trung = v[j];
            for (int j1 = 0; j1 < v.size(); j1++)
            {
                if (trung == v[j1] && j != j1)
                {
                    
                    v.erase(v.begin() + j1); 
                    v[j] = v[j] * 2;
                }
            }
        }
    }
}

int main()
{
    int n;
    int k;
    vector<int> v;
    nhap(n, k, v);
    solve(n, k, v);
}