cmake_minimum_required (VERSION 2.6)
project (tree)
add_executable(tree main.cpp Sisyphus.cpp Sisyphus.h)

# Locate Boost libraries
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.55 REQUIRED COMPONENTS filesystem)
# We need boost includes
target_include_directories(tree PRIVATE ${Boost_INCLUDE_DIRS})
# We need boost libraries
target_link_libraries(tree ${Boost_LIBRARIES})

