#include <map>
#include <string>
class CrashSite {
public:
    CrashSite(std::string name);
    // Map of object numbers to object names
    std::map<int, std::string> objects;
    void prompt();

};
