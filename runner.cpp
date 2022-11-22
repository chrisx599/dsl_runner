#include "interpreter.h"

int main(int argc, char** argv)
{
    std::cout << "程序正在启动……" << std::endl;
    if(!argc)
    {
        std::cout << "错误:请使用正确格式:./runner.exe 脚本文件名称" << std::endl;
        return 0;
    }
    Parser::ParseFile(argv[0]);
    std::cout << "脚本语法树已生成……" << std::endl;

    int i = 0;
    stepnode node;
    node = steptree[0];
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
}
