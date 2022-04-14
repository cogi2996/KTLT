#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    string chuThuong, chuHoa,number,khac;
    for(auto x: str)
    {
        if(x<='z'&&x>='a')
        {
            chuThuong+=x;
            chuThuong+=" ";
        }
        else if(x<='Z'&&x>='A')
        {
            chuHoa+=x;
            chuHoa+=" ";
        }
        else if(x<='9'&&x>='0')
        {
            number+=x;
            number+=" ";
        }
        else if(x!=' ')
        {
            khac+=x;
            khac+=" ";
        }
    }
    cout<<"Chu Thuong: "<<chuThuong<<endl<<"Chu Hoa: "<<chuHoa<<endl<<"So: "<<number<<endl<<"Khac: "<<khac;
    
}