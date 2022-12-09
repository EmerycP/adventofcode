#include "headers/december4th.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int transformValue(char t, char t2)
{
    if(t2 != '-')
        return (((int)t - '0') * 10) + (int)t2 - '0';
    else
        return (int)t - '0';
}

void December4th()
{
    // File infos
    std::ifstream f( "inputs/december4th");
    std::string s;
    int count = 0;
    
    // Read file
    while (getline( f, s ))
    {
        std::string fAssign = s.substr(0, s.length() / 2);
        std::string sAssign = s.substr(s.length() / 2 + 1);
        
        int compareValueA = transformValue(fAssign[0], fAssign[1]);
        int index = fAssign[1] != '-' ? 3 : 2;
        int compareValueB = transformValue(fAssign[index], fAssign[index + 1]);
        
        int compareValueC = transformValue(sAssign[0], sAssign[1]);
        int index2 = sAssign[1] != '-' ? 3 : 2;
        int compareValueD = transformValue(sAssign[index2], sAssign[index2 + 1]);
        
        if(compareValueA <= compareValueD && compareValueA >= compareValueC &&
            compareValueB >= compareValueC && compareValueB <= compareValueD)
                count++;
        else if(compareValueA >= compareValueD && compareValueA <= compareValueC &&
            compareValueB <= compareValueC && compareValueB >= compareValueD)
                count++;
    }
    std::cout << count;
}
