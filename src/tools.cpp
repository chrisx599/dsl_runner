#include "tools.h"

/*作用:查找下一个Step,将index改到下一个Step步骤
* 参数:instruction:指令名称
       index:当前Step索引
* 返回:无*/
void FindNextStep(std::string instruction, int &index)
{
    int size = steptree.size();
    stepnode temp;
    for (int i = index + 1; i < size; i++)
    {
        temp = steptree[i];
        if (temp.first == "Branch")
        {
            if(instruction == temp.second[0])
            {
                int re = FindProcId(temp.second[1]);
                if(re)
                {
                    index = re;
                    break;
                }
                else
                    ScriptError();
            }
        }
        else if (temp.first == "Silence")
        {
            if(instruction == "")
            {
                int re = FindProcId(temp.second[0]);
                if(re)
                {
                    index = re;
                    break;
                }
                else
                    ScriptError();
            }   
        }
        else if (temp.first == "Default")
        {
            int re = FindProcId(temp.second[0]);
            if(re)
                index = re;
            else
                ScriptError();
            break;
        }
    }
}

/*作用:查找Step程序名称
* 参数:wantproc:想要查找的Step程序名称
* 返回:无*/
int FindProcId(std::string wantproc)
{
    int size = steptree.size();
    for (int j = 0; j < size; j++)
    {
        if (steptree[j].first == "Step")
        {
            if (steptree[j].second[0] == wantproc)
            {
                return j;
            }
        }
    }
    return 0;
}

/*作用:错误处理
* 参数:无
* 返回:无*/
void ScriptError()
{
    std::cout << "Error:Script Wrong" << std::endl;
}