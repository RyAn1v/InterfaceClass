#ifndef INF_API_H
#define INF_API_H

// class EClient;
class Inf_Spi;

class Inf_Api
{
public:
	Inf_Api() {}

	// virtual void RegisterSpi(Inf_Spi *p) = 0;

	virtual void Start() = 0;
	
	/// do other request...

private:
	// EClient* pEClient;
};

#endif // INF_API_H
