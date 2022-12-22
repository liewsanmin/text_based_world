#include <map>
#include <string>
class AlienCity {
public:
    AlienCity(std::string name);
    // Map of object numbers to object names
    std::map<int, std::string> objects;

};
