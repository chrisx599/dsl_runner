#include "analysis.h"


std::vector<std::string> item;
std::vector<stepnode> steptree;

/*作用:读取脚本文件,生成脚本语法树
* 参数:filename:文件名称
* 返回:语法脚本树构建成功或失败*/
bool Parser::ParseFile(std::string filename)
{
    std::vector<std::string> token;
    std::ifstream ifs;
    ifs.open(filename, std::ios::in);
    std::string line;
    for (int i = 0; !ifs.eof(); i++)
    {
        std::getline(ifs, line);
        if(line == "")
            continue;
        HandleLine(line);
        ParseLine(line, token);
        if(!ProcessTokens(token))
            return 0;
        token.clear();
    }
    ifs.close();
    return 1;
}


/*作用:去除字符串中的行首空白字符
* 参数:line:待处理字符串
* 返回:无*/
void Parser::HandleLine(std::string &line)
{
   int size = line.size();
   for (int i = 0; i < size; size--)
   {
        if(line[i] == ' ')
            line.erase(i, 1);
        else
            break;
   }
}


/*作用:获得字符串中单词
* 参数:line:待处理字符串
* 返回:无*/
void Parser::ParseLine(std::string line, std::vector<std::string> &token)
{
  int size = line.size();
  std::string temp = "";
  for (int i = 0; i < size; i++)
  {
        if(line[i] == '#')
            break;
        else if(line[i] == ' ')
        {
            token.push_back(temp);
            temp = "";
        }
        else
        {
            temp+=line[i];
            if(i == size-1)
                token.push_back(temp);
        }
  }
}


/*作用:对单词集合进行处理,生成语法树节点
* 参数:token:从一串字符串处理得到的单词集合
* 返回:语法正确或错误*/
bool Parser::ProcessTokens(std::vector<std::string> &token)
{
    if(!token.size())
        return 1;
    if(token[0] == "Step")
        ProcessStep(token[1]);
    else if(token[0] == "Speak")
        ProcessSpeak(token);
    else if(token[0] == "Assign")
        ProcessAssign(token);
    else if(token[0] == "Getdata")
        ProcessGetdata(token[1], token[2]);
    else if(token[0] == "Listen")
        ProcessListen(token[1], token[2]);
    else if(token[0] == "Branch")
        ProcessBranch(token[1], token[2]);
    else if(token[0] == "Silence")
        ProcessSilence(token[1]);
    else if(token[0] == "Default")
        ProcessDefault(token[1]);
    else if(token[0] == "Exit")
        ProcessExit();
    else if(token[0] == "Endstep")
        ProcessEndstep();
    else
    {
        SyntaxError();
        return 0;
    }
    return 1;
}

/*作用:对关键词Step进行处理,向语法树中添加节点
* 参数:stepname:Step的名称
* 返回:无*/
void Parser::ProcessStep(std::string stepname)
{
    std::vector<std::string> temp;
    temp.push_back(stepname);
    stepnode node;
    node = std::make_pair("Step", temp);
    steptree.push_back(node);
}

/*作用:对关键词Speak进行处理,向语法树中添加节点
* 参数:sentense:Speak要输出的语句
* 返回:无*/
void Parser::ProcessSpeak(std::vector<std::string> sentense)
{
    ProcessExpression(sentense);
    stepnode node;
    node = std::make_pair("Speak", item);
    steptree.push_back(node);
    item.clear();
}

/*作用:对关键词Assign进行处理,向语法树中添加节点
* 参数:var:Assign要赋值的变量
* 返回:无*/
void Parser::ProcessAssign(std::vector<std::string> var)
{
    item = var;
    item.erase(item.begin());
    stepnode node;
    node = std::make_pair("Assign", item);
    steptree.push_back(node);
    item.clear();
}

/*作用:对关键词Getdata进行处理,向语法树中添加节点
* 参数:dicfirst:Getdata要查找的变量名
       dicseconde:保存Getdata查找到的内容的变量名
* 返回:无*/
void Parser::ProcessGetdata(std::string dicfirst, std::string dicsecond)
{
    stepnode node;
    std::vector<std::string> temp;
    temp.push_back(dicfirst);
    temp.push_back(dicsecond);
    node = std::make_pair("Getdata", temp);
    steptree.push_back(node);
    item.clear();
}

/*作用:去除字符串中的'+'
* 参数:sentense:待处理的语句
* 返回:无*/
void Parser::ProcessExpression(std::vector<std::string> sentense)
{
    int size = sentense.size();
    for (int i = 1; i < size; i++)
    {
        if(sentense[i] == "+")
            continue;
        else
            item.push_back(sentense[i]);
    }
}

/*作用:对关键词Listen进行处理,向语法树中添加节点
* 参数:starttimer:起始输入时间
       stoptimer:结束输入时间
* 返回:无*/
void Parser::ProcessListen(std::string starttimer, std::string stoptimer)
{
    stepnode node;
    std::vector<std::string> timer;
    timer.push_back(starttimer);
    timer.push_back(stoptimer);
    node = std::make_pair("Listen", timer);
    steptree.push_back(node);
}

/*作用:对关键词Branch进行处理,向语法树中添加节点
* 参数:answer:分支指令名称
       nextstepid:程序名称
* 返回:无*/
void Parser::ProcessBranch(std::string answer, std::string nextstepid)
{
    stepnode node;
    std::vector<std::string> temp;
    temp.push_back(answer);
    temp.push_back(nextstepid);
    node = std::make_pair("Branch", temp);
    steptree.push_back(node);
}

/*作用:对关键词Silence进行处理,向语法树中添加节点
* 参数:nextstepid:程序名称
* 返回:无*/
void Parser::ProcessSilence(std::string nextstepid)
{
    stepnode node;
    std::vector<std::string> temp;
    temp.push_back(nextstepid);
    node = std::make_pair("Silence", temp);
    steptree.push_back(node);
}

/*作用:对关键词Default进行处理,向语法树中添加节点
* 参数:nextstepid:程序名称
* 返回:无*/
void Parser::ProcessDefault(std::string nextstepid)
{
    stepnode node;
    std::vector<std::string> temp;
    temp.push_back(nextstepid);
    node = std::make_pair("Default", temp);
    steptree.push_back(node);
}

/*作用:对关键词Exit进行处理,向语法树中添加节点
* 参数:无
* 返回:无*/
void Parser::ProcessExit()
{
    stepnode node;
    std::vector<std::string> temp;
    temp.push_back("");
    node = std::make_pair("Exit", temp);
    steptree.push_back(node);
}

/*作用:对关键词Endstep进行处理,向语法树中添加节点
* 参数:无
* 返回:无*/
void Parser::ProcessEndstep()
{
    stepnode node;
    std::vector<std::string> temp;
    temp.push_back("");
    node = std::make_pair("Endstep", temp);
    steptree.push_back(node);
}

/*作用:语法错误处理
* 参数:无
* 返回:无*/
void Parser::SyntaxError()
{
    std::cout << "Error:Please check script syntax" << std::endl;
}