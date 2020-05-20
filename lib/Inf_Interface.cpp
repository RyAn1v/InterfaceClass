#include "Inf_Interface.h"
#include <iostream>

Inf_Interface::Inf_Interface(Inf_Spi *pSpi)
    : m_client(new EClient(this))
    , m_spi(pSpi)
{
    printf("Call Inf_Interface Constructor\n");
}

void Inf_Interface::Start()
{
    m_client->start();
}

void Inf_Interface::Proc_Msg(const std::string& msg)
{
    std::cout << "Call Inf_Interface::Proc_Msg: " << msg << std::endl;
    m_spi->OnRspPrint(msg);
}

extern "C" Inf_Interface *create(Inf_Spi* pspi)
{
    auto pTrans = new Inf_Interface(pspi);
    return pTrans;
}
