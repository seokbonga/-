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
	else if (node->compare(newNode) < 0)	//만약 node의 string보다 크면
	{
		if (!node->getRight())	//만약 node의 오른쪽이 비었으면
			node->setRight(newNode);	//오른삽입
		else //안비었으면
			insertRecur(node->getRight(), newNode);//오른재귀
	}
	else //만약 node의 string보다 작으면
	{
		if (!node->getLeft())//만약 왼쪽 비었으면
			node->setLeft(newNode);//왼쪽삽입
		else//왼쪽에 뭔가있으면
			insertRecur(node->getLeft(), newNode);//왼쪽재귀
	}
}

void SrchRecordTree::remove(const char* key)//삭제함수
{
	if (isEmpty())
		return;

	BinRecordNode* parent = nullptr;
	BinRecordNode* node = root;
	while (node && node->compare(key) != 0) // 노드가 null 아니고 노드가 키랑 같이 않다면 node key의 노드를 찾을때까지
	{
		parent = node;
		node = (node->compare(key) < 0) ? node->getRight() : node->getLeft(); // 조건식 ? true일때 : false일때
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

	else if (node->getLeft() && node->getRight())//삭제대상이 좌우자식 모두보유
	{
		BinRecordNode* successorParent = node;
		BinRecordNode* successor = node->getRight();
		while (successor->getLeft())
		{
			successorParent = successor;
			successor = successor->getLeft();// 최소 Left를 찾아줌
		}
		if (successorParent->getLeft() == successor)
			successorParent->setLeft(successor->getRight());
		else
			successorParent->setRight(successor->getRight());

		node->copy(successor);
		node = successor;
	}
	else//만약 둘중 하나만 보유중일때
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