#include <iostream>

#include "prompt.h"

Prompt::Prompt() {}

void Prompt::intro() {
    std::cout << "Welcome Bobby! You've crash-landed on this mysterious planet and must now embark on an adventure to explore your surroundings "
        "and figure out a way to repair your spaceship. As you wander the alien landscape, you'll come across a variety of strange and "
        "intriguing creatures, each with their own unique abilities and personalities. With your wits and a little bit of luck, "
        "you'll need to navigate through the dangers and find the resources you need to fix your ship and make your way "
        "back home. Good luck, and have fun on your adventure!\n";
}

int Prompt::get_response() {
    // Read the player's input
    int input;
    std::cin >> input;
    return input;
}

void Prompt::give_option() {
    std::cout << "What do you plan to do next?\n";
    std::cout << "1. get stat\n";
    std::cout << "2. move\n";
    std::cout << "3. interact\n";
    std::cout << "0. quit\n";
}

void Prompt::end_credit() {
    std::cout << "\n\n\nDeveloper: Joshua Liew\n\n\n";
    std::cout << " * " << std::endl;
    std::cout << " *** " << std::endl;
    std::cout << " * " << std::endl;
    std::cout << " * * " << std::endl;
    std::cout << " *** " << std::endl;
}