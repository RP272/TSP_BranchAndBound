#include "InputDataGenerator.hpp"
#include "RandomIntegerGenerator.hpp"

InputData InputDataGenerator::generateInputData(ConfigurationData config)
{
	InputData result = { 0 };
    RandomIntegerGenerator rng(1, 100);
    int randomWeight;
	result.numberOfCities = config.quantityOfCities;
    result.costMatrix = new int* [result.numberOfCities];
    for (int i = 0; i < result.numberOfCities; i++)
    {
        result.costMatrix[i] = new int[result.numberOfCities];
    }
    for (int i = 0; i < result.numberOfCities; i++)
    {
        for (int j = 0; j < result.numberOfCities; j++) {
            if (j == i) {
                result.costMatrix[i][j] = -1;
                continue;
            }
            else {
                randomWeight = rng.generate();
                result.costMatrix[i][j] = randomWeight;
                if (config.asymmetricOrSymmetric == 0) result.costMatrix[j][i] = randomWeight;
            }
        }
    }

	return result;
}
