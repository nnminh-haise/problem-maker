#pragma once

#ifndef RNDLIB_H
#define RNDLIB_H

#include <iostream>
#include <random>

namespace Random {

    /*
    * Function returns a random integer number between a minimum value to a maximum value
    @param minValue: the minimum value of the return value.
    @param maxValue: the maximum value of the return value.
    @param randomEngine: the random engine used by the distribution of the algorithm. By default, the algorithm uses the std::randome_device{}.
    @return int or long long
    */
    template < typename templateType = int >
    templateType integer(templateType minValue, templateType maxValue, std::random_device&& randomEngine = std::random_device{}) {
        if (minValue > maxValue) { return 0; }

        std::uniform_int_distribution < templateType > distribution(minValue, maxValue);
        return distribution(randomEngine);
    }

    /*
    * Function returns a random real number between a minimum value to a maximum value
    @param minValue: the minimum value of the return value.
    @param maxValue: the maximum value of the return value.
    @param randomEngine: the random engine used by the distribution of the algorithm. By default, the algorithm uses the std::randome_device{}.
    @return double
    */
    double real(double minValue, double maxValue, std::random_device&& randomEngine = std::random_device{}) {
        if (minValue > maxValue) { return 0; }

        std::uniform_real_distribution < double > distribution(minValue, maxValue);
        return distribution(randomEngine);
    }

    /*
    * Function returns a random character in the given template string.
    @param templateString: a string contains a collection of character which will be returned by the function.
    @return char
    */
    char character(std::string templateString = "qwertyuiopasdfghjklzxcvbnm") {
        return templateString[integer(0, (int)templateString.length() - 1)];
    }

    /*
    * Function returns a string of a given length contains random character in the given template string.
    @param stringSize: length of the return string.
    @param templateString: a string contains a collection of character which will be returned by the function.
    @return std::string
    */
    std::string String(int stringLength, std::string templateString) {
        std::string str = "";
        while (str.length() != stringLength) { str += character(templateString); }

        return str;
    }

    /*
    * Function returns an array of a given size with each element has the value betweeen a given minimum value and a given maximum value.
    * The elements in the return array can be unique or duplicate. By default, the return array will contain duplicates.
    @param arraySize: the size of the return array.
    @param minValue: the minimum value of the element in the array.
    @param maxValue: the maximum value of the element in the array.
    @param isUnique: an indicator shows whether the return array conains duplicates or not. By default is false.
    @return int* or long long*
    */
    template < typename T = int >
    T* array(size_t arraySize, T minValue, T maxValue, bool isUnique = false) {
        if (minValue > maxValue) { return nullptr; }

        if (isUnique == true && (int)arraySize > (maxValue - minValue + 1)) { return nullptr; }

        T* array = new T[arraySize];

        if (isUnique == true) {
            T* values = new T[maxValue - minValue + 2];
            for (int i = minValue; i <= maxValue; ++i) { values[i] = i; }

            int randomIndex = -1, leftIndex = minValue, rightIndex = maxValue;
            for (int i = 0; i < arraySize; ++i) {
                randomIndex = integer(leftIndex, rightIndex);
                array[i] = values[randomIndex];
                std::swap(values[leftIndex++], values[randomIndex]);
            }
            delete[] values;
            return array;
        }

        for (int i = 0; i < arraySize; ++i) { array[i] = integer(minValue, maxValue); }
        return array;
    }

    /*
    * Function returns an array of a given size with each element has the value betweeen a given minimum value and a given maximum value.
    * The elements in the return array can be unique or duplicate. By default, the return array will contain duplicates.
    @param arraySize: the size of the return array.
    @param minValue: the minimum value of the element in the array.
    @param maxValue: the maximum value of the element in the array.
    @param isUnique: an indicator shows whether the return array conains duplicates or not. By default is false.
    @return double*
    */
    double* array(size_t arraySize, double minValue, double maxValue, bool isUnique = false) {
        if (minValue > maxValue) { return nullptr; }

        double* array = new double[arraySize];

        for (int i = 0; i < arraySize; ++i) { array[i] = real(minValue, maxValue); }
        return array;
    }

};


#endif
