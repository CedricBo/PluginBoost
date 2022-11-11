cmake_minimum_required(VERSION 3.0.0)
project(PluginSystem VERSION 0.1.0)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
add_compile_options(-fvisibility=hidden -g3)

set(CXX_STANDARD 20)

include(conan/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Boost REQUIRED)

add_executable(PluginSystemCore App/src/main.cpp)

add_library(PluginSystemPluginAdd SHARED Plugin/src/pluginImplAdd.cpp)
add_library(PluginSystemPluginSub SHARED Plugin/src/pluginImplSub.cpp)

target_include_directories(PluginSystemCore PRIVATE App/include)
target_include_directories(PluginSystemPluginAdd PRIVATE App/include)
target_include_directories(PluginSystemPluginSub PRIVATE App/include)

target_link_libraries(PluginSystemCore ${CONAN_LIBS})
target_link_libraries(PluginSystemPluginAdd ${CONAN_LIBS})
target_link_libraries(PluginSystemPluginSub ${CONAN_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)