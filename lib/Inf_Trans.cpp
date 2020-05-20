#include "Inf_Trans.h"
#include <iostream>

Inf_Trans::Inf_Trans(Inf_Spi* pSpi)
    : m_spi(pSpi)
{
    printf("Call Inf_Trans Constructor\n");
}

void Inf_Trans::Proc_Msg(const std::string& msg)
{
    std::cout << "Call Inf_Trans::Proc_Msg: " << msg << std::endl;
    m_spi->OnRspPrint(msg);
}

extern "C" Inf_Trans *create(Inf_Spi* pspi)
{
    auto pTrans = new Inf_Trans(pspi);
    return pTrans;
}
