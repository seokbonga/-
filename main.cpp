#include "Dictionary.h"
#include <fstream>
#include <conio.h>
#include <iostream>
using namespace std;
Dictionary* MyDictionary;
Dictionary* eng_kor = new Dictionary();
Dictionary* kor_eng = new Dictionary();
const char* Library = "Library.txt";

void Start()	//사전기능 시작
{
	int select;
	char word[100];
	while (true)
	{
		system("cls");	//화면지우기
		cout << "=============================================================================" << endl << endl;
		cout << "1. 사전검색" << endl;
		cout << "2. 사전출력" << endl;
		cout << "3. 단어추가" << endl;
		cout << "4. 단어삭제" << endl;
		cout << "5. 뒤로가기" << endl;
		cout << endl << "=============================================================================" << endl << endl;
		cin >> select;
		
		if (select == 1)	//사전검색
		{
			printf("검색할 단어를 입력해주세요\n");
			cin >> word;
			MyDictionary->searchWord(word);	//검색함수
		}
		else if (select == 2)	//사전출력
		{
			MyDictionary->printAllWords();	//Inorder방식 출력함수 ( 사전순서로 출력 )
		}
		else if (select == 3)	//단어추가
		{
			char word[100];
			char meaning[100];
			cout << "단어를 입력해주세요" << endl;
			cin >> word;
			cout << "뜻을 입력해주세요" << endl;
			cin >> meaning;
			ofstream output;
			output.open(Library);
			MyDictionary->insert(new BinRecordNode(word, meaning));	//Tree에 추가			
			if (MyDictionary == eng_kor)
				MyDictionary->writeAllWords(&output, true);	// text File을 다시 Write해줌 -> text파일에도 단어 추가됨
			else
				MyDictionary->writeAllWords(&output, false);
			output.close();
		}
		else if (select == 4)	//단어삭제
		{
			char word[100];
			cout << "삭제할 단어를 입력해주세요" << endl;
			cin >> word;
			ofstream output;
			output.open(Library);
			MyDictionary->remove(word);	//Tree에서 삭제
			if (MyDictionary == eng_kor)
				MyDictionary->writeAllWords(&output, true);	// text File을 다시 Write해줌 -> text파일에도 단어 추가됨
			else
				MyDictionary->writeAllWords(&output, false);
			output.close();
		}
		else if (select == 5) break;

		else {
			cout << "잘못된입력입니다." << endl;
		}
		cout << "[ENTER]" << endl;
		_getch();
	}
}

int main()
{
	ifstream input;
	char word[100];
	char meaning[100];
	input.open(Library);
	if (!input.is_open()) // 파일이 없을경우 강제종료
	{
		cout << "Library.txt 파일을 찾을 수 없습니다." << endl;
		exit(-1);
	}
	while (!input.eof())
	{
		input >> word;
		input >> meaning;
		eng_kor->insert(new BinRecordNode(word, meaning));	//트리 구축
		kor_eng->insert(new BinRecordNode(meaning, word));
	}
	input.close();
	int select;
	while (1)
	{
		system("cls");
		cout << "=============================================================================" << endl << endl;
		cout << "1. 영한사전" << endl;
		cout << "2. 한영사전" << endl;
		cout << "3. 종료" << endl << endl;
		cout << "=============================================================================" << endl << endl;
		cin >> select;
		if (select == 1 || select == 2) {
			select == 1 ? MyDictionary = eng_kor : MyDictionary = kor_eng;	//1이면 eng_kor , 2이면 kor_eng
			Start();
			continue;
		}
		else if (select == 3)break;
		else
		{
			cout << "잘못된 입력입니다" << endl;
		}
		cout << "[ENTER]" << endl;
		_getch();
	}
}