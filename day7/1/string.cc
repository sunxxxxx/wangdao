#include <string.h>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::istream;
using std::vector;

class String {
public:
	String();
	String(const char *);
	String(const String&);
	~String();
    
    void print();
    char * getStr() const;
    
    
	String &operator=(const String &);
	String &operator=(const char *);

	String &operator+=(const String &);
	String &operator+=(const char *);

	char &operator[](std::size_t index);
	const char &operator[](std::size_t index) const;

	std::size_t size() const;
	const char* c_str() const;

	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);

	friend bool operator<(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>=(const String &, const String &);

	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s);

private:
	char * _pstr;
};

String::String()
: _pstr(new char[1]())
{
    cout<<"String()"<<endl;
}

String::String(const char *p)
: _pstr(new char[strlen(p)+1]())
{
    strcpy(_pstr,p);
    cout<<"String(const char *)"<<endl;
}

String::String(const String& cc)
: _pstr(new char[strlen(cc._pstr)+1]())
{
    strcpy(_pstr,cc._pstr);
    cout<<"String(const string *)"<<endl;
}

String::~String()
{
    if(_pstr)
        delete _pstr;
    cout<<"~String()"<<endl;
}

void String::print()
{
    cout<<_pstr<<endl;
}

 char * String::getStr() const
    {
        return  this->_pstr;
    }

String & String::operator=(const String &cc)
{
    if(this!=&cc)
    {
        cout<<"String &operator=(const String &)"<<endl;
        delete [] _pstr;
        _pstr=new char[strlen(cc._pstr)+1];
        strcpy(_pstr,cc._pstr);
        return *this;
    }
}

String & String::operator=(const char *p)
{
    if(_pstr!=p)
    {
        cout<<"String & operator=(const char *)"<<endl;
        delete [] _pstr;
        _pstr=new char[strlen(p)+1];
        strcpy(_pstr,p);
        return *this;
    }
}

//operator []
char & String::operator[](std::size_t index)
{
    //cout<<"char & String::operator[](std::size_t )"<<endl;
    static char szNull='\0';
    if(index<strlen(_pstr)&&index>=0)
    {
        return _pstr[index];
    }else
    {
        return szNull;
    }
}

const char & String::operator[](std::size_t index) const
{
    //cout<<"const char & String::operator[](std::size_t ) const"<<endl;
    return _pstr[index];
}

std::size_t String::size() const
{
    cout<<"std::size_t String::size() const"<<endl;
    return strlen(_pstr);
}
const char* String::c_str() const
{
    cout<<"const char* String::c_str() const"<<endl;
    return _pstr;
}

//operator +=
String & String::operator+=(const String &cc)
{
    cout<<"String &operator+=(const String &)"<<endl;
    char s[strlen(_pstr)+strlen(cc.getStr())+1]={0};
    sprintf(s,"%s%s",_pstr,cc.getStr());
    return *this=s;
}

String & String::operator+=(const char *c)
{
    cout<<"String &operator+=(const char *)"<<endl;
    char s[strlen(_pstr)+strlen(c)+1]={0};
    sprintf(s,"%s%s",_pstr,c);
    return *this=s;
}

//operator ==   !=
bool operator==(const String &cc1, const String &cc2)
{
    cout<<"bool operator==(const String &, const String &)"<<endl;
    if(strcmp(cc1._pstr,cc2._pstr))
        return false;
    else
        return true;
}

bool operator!=(const String &cc1, const String &cc2)
{
    cout<<"bool operator!=(const String &, const String &)"<<endl;
    if(strcmp(cc1._pstr,cc2._pstr))
        return true;
    else
        return false;
}

//operator < > <= >=
bool operator<(const String &cc1, const String &cc2)
{
    cout<<"bool operator<(const String &, const String &)"<<endl;
    if(strcmp(cc1._pstr,cc2._pstr)<0)
        return true;
    else
        return false;
}
bool operator>(const String &cc1, const String &cc2)
{
    cout<<"operator>(const String &, const String &)"<<endl;
    if(strcmp(cc1._pstr,cc2._pstr)>0)
        return true;
    else
        return false;
}
bool operator<=(const String &cc1, const String &cc2)
{
    cout<<"operator<=(const String &, const String &)"<<endl;
    if(strcmp(cc1._pstr,cc2._pstr)<=0)
        return true;
    else
        return false;
}
bool operator>=(const String &cc1, const String &cc2)
{
    cout<<"operator>=(const String &, const String &)"<<endl;
    if(strcmp(cc1._pstr,cc2._pstr)>=0)
        return true;
    else
        return false;
}

//operator << >>
std::ostream &operator<<(std::ostream &os, const String &s)
{
    cout<<"std::ostream &operator<<(std::ostream &os, const String &s)"<<endl;
    os<<s._pstr;
    return os;
}
std::istream &operator>>(std::istream &is, String &s)
{
    cout<<"std::istream &operator>>(std::istream &is, String &s)"<<endl;
    cout<<"enter '#' in the end"<<endl;
    vector <char> v;
    char c;
    while(is>>c)
    {
        if(c=='#')
            break;
        v.push_back(c);
    }
    cout<<"v ok"<<endl;
    if(s._pstr)
    {
        int j=0;
        delete [] s._pstr;
        s._pstr=new char[v.size()+1]();
        for(auto &i:v)
            s._pstr[j++]=i;
    }
    return is;
}

//  operator+
String operator+(const String &cc1, const String &cc2)
{
    cout<<"String operator+(const String &, const String &)"<<endl;
    char s[strlen(cc1.getStr())+strlen(cc2.getStr())+1]={0};
    sprintf(s,"%s%s",cc1.getStr(),cc2.getStr());
    return String(s);
}

String operator+(const String &cc1, const char *c)
{
    cout<<"String operator+(const String &, const char *)"<<endl;
    char s[strlen(cc1.getStr())+strlen(c)+1]={0};
    sprintf(s,"%s%s",cc1.getStr(),c);
    return String(s);
}

String operator+(const char *c, const String &cc1)
{
    cout<<"String operator+(const char *, const String &)"<<endl;
    char s[strlen(cc1.getStr())+strlen(c)+1]={0};
    sprintf(s,"%s%s",cc1.getStr(),c);
    return String(s);
}


int main()
{
    char s[]="xiyangyangyang";
    String str(s);
    str.print();
    String str1(str);
    str1.print();

    String str2;
    str2=str;
    str2.print();
    str2=s;
    str2.print();

    (str1+str2).print();
    (s+str1).print();
    (str1+s).print();

    str1+=str1;
    str1.print();
    str1+=s;
    str1.print();

    size_t index=str1.size();
    for(int i=1;i<index;i++)
    {
        cout<<str1[i];
    }
    cout<<endl;

    cout<<str1.size()<<endl;
    cout<<str1.c_str()<<endl;

    cout<<(str1==str2)<<endl;
    cout<<(str1!=str2)<<endl;

    cout<<(str1<str2)<<endl;
    cout<<(str1>str2)<<endl;
    cout<<(str1<=str2)<<endl;
    cout<<(str1>=str2)<<endl;

    cout<<str1<<endl;
    cin>>str1;
    cout<<str1<<endl;

    return 0;
}

