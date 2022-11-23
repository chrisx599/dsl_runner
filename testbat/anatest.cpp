#include "analysis.h"

using namespace std;

int main()
{
    string filename;
    cin >> filename;
    Parser::ParseFile(filename);
    int size = steptree.size();
    for (int i = 0; i < size; i++)
    {
        stepnode node = steptree[i];
        cout << node.first << " ";
        int size2 = node.second.size();
        for (int j = 0; j < size2; j++)
            cout << node.second[j] << " ";
        cout << "\n";
    }
    
    system("pause");
    return 0;
}