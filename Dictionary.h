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

void Dictionary::printAllWords()	//사전순서출력
{
	if (!isEmpty()) inorder(root);
}
void Dictionary::writeAllWords(ofstream* output, bool eng)	//사전순서 txt write
{
	if (!isEmpty()) Writeinorder(root, output, eng);
}

void Dictionary::searchWord(const char* word)	//단어를 검색하는 함수
{
	BinRecordNode* node = search(word);
	if (node)
	{
		node->display();
	}
	else
		std::cout << " >> 등록되지 않은 단어 : " << word << std::endl;
}

#endif