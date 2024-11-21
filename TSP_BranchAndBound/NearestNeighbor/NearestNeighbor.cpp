#include "NearestNeighbor.h"
#include <string>
#include <iostream>

int NearestNeighbor::getShortestPathValue(InputData data)
{
	bool* visited = new bool[data.numberOfCities];
	int startingIndex, currentVertexIndex, visitedVertices, shortestEdge, shortestEdgeVertex, cost, minimumCost;
	minimumCost = INT_MAX;
	for (int a = 0; a < data.numberOfCities; a++) {
		for (int i = 0; i < data.numberOfCities; i++) visited[i] = false;
		visitedVertices = 0;
		cost = 0;
		startingIndex = a;
		currentVertexIndex = startingIndex;
		visited[currentVertexIndex] = true;
		visitedVertices++;

		while (visitedVertices < data.numberOfCities) {
			shortestEdge = INT_MAX;
			for (int j = 0; j < data.numberOfCities; j++) {
				if (j != currentVertexIndex && visited[j] == false && data.costMatrix[currentVertexIndex][j] < shortestEdge) {
					shortestEdge = data.costMatrix[currentVertexIndex][j];
					shortestEdgeVertex = j;
				}
			}
			cost += shortestEdge;
			visited[shortestEdgeVertex] = true;
			currentVertexIndex = shortestEdgeVertex;
			visitedVertices++;
		}
		cost += data.costMatrix[currentVertexIndex][startingIndex];
		if (cost < minimumCost) minimumCost = cost;
	}
	delete[] visited;
	return minimumCost;
}

