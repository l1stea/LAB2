#include "configs.h"


int Configs::GetSizeGroup()
{
    return this->SizeGroup;
}

Configs Configs::operator=(Configs cfg)
{
    return cfg;
}
