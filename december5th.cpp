#include "headers/december5th.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void extractIntegerWords(std::string str, std::vector<int>& vec)
{
    std::stringstream ss;
    ss << str;

    std::string temp;
    int found;
    while (!ss.eof()) {
        ss >> temp;

        if (std::stringstream(temp) >> found)
            vec.push_back(found);

        temp = "";
    }
}

void December5th()
{
    // File infos
    std::ifstream f( "inputs/december5th" );
    std::string s;

    std::vector<std::vector<char>> stacks(9);
    
    // Read file
    while (getline( f, s ))
    {
        std::vector<int> instructions;
        if (s.find("from") != std::string::npos) {
            extractIntegerWords(s, instructions);
            // to add

            // Reverse every stacks
            for (int i = 0; i < stacks.size(); ++i)
            {
                std::reverse(stacks[i].begin(), stacks[i].end());
            }

            for (int i = 0; i < instructions[0]; ++i)
            {
                char lastChar = stacks[instructions[1] - 1].at(stacks[instructions[1] - 1].size() - 1);
                stacks[instructions[1] - 1].pop_back();
                stacks[instructions[2] - 1].push_back(lastChar);
            }
        }
        else if(!s.empty())
        {
            int index = 0;
            int vectorIdx = 0;
            for (auto character : s)
            {
                if(index == 1 && (character > 57 || character < 49))
                {
                    if(character != ' ')
                        stacks[vectorIdx].push_back(character);
                    vectorIdx++;
                }

                if(vectorIdx == 9)
                    break;
                
                if(index == 3)
                    index = 0;
                else
                    index++;
            }
        }
    }

    std::cout << "Here's every crate on top: ";
    for (int i = 0; i < stacks.size(); ++i)
    {
        std::cout << stacks[i].at(stacks[i].size() - 1);
    }
    
}
