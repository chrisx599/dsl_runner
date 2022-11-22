#include "interpreter.h"

std::map<std::string, std::string> varname;

/*作用:对关键词Speak进行解释,输出语句
* 参数:expression:将要输出的语句
* 返回:无*/
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

/*作用:对关键词Assign进行解释,对变量进行赋值
* 参数:var:将要赋值的变量集合
* 返回:无*/
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

/*作用:对关键词Getdata进行解释,对db数据库字典查找数据
* 参数:parameter:parameter中有两个字符串,字符串1为key变量,字符串2为将要保存value的变量
* 返回:无*/
void Interpreter::Getdata(std::vector<std::string> parameter)
{
    std::ifstream ifs;
    std::string filename = "./data/data.db";
    ifs.open(filename, std::ios::in);
    while (!ifs.eof())
    {
        std::string dicfirst, dicsecond;
        ifs >> dicfirst >> dicsecond;
        auto indexitem = varname.find(parameter[0]);
        if(indexitem == varname.end())
        {
            Interpreter::Error();
            break;
        }
        if(dicfirst == indexitem->second)
        {
            varname.insert(std::make_pair(parameter[1], dicsecond));
            return;
        } 
    }
    varname.insert(std::make_pair(parameter[1], std::string("-1")));
    ifs.close();
}

/*作用:对关键词Listen进行解释,将index改为用户输入的指令对应的Step步骤
* 参数:timer:时间段
       index:当前runner环境中运行到的step步骤索引
* 返回:无*/
void Interpreter::Listen(std::vector<std::string> timer, int &index)
{
    std::cout << "Please input from " << timer[0] << " seconds to " << timer[1] << " secondes, wating for input:" << std::endl;
    std::string instruction;
    std::cin >> instruction;
    FindNextStep(instruction, index);
}

/*作用:对关键词Exit进行解释,退出程序
* 参数:expression:将要输出的语句
* 返回:无*/
void Interpreter::Exit()
{
    std::cout << "Script is ending" << std::endl;
}

/*作用:错误处理
* 参数:无
* 返回:无*/
void Interpreter::Error()
{
    std::cout << "Error:Script Wrong" << std::endl;
}