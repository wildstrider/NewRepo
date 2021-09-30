#include "BinaryTree.h"

BinaryTree::Node::Node(int id, int value, Node* left, Node* right)
{
	this->id = id;
	this->value = value;
	this->left = left;
	this->right = right;
}

void BinaryTree::Node::addNode(int id, int value)
{
	if (value >= this->value) { // то добавляем узел вправо
		if (right == nullptr)
			right = new Node(id, value);
		else
			right->addNode(id, value);
	}
	else { // добавляем узел влево
		if (left == nullptr)
			left = new Node(id, value);
		else
			left->addNode(id, value);
	}
}

// поиск идентификатора узла с заданными значением
int BinaryTree::Node::findIdWithValue(int value)
{
	// шаг 1 <=> К <=> корень
	if (this->value == value)
		return id;

	// шаг 2 <=> Л <=> левое (посмотреть левое поддерево)
	int next_id;
	if (left != nullptr) {
		next_id = left->findIdWithValue(value);
		if (next_id != -1)
			return next_id;
	}
	else
		next_id = -1;

	// шаг 3 <=> П <=> правое (посмотреть правое поддерево)
	if (right != nullptr) {
		next_id = right->findIdWithValue(value);
		if (next_id != -1)
			return next_id;
	}
	else
		next_id = -1;
	return next_id;
}

void BinaryTree::Node::display(int level)
{
	// вывод узла, открывающаяся скобка
	for (int i = 0; i < level; i++)
		cout << '\t';
	cout << "(id = " << id << ", value = " << value << endl;

	// вывод правого поддерева
	if (right != nullptr)
		right->display(level + 1);
	else {
		for (int i = 0; i < level + 1; i++)
			cout << '\t';
		cout << "(nullptr)" << endl;
	}

	// вывод левого поддерева
	if (left != nullptr)
		left->display(level + 1);
	else {
		for (int i = 0; i < level + 1; i++)
			cout << '\t';
		cout << "(nullptr)" << endl;
	}

	// закрывающаяся скобка
	for (int i = 0; i < level; i++)
		cout << '\t';
	cout << ")" << endl;
}

BinaryTree::BinaryTree()
{
	root = nullptr;
	nodeCount = 0;
}

void BinaryTree::addNode(int value)
{
	if (root == nullptr)
		root = new Node(nodeCount++, value);
	else
		root->addNode(nodeCount++, value);
}

int BinaryTree::findIdWithValue(int value)
{
	if (root == nullptr)
		return -1;
	return root->findIdWithValue(value);
}

void BinaryTree::display()
{
	if (root == nullptr)
		cout << "empty tree" << endl;
	else
		root->display(0);
}
