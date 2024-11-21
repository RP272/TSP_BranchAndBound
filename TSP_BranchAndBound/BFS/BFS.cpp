#include "BFS.h"
#include <queue>
#include <climits>
#include <iostream>

#define INF INT_MAX

class Node {
public:
	int lowerBound;
	std::vector<int> items;
	std::vector<std::vector<int>> matrix;

	Node(int lowerBound, int cityNumber, std::vector<int> items, std::vector<std::vector<int>> matrix) {
		this->lowerBound = lowerBound;
		this->items = items;
		this->items.push_back(cityNumber);
		this->matrix = matrix;
	}

	int bound() {
		int lastCity, secondLastCity, edgeValue;
		if (this->items.size() > 1) {
			// not root
			
			// take the last edge from the path. remember cost from the matrix.
			lastCity = this->items.at(this->items.size() - 1);
			secondLastCity = this->items.at(this->items.size() - 2);
			edgeValue = this->matrix.at(secondLastCity).at(lastCity);

			// update the matrix. change every value in secondLastCity row to -1. change every value in lastCity column to -1.
			for (int i = 0; i < this->matrix.size(); i++) {
				this->matrix.at(secondLastCity).at(i) = -1;
				this->matrix.at(i).at(lastCity) = -1;
			}

			// update the edge (last node from the path -> beginning) to -1
			this->matrix.at(lastCity).at(0) = -1;

			// do matrix reduction.
			int rowMinimum, columnMinimum, val;
			for (int i = 0; i < this->matrix.size(); i++) {
				// find minimum value in i-th row.
				rowMinimum = INF;
				for (int j = 0; j < this->matrix.at(i).size(); j++) {
					val = this->matrix.at(i).at(j);
					if (val != -1 && val < rowMinimum) rowMinimum = val;
				}
				// subtract that minimum from each value in i-th row.
				if (rowMinimum != 0 && rowMinimum != INF) {
					for (int j = 0; j < this->matrix.at(i).size(); j++) {
						if (this->matrix.at(i).at(j) != -1) this->matrix.at(i).at(j) -= rowMinimum;
					}
					lowerBound += rowMinimum;
				}

			}

			for (int i = 0; i < this->matrix.size(); i++) {
				// find minimum value in i-th column.
				columnMinimum = INF;
				for (int j = 0; j < this->matrix.at(i).size(); j++) {
					val = this->matrix.at(j).at(i);
					if (val != -1 && val < columnMinimum) columnMinimum = val;
				}
				if (columnMinimum != 0 && columnMinimum != INF) {
					// subtract that minimum from each value in i-th column.
					for (int j = 0; j < this->matrix.at(i).size(); j++) {
						if (this->matrix.at(j).at(i) != -1) this->matrix.at(j).at(i) -= columnMinimum;
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
			for (int i = 0; i < this->matrix.size(); i++) {
				// find minimum value in i-th row.
				rowMinimum = INF;
				for (int j = 0; j < this->matrix.at(i).size(); j++) {
					val = this->matrix.at(i).at(j);
					if (val != -1 && val < rowMinimum) rowMinimum = val;
				}
				// subtract that minimum from each value in i-th row.
				if (rowMinimum != 0) {
					for (int j = 0; j < this->matrix.at(i).size(); j++) {
						if (this->matrix.at(i).at(j) != -1) this->matrix.at(i).at(j) -= rowMinimum;
					}
					lowerBound += rowMinimum;
				}
				
			}

			for (int i = 0; i < this->matrix.size(); i++) {
				// find minimum value in i-th column.
				columnMinimum = INF;
				for (int j = 0; j < this->matrix.at(i).size(); j++) {
					val = this->matrix.at(j).at(i);
					if (val != -1 && val < columnMinimum) columnMinimum = val;
				}
				if (columnMinimum != 0) {
					// subtract that minimum from each value in i-th column.
					for (int j = 0; j < this->matrix.at(i).size(); j++) {
						if (this->matrix.at(j).at(i) != -1) this->matrix.at(j).at(i) -= columnMinimum;
					}
					lowerBound += columnMinimum;
				}
			}
		}
		return lowerBound;
	}

	/*int value() {
		int cost = 0;
		return cost;
		
	}*/
};

void BFS::Solve(int numberOfCities, std::vector<std::vector<int>> matrix, int initialBest) {
	std::queue<Node*> q;

	Node* root = new Node(0, 0, {}, matrix);
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
			for (int j = 0; j < v->items.size(); j++) {
				if (i == v->items.at(j)) {
					iFound = true;
					break;
				};
			}
			if (iFound == false) {
				// i is a city which hasn't been visited yet. create a new node for it.
				u = new Node(v->lowerBound, i, v->items, v->matrix);
				// check if u is a leaf node.
				if (u->items.size() == numberOfCities) {
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
	
		delete v;
	}
	if (bestNode != nullptr) {
		std::cout << std::endl << "PATH" << std::endl;
		for (int i = 0; i < bestNode->items.size(); i++) {
			std::cout << bestNode->items.at(i)+1 << "->";
		}
		std::cout << "1 . koszt: " << (bestNode->lowerBound) << std::endl;
	}
}
