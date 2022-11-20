#include "tools.h"


long long VecstrToU(std::vector<std::string> timer)
{
    
}
void* is_timeout(void *arg)
{
    unsigned int* period = (unsigned int*)arg;
    sleep(*period);
    return;
}