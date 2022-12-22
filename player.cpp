
#include <vector>
#include <map>
#include "player.h"
#include <iostream>
#include <string>
std::string location_name = "";
Player::Player(std::string name) {
    player_name = name;
    inventory = {};
    info = {};
}

void Player::move(std::string new_location) {
    location_name = new_location;
    std::cout << "You have moved to " << new_location << "!\n";
}



int Player::get_stat(std::string stat) {
    return info.at(stat);
}

std::string Player::get_location() {
    return location_name;
}

void Player::set_location(std::string new_location) {
    location_name = new_location;
}