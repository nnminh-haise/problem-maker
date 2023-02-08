#include <iostream>
#include "rndlib.h"

int main()
{
    int a = Random::integer(1, 10);
    int b = Random::integer(11, 20);

    std::cout << a << " " << b << std::endl;

    return 0;
}