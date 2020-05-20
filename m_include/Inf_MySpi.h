#ifndef INF_MYSPI_H
#define INF_MYSPI_H

#include "Inf_Spi.h"
#include <string>

class Inf_MySpi : public Inf_Spi
{
public:
    Inf_MySpi() {}
    
    void OnRspPrint(const std::string& msg);
};

#endif
