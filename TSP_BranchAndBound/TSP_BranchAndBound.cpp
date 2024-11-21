// TSP_BranchAndBound.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BFS/BFS.h"
#include <vector>

int main()
{
    std::cout << "Hello World!\n";
    std::vector<std::vector<int>> matrix;
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

    matrix.push_back({ -1, 63, 50, 95, 28, 46, 42, 76, 91, 63, 47, 81, 29, 52 });
    matrix.push_back({ 29, -1, 17, 84, 52, 11, 77, 85, 14, 41, 94, 60, 12, 33 });
    matrix.push_back({ 99, 94, -1, 43, 72, 25, 81, 67, 65, 14, 85, 39, 67, 20 });
    matrix.push_back({ 18, 69, 47, -1, 64, 19, 39, 75, 76, 39, 20, 41, 87, 48 });
    matrix.push_back({ 99, 80, 60, 51, -1, 83, 15, 34, 72, 43, 62, 72, 71, 38 });
    matrix.push_back({ 28, 92, 73, 50, 90, -1, 56, 95, 62, 56, 34, 27, 49, 43 });
    matrix.push_back({ 60, 88, 51, 50, 79, 84, -1, 51, 21, 91, 78, 68, 40, 97 });
    matrix.push_back({ 48, 56, 90, 27, 45, 45, 82, -1, 83, 50, 66, 31, 72, 93 });
    matrix.push_back({ 39, 33, 43, 79, 80, 59, 51, 42, -1, 13, 18, 39, 92, 22 });
    matrix.push_back({ 91, 55, 33, 37, 38, 61, 66, 92, 72, -1, 81, 87, 77, 25 });
    matrix.push_back({ 69, 90, 71, 54, 50, 40, 98, 53, 32, 57, -1, 49, 79, 15 });
    matrix.push_back({ 46, 24, 34, 63, 97, 61, 92, 31, 70, 74, 80, -1, 59, 69 });
    matrix.push_back({ 71, 72, 74, 88, 29, 92, 83, 56, 77, 58, 94, 35, -1, 22 });
    matrix.push_back({ 50, 31, 75, 83, 53, 89, 67, 71, 16, 39, 29, 13, 34, -1 });


    int nnValue = NearestNeighbor::getShortestPathValue(matrix);
    //sum_min = 136
    BFS::Solve(14, matrix, nnValue);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
