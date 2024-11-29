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
    game(string, int, int, int, int);
    string getname();
    int getprice();
    int getrelease();
    int getreviews();
    int getplayers();
    void swap(game&);
    ~game();
};


