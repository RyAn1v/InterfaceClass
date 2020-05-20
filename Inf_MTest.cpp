#include "Inf_Api.h"
#include "Inf_Spi.h"
#include <dlfcn.h>
#include <string>
#include <iostream>
#include <unistd.h>

class Inf_MySpi : public Inf_Spi
{
public:
    Inf_MySpi() {}
    
    void OnRspPrint(const std::string& msg)
    {
        std::cout << "Call MySpi: " << msg << std::endl;
    }
};

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        std::cout << "Usage: InfTest [so]\n";
        return 0;
    }
    
    std::string soPath(argv[1]);
    void *p = dlopen(soPath.c_str(), RTLD_LAZY);
    if (p != nullptr) 
    {
        Inf_MySpi mySpi;
        Inf_Api *(*create)(const std::string&, Inf_Spi *) = (Inf_Api *(*)(const std::string&, Inf_Spi *))dlsym(p, "create_interface");
        Inf_Api *myApi = (*create)(soPath, &mySpi);
        myApi->Start();

        // Inf_Spi *(*create)(Inf_Spi *) = (Inf_Spi *(*)(Inf_Spi *))dlsym(p, "create");
        // myApi.RegisterSpi((*create)(&mySpi));
        // myApi.Start();
    }
    else
    {
        std::cout << "Open So failed: " << soPath << std::endl;
        return 0;
    }
    
    int i = 0;
    while (true)
    {
        ++i;
        if (i >= 60) break;
        sleep(1);
    }
    return 0;
}