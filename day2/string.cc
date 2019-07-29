#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
class String
{
public:
    //构造函数
    String(const char *pstr)
    : _pstr(new char[strlen(pstr)+1]())
    {
        strcpy(_pstr,pstr);
        cout<<"String(const char *)"<<endl;
    }

    String()
    : _pstr(new char[1]())
    {
        /*
        strcpy(_pstr,"0");
        cout<<"String()"<<endl;
        */
    }

    void print()
    {
        cout<<"String:"<<_pstr<<endl;
    }

    ~String()
    {
        if(_pstr)
            delete [] _pstr;

        cout<<"~String()"<<endl;
    }

    String(const String & rhs)
    : _pstr(new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
        cout<<"String(const String &)"<<endl;
    }

    String & operator=(const String & rhs)
    {
        //防止自复制
        if(this!=&rhs)
        {
            //回收空间
            cout<<"String &operator=(const String &)"<<endl;
            delete [] _pstr;
            //深拷贝
            _pstr=new char[strlen(rhs._pstr)+1]();
            strcpy(_pstr,rhs._pstr);
        }
        return *this;
    }


private:
    char * _pstr;

};

int main(void)
{
    String str1;
    str1.print();

    String str2 = "Hello,world";
    String str3("wangdao");

    str2.print();       
    str3.print();   

    String str4 = str3;
    str4.print();

    str4 = str2;
    str4.print();

    return 0;

}

