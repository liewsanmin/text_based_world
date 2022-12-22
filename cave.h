#include <map>
#include <string>
class Cave {
public:
    std::string cave_name;
    Cave(std::string name);
    // Map of object numbers to object names
    std::map<int, std::string> objects;
    void prompt();
};
