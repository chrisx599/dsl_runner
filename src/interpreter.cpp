#include "interpreter.h"

static std::map<std::string, std::string> varname;

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
                words+=temp->second;
        }
        else
            words+=expression[i];
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
    std::string filename = "userdata.db";
    ifs.open(filename, std::ios::in);
    while (!ifs.eof())
    {
        std::string temp, amount;
        ifs >> temp >> amount;
        if(temp == user[0])
            varname.insert(std::make_pair(std::string("amount"), amount));
    }
    varname.insert(std::make_pair(std::string("amount"), std::string("0")));
    ifs.close();
}

void Interpreter::Listen(std::vector<std::string> timer, int &index)
{
    std::cout << "请在" << timer[0] << "秒到" << timer[1] << "秒输入,正在等待用户输入:" << std::endl;
    std::string instruction;
    std::cin >> instruction;
    FindNextStep(instruction, index);
}

void Interpreter::Exit()
{
    std::cout << "程序已结束" << std::endl;
}

void Interpreter::Error()
{
    std::cout << "错误:脚本文件发生错误" << std::endl;
}