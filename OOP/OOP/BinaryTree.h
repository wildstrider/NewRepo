#pragma once

#include <iostream>
using namespace std;

class BinaryTree
{
private:
	class Node {
	private:
		int id;
		int value;
		Node* left;
		Node* right;

	public:
		Node(int id, int value, Node* left, Node* right);
		Node(int id, int value) : Node(id, value, nullptr, nullptr){}

		// добавление узла к поддереву
		void addNode(int id, int value);
		int findIdWithValue(int value);

		// вывод на экран
		void display(int level);
	};

private:
	Node* root;
	int nodeCount;

public:
	BinaryTree();

	// методы для работы с деревом
	void addNode(int value);
	int findIdWithValue(int value);

	// методы вывода на экран
	void display();
};

