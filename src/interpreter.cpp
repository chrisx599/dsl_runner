#include "interpreter.h"

std::map<std::string, std::string> varname;

/**/
void Interpreter::Speak(std::vector<std::string> expression)
{
    int expsize = expression.size();
    std::string words = "";
    for (int i = 0; i < expsize; i++)
    {
        if(expression[i][0] == '$')
        {
            auto temp = varname.find(expression[i]);
            if(temp == varname.end())
            {
                Interpreter::Error();
                break;
            }
            else
                words = words + " " + temp->second;
        }
        else
            words = words + " " + expression[i];
    }
    std::cout << words << std::endl;
}

void Interpreter::Assign(std::vector<std::string> var)
{
    int varnum = var.size();
    std::string value;
    for (int i = 0; i < varnum; i++)
    {
        std::cin >> value;
        if(var[i][0] == '$')
            varname.insert(std::make_pair(var[i], value));
        else
            Interpreter::Error();
    }
}

void Interpreter::Getdata(std::vector<std::string> user)
{
    std::ifstream ifs;
    std::string filename = "./data/userdata.db";
    ifs.open(filename, std::ios::in);
    while (!ifs.eof())
    {
        std::string temp, amount;
        ifs >> temp >> amount;
        auto userid = varname.find(user[0]);
        if(userid == varname.end())
        {
            Interpreter::Error();
            break;
        }
        if(temp == userid->second)
        {
            varname.insert(std::make_pair(std::string("$amount"), amount));
            return;
        } 
    }
    varname.insert(std::make_pair(std::string("$amount"), std::string("0")));
    ifs.close();
}

void Interpreter::Listen(std::vector<std::string> timer, int &index)
{
    std::cout << "Please input from" << timer[0] << "seconds to " << timer[1] << "secondes, wating for input:" << std::endl;
    std::string instruction;
    std::cin >> instruction;
    FindNextStep(instruction, index);
}

void Interpreter::Exit()
{
    std::cout << "Script is ending" << std::endl;
}

void Interpreter::Error()
{
    std::cout << "Error:Script Wrong" << std::endl;
}