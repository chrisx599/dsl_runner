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
    int size = steptree.size();
    int i = 0;
    stepnode node;
    while (1)
    {
        node = steptree[i++];
        if(node.first == "Step")
            continue;
        else if(node.first == "Speak")
            Interpreter::Speak(node.second);
        else if(node.first == "Listen")
            Interpreter::Listen(node.second);
        else if(node.first == "Branch")
            Interpreter::Branch(node.second);
        else if(node.first == "Silence")
            Interpreter::Silence(node.second);
        else if(node.first == "Default")
            Interpreter::Default(node.second);
        else if(node.first == "Exit")
            break;
        else
        {

        }
    }
}
