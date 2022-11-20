#include "analysis.h"
#include <map>
#include <time.h>
#include <pthread.h>

class Interpreter
{
public:
    static void Speak(std::vector<std::string> expression);
    static void Listen(std::vector<std::string> timer);
    static void Branch(std::vector<std::string> expression);
    static void Silence(std::vector<std::string> expression);
    static void Default(std::vector<std::string> expression);
};
