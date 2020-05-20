#include "Inf_MySpi.h"
#include <iostream>

void Inf_MySpi::OnRspPrint(const std::string& msg)
{
    std::cout << "Call MySpi: " << msg << std::endl;
}

extern "C" Inf_Spi* create()
{
    return new Inf_MySpi();
}