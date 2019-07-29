#include <iostream>
#include <string>

#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <cstdlib>


#include <iostream>
using std::cout;
using std::endl;
using std::string;
using namespace log4cpp;


//输出的日志信息能同时输出到终端和文件
//输出的日志信息中最好能有文件的名字，函数的名字及其所在的行号
//使用单例模式
class Mylogger{
public:
	void Warn(const char * msg)
    {
        _mycategory.warn(msg);
    }

	void Error(const char * msg)
    {
	   _mycategory.error(msg);
    }

	void Debug(const char * msg)
    {
	   _mycategory.debug(msg);
    }

	void Info(const char * msg)
    {
	    _mycategory.info(msg);
    }

    static Mylogger *getInstance()
    {
        if(nullptr==_pInstance)
        {
            _pInstance=new Mylogger();
        }
        return _pInstance;
    }

    static void destory()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }

	
private:
	Mylogger()
    : _mycategory(Category::getRoot().getInstance("mycategory"))
    {
        PatternLayout * ptnLayout1 = new PatternLayout();
	    ptnLayout1->setConversionPattern("%d %c [%p] %m%n");
	    PatternLayout * ptnLayout2 = new PatternLayout();
	    ptnLayout2->setConversionPattern("%d %c [%p] %m%n");
	    PatternLayout * ptnLayout3 = new PatternLayout();
	    ptnLayout3->setConversionPattern("%d %c [%p] %m%n");

	    OstreamAppender * ostreamAppender = new OstreamAppender("ostreamAppender",&cout);
	    ostreamAppender->setLayout(ptnLayout1);

	    FileAppender * fileAppender = new FileAppender("fileAppender","wangdao.log");
	    fileAppender->setLayout(ptnLayout2);

	    RollingFileAppender * rollingFileAppender = new RollingFileAppender("rollingFileAppender","rollwangdao.log",1024,5);
	    rollingFileAppender->setLayout(ptnLayout3);

	    _mycategory.setPriority(Priority::DEBUG);
	    _mycategory.addAppender(ostreamAppender);
	    _mycategory.addAppender(fileAppender);
	    _mycategory.addAppender(rollingFileAppender);
    }
	~Mylogger()
    {
        Category::shutdown();
    }
private:

    Category &_mycategory;

    static Mylogger *_pInstance;
};

Mylogger * Mylogger::_pInstance=nullptr;
Mylogger * Log = Mylogger::getInstance();

/*
string getstr(int i)
{
    string s;
    char line[6]={0};
    sprintf(line,"%d",i);
    s=line;
    return s;
}
*/

#define make(msg) string(msg).append("(").append(__FILE__).append(":").append(__func__).append(":").append(std::to_string(__LINE__)).append(")").c_str()

#define LogError(msg) Log->Error(make(msg))
#define LogInfo(msg) Log->Info(make(msg))
#define LogWarn(msg) Log->Warn(make(msg))
#define LogDebug(msg) Log->Debug(make(msg))
int main(void)
{
	cout << "hello,world"<<endl;

	LogError("this is Info message");
    LogInfo("this is Info message");
    LogWarn("this is Info message");
    LogDebug("this is Info message");

    Log->destory();
}
