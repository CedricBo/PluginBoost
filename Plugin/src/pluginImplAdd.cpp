#include "pluginImpl.hpp"

std::string pluginImpl::getName()
{
    return "Addition plugin";
}

int pluginImpl::method(int x, int y) 
{
    return x + y;
}