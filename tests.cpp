#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"
#include <string>

Profile p1("marco", "Marco");    
Profile p2("polo", "Polo");    
Profile p3("tarma1", "Tarma Roving");       

TEST_CASE("TASK A") 
{
    CHECK(p1.getUsername() == "marco");
    CHECK(p2.getUsername() == "polo");
    CHECK(p3.getUsername() == "tarma1");

    CHECK(p1.getFullName() == "Marco (@marco)");
    CHECK(p2.getFullName() == "Polo (@polo)");
    CHECK(p3.getFullName() == "Tarma Roving (@tarma1)");
}

TEST_CASE("TASK B") 
{
    Network nw; 
    CHECK(nw.addUser("mario", "Mario") == true); 
    CHECK(nw.addUser("mario", "Mario") == false); 
    CHECK(nw.addUser("mario-2", "Mario2") == false);
    CHECK(nw.addUser("yoshi1", "yoshi") == true); 
    CHECK(nw.addUser("yoshi", "Yoshi") == true);
}

TEST_CASE("TASK C") 
{ 
    Network nw2;

    CHECK(nw2.addUser("mario", "Mario") == true);
    CHECK(nw2.addUser("luigi", "Luigi") == true);

    nw2.addUser("mario", "Mario");
    nw2.addUser("luigi", "Luigi");
    for(int i = 2; i < 20; i++) 
    {
        nw2.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i));
    }

    CHECK(nw2.addUser("user", "user") == false); 

    nw2.addUser("mario", "Mario");
    nw2.addUser("luigi", "Luigi");
    for(int i = 2; i < 20; i++) 
    {
        nw2.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i));
    }

    CHECK(nw2.follow("mario", "luigi") == true);
    CHECK(nw2.follow("mario-", "mario") == false);
    CHECK(nw2.follow("mario1", "mario2") == false);
    CHECK(nw2.follow("mario2", "mario2") == true); 
    CHECK(nw2.follow("mario-3", "mario3") == false); 
}