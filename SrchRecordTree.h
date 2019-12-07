#pragma once

#ifndef __SRCHRECORDTREE_H__
#define __SRCHRECORDTREE_H__

#include "RecordTree.h"

struct SrchRecordTree : public RecordTree {
	SrchRecordTree() = default;

	BinRecordNode* search(const char* key) { return searchRecur(root, key); }
	BinRecordNode* searchRecur(BinRecordNode* node, const char* key);

	void	insert(BinRecordNode* node);
	void	insertRecur(BinRecordNode* node, BinRecordNode* newNode);
	void	remove(const char* data);
	void	remove(BinRecordNode* parent, BinRecordNode* node);
};

BinRecordNode* SrchRecordTree::searchRecur(BinRecordNode* node, const char* key)
{
	if (!node)
		return nullptr;
	if (!node->compare(key))
		return node;
	else if (node->compare(key) < 0)
		return searchRecur(node->getRight(), key);
	else
		return searchRecur(node->getLeft(), key);
}

void SrchRecordTree::insert(BinRecordNode* node)
{
	if (!node) return;
	if (isEmpty()) root = node;
	else insertRecur(root, node);
}

void SrchRecordTree::insertRecur(BinRecordNode* node, BinRecordNode* newNode)
{
	if (!node->compare(newNode))
		return;
	else if (node->compare(newNode) < 0)	//���� node�� string���� ũ��
	{
		if (!node->getRight())	//���� node�� �������� �������
			node->setRight(newNode);	//��������
		else //�Ⱥ������
			insertRecur(node->getRight(), newNode);//�������
	}
	else //���� node�� string���� ������
	{
		if (!node->getLeft())//���� ���� �������
			node->setLeft(newNode);//���ʻ���
		else//���ʿ� ����������
			insertRecur(node->getLeft(), newNode);//�������
	}
}

void SrchRecordTree::remove(const char* key)//�����Լ�
{
	if (isEmpty())
		return;

	BinRecordNode* parent = nullptr;
	BinRecordNode* node = root;
	while (node && node->compare(key) != 0) // ��尡 null �ƴϰ� ��尡 Ű�� ���� �ʴٸ� node key�� ��带 ã��������
	{
		parent = node;
		node = (node->compare(key) < 0) ? node->getRight() : node->getLeft(); // ���ǽ� ? true�϶� : false�϶�
	}
	if (node)
		remove(parent, node);
}

void SrchRecordTree::remove(BinRecordNode* parent, BinRecordNode* node)
{
	if (node->isLeaf())
	{
		if (node == root)
			root = nullptr;
		else
		{
			if (parent->getLeft() == node)
				parent->setLeft(nullptr);
			else
				parent->setRight(nullptr);
		}
	}

	else if (node->getLeft() && node->getRight())//��������� �¿��ڽ� ��κ���
	{
		BinRecordNode* successorParent = node;
		BinRecordNode* successor = node->getRight();
		while (successor->getLeft())
		{
			successorParent = successor;
			successor = successor->getLeft();// �ּ� Left�� ã����
		}
		if (successorParent->getLeft() == successor)
			successorParent->setLeft(successor->getRight());
		else
			successorParent->setRight(successor->getRight());

		node->copy(successor);
		node = successor;
	}
	else//���� ���� �ϳ��� �������϶�
	{
		BinRecordNode* child = node->getLeft() ? node->getLeft() : node->getRight();
		if (node == root)
			root = child;
		else if (parent->getLeft() == node)
			parent->setLeft(child);
		else
			parent->setRight(child);
	}
	delete node;
}
#endif