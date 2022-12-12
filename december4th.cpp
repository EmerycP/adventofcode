#include "headers/december4th.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int transformValue(char t, char t2)
{
    if(t2 != '-' && t2 != ',')
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
        // Vectors for comparaison   
        std::vector<int> firstOfPair;
        std::vector<int> secondOfPair;

        // Get both pair
        std::stringstream line(s);
        std::string pair;
        while(getline(line, pair, ','))
        {
            std::stringstream pairsToDelimit(pair);
            std::string currentDelimitedPair;

            // First value of the pair
            getline(pairsToDelimit, currentDelimitedPair, '-');
            firstOfPair.push_back(stoi(currentDelimitedPair));

            // Second value of the pair
            std::getline(pairsToDelimit, currentDelimitedPair, '-');
            secondOfPair.push_back(stoi(currentDelimitedPair));
        }
        
        if(firstOfPair[0] <= secondOfPair[1] && firstOfPair[0] >= firstOfPair[1] &&
            secondOfPair[0] >= firstOfPair[1] && secondOfPair[0] <= secondOfPair[1])
                count++;
        else if(secondOfPair[1] >= firstOfPair[0] && secondOfPair[1] <= secondOfPair[0] &&
            firstOfPair[1] <= secondOfPair[0] && firstOfPair[1] >= firstOfPair[0])
                count++;
    }
    std::cout << count;
}
