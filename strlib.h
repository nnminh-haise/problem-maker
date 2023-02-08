#ifndef STRLIB_H
#define STRLIB_H

#include <iostream>
#include <list>

namespace str {
    /*
    * Function returns a std::string object which is a copy of a char* object.
    @param sourceString: the given source string which will be copied.
    @return std::string.
    */
    std::string convertString(char* sourceString) {
        size_t sourceStringLength = sizeof(sourceString) / sizeof(char);
        std::string stringObj = "";
        for (int i = 0; i < sourceStringLength; ++i) {
            if (sourceString[i] != '\0') {
                stringObj += sourceString[i];
            }
        }
        return stringObj;
    }

    /*
    * Function returns a char* object which is a copy of a std::string object.
    @param sourceString: the given source string which will be copied.
    @return char*.
    */
    char* convertString(std::string sourceString) {
        char* charObj = new char [sourceString.length() + 1];
        int index = 0;
        for (char character: sourceString) {
            charObj[index++] = character;
        }
        charObj[sourceString.length()] = '\0';
        return charObj;
    }

    /*
    * Function returns a std::string which is a sub-string of a given source string.
    @param sourceString: the source string which contains the sub-string.
    @return std::string.
    */
    std::string getSubString(std::string sourceString, unsigned int length, unsigned int position) {
        std::string stringObj = "";

        for (int i = position; i < position + length; ++i) {
            stringObj += sourceString[i];
        }

        return stringObj;
    }

    /*
    * Function returns an integer number which is the number of occurrence of targeted character in the source string.
    @param sourceString: the string which will be checked for the targeted character.
    @param target: the targeted character needed to be check in the source string.
    > Return type: int.
    */
    int countCharacter(const std::string sourceString, const char target) {
        int counter = 0;

        for (int i = 0; i < (int)sourceString.length(); ++i) {
            counter += (sourceString[i] == target);
        }

        return counter;
    }

    /*
    * Function returns a list of integer which is the position of the targeted character in the source string.
    @param sourceString: the string which will be checked for the targeted character.
    @param target: the targeted character needed to be check in the source string.
    > Return type: int*.
    */
    int* listCharacterPostions(const std::string sourceString, const char target) {
        int targetCount = countCharacter(sourceString, target);
        int* targetPositions = new int [targetCount];
        int index = 0;

        for (int i = 0; i < (int)sourceString.length(); ++i) {
            if (sourceString[i] == target) {
                targetPositions[index++] = i;
            }
        }

        return targetPositions;
    }

    /*
    * Function returns a std::list of std::string is the sub-string of the source string by spliting at the given divider character.
    @param sourceString: the source string which will be splited into sub-strings.
    @param divider: the dividing character of the source string.
    @return std::list < std::string >
    */
    std::list < std::string > split(const std::string sourceString, const char divider) {
        int dividerCount = countCharacter(sourceString, divider);
        int* dividerPositions = listCharacterPostions(sourceString, divider);

        std::list < std::string > subStrings;
        int startPosition = 0;
        for (int i = 0; i < dividerCount; ++i) {
            int subStringLength = dividerPositions[i] - startPosition;
            subStrings.push_back(getSubString(sourceString, subStringLength, startPosition));
            startPosition = dividerPositions[i] + 1;
        }

        subStrings.push_back(getSubString(sourceString, sourceString.length() - startPosition, startPosition));

        return subStrings;
    }
};

#endif