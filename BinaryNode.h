#pragma once

#ifndef __BINARYNODE_H__
#define __BINARYNODE_H__

template <typename T>
class BinaryNode {
public:
	BinaryNode()
		: data(), left(nullptr), right(nullptr) { }
	BinaryNode(T data, BinaryNode* left, BinaryNode* right)
		: data(data), left(left), right(right) { }

	void		setData(T item) { data = item; }
	void		setLeft(BinaryNode* node) { left = node; }
	void		setRight(BinaryNode* node) { right = node; }
	T			getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool		isLeaf() { return !left && !right; }
	void		inOrder();

	BinaryNode* search(T key);
	void		insert(BinaryNode* node);
private:
	T			data;
	BinaryNode* left;
	BinaryNode* right;
};
#endif

template<typename T>
void BinaryNode<T>::inOrder()	//중위순회
{
	if (left) left->inOrder();
	printf(" [%c] ", data);
	if (right) right->inOrder();
}

template<typename T>
inline BinaryNode<T>* BinaryNode<T>::search(T key)	//검색함수
{
	if (key == data)
		return this;
	else if (!left && key < data)	//만약 key값이 현재 노드의 data보다 작으면
		return left->search(key);	//왼쪽검색
	else if (!right && key > data)	//만약 key값이 현재 노드의 data보다 크면
		return right->search(key);	//오른쪽검색
	else
		return nullptr;
}

template<typename T>
inline void BinaryNode<T>::insert(BinaryNode* node)	//삽입함수
{
	if (node)
	{
		if (data == node->getData())
			return;
		else if (data < node->getData())
		{
			if (!right)
				right = node;
			else
				right->insert(node);
		}
		else
		{
			if (!left)
				left = node;
			else
				left->insert(node);
		}
	}
}