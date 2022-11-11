#include <boost/dll/import.hpp> // for import_alias
#include <iostream>
#include "pluginAPI.hpp"

int main(int argc, char* argv[]) 
{
    boost::filesystem::path lib_path(argv[1]);
    std::string lib(argv[2]);
    std::cout << "Starting.." << std::endl;

    boost::shared_ptr<pluginAPI> plugin;
    std::cout << "Loading the plugin" << std::endl;
     
    plugin = boost::dll::import_symbol<pluginAPI>(
        lib_path / lib,
        "plugin",
        boost::dll::load_mode::append_decorations
    );

    std::cout << "plugin->method(10, 5) call:  " << plugin->method(10, 5) << std::endl;
    std::cout << "plugin->getName() call:  " << plugin->getName() << std::endl;
    
    return 0;
}
