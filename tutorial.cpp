// tutorial.cpp

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include "TutorialConfig.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << argv[0] <<"\n"<< " Version " << Tutorial_VERSION_MAJOR << "."
                << Tutorial_VERSION_MINOR<<"."<<Tutorial_VERSION_PATCH << std::endl;
      std::cout << "Usage: " << argv[0] << " number" << std::endl;
    }

    // convert input to double
    const double inputValue = atof(argv[1]);

    // calculate square root
    const double outputValue = sqrt(inputValue);
    std::cout << "The square root of " << inputValue
              << " is " << outputValue
              << std::endl;
    std::cout << __TIMESTAMP__ << std::endl;          
    return 0;
}