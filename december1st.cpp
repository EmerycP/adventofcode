#include "headers/december1st.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <climits>


void December1st()
{
    // File infos
    std::ifstream f( "inputs/december1st.txt" );
    std::string s;

    // Var for sum
    std::vector<int> sumEveryElf;
    int sum = 0;

    // Read file
    while (getline( f, s ))
    {
        if(s.empty())
        {
            sumEveryElf.push_back(sum);
            sum = 0;
        }
        else
        {
            sum += std::stoi(s);
        }

        if(f.eof())
        {
            sum += std::stoi(s);
            sumEveryElf.push_back(sum);
        }
    }

    // Part 1
    // Find max
    int maximum = 0;
    for(int sumElf : sumEveryElf)
    {
        if(sumElf >= maximum)
            maximum = sumElf;
    }
    std::cout << "The most calories an Elf is carrying is " << maximum << ". " << std::endl;
    
    // Part 2.
    // Find top 3
    int max = INT_MIN;
    int secondMax = INT_MIN;
    int thirdMax = INT_MIN;
    for(int sumElf : sumEveryElf)
    {
        if(sumElf > max)
        {
            thirdMax = secondMax;
            secondMax = max;
            max = sumElf;
        }
        else
        {
            if(sumElf > secondMax)
            {
                thirdMax = secondMax;
                secondMax = sumElf;
            }
            else
            {
                if(sumElf > thirdMax)
                    thirdMax = sumElf;  
            }
        }
    }
    
    std::cout << "The top 3 elves are carrying a total of " << (max + secondMax + thirdMax) << " calories.";
}
