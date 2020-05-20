#ifndef INF_TRANS_H
#define INF_TRANS_H

#include "Inf_Spi.h"
#include "EWrapper.h"

class Inf_Trans : public Inf_Spi, public EWrapper
{
public:
    Inf_Trans(Inf_Spi* pSpi);

    void Proc_Msg(const std::string& msg);

private:
    Inf_Spi* m_spi;
};

#endif