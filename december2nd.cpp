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

int calculateOpposite(char shape, bool shouldWin)
{
    switch (shape)
    {
    case 65:
        return shouldWin ? 2 : 3;
    case 66:
        return shouldWin ? 3 : 1;
    case 67:
        return shouldWin ? 1 : 2;
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

        // Part 1
        // if((player - opponent) == 23) // Draw
        //     sum += (3 + calculateShape(player));
        // else if(((player - opponent) % 3) == 0) // Win
        //     sum += (6 + calculateShape(player));
        // else // Lose
        //     sum += calculateShape(player);

        // Part 2
        switch (player)
        {
        case 88: // Lose
            sum += calculateOpposite(opponent, false);
            break;
        case 89: // Draw
            sum += 3 + calculateShape(opponent += 23);
            break;
        case 90: // Win
            sum += 6 + calculateOpposite(opponent, true);
            break;
        default:
            break;
        }
            
        
    }
    std::cout << "The total score is : " << sum; 
}
