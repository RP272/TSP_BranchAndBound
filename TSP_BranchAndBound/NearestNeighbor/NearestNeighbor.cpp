#include "NearestNeighbor.h"
#include "../DataManagement/RandomIntegerGenerator.hpp"
#include <string>
#include <iostream>

int NearestNeighbor::getShortestPathValue(InputData data)
{
	RandomIntegerGenerator rng(0, data.numberOfCities - 1);
	bool* visited = new bool[data.numberOfCities];
	for (int i = 0; i < data.numberOfCities; i++) visited[i] = false;
	int startingIndex, currentVertexIndex, visitedVertices, shortestEdge, shortestEdgeVertex, cost;
	visitedVertices = 0;
	cost = 0;
	startingIndex = rng.generate();
	currentVertexIndex = startingIndex;
	visited[currentVertexIndex] = true;
	visitedVertices++;

	while (visitedVertices < data.numberOfCities) {
		shortestEdge = INT_MAX;
		for (int j = 0; j < data.numberOfCities; j++) {
			if (j != currentVertexIndex && visited[j] == false && data.costMatrix[currentVertexIndex][j] < shortestEdge) {
				shortestEdge = data.costMatrix[currentVertexIndex][j];
				shortestEdgeVertex = j;
;			}
		}
		cost += shortestEdge;
		visited[shortestEdgeVertex] = true;
		currentVertexIndex = shortestEdgeVertex;
		visitedVertices++;
	}
	cost += data.costMatrix[currentVertexIndex][startingIndex];
	delete[] visited;
	return cost;
}

int NearestNeighbor::getShortestPathValue(std::vector<std::vector<int>> matrix)
{
	bool* visited = new bool[matrix.size()];
	for (int i = 0; i < matrix.size(); i++) visited[i] = false;
	int startingIndex, currentVertexIndex, visitedVertices, shortestEdge, shortestEdgeVertex, cost;
	visitedVertices = 0;
	cost = 0;
	startingIndex = 0;
	currentVertexIndex = startingIndex;
	visited[currentVertexIndex] = true;
	visitedVertices++;

	while (visitedVertices < matrix.size()) {
		shortestEdge = INT_MAX;
		for (int j = 0; j < matrix.size(); j++) {
			if (j != currentVertexIndex && visited[j] == false && matrix.at(currentVertexIndex).at(j) < shortestEdge) {
				shortestEdge = matrix.at(currentVertexIndex).at(j);
				shortestEdgeVertex = j;
				;
			}
		}
		cost += shortestEdge;
		visited[shortestEdgeVertex] = true;
		currentVertexIndex = shortestEdgeVertex;
		visitedVertices++;
	}
	cost += matrix.at(currentVertexIndex).at(startingIndex);
	delete[] visited;
	return cost;
}

