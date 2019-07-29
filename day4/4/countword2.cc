#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;
/*
typedef struct word_count{
	char word[50];
	int count;
	struct word_count* pNext;
}Word,*pWord;
*/
struct info{
    info(const string &s,const int &i)
    : word(s)
    ,count(i){}

    string word;
    int count=1;
};

void countWord(vector <info> &dictionary,string &word)
{
    int flag=0;
    for(auto & info:dictionary)
    {
        if(info.word==word)
        {
            info.count++;
            flag=1;
            break;
        }
    }
    if(0==flag)
    {
        dictionary.push_back(info(word,1));
    }
}






int main()
{
	FILE* fp;
	time_t start, end;
	const char* p;
	ofstream ofs("dictionary.txt");
    vector <info> dictionary;
	string filename="The_Holy_Bible.txt";
	ifstream ifs(filename);
	if(!ifs) {
		cout << "ifstream open file " << filename << " error!" << endl;
		return 0;
	}
	start = time(NULL);
	string word;
	while(ifs>>word ) {
		if(word>"9"||word<"0"){
			countWord(dictionary,word);
		}
	} 


    for(auto & info:dictionary)
    {
        cout<<info.word<<"  "<<info.count<<endl;
    }

	for(auto & info:dictionary)
    {
       ofs<<info.word<<"  "<<info.count<<endl;
    }

	end = time(NULL);
	printf("use time:%ld\n", end - start);

}
