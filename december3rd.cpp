#include "headers/december3rd.h"

#include <fstream>
#include <iostream>
#include <string>


void December3rd()
{
    // File infos
    std::ifstream f( "inputs/december3rd.txt" );
    std::string s;
    int total = 0;
    
    // Read file
    while (getline( f, s ))
    {
        std::string firstHalf = s.substr(0, s.length() / 2);
        std::string secondHalf = s.substr(s.length() / 2);

        bool found = false;
        for (int i = 0; i < firstHalf.length(); ++i)
        {
            for (int j = 0; j < secondHalf.length(); ++j)
            {
                if(secondHalf[j] == firstHalf[i])
                {
                    if(std::islower(secondHalf[j]))
                        total += 1 + secondHalf[j] - 'a';
                    else
                        total += 27 + secondHalf[j] - 'A';

                    found = true; break;
                }
            }
            if(found) break;
        }
    }
    std::cout <<  total << std::endl;
}
