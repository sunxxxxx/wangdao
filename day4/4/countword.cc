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
using std::istringstream;
using std::ostringstream;
using std::stringstream;

typedef struct word_count{
	char word[50];
	int count;
	struct word_count* pNext;
}Word,*pWord;

void countWord(pWord* ppHead, const char* buf)
{
	if (*ppHead)   //结构体链表不为空
	{
		pWord pCur = *ppHead;
		//该单词是否已在结构体链表中存在
		while (pCur)
		{
			if (!strcmp(buf,pCur->word))    //若存在该单词
			{
				pCur->count++;
				break;
			}
			else
			{
				//pPer = pCur;
				pCur = pCur->pNext;
			}
		}
		if (pCur == NULL)             //结构体链表中不存在该单词
		{
			pCur = (pWord)calloc(1, sizeof(Word));
			pCur->count++;
			strcpy(pCur->word,buf);
			pCur->pNext = (*ppHead)->pNext;
			(*ppHead)->pNext=pCur;
		}
	}
	else          //结构体链表为空
	{
		*ppHead = (pWord)calloc(1, sizeof(Word));
		strcpy((*ppHead)->word,buf);
		(*ppHead)->count++;
	}
}



int main()
{
	pWord pHead=NULL,pCur;
	FILE* fp;
	time_t start, end;
	const char* p;
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
			//cout<<word<<endl;
	        const char* p=word.data();
			countWord(&pHead,p);
		}
	} 


	pCur = pHead;
	while(pCur)
	{
		cout<<pCur->word<<"  "<<pCur->count<<endl;
		pCur=pCur->pNext;
	}

	end = time(NULL);
	printf("use time:%ld\n", end - start);

}
