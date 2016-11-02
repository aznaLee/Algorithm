

#define SAFE_DELETE(p) if(p){delete p; p = NULL;}

enum ALGORITHM
{
	LINKECLIST,
	STACK,
	QUEUE
};