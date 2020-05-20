#ifndef ECLIENT_H
#define ECLIENT_H

#include "EWrapper.h"

class EClient
{
public:
    EClient(EWrapper* p);

    void start();

    static void RunThread(void *argv);
    
private:
    EWrapper* pEWrapper;
};

#endif