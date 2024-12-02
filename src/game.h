# pragma once

#include <string>
using namespace std;

class game {
private:
    string name;
    int price;
    int releasedate;
    int reviews;
    int players;
public:
    game(string, float, int, int, int);
    string getname();
    float getprice();
    int getrelease();
    int getreviews();
    int getplayers();
    void swap(game&);
    //~game();
};


