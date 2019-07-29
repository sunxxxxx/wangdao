#include <iostream>
using std::cout;
using std::endl;

class queue
{
public:

    queue(int size)
        :_size(size)
         ,_pstr(new int[size]())
    {
        cout<<"create a queue ,capacity is "<<_size<<endl;
    }

    ~queue()
    {
        if(_pstr)
        {
            delete _pstr;
            cout<<"~queue()"<<endl;
        }
    }

    void push(int i)
    {
        if((_rear+1)%_size==_front)
        {
            cout<<"queue is full"<<endl;
        }else
        {
            _pstr[_rear++]=i;
            cout<<"enque "<<i<<endl;
        }
    }

    void pop()
    {
        if(_rear==_front)
        {
            cout<<"queue is empty"<<endl;
        }else
        {
            cout<<"queue pop "<<_pstr[_front]<<endl;
            _front=(_front+1)%_size;
        }
    }

    int front()
    {
        if(_front==_rear)
        {
            cout<<"queue is empty"<<endl;
        }else
        {
            cout<<"front of queue is "<<_pstr[(_rear-1+_size)%_size]<<endl;
            return _pstr[_rear-1];
        }
    }

    int back()
    {
        if(_front==_rear)
        {
            cout<<"queue is empty"<<endl;
        }else
        {
            cout<<"back of queue is "<<_pstr[_front]<<endl;
            return _pstr[_front];
        }
    }

    bool empty()
    {
        if(_front==_rear)
        {
            cout<<"queue is empty"<<endl;
            return true;
        }else
        {
            cout<<"back of queue is not empty"<<endl;
            return false;
        }
    }

    bool full()
    {
        if((_rear+1)%_size==_front)
        {
            cout<<"queue is full"<<endl;
            return true;
        }else
        {
            cout<<"back of queue is not full"<<endl;
            return false;
        }
    }

private:
    int _front=0;
    int _rear=0;
    int _size;
    int *_pstr;

};

int main()
{
    queue que(10);
    que.push(10);
    que.push(11);
    que.push(12);
    int i=que.front();
    cout<<"front is "<<i<<endl;
    i=que.back();
    cout<<"back is "<<i<<endl;
    que.pop();
    que.empty();
    que.full();

    return 0;
}

