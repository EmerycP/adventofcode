#include "headers/december3rd.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>


void December3rd()
{
    // File infos
    std::ifstream f( "inputs/december3rd.txt" );
    std::string s;
    int total = 0;

    std::vector<std::string> stacks;
    int count = 0;
    // Read file
    while (getline( f, s ))
    {
        // Part 1
        // std::string firstHalf = s.substr(0, s.length() / 2);
        // std::string secondHalf = s.substr(s.length() / 2);
        //
        // bool found = false;
        // for (int i = 0; i < firstHalf.length(); ++i)
        // {
        //     for (int j = 0; j < secondHalf.length(); ++j)
        //     {
        //         if(secondHalf[j] == firstHalf[i])
        //         {
        //             if(std::islower(secondHalf[j]))
        //                 total += 1 + secondHalf[j] - 'a';
        //             else
        //                 total += 27 + secondHalf[j] - 'A';
        //
        //             found = true; break;
        //         }
        //     }
        //     if(found) break;
        // }

        // Part 2
        stacks.push_back(s);
        if(stacks.size() == 3)
        {
            bool found = false;
            for (char firstStackValue : stacks.at(0))
            {
                for (char secondStackValue : stacks.at(1))
                {
                    if(firstStackValue == secondStackValue)
                    {
                        for (char thirdStackValue : stacks.at(2))
                        {
                            if(thirdStackValue == secondStackValue)
                            {
                                if(std::islower(thirdStackValue))
                                    total += 1 + thirdStackValue - 'a';
                                else
                                    total += 27 + thirdStackValue - 'A';
                                found = true;
                                break;
                            }
                        }
                    }
                    if(found)break;
                }
                if(found)break; 
            }
            stacks.clear();
        }
    }
    std::cout <<  total << std::endl;
}
