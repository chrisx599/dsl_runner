#include "interpreter.h"
#include "tools.h"

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
                std::cout << "错误:脚本文件发生错误" << std::endl;
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

void Interpreter::Listen(std::vector<std::string> timer)
{
    std::cout << "正在等待用户输入:" << std::endl;
    
    // unsigned int period = VecstrToU(timer);
    // time();
    // pthread_t id;
    // if(pthread_create(&id, NULL, is_timeout, (void *)&period))
    //     std::cout << "正在等待用户输入:" << std::endl;
    // pthread_join(id, )
}
void Interpreter::Branch(std::vector<std::string> expression)
{

}

void Interpreter::Silence(std::vector<std::string> expression)
{

}
void Interpreter::Default(std::vector<std::string> expression)
{

}