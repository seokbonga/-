#pragma once

#ifndef __RECORDTREE_H__
#define __RECORDTREE_H__

#include "BinRecordNode.h"
#include<iostream>
using namespace std;
#include <fstream>

class RecordTree {
public:
	RecordTree()
		: root(nullptr) { }
	bool	isEmpty() { return !root; }
	void	inorder(BinRecordNode* node);
	void	Writeinorder(BinRecordNode* node, ofstream* output, bool eng);
protected:
	BinRecordNode * root;
};

void RecordTree::inorder(BinRecordNode* node)	//inorder 형식으로 순회하여 display
{
	if (node)
	{
		inorder(node->getLeft());	//좌	
		node->display();	//노드
		inorder(node->getRight());	//우
	}
}

void RecordTree::Writeinorder(BinRecordNode* node, ofstream* output, bool eng)	//Inorder 형식으로 파일에 쓰기
{
	if (node)
	{
		Writeinorder(node->getLeft(), output, eng);
		if (eng == true)*output << node->getWord() << "	" << node->getMeaning() << endl;
		else
			*output << node->getMeaning() << "	" << node->getWord() << endl;
		Writeinorder(node->getRight(), output, eng);
	}
}
#endif