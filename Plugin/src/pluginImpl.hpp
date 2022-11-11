#pragma once

#include <boost/config.hpp>
#include "pluginAPI.hpp"

class pluginImpl : public pluginAPI {
public:
    std::string getName();

    int method(int x, int y);
};

extern "C" BOOST_SYMBOL_EXPORT pluginImpl plugin;
pluginImpl plugin;