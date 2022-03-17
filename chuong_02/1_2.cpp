#include <iostream>
using namespace std;

int Find(int *a,int x, int begin, int end)
{
    while (begin <= end)
    {
        int middle = (begin + end) / 2;

        if (x == a[middle])
        {
            return middle;
        }

        if (x > a[middle])
        {
            begin = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }
    return -1;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int begin = 0, end = 7;
    int x;
    cin >> x;
    int kq = Find(a, x, begin, end);
    if(kq!= -1)
    {
        cout<<"vi tri cua diem can tim la : "<<kq;
    }
    else
    {
        cout<<"diem can tim khong ton tai trong mang";
    }
}
