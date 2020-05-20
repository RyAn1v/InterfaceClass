#ifndef INF_SPI_H
#define INF_SPI_H

#include <string>

class Inf_Spi
{
public:
    virtual void OnRspPrint(const std::string& msg) {};
};

#endif