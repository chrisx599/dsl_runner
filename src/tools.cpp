#include "tools.h"

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

void ScriptError()
{
    std::cout << "Error:Script Wrong" << std::endl;
}