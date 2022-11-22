#include <iostream>
#include <string>
#include <fstream>
#include <vector>


typedef std::pair<std::string, std::vector<std::string>> stepnode;
extern std::vector<std::string> item;
extern std::vector<stepnode> steptree;

class Parser
{
public:
    static void ParseFile(std::string filename);
    static void HandleLine(std::string &line);
    static void ParseLine(std::string line, std::vector<std::string> &token);
    static void ProcessTokens(std::vector<std::string> &token);
    static void ProcessStep(std::string stepname);
    static void ProcessSpeak(std::vector<std::string> token);
    static void ProcessAssign(std::vector<std::string> token);
    static void ProcessGetdata(std::string user);
    static void ProcessListen(std::string starttimer, std::string stoptimer);
    static void ProcessBranch(std::string answer, std::string nextstepid);
    static void ProcessSilence(std::string nextstepid);
    static void ProcessDefault(std::string nextstepid);
    static void ProcessExit();
    static void ProcessExpression(std::vector<std::string> token);
};