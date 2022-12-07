#include "headers/december2nd.h"

#include <fstream>
#include <iostream>
#include <string>

int calculateShape(char shape)
{
    switch (shape)
    {
    case 88:
        return 1;
    case 89:
        return 2;
    case 90:
        return 3;
    default:
        return 0;
    }
}


void December2nd()
{
    // File infos
    std::ifstream f( "inputs/december2nd.txt" );
    std::string s;

    int sum = 0;
    
    // Read file
    while (getline( f, s ))
    {

        char opponent = (char)s.substr(0, s.find(" "))[0];
        char player = (char)s.substr(2, s.find(" "))[0];
        
        if((player - opponent) == 23) // Draw
            sum += (3 + calculateShape(player));
        else if(((player - opponent) % 3) == 0) // Win
            sum += (6 + calculateShape(player));
        else // Lose
            sum += calculateShape(player);
    }
    std::cout << "The total score is : " << sum; 
}
