#include <func.h>
#include <iostream>
#define N 20000000
using std::cout;
using std::endl;

class MutexLock
{
    friend class Condition;
public:
    MutexLock()
    {
        pthread_mutex_init(&_mutex,NULL);
    }

    void lock()
    {
        pthread_mutex_lock(&_mutex);
    }

    void unlock()
    {
        pthread_mutex_unlock(&_mutex);

    }

    pthread_mutex_t* getMutex()
    {
        return &_mutex;
    }

private:
    pthread_mutex_t _mutex;
};

class Condition
{
public:
    Condition(MutexLock & mutex)
    :_mutex(mutex)
    {
        pthread_cond_init(&_cond,NULL);
    }

    void wait()
    {
        pthread_mutex_lock(&_mutex._mutex);
        pthread_cond_wait(&_cond,_mutex.getMutex());
        pthread_mutex_unlock(&_mutex._mutex);
    }

    void notify()
    {
        pthread_cond_signal(&_cond);
    }

    void notifyall()
    {
        pthread_cond_broadcast(&_cond);
    }
private:
    pthread_cond_t _cond;
    MutexLock& _mutex;
};


//进程1
void* threadFunc1(void*p)
{
    Condition *pval=(Condition*)p;
    cout<<"i am child1 before wait"<<endl;
    pval->wait();
    cout<<"i am child1 after unlock"<<endl;
}
//进程2
void* threadFunc2(void*p)
{
    Condition *pval=(Condition*)p;
    cout<<"i am child2 before wait"<<endl;
    pval->wait();
    cout<<"i am child2 after unlock"<<endl;
}
int main()
{
    MutexLock mutex;
    Condition cond(mutex);
    pthread_t pthid,pthid1;
    int ret=pthread_create(&pthid,NULL,threadFunc1,&cond);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    ret=pthread_create(&pthid1,NULL,threadFunc2,&cond);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    sleep(1);
    cond.notifyall();
    sleep(1);
    pthread_join(pthid,NULL);
    pthread_join(pthid1,NULL);
}
