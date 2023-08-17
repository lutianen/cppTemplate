
#include "cppTemplate.h"

int templateFunc(int a) {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    std::cout << a << std::endl;
    return 0;
}