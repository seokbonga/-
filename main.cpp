#include "Dictionary.h"
#include <fstream>
#include <conio.h>
#include <iostream>
using namespace std;
Dictionary* MyDictionary;
Dictionary* eng_kor = new Dictionary();
Dictionary* kor_eng = new Dictionary();
const char* Library = "Library.txt";

void Start()	//������� ����
{
	int select;
	char word[100];
	while (true)
	{
		system("cls");	//ȭ�������
		cout << "=============================================================================" << endl << endl;
		cout << "1. �����˻�" << endl;
		cout << "2. �������" << endl;
		cout << "3. �ܾ��߰�" << endl;
		cout << "4. �ܾ����" << endl;
		cout << "5. �ڷΰ���" << endl;
		cout << endl << "=============================================================================" << endl << endl;
		cin >> select;
		
		if (select == 1)	//�����˻�
		{
			printf("�˻��� �ܾ �Է����ּ���\n");
			cin >> word;
			MyDictionary->searchWord(word);	//�˻��Լ�
		}
		else if (select == 2)	//�������
		{
			MyDictionary->printAllWords();	//Inorder��� ����Լ� ( ���������� ��� )
		}
		else if (select == 3)	//�ܾ��߰�
		{
			char word[100];
			char meaning[100];
			cout << "�ܾ �Է����ּ���" << endl;
			cin >> word;
			cout << "���� �Է����ּ���" << endl;
			cin >> meaning;
			ofstream output;
			output.open(Library);
			MyDictionary->insert(new BinRecordNode(word, meaning));	//Tree�� �߰�			
			if (MyDictionary == eng_kor)
				MyDictionary->writeAllWords(&output, true);	// text File�� �ٽ� Write���� -> text���Ͽ��� �ܾ� �߰���
			else
				MyDictionary->writeAllWords(&output, false);
			output.close();
		}
		else if (select == 4)	//�ܾ����
		{
			char word[100];
			cout << "������ �ܾ �Է����ּ���" << endl;
			cin >> word;
			ofstream output;
			output.open(Library);
			MyDictionary->remove(word);	//Tree���� ����
			if (MyDictionary == eng_kor)
				MyDictionary->writeAllWords(&output, true);	// text File�� �ٽ� Write���� -> text���Ͽ��� �ܾ� �߰���
			else
				MyDictionary->writeAllWords(&output, false);
			output.close();
		}
		else if (select == 5) break;

		else {
			cout << "�߸����Է��Դϴ�." << endl;
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
	if (!input.is_open()) // ������ ������� ��������
	{
		cout << "Library.txt ������ ã�� �� �����ϴ�." << endl;
		exit(-1);
	}
	while (!input.eof())
	{
		input >> word;
		input >> meaning;
		eng_kor->insert(new BinRecordNode(word, meaning));	//Ʈ�� ����
		kor_eng->insert(new BinRecordNode(meaning, word));
	}
	input.close();
	int select;
	while (1)
	{
		system("cls");
		cout << "=============================================================================" << endl << endl;
		cout << "1. ���ѻ���" << endl;
		cout << "2. �ѿ�����" << endl;
		cout << "3. ����" << endl << endl;
		cout << "=============================================================================" << endl << endl;
		cin >> select;
		if (select == 1 || select == 2) {
			select == 1 ? MyDictionary = eng_kor : MyDictionary = kor_eng;	//1�̸� eng_kor , 2�̸� kor_eng
			Start();
			continue;
		}
		else if (select == 3)break;
		else
		{
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
		cout << "[ENTER]" << endl;
		_getch();
	}
}