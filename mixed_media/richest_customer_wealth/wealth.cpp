//#!/usr/bin/env g++ -std=c++17

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

#define M 4
#define N 5


int maxWealth(const std::vector<std::vector<int>>& accounts) {
    return std::transform_reduce(
        accounts.cbegin(),
        accounts.cend(),
        0,
        [](auto a, auto b) { return std::max(a, b); },
        [](const auto& row) { return std::reduce(row.cbegin(), row.cend()); }
    );
}

// Random MxN matrix
std::vector<std::vector<int>> generateRandomMatrix(int rows, int cols, int minVal, int maxVal) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    for (auto& row : matrix) {
        for (auto& elem : row) {
            elem = dis(gen);
        }
    }
    return matrix;
}


void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << '\n';
    }
}

int main() {
    int minVal = 1, maxVal = 100; // Random value range

    std::vector<std::vector<int>> accounts = generateRandomMatrix(M, N, minVal, maxVal);

    std::cout << "Generated " << M << "x" << N << " matrix (accounts):\n";
    printMatrix(accounts);

    int result = maxWealth(accounts);
    std::cout << "\nThe maximum wealth: " << result << '\n';

    return 0;
}
