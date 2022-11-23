#include "interpreter.h"

int main(int argc, char** argv)
{
    std::cout << "Program is starting" << std::endl;
    if(argc != 2 && argc != 3)
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

    int i = 0, cnt = 0;
    stepnode node = steptree[0];
    int nextstepid;
    while (1)
    {
        if(node.first == "Step")
        {
            cnt++;
            node = steptree[++i];
            continue;
        }
        else if(node.first == "Speak")
        {
            cnt++;
            Interpreter::Speak(node.second);
            node = steptree[++i];
        }
        else if(node.first == "Assign")
        {
            cnt++;
            Interpreter::Assign(node.second);
            node = steptree[++i];
        }
        else if(node.first == "Getdata")
        {
            cnt++;
            if(argc == 2)
                Interpreter::Getdata(node.second);
            else if(argc == 3)
                Interpreter::Getdata(argv[2], node.second);
            node = steptree[++i];
        }
        else if(node.first == "Listen")
        {
            cnt++;
            Interpreter::Listen(node.second, i);
            node = steptree[i];
        }
        else if(node.first == "Exit")
        {
            cnt++;
            Interpreter::Exit();
            break;
        }
        else if(node.first == "Endstep")
        {
            i-=cnt;
            cnt = 0;
            node = steptree[i];
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
