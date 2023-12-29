#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <random>

#define arrSize(arr, T) sizeof(arr) / sizeof(T)

std::random_device randomEngine; //* For running random functions

//# Helper functions
template <class T> void printArr(T* arr, const int& arrSize);
template <class T> void printVec(const std::vector <T>& list);
template <class T = int> T Int(T minValue, T maxValue);
double Double(double minValue, double maxValue);
char Char(const std::string& templateString = "qwertyuiopasdfghjkklzxcvbnm");
std::string Str(int length, const std::string& templateString = "qwertyuiopasdfghjkklzxcvbnm");
template <class T> T* Arr(int arrSize, T minValue, T maxValue);
template <class T> T* ArrUnique(int arrSize, T minValue, T maxValue);

//! Main code can start here!
int main() {

    //! Un-comment below line if you need to log your standard output to file
    freopen("log.txt", "w", stdout);

}

//# Helper functions implementations
template <class T> void printArr(T* arr, const int& arrSize) {
    for (int i = 0; i < arrSize; ++i) {
        std::cout << *(arr + i);
        if (i + 1 < arrSize) {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

template <class T> void printVec(const std::vector <T>& list) {
    for (auto iter = list.begin(); iter != list.end(); ++iter) {
        std::cout << *iter;
        if (iter + 1 != list.end()) {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

template <class T> T Int(T minValue, T maxValue) {
    if (minValue > maxValue) { return 0; }

    std::uniform_int_distribution <T> distribution(minValue, maxValue);
    return distribution(randomEngine);
}

double Double(double minValue, double maxValue) {
    if (minValue > maxValue) { return 0; }

    std::uniform_real_distribution <double> distribution(minValue, maxValue);
    return distribution(randomEngine);
}

char Char(const std::string& templateString) {
    return templateString[Int(0, (int)(templateString.length() - 1))];
}

std::string Str(int length, const std::string& templateString) {
    std::string result = "";
    for (int i = 0; i < length; ++i) {
        result += Char(templateString);
    }
    return result;
}

template <class T> T* Arr(int arrSize, T minValue, T maxValue) {
    if (arrSize < 1) {
        return nullptr;
    }

    T* newArr = new T[arrSize];
    for (int i = 0; i < arrSize; ++i) {
        newArr[i] = Int(minValue, maxValue);
    }
    return newArr;
}

template <class T> T* ArrUnique(int arrSize, T minValue, T maxValue) {
    if (arrSize < 1) {
        return nullptr;
    }

    if (arrSize > maxValue - minValue + 1) {
        return nullptr;
    }

    const int bufferSize = maxValue - minValue + 1;
    T* buffer = new T[bufferSize];
    for (int i = 0; i < bufferSize; ++i) {
        buffer[i] = minValue + i;
    }

    T* newArr = new T[arrSize];
    int selectedId = -1;
    for (int i = 0; i < arrSize; ++i) {
        selectedId = Int(i, bufferSize - 1);
        newArr[i] = buffer[selectedId];
        std::swap(buffer[i], buffer[selectedId]);
    }

    delete[] buffer;
    return newArr;
}
