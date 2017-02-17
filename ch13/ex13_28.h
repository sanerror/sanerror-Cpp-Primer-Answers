// not a good example. I just have done some small works. +1s
#ifndef EX13_28_H
#define EX13_28_H

#include <iostream>

class TreeNode{
private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
public:
	TreeNode(std::string value_ = 0, int count_ = 0,
		TreeNode *left_ = nullptr, TreeNode *right_ = nullptr) :
		value(value_), count(count_), left(left_), right(right_) {}
	TreeNode(const TreeNode& a) : value(a.value), count(a.count),
		left(new TreeNode(*a.left)), right(new TreeNode(*a.right)) {}
	TreeNode& operator=(const TreeNode&);
	~TreeNode();
};

TreeNode& TreeNode::operator=(const TreeNode& a) {
	value = a.value;
	count = a.count;
	left = new TreeNode(*a.left);
	right = new TreeNode(*a.right);
	return *this;
}

TreeNode::~TreeNode() {
	// should delete it recursively.. it's a simple sample. it still have
	// a lot of functions to be define.
	delete left;
	delete right;
}

class BinStrTree {
private:
	TreeNode *root;
public:
	BinStrTree(TreeNode *a = new TreeNode()) : root(a) {}
	BinStrTree(const BinStrTree& a) { *root = *a.root; }
	BinStrTree& operator=(const BinStrTree& a) { *root = *a.root; }
	~BinStrTree() { delete root; }
};

#endif