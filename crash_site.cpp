#include "crash_site.h"
#include <iostream>
CrashSite::CrashSite(std::string name) {
    // Initialize the objects map
    objects = {
        {1, "debris"},
        {2, "scrap metal"},
        {3, "broken electronics"},
        {4, "survival kit"}
    };

    // Initialize the name member variable
    // this->name = name;
}