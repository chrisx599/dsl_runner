#include "tools.h"
#include <map>
#include <fstream>


extern std::map<std::string, std::string> varname;

class Interpreter
{
public:
    static void Speak(std::vector<std::string> expression);
    static void Assign(std::vector<std::string> var);
    static void Getdata(std::vector<std::string> user);
    static void Listen(std::vector<std::string> timer, int &index);
    static void Exit();
    static void Error();
};
