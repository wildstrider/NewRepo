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

		// ���������� ���� � ���������
		void addNode(int id, int value);
		int findIdWithValue(int value);

		// ����� �� �����
		void display(int level);
	};

private:
	Node* root;
	int nodeCount;

public:
	BinaryTree();

	// ������ ��� ������ � �������
	void addNode(int value);
	int findIdWithValue(int value);

	// ������ ������ �� �����
	void display();
};

