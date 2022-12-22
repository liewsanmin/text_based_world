
#include <vector>
#include <map>
#include <string>
class Player {
public:
    std::string player_name;
    std::map<std::string, int> info;
    // Constructor
    Player(std::string name);
    void move(std::string new_location);
    void interact(std::string object);
    void addItem(std::string item);
    void removeItem(std::string item);
    void set_stat();
    int get_stat(std::string stat);
    void interact();
    std::string get_location();
    void set_location(std::string new_location);
private:

    std::vector<std::string> inventory;
    
};