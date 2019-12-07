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
void BinaryNode<T>::inOrder()	//������ȸ
{
	if (left) left->inOrder();
	printf(" [%c] ", data);
	if (right) right->inOrder();
}

template<typename T>
inline BinaryNode<T>* BinaryNode<T>::search(T key)	//�˻��Լ�
{
	if (key == data)
		return this;
	else if (!left && key < data)	//���� key���� ���� ����� data���� ������
		return left->search(key);	//���ʰ˻�
	else if (!right && key > data)	//���� key���� ���� ����� data���� ũ��
		return right->search(key);	//�����ʰ˻�
	else
		return nullptr;
}

template<typename T>
inline void BinaryNode<T>::insert(BinaryNode* node)	//�����Լ�
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