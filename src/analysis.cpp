#include "analysis.h"


/*作用:读取脚本文件
* 参数:filename:文件名称
*/
void Parser::ParseFile(std::string filename)
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
        ProcessTokens(token);
        token.clear();
    }
    ifs.close();
}


/*作用:去除字符串中的行首空白字符
* 参数:line:待处理字符串
*/
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
*/
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


/*作用:对token进行处理
* 参数:token:获取到的单词
*      varname:用于保存变量名
*      steptree:用于构建step语法树
*/
void Parser::ProcessTokens(std::vector<std::string> &token)
{
    int token_size = token.size();
    if(token[0] == "Step")
        ProcessStep(token[1]);
    else if(token[0] == "Speak")
        ProcessSpeak(token);
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
    else
    {

    }
}

void Parser::ProcessStep(std::string stepname)
{
    std::vector<std::string> temp;
    temp.push_back(stepname);
    stepnode node;
    node = std::make_pair("Step", temp);
    steptree.push_back(node);
}

void Parser::ProcessSpeak(std::vector<std::string> token)
{
    ProcessExpression(token);
    stepnode node;
    node = std::make_pair("Speak", item);
    steptree.push_back(node);
    item.clear();
}

void Parser::ProcessExpression(std::vector<std::string> token)
{
    int size = token.size();
    for (int i = 1; i < size; i++)
    {
        if(token[i] == "+")
            continue;
        else
            item.push_back(token[i]);
    }
}

void Parser::ProcessListen(std::string starttimer, std::string stoptimer)
{
    stepnode node;
    std::vector<std::string> timer;
    timer.push_back(starttimer);
    timer.push_back(stoptimer);
    node = std::make_pair("Listen", timer);
    steptree.push_back(node);
}
void Parser::ProcessBranch(std::string answer, std::string nextstepid)
{
    stepnode node;
    std::vector<std::string> temp;
    temp.push_back(answer);
    temp.push_back(nextstepid);
    node = std::make_pair("Branch", temp);
    steptree.push_back(node);
}
void Parser::ProcessSilence(std::string nextstepid)
{
    stepnode node;
    std::vector<std::string> temp;
    temp.push_back(nextstepid);
    node = std::make_pair("Silence", temp);
    steptree.push_back(node);
}
void Parser::ProcessDefault(std::string nextstepid)
{
    stepnode node;
    std::vector<std::string> temp;
    temp.push_back(nextstepid);
    node = std::make_pair("Default", temp);
    steptree.push_back(node);
}
void Parser::ProcessExit()
{
    stepnode node;
    std::vector<std::string> temp;
    temp.push_back("");
    node = std::make_pair("Exit", temp);
    steptree.push_back(node);
}