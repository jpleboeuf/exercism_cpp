// This is an include guard.
#pragma once

// Include the string header so that we have access to `std::string`.
#include <string>

// Declare a namespace for the function(s) we are exporting.
namespace hello_world {

// Declare the `hello()` function,
//  which takes no arguments and returns a `std::string`.
// The function itself is defined in the `hello_world.cpp` source file.
// Because it is inside of the `hello_world` namespace,
//  it's full name is `hello_world::hello()`.
std::string hello();

}  // namespace hello_world
