#include <iostream>
#include "network.h"
#include "profile.h"
#include <string>
#include <cctype>

int Network::findID(std::string usrn)
{
    for (int i = 0; i < numUsers; i++)
    {
        if (profiles[i].getUsername() == usrn)
        {
            return i;
        }
    }
    return -1;
}

Network::Network()
{
    numUsers = 0;

    for (int i = 0; i < MAX_USERS; i++) 
    { 
        for(int j = 0; j < MAX_USERS; j++) 
        { 
            following[i][j] = false; //false by default
        }
    }
}

bool Network::addUser(std::string usrn, std::string dspn)
{
    if (numUsers == MAX_USERS || findID(usrn) != -1 || usrn == "")
    {
        return false;
    }
    
    for (int i = 0; i < usrn.length(); i++)
    {
        if (!isalnum(usrn[i]))
        {
            return false;
        }
    }
    
    profiles[numUsers] = {usrn, dspn};
    numUsers++;
    return true;
}

bool Network::follow(std::string usrn1, std::string usrn2)
{
    if (findID(usrn1) == -1 || findID(usrn2) == -1)
    {
        return false;
    }

    following[findID(usrn1)][findID(usrn2)] = true;
    return true;
}

void Network::printDot()
{
    std::cout << "digraph {\n";
    for (int i = 0; i < numUsers; i++) 
    { 
        std::cout << " @" << profiles[i].getUsername() << "\n";
    }
    
    std::cout << "\n";

    for (int i = 0; i < MAX_USERS; i++) 
    { 
        for (int j = 0; j < MAX_USERS; j++) 
        { 
            if (following[i][j] == true) 
            { 
                std::cout << " @" << profiles[i].getUsername() << " -> @" << profiles[j].getUsername() << "\n";
            }
        }
    }
    std::cout << "}\n";
}