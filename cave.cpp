#include <iostream>
#include "cave.h"
Cave::Cave(std::string name) {
    // Initialize the objects map
    objects = {
        {1, "torch"},
        {2, "rock"},
        {3, "cave painting"},
        {4, "ancient artifact"}
    };

    // Initialize the name member variable
    cave_name = name;
}
