#ifndef NEARESTNEIGHBOR_HPP
#define NEARESTNEIGHBOR_HPP
#include "../DataManagement/InputData.hpp"
#include <vector>

class NearestNeighbor
{
public:
	static int getShortestPathValue(InputData data);
	static int getShortestPathValue(std::vector<std::vector<int>> matrix);
};

#endif
