#include "EClient.h"
#include <thread>
#include <string>
#include <iostream>
#include <unistd.h>

EClient::EClient(EWrapper* p)
    : pEWrapper(p)
{
}

void EClient::start()
{
    std::thread m_thread(RunThread, this);
    m_thread.join();
    std::cout << "RunThread completed.\n";
}

void EClient::RunThread(void *argv)
{
    auto pEClient = (EClient *)argv;
    int i = 0;
    while (true)
    {
        std::string msg("Hello! ");
        msg += std::to_string(i);
        pEClient->pEWrapper->Proc_Msg(msg);

        ++i;
        if (i >= 60) break;
        sleep(1);
    }
}
