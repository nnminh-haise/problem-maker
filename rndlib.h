#ifndef RNDLIB_H
#define RNDLIB_H

#include <iostream>
#include <random>
#include <algorithm>
#include <cstring>
#include <set>

/*
* Namespace provides functions which can generate random values.
! Functions in the namespace only supports the primitive data type in c++.
TODO: Make more generator for object such as std::vector, std::set, ect.
*/
namespace rnd {

    /*
    * Check whether the given values can be represent a range.
    @param minValue: the minimum value of the range.
    @param maxValue: the maximum value of the range.
    @return bool.
    */
    template < typename T = int >
    bool validRange(T minValue, T maxValue) {
        return (minValue <= maxValue);
    }

    /*
    * Function return a random integer between @minValue and @maxValue.
    @param minValue: the minimum value will be returned.
    @param maxValue: the maximum value will be returned.
    @param randomEngine: std::random_device object represent the random engine will be used.
    @return int.
    */
    int rnd(int minValue, int maxValue, std::random_device&& randomEngine = std::random_device{}) {
        if (validRange(minValue, maxValue) == false) {
            return 0;
        }

        /*
        * An uniform discrete distribution based on the probability mass function. 
        * The distribution returns an integer between the minimum value and the maximum value.
        @param minValue: the minimum value will be generated.
        @param maxValue: the maximum value will be generated.
        @return int.
        */
        std::uniform_int_distribution < int > distribution(minValue, maxValue);
        return distribution(randomEngine);
    }

    /*
    * Function return a random integer between @minValue and @maxValue.
    @param minValue: the minimum value will be returned.
    @param maxValue: the maximum value will be returned.
    @param randomEngine: std::random_device object represent the random engine will be used.
    @return long long.
    */
    long long rnd(long long minValue, long long maxValue, std::random_device&& randomEngine = std::random_device{}) {
        if (validRange(minValue, maxValue) == false) {
            return 0;
        }

        /*
        * An uniform discrete distribution based on the probability mass function. 
        * The distribution returns an integer between the minimum value and the maximum value.
        @param minValue: the minimum value will be generated.
        @param maxValue: the maximum value will be generated.
        @return long long.
        */
        std::uniform_int_distribution < long long > distribution(minValue, maxValue);
        return distribution(randomEngine);
    }

    /*
    * Function return a random float between @minValue and @maxValue.
    @param minValue: the minimum value will be returned.
    @param maxValue: the maximum value will be returned.
    @param randomEngine: std::random_device object represent the random engine will be used.
    @return float.
    */
    float rnd(float minValue, float maxValue, std::random_device&& randomEngine = std::random_device{}) {
        if (validRange(minValue, maxValue) == false) {
            return 0;
        }

        /*
        * An uniform discrete distribution based on the probability mass function. 
        * The distribution returns an integer between the minimum value and the maximum value.
        @param minValue: the minimum value will be generated.
        @param maxValue: the maximum value will be generated.
        @return float.
        */
        std::uniform_real_distribution < float > distribution(minValue, maxValue);
        return distribution(randomEngine);
    }

    /*
    * Function return a random float between @minValue and @maxValue.
    @param minValue: the minimum value will be returned.
    @param maxValue: the maximum value will be returned.
    @param randomEngine: std::random_device object represent the random engine will be used.
    @return double.
    */
    double rnd(double minValue, double maxValue, std::random_device&& randomEngine = std::random_device{}) {
        if (validRange(minValue, maxValue) == false) {
            return 0;
        }

        /*
        * An uniform discrete distribution based on the probability mass function. 
        * The distribution returns an integer between the minimum value and the maximum value.
        @param minValue: the minimum value will be generated.
        @param maxValue: the maximum value will be generated.
        @return double.
        */
        std::uniform_real_distribution < double > distribution(minValue, maxValue);
        return distribution(randomEngine);
    }

    /*
    * Function return a random array with @objSize integer between @minValue and @maxValue.
    * The returned object can be customized to contain unique object with @unique = true by default.
    @param objSize: number of element of the object.
    @param minValue: the minimum value of the element of the object.
    @param maxValue: the maximum value of the element of the object.
    @param unique: indicate if return object contain unique elements or not. By default is true.
    @param randomEngine: std::random_device object represent the random engine will be used.
    @return int*.
    */
    int* rndArr(size_t objSize, int minValue, int maxValue, bool unique = false, std::random_device&& randomEngine = std::random_device{}) {
        int* arr = new int [objSize]; //* The return array.
        memset(arr, 0, objSize * sizeof(int));

        if (validRange(minValue, maxValue) == false) {
            return arr;
        }

        //! can not create an object if the object size is bigger than the size of the range.
        if (unique == true && objSize > maxValue - minValue + 1) {
            return arr;
        }

        /*
        * An uniform discrete distribution based on the probability mass function. 
        * The distribution returns an integer between the minimum value and the maximum value.
        @param minValue: the minimum value will be generated.
        @param maxValue: the maximum value will be generated.
        @return int.
        */
        std::uniform_int_distribution < int > distribution(minValue, maxValue);

        //* Generating a list contains unique elements.
        if (unique == true) {
            //* Using std::set to create.
            std::set < int > customSet;
            //* Create a std::set contains @objSize.
            while (customSet.size() != objSize) {
                customSet.insert(distribution(randomEngine));
            }

            //* Put elements inside the array.
            int index = 0;
            for (auto item: customSet) {
                arr[index++] = item;
            }

            //* Shuffle the array.
            std::shuffle(arr, arr + objSize, randomEngine);
        }
        //* Generating a list contains duplicatable elements.
        else {
            for (int i = 0; i < objSize; ++i) {
                arr[i] = distribution(randomEngine);
            }
        }

        return arr;
    }

    /*
    * Function return a random array with @objSize integer between @minValue and @maxValue.
    * The returned object can be customized to contain unique object with @unique = true by default.
    @param objSize: number of element of the object.
    @param minValue: the minimum value of the element of the object.
    @param maxValue: the maximum value of the element of the object.
    @param unique: indicate if return object contain unique elements or not. By default is true.
    @param randomEngine: std::random_device object represent the random engine will be used.
    @return long long*.
    */
    long long* rndArr(size_t objSize, long long minValue, long long maxValue, bool unique = false, std::random_device&& randomEngine = std::random_device{}) {
        long long* arr = new long long [objSize];
        memset(arr, 0, objSize * sizeof(long long));

        if (validRange(minValue, maxValue) == false) {
            return arr;
        }

        //! can not create an object if the object size is bigger than the size of the range.
        if (unique == true && objSize > maxValue - minValue + 1) {
            return arr;
        }

        
        std::uniform_int_distribution < long long > distribution(minValue, maxValue);

        if (unique == true) {
            std::set < long long > customSet;
            while (customSet.size() != objSize) {
                customSet.insert(distribution(randomEngine));
            }

            int index = 0;
            for (auto item: customSet) {
                arr[index++] = item;
            }

            std::shuffle(arr, arr + objSize, randomEngine);
        }
        else {
            for (int i = 0; i < objSize; ++i) {
                arr[i] = distribution(randomEngine);
            }
        }

        return arr;
    }

    /*
    * Function return a random array with @objSize float between @minValue and @maxValue.
    * The returned object can be customized to contain unique object with @unique = true by default.
    @param objSize: number of element of the object.
    @param minValue: the minimum value of the element of the object.
    @param maxValue: the maximum value of the element of the object.
    @param unique: indicate if return object contain unique elements or not. By default is true.
    @param randomEngine: std::random_device object represent the random engine will be used.
    @return float*.
    */
    float* rndArr(size_t objSize, float minValue, float maxValue, bool unique = false, std::random_device&& randomEngine = std::random_device{}) {
        float* arr = new float [objSize];
        memset(arr, 0, objSize * sizeof(float));

        if (validRange(minValue, maxValue) == false) {
            return arr;
        }

        std::uniform_real_distribution < float > distribution(minValue, maxValue);

        if (unique == true) {
            std::set < float > customSet;
            while (customSet.size() != objSize) {
                customSet.insert(distribution(randomEngine));
            }

            int index = 0;
            for (auto item: customSet) {
                arr[index++] = item;
            }

            std::shuffle(arr, arr + objSize, randomEngine);
        }
        else {
            for (int i = 0; i < objSize; ++i) {
                arr[i] = distribution(randomEngine);
            }
        }

        return arr;
    }

    /*
    * Function return a random array with @objSize float between @minValue and @maxValue.
    * The returned object can be customized to contain unique object with @unique = true by default.
    @param objSize: number of element of the object.
    @param minValue: the minimum value of the element of the object.
    @param maxValue: the maximum value of the element of the object.
    @param unique: indicate if return object contain unique elements or not. By default is true.
    @param randomEngine: std::random_device object represent the random engine will be used.
    @return double*.
    */
    double* rndArr(size_t objSize, double minValue, double maxValue, bool unique = false, std::random_device&& randomEngine = std::random_device{}) {
        double* arr = new double [objSize];
        memset(arr, 0, objSize * sizeof(double));

        if (validRange(minValue, maxValue) == false) {
            return arr;
        }

        std::uniform_real_distribution < double > distribution(minValue, maxValue);

        if (unique == true) {
            std::set < double > customSet;
            while (customSet.size() != objSize) {
                customSet.insert(distribution(randomEngine));
            }

            int index = 0;
            for (auto item: customSet) {
                arr[index++] = item;
            }

            std::shuffle(arr, arr + objSize, randomEngine);
        }
        else {
            for (int i = 0; i < objSize; ++i) {
                arr[i] = distribution(randomEngine);
            }
        }

        return arr;
    }

    /*
    * Generate a random string with length of @len with all character from @templateString.
    @param len: string's length.
    @param templateString: a string contains all the character will be randomly choosen.
    @param randomEngine: std::random_device object represent the random engine will be used.
    @return std::string.
    */
    std::string rndStr(unsigned int len, std::string templateString = "qwertyuiopasdfghjklzxcvbnm") {
        std::string str = "";

        while (str.length() != len) {
            str += templateString[rnd(0, templateString.length() - 1)];
        }

        return str;
    }
}

#endif