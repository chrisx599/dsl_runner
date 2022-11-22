#include "interpreter.h"

int main(int argc, char** argv)
{
    std::cout << "Program is starting" << std::endl;
    if(argc != 2)
    {
        std::cout << "Error:Please use correct form:./runner.exe script_name.ss" << std::endl;
        system("pause");
        return 0;
    }
    if(!Parser::ParseFile(argv[1]))
    {
        std::cout << "Error:Script parser tree is not created" << std::endl;
        system("pause");
        return 0;
    }
    std::cout << "Script parser tree is created" << std::endl;

    int i = 0;
    stepnode node = steptree[0];
    int nextstepid;
    while (1)
    {
        if(node.first == "Step")
        {
            node = steptree[++i];
            continue;
        }
        else if(node.first == "Speak")
        {
            Interpreter::Speak(node.second);
            node = steptree[++i];
        }
        else if(node.first == "Assign")
        {
            Interpreter::Assign(node.second);
            node = steptree[++i];
        }
        else if(node.first == "Getdata")
        {
            Interpreter::Getdata(node.second);
            node = steptree[++i];
        }
        else if(node.first == "Listen")
        {
            Interpreter::Listen(node.second, i);
            node = steptree[i];
        }
        else if(node.first == "Exit")
        {
            Interpreter::Exit();
            break;
        }   
        else
        {
            Interpreter::Error();
            break;
        }
    }


    system("pause");
    return 0;
}
