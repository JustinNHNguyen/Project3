#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <string>
using namespace std;

class game {
private:
    string name;
    float price;
    int releasedate;
    int reviews;
    int players;
public:
    game();
    game(string name, float price, int releasedate, int reviews, int players);
    string getname();
    float getprice();
    int getrelease();
    int getreviews();
    int getplayers();
    void setname(string name);
    void setprice(float price);
    void setrelease(int releasedate);
    void setreviews(int reviews);
    void setplayers(int players);
    void swap(game& swapee);
    ~game();
};

#endif

