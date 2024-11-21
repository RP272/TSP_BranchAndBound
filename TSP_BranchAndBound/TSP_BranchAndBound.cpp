// TSP_BranchAndBound.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BFS/BFS.h"
#include "DataManagement/ConfigurationData.hpp"
#include "DataManagement/FileReader.hpp"
#include <vector>

int main()
{
    ConfigurationData configurationData = FileReader::readConfigurationDataFile();
    if (configurationData.readOrGenerateData == 0) {
        // Read data from input_file.txt.
        InputData inputData = FileReader::readInputDataFile();
        int nnValue = NearestNeighbor::getShortestPathValue(inputData);

        BFS::Solve(inputData.numberOfCities, inputData.costMatrix, nnValue);

        //if (configurationData.whichAlgorithm == 0) {
        //    // Bruteforce
        //    std::cout << "Przeglad zupelny" << std::endl;
        //    std::cout << "Rozmiar aktualnie analizowanych instancji: " << inputData.numberOfCities << " miast" << std::endl;
        //    auto BFt1 = std::chrono::high_resolution_clock::now();
        //    minimumCost = BruteForce::getShortestPathValue(inputData, fact, configurationData.progressBarSwitch);
        //    auto BFt2 = std::chrono::high_resolution_clock::now();
        //    BFtimer = BFt2 - BFt1;
        //    if (minimumCost == -1) {
        //        std::cout << "Cykl Hamiltona nie istnieje. Brak rozwiazania dla TSP." << std::endl;
        //    }
        //    else {
        //        std::cout << "obliczony koszt sciezki TSP: " << minimumCost << std::endl;
        //    }
        //    std::cout << "czas dzialania metody: " << BFtimer.count() << " ms" << std::endl;
        //}
        //else if (configurationData.whichAlgorithm == 1) {
        //    // Nearest neighbor
        //    std::cout << "Metoda najblizszych sasiadow" << std::endl;
        //    std::cout << "Rozmiar aktualnie analizowanych instancji: " << inputData.numberOfCities << " miast" << std::endl;
        //    auto NNt1 = std::chrono::high_resolution_clock::now();
        //    minimumCost = NearestNeighbor::getShortestPathValue(inputData);
        //    auto NNt2 = std::chrono::high_resolution_clock::now();
        //    NNtimer = NNt2 - NNt1;
        //    std::cout << "obliczony koszt sciezki TSP: " << minimumCost << std::endl;
        //    std::cout << "czas dzialania metody: " << NNtimer.count() << " ms" << std::endl;
        //}
        //else if (configurationData.whichAlgorithm == 2) {
        //    // Random
        //    std::cout << "Metoda losowa" << std::endl;
        //    std::cout << "Rozmiar aktualnie analizowanych instancji: " << inputData.numberOfCities << " miast" << std::endl;
        //    auto Rt1 = std::chrono::high_resolution_clock::now();
        //    minimumCost = Random::getShortestPathValue(inputData, configurationData.numberOfIterationsForRandom, configurationData.progressBarSwitch);
        //    auto Rt2 = std::chrono::high_resolution_clock::now();
        //    Rtimer = Rt2 - Rt1;
        //    std::cout << "obliczony koszt sciezki TSP: " << minimumCost << std::endl;
        //    std::cout << "czas dzialania metody: " << Rtimer.count() << " ms" << std::endl;
        //}
    }
    else if (configurationData.readOrGenerateData == 1) {

    }
  /*  matrix->push_back({ -1, 99, 19, 83, 23, 12 });
    matrix->push_back({ 67, -1, 3, 71, 85, 74 });
    matrix->push_back({ 54, 76, -1, 55, 62, 78 });
    matrix->push_back({ 32, 29, 68, -1, 76, 14 });
    matrix->push_back({ 20, 51, 84, 68, -1, 93 });
    matrix->push_back({ 96, 38, 82, 24, 9, -1 });
    BFS::Solve(6, matrix, INT_MAX);*/
   /*  matrix->push_back({ -1, 20, 30, 10, 11 });
     matrix->push_back({ 15, -1, 16, 4, 2 });
     matrix->push_back({ 3, 5, -1, 2, 4 });
     matrix->push_back({ 19, 6, 18 , -1, 3 });
     matrix->push_back({ 16, 4, 7, 16, -1 });
     BFS::Solve(5, matrix, INT_MAX);*/

    //matrix.push_back({ -1, 63, 50, 95, 28, 46, 42, 76, 91, 63, 47, 81, 29, 52 });
    //matrix.push_back({ 29, -1, 17, 84, 52, 11, 77, 85, 14, 41, 94, 60, 12, 33 });
    //matrix.push_back({ 99, 94, -1, 43, 72, 25, 81, 67, 65, 14, 85, 39, 67, 20 });
    //matrix.push_back({ 18, 69, 47, -1, 64, 19, 39, 75, 76, 39, 20, 41, 87, 48 });
    //matrix.push_back({ 99, 80, 60, 51, -1, 83, 15, 34, 72, 43, 62, 72, 71, 38 });
    //matrix.push_back({ 28, 92, 73, 50, 90, -1, 56, 95, 62, 56, 34, 27, 49, 43 });
    //matrix.push_back({ 60, 88, 51, 50, 79, 84, -1, 51, 21, 91, 78, 68, 40, 97 });
    //matrix.push_back({ 48, 56, 90, 27, 45, 45, 82, -1, 83, 50, 66, 31, 72, 93 });
    //matrix.push_back({ 39, 33, 43, 79, 80, 59, 51, 42, -1, 13, 18, 39, 92, 22 });
    //matrix.push_back({ 91, 55, 33, 37, 38, 61, 66, 92, 72, -1, 81, 87, 77, 25 });
    //matrix.push_back({ 69, 90, 71, 54, 50, 40, 98, 53, 32, 57, -1, 49, 79, 15 });
    //matrix.push_back({ 46, 24, 34, 63, 97, 61, 92, 31, 70, 74, 80, -1, 59, 69 });
    //matrix.push_back({ 71, 72, 74, 88, 29, 92, 83, 56, 77, 58, 94, 35, -1, 22 });
    //matrix.push_back({ 50, 31, 75, 83, 53, 89, 67, 71, 16, 39, 29, 13, 34, -1 });


    //int nnValue = NearestNeighbor::getShortestPathValue(matrix);
    ////sum_min = 136
    //BFS::Solve(14, matrix, nnValue);

    //matrix.push_back({ -1, 55, 89, 91, 79, 45, 56, 62, 76, 90, 54, 63, 81, 67, 72, 92, 54, 66, 88 });
    //matrix.push_back({ 60, -1, 84, 68, 77, 89, 56, 65, 71, 79, 81, 94, 72, 64, 87, 62, 74, 88, 56 });
    //matrix.push_back({ 89, 84, -1, 95, 50, 62, 91, 67, 56, 64, 80, 77, 65, 73, 85, 59, 56, 70, 74 });
    //matrix.push_back({ 91, 68, 95, -1, 81, 94, 67, 80, 69, 72, 93, 85, 61, 85, 90, 77, 68, 81, 64 });
    //matrix.push_back({ 79, 77, 50, 81, -1, 82, 63, 91, 80, 56, 93, 72, 59, 68, 79, 77, 72, 65, 54 });
    //matrix.push_back({ 45, 89, 62, 94, 82, -1, 91, 76, 54, 80, 57, 65, 86, 72, 88, 81, 60, 92, 64 });
    //matrix.push_back({ 56, 56, 91, 67, 63, 91, -1, 70, 85, 61, 79, 79, 70, 84, 71, 79, 58, 73, 95 });
    //matrix.push_back({ 62, 65, 67, 80, 91, 76, 70, -1, 95, 59, 72, 85, 58, 75, 88, 64, 79, 61, 92 });
    //matrix.push_back({ 76, 71, 56, 69, 80, 54, 85, 95, -1, 91, 63, 80, 92, 68, 71, 72, 63, 59, 83 });
    //matrix.push_back({ 90, 79, 64, 72, 56, 80, 61, 59, 91, -1, 70, 94, 89, 71, 74, 81, 65, 78, 84 });
    //matrix.push_back({ 54, 81, 80, 93, 93, 57, 79, 72, 63, 70, -1, 91, 92, 56, 73, 85, 79, 68, 63 });
    //matrix.push_back({ 63, 94, 77, 85, 72, 65, 79, 85, 80, 94, 91, -1, 56, 92, 75, 64, 92, 70, 60 });
    //matrix.push_back({ 81, 72, 65, 61, 59, 86, 70, 58, 92, 89, 92, 56, -1, 79, 72, 78, 85, 67, 84 });
    //matrix.push_back({ 67, 64, 73, 85, 68, 72, 84, 75, 68, 71, 56, 92, 79, -1, 61, 67, 70, 61, 77 });
    //matrix.push_back({ 72, 87, 85, 90, 79, 88, 71, 88, 71, 74, 73, 75, 72, 61, -1, 67, 59, 81, 80 });
    //matrix.push_back({ 92, 62, 59, 77, 77, 81, 79, 64, 72, 81, 85, 64, 78, 67, 67, -1, 88, 77, 90 });
    //matrix.push_back({ 54, 74, 56, 68, 72, 60, 58, 79, 63, 65, 79, 92, 85, 70, 59, 88, -1, 90, 85 });
    //matrix.push_back({ 66, 88, 70, 81, 65, 92, 73, 61, 59, 78, 68, 70, 67, 61, 81, 77, 90, -1, 94 });
    //matrix.push_back({ 88, 56, 74, 64, 54, 64, 95, 92, 83, 84, 63, 60, 84, 77, 80, 90, 85, 94, -1 });

    //int nnValue = NearestNeighbor::getShortestPathValue(matrix);
    //BFS::Solve(19, matrix, nnValue);
}