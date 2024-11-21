#include "BFS.h"
#include <queue>
#include <climits>
#include <iostream>

#define INF INT_MAX

class Node {
public:
	int lowerBound;
	int* items;
	int** matrix;
	int itemsLen;
	int matrixLen;

	Node(int lowerBound, int cityNumber, int* items, int itemsLen, int** matrix, int matrixLen) {
		this->lowerBound = lowerBound;
		this->matrixLen = matrixLen;
		this->itemsLen = itemsLen + 1;
		this->items = new int[itemsLen+1];
		for (int i = 0; i < itemsLen; i++) {
			this->items[i] = items[i];
		}
		this->items[itemsLen] = cityNumber;

		this->matrix = new int*[matrixLen];
		for (int i = 0; i < matrixLen; i++) {
			this->matrix[i] = new int[matrixLen];
			for (int j = 0; j < matrixLen; j++) {
				this->matrix[i][j] = matrix[i][j];
			}
		}
	}

	int bound() {
		int lastCity, secondLastCity, edgeValue;
		if (this->itemsLen > 1) {
			// not root
			
			// take the last edge from the path. remember cost from the matrix.
			lastCity = this->items[this->itemsLen - 1];
			secondLastCity = this->items[this->itemsLen - 2];
			edgeValue = this->matrix[secondLastCity][lastCity];

			// update the matrix. change every value in secondLastCity row to -1. change every value in lastCity column to -1.
			for (int i = 0; i < this->matrixLen; i++) {
				this->matrix[secondLastCity][i] = -1;
				this->matrix[i][lastCity] = -1;
			}

			// update the edge (last node from the path -> beginning) to -1
			this->matrix[lastCity][0] = -1;

			// do matrix reduction.
			int rowMinimum, columnMinimum, val;
			for (int i = 0; i < this->matrixLen; i++) {
				// find minimum value in i-th row.
				rowMinimum = INF;
				for (int j = 0; j < this->matrixLen; j++) {
					val = this->matrix[i][j];
					if (val != -1 && val < rowMinimum) rowMinimum = val;
				}
				// subtract that minimum from each value in i-th row.
				if (rowMinimum != 0 && rowMinimum != INF) {
					for (int j = 0; j < this->matrixLen; j++) {
						if (this->matrix[i][j] != -1) this->matrix[i][j] -= rowMinimum;
					}
					lowerBound += rowMinimum;
				}
			}

			for (int i = 0; i < this->matrixLen; i++) {
				// find minimum value in i-th column.
				columnMinimum = INF;
				for (int j = 0; j < this->matrixLen; j++) {
					val = this->matrix[j][i];
					if (val != -1 && val < columnMinimum) columnMinimum = val;
				}
				if (columnMinimum != 0 && columnMinimum != INF) {
					// subtract that minimum from each value in i-th column.
					for (int j = 0; j < this->matrixLen; j++) {
						if (this->matrix[j][i] != -1) this->matrix[j][i] -= columnMinimum;
					}
					lowerBound += columnMinimum;
				}
			}
			// after matrix reduction, add edgeValue to the total lowerBound cost.
			lowerBound += edgeValue;

		} else {
			// root.
			// do matrix reduction.
			int rowMinimum, columnMinimum, val;
			for (int i = 0; i < this->matrixLen; i++) {
				// find minimum value in i-th row.
				rowMinimum = INF;
				for (int j = 0; j < this->matrixLen; j++) {
					val = this->matrix[i][j];
					if (val != -1 && val < rowMinimum) rowMinimum = val;
				}
				// subtract that minimum from each value in i-th row.
				if (rowMinimum != 0) {
					for (int j = 0; j < this->matrixLen; j++) {
						if (this->matrix[i][j] != -1) this->matrix[i][j] -= rowMinimum;
					}
					lowerBound += rowMinimum;
				}
			}

			for (int i = 0; i < this->matrixLen; i++) {
				// find minimum value in i-th column.
				columnMinimum = INF;
				for (int j = 0; j < this->matrixLen; j++) {
					val = this->matrix[j][i];
					if (val != -1 && val < columnMinimum) columnMinimum = val;
				}
				if (columnMinimum != 0) {
					// subtract that minimum from each value in i-th column.
					for (int j = 0; j < this->matrixLen; j++) {
						if (this->matrix[j][i] != -1) this->matrix[j][i] -= columnMinimum;
					}
					lowerBound += columnMinimum;
				}
			}
		}
		return lowerBound;
	}
};

void BFS::Solve(int numberOfCities, int** matrix, int initialBest) {
	std::queue<Node*> q;
	Node* root = new Node(0, 0, {}, 0, matrix, numberOfCities);
	int val = root->bound();
	q.push(root);
	int best = initialBest;
	Node* bestNode = nullptr;
	Node* v;
	Node* u;
	int cost, bound;
	bool iFound;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		// generate children nodes for v node. these are cities, which have not been visited yet.
		for (int i = 0; i < numberOfCities; i++) {
			iFound = false;
			for (int j = 0; j < v->itemsLen; j++) {
				if (i == v->items[j]) {
					iFound = true;
					break;
				};
			}
			if (iFound == false) {
				// i is a city which hasn't been visited yet. create a new node for it.
				u = new Node(v->lowerBound, i, v->items, v->itemsLen, v->matrix, v->matrixLen);
				// check if u is a leaf node.
				if (u->itemsLen == numberOfCities) {
					// calculate leaf node cost. update best if cost is lower than it.
					cost = u->bound();
					if (cost < best) {
						best = cost;
						bestNode = u;
					}
				}
				else {
					// if u is not a leaf node, calculate it's bound. if it is smaller than best, add u to queue.
					bound = u->bound();
					if (bound < best) {
						q.push(u);
					}
				}
			}
		}
		delete[] v->items;
		for (int i = 0; i < v->matrixLen; i++) {
			delete[] v->matrix[i];
		}
		delete[] v->matrix;
		delete v;
	}
	if (bestNode != nullptr) {
		std::cout << std::endl << "PATH" << std::endl;
		for (int i = 0; i < bestNode->itemsLen; i++) {
			std::cout << bestNode->items[i]+1 << "->";
		}
		std::cout << "1 . koszt: " << (bestNode->lowerBound) << std::endl;
	}
}
