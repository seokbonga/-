#pragma once

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include "SrchRecordTree.h"

struct Dictionary : public SrchRecordTree {
	Dictionary() = default;

	void	printAllWords();
	void	writeAllWords(ofstream* output, bool eng);
	void	searchWord(const char* word);
};

void Dictionary::printAllWords()	//�����������
{
	if (!isEmpty()) inorder(root);
}
void Dictionary::writeAllWords(ofstream* output, bool eng)	//�������� txt write
{
	if (!isEmpty()) Writeinorder(root, output, eng);
}

void Dictionary::searchWord(const char* word)	//�ܾ �˻��ϴ� �Լ�
{
	BinRecordNode* node = search(word);
	if (node)
	{
		node->display();
	}
	else
		std::cout << " >> ��ϵ��� ���� �ܾ� : " << word << std::endl;
}

#endif