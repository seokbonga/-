#pragma once

#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include "BinaryNode.h"

template <typename T>
class BinaryTree {
public:
	BinaryTree()
		: root(nullptr) { }

	void			setRoot(BinaryNode<T>* node) { root = node; }
	BinaryNode<T>* getRoot() { return root; }
	bool			isEmpty() { return !root; }
	void			inOrder() { printf("\n  inorder: "); if (!isEmpty()) root->inOrder(); }
	void			preOrder() { printf("\n  preorder: "); if (!isEmpty()) root->preOrder(); }
	void			postOrder() { printf("\n  postorder: "); if (!isEmpty()) root->postOrder(); }

protected:
	BinaryNode<T>* root;
};

#endif