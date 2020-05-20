#ifndef INF_INTERFACE_H
#define INF_INTERFACE_H

#include "Inf_Api.h"
#include "Inf_Spi.h"
#include "EClient.h"
#include "EWrapper.h"

class Inf_Interface : public Inf_Api, public EWrapper
{
public:
    Inf_Interface(Inf_Spi* pSpi);

    // void RegisterSpi(Inf_Spi* pSpi);
    void Start();

    void Proc_Msg(const std::string& msg);

private:
    EClient* m_client;
    Inf_Spi* m_spi;
};

#endif