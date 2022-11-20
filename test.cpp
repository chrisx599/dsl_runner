#include "analysis.h"
#include <iostream>
using namespace std;
int main()
{
    cout << "hel" << endl;
    Parser::ParseFile("test.txt");
    system("pause");
    return 0;
}


//#include "interpreter.h"


// int main()
// {
//     int size = steptree.size();
//     int i = 0;
//     stepnode node;
//     while (1)
//     {
//         node = steptree[i++];
//         if(node.first == "Step")
//             continue;
//         else if(node.first == "Speak")
//             Speak();
//         else if(node.first == "Listen")
//             Listen();
//         else if(node.first == "Branch")
//             Branch();
//         else if(node.first == "Silence")
//             Silence();
//         else if(node.first == "Default")
//             Default();
//         else if(node.first == "Exit")
//             break;
//         else
//         {

//         }
//     }
// }

