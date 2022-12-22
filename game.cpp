#include <iostream>
#include <string>
#include "prompt.h"
#include "player.h"
#include <map>
#include "cave.h"
#include "crash_site.h"
#include "alien_city.h"

const std::string CRASH_SITE = "Crash Site";
const std::string CAVE = "Cave";
const std::string ALIEN_CITY = "Alien City";
const std::string GAME_BORDER = "Game Border";
bool is_game_end = false;

// Map of directions to location names
std::map<int, std::string> directions{
    {1, CRASH_SITE},
    {2, CAVE},
    {3, ALIEN_CITY},
    {4, GAME_BORDER}
};

// locations
Cave cave("Cave");
CrashSite crash_site(CRASH_SITE);
AlienCity alien_city(ALIEN_CITY);

void process_response(int response, Player player) {
    std::string direction;
    std::string new_location;
    std::string object_name;
    switch (response)
    {
    case 1:
        // Get the player's stats and display them to the user
        std::cout << "Name: " << player.player_name << std::endl;
        std::cout << "Health: " << player.get_stat("health") << std::endl;
        std::cout << "Attack: " << player.get_stat("attack") << std::endl;
        std::cout << "Location: " << player.get_location() << std::endl;
        break;
    case 2:
        // Move the player to a different location
        std::cout << "Enter the direction you want to move:\n1. north\n2. south\n3. east\n4. west\n";
        int direction;
        std::cin >> direction;
        new_location = directions.at(direction);
        player.move((new_location));
        break;
    case 3:
        // Interact with an object
        std::cout << "Enter the object you want to interact with. One of the items will help you escape this world!\n\n";

        if (player.get_location() == "Cave") {
            for (const auto& [key, value] : cave.objects) {
                std::cout << key << ": " << value << std::endl;
            }
        }
        else if (player.get_location() == CRASH_SITE) {
            for (const auto& [key, value] : crash_site.objects) {
                std::cout << key << ": " << value << std::endl;
            }
        }
        else if (player.get_location() == ALIEN_CITY) {
            for (const auto& [key, value] : alien_city.objects) {
                std::cout << key << ": " << value << std::endl;
            }
        }
        else if (player.get_location() == GAME_BORDER) {
            std::cout << "Congratulations on reaching the game's border! You have successfully navigated the dangers and challenges of this alien world and made it to the edge. As you approach the door back home, you can't help but wonder what mysteries and adventures await you in other parts of the universe. You take a deep breath and push open the door, ready to face whatever lies ahead. Thank you for playing, and we hope you enjoyed your journey!";
            is_game_end = true;
        
        }
        break;
    case 0:
        // Quit the game
        std::cout << "Thank you for playing!\n";
        exit(0);
        break;
    default:
        std::cout << "Invalid option. Please try again.\n";
        break;
    }

}

int main()
{
    int response;
    Prompt prompt;

    Player player("Bobby");
    player.info["health"] = 100;
    player.info["attack"] = 20;
    player.set_location(CRASH_SITE);
    
    prompt.intro();
    
    while (true){
        if (is_game_end) {
            prompt.end_credit();
            while (true) {

            }
        }
        else {
            std::cout << std::endl;
            prompt.give_option();
            std::cout << std::endl;
            response = prompt.get_response();
            process_response(response, player);
            std::cout << std::endl;
        }
    }
    return 0;
}
