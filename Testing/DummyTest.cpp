#include <iostream>
#include "dummy.h"

int main()
{
    DummyObject object;
    std::cout << "Adding 3 + 4, expecting 7... => Actual is " << object.add(3, 4) << std::endl; 

    return 0;
}