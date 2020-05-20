#include "Inf_Api.h"
#include "Inf_Spi.h"
// #include "Inf_Trans.h"
#include "Inf_Interface.h"
// #include "EClient.h"
#include <dlfcn.h>

// void Inf_Api::RegisterSpi(Inf_Spi *pTrans)
// {
//     auto pt = (Inf_Trans *)pTrans;
//     pEClient = new EClient(pt);
// }

// void Inf_Api::Start()
// {
//     pEClient->start();
//     printf("Call Client Start\n");
// }

extern "C" Inf_Api* create_interface(const std::string& soPath, Inf_Spi* pSpi)
{
    Inf_Api *pApi = nullptr;
    void *p = dlopen(soPath.c_str(), RTLD_LAZY);
    if (p != nullptr) 
    {
        Inf_Interface *(* create)(Inf_Spi *) = (Inf_Interface *(*)(Inf_Spi *))dlsym(p, "create");
        pApi = (*create)(pSpi);
    }
    return pApi;
}