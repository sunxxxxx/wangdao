#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;


class student
{
public:
    student(int id,const char *name)
    : _id(id)
    ,_name(new char[strlen(name)+1]())
    {
        strcpy(_name,name);
        cout<<"stuent(int,const char *)"<<endl;
    }

    ~student()
    {
        cout<<"~student()"<<endl;
        if(_name)
        {
            delete _name;
            _name=nullptr;
        }
    }

    void print() const
    {
        cout<<"id:"<<_id<<endl
            <<"name:"<<_name<<endl;
    }

private:
    void *operator new(size_t sz);
    void operator delete(void *p);

private:
    int _id;
    char *_name;
};

int main()
{
    student stu1(1,"xiyangyang");
    stu1.print();
/*
    student *pstu=new student(2,"meiyangyang");
    pstu->print();
    delete pstu;
*/
    return 0;
}


