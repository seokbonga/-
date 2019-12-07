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

void RecordTree::inorder(BinRecordNode* node)	//inorder �������� ��ȸ�Ͽ� display
{
	if (node)
	{
		inorder(node->getLeft());	//��	
		node->display();	//���
		inorder(node->getRight());	//��
	}
}

void RecordTree::Writeinorder(BinRecordNode* node, ofstream* output, bool eng)	//Inorder �������� ���Ͽ� ����
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