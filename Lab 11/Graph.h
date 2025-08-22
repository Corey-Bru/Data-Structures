#pragma once
#include<iostream>
#include "LinkedList.h"
using namespace std;
struct NodeGraph{
	char data;
	NodeGraph() {
		data = ' ';
	}
	NodeGraph(char Data) {
		data = Data;
	}
};
class Graph
{
private:
	static const int rooms = 20;
	NodeGraph arr[rooms];
	int numOfNodes = 0;
	int arrows = 3;
	int matrix[rooms][rooms];
	int rowLoc = 0;
	int colLoc = 0;
public:
	Graph(){
		for (int i = 0; i < rooms; i++) {
			for (int j = 0; j < rooms; j++) {
				matrix[i][j] = 0;
			}
		}
	}

	void AddEdge(int row, int col) {
		matrix[row][col] = 1;
	}

	void RemoveEdge(int row, int col) {
		matrix[row][col] = 0;
	}
	bool hasEdge(int row, int col) {
		return matrix[row][col] == 1;
	}
	void AddNode(NodeGraph node) {
		
		arr[numOfNodes] = node;
		numOfNodes++;
	}
	LinkedList<char> inEdges(NodeGraph node) {
		int count = 0;
		LinkedList<char> edge;
		for (int i = 0; i <= numOfNodes; i++) {
			if (node.data == arr[i].data) {
				break;
			}
			count++;
		}
		for (int i = 0; i < rooms; i++) {
			if (matrix[i][count] == 1) {
				edge.Insert(&arr[i].data);
			}
		}
		return edge;
	
	}
	 LinkedList<char> OutEdges(NodeGraph node) {
	 	int count = 0;
	 	LinkedList<char> edge;
	 	for (int i = 0; i <= numOfNodes; i++) {
	 		if (node.data == arr[i].data) {
	 			break;
	 		}
	 		count++;
	 	}
	 	for (int i = 0; i < rooms; i++) {
	 		if (matrix[count][i] == 1) {
	 			edge.Insert(&arr[i].data);
	 		}
	 	}
	 	return edge;
	 }

// char OutEdges(NodeGraph node) {
// 	int count = 0;
// 	char edge[rooms];
// 	for (int i = 0; i <= numOfNodes; i++) {
// 		if (node.data == arr[i].data) {
// 			break;
// 		}
// 		count++;
// 	}
// 	for (int i = 0; i < rooms; i++) {
// 		if (matrix[count][i] == 1) {
// 			//edge.Insert(&arr[i].data);
// 			edge[i] = arr[i].data;
// 		}
// 	}
// 	return edge;
// }

// LinkedList<char> OutEdges(NodeGraph node, LinkedList<char>) {
// 	int count = 0;
// 	LinkedList<char> edge;
// 	for (int i = 0; i <= numOfNodes; i++) {
// 		if (node.data == arr[i].data) {
// 			break;
// 		}
// 		count++;
// 	}
// 	for (int i = 0; i < rooms; i++) {
// 		if (matrix[count][i] == 1) {
// 			edge.Insert(&arr[i].data);
// 		}
// 	}
// 	return edge;
// }

	void printGraph() {
		for (int i = 0; i < rooms; i++) {
			for (int j = 0; j < rooms; j++) {
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
};

