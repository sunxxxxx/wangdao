#include <iostream>
using std::cout;
using std::endl;

class stack
{
public:

    void push(int i)
    {
        if(_val<9)
        {
            _num[++_val]=i;
            cout<<"push "<<i<<endl;
        }else
        {
            cout<<"stack is full"<<endl;
        }
    }

    void pop()
    {
        if(_val>0)
        {
            _val--;
            cout<<"pop "<<_num[_val+1]<<endl;
        }else
        {
            cout<<"stact is empty"<<endl;
        }
    }

    int top()
    {
        if(_val<0)
        {
            cout<<"no data in stact!"<<endl;
            return -1;
        }else
        {
            cout<<"top of stack is "<<_num[_val]<<endl;
            return _num[_val];
        }
    }

    bool empty()
    {
        if(_val<0)
        {
            cout<<"empty"<<endl;
            return true;
        }else
        {
            cout<<"not empty"<<endl;
            return false;
        }
    }

    bool full()
    {
        if(9==_val)
        {
            cout<<"stack is full"<<endl;
            return true;
        }else
        {
            cout<<"stact is not full"<<endl;
            return false;
        }
    }
private:
    int _val=-1;
    int _num[10]={0};
    //static int _size;
};

//int  stack::_size=10;
int main()
{
    stack stack1;
    stack1.push(10);
    stack1.push(12);
    stack1.push(14);
    int i=stack1.top();
    cout<<"top "<<i<<endl;
    stack1.pop();
    i=stack1.top();
    cout<<"top "<<i<<endl;
}

