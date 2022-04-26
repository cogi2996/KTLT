#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<int, string> m;
    string str;
    cout << "Nhap mot chuoi: " << endl;
    getline(cin, str);
    int keyCap = 1, sizeM = 0, keySl = 0 ;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            if (keyCap == 1&& str[i]<='z' && str[i]>='a')
            {
                m[sizeM] += (str[i]-' ');
                keyCap = 0;
                continue;
            }
            else if(keyCap ==1)
            {
                keyCap = 0;
            }
            m[sizeM] += str[i];
            keySl = 1;
        }
        else 
        {
            if (keySl == 1)
            {
                sizeM++;
                keySl = 0;
                keyCap = 1;
            }
        }
    }

    cout << "chuoi sau khi chuan hoa:"<<endl;
    for (int i = 0; i < m.size() - 1; i++)
    {
        cout <<m[i]<<" ";
    }
    cout << m[m.size() - 1];
}