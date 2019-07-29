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
    , _name(new char[strlen(name)+1]())
    {
        cout<<"student(int,const char*)"<<endl;
        strcpy(_name,name);
    }

    void destory()
    {
        if(this)
        {
            delete this;
        }
    }

    void *operator new(size_t sz)
    {
        void *ret=malloc(sz);
        cout<<"viod * operator new(size_t)"<<endl;
        return ret;
    }

    void operator delete(void *p)
    {
        cout<<"void operator delete(void *p)"<<endl;
        free(p);
    }

    void print()
    {
        cout<<"id="<<_id<<endl
            <<"name="<<_name<<endl;
    }

private:
    ~student()
    {
        cout<<"~student()"<<endl;
        if(_name){
            delete [] _name;
            _name=nullptr;
        }
           
    }

private:
    int _id;
    char *_name;
};
int main()
{
    student *pstu=new student(1,"xiyangyang");
    pstu->print();
    pstu->destory();
    return 0;
}

