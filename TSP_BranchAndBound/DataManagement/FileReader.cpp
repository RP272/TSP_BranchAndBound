#include "FileReader.hpp"
#include <sstream>
#include <fstream>

ConfigurationData FileReader::readConfigurationDataFile()
{
    ConfigurationData result = { 0 };
    std::ifstream configurationFile("configuration_file.txt");
    if (configurationFile.good()) {
        std::string line;
        std::getline(configurationFile, line);
        result.readOrGenerateData = std::stoi(line.substr(line.find(':') + 1));
        std::getline(configurationFile, line);
        result.whichAlgorithm = std::stoi(line.substr(line.find(':') + 1));
        std::getline(configurationFile, line);
        result.quantityOfCities = std::stoi(line.substr(line.find(':') + 1));
        std::getline(configurationFile, line);
        result.quantityOfMeasurements = std::stoi(line.substr(line.find(':') + 1));
        std::getline(configurationFile, line);
        result.asymmetricOrSymmetric = std::stoi(line.substr(line.find(':') + 1));
        std::getline(configurationFile, line);
        result.progressBarSwitch = std::stoi(line.substr(line.find(':') + 1));
        std::getline(configurationFile, line);
        result.numberOfIterationsForRandom = std::stoi(line.substr(line.find(':') + 1));
    }
    configurationFile.close();
    return result;
}

InputData FileReader::readInputDataFile()
{
    InputData result = { 0 };
    std::ifstream inputFile("input_file.txt");
    if (inputFile.good()) {
        std::string line;
        // First line has to contain number of cities
        std::getline(inputFile, line);
        std::istringstream data(line);
        data >> result.numberOfCities;

        result.costMatrix = new int*[result.numberOfCities];
        for (int i = 0; i < result.numberOfCities; i++)
        {
            result.costMatrix[i] = new int[result.numberOfCities];
            if (std::getline(inputFile, line)) {
                std::istringstream row(line);
                for (int j = 0; j < result.numberOfCities; j++)
                {
                    row >> result.costMatrix[i][j];
                }
            }
        }
    }
    inputFile.close();
    return result;
};