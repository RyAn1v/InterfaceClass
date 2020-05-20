#ifndef EWRAPPER_H
#define EWRAPPER_H

#include <string>

class EWrapper
{
public:
    EWrapper() {}

    virtual void Proc_Msg(const std::string& msg) = 0;
};

#endif