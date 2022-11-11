#pragma once

#include <string>

#include <boost/config.hpp>

class BOOST_SYMBOL_VISIBLE pluginAPI {

public:
    virtual std::string getName() = 0;

    virtual int method(int x, int y) = 0;

    virtual ~pluginAPI() {}
};