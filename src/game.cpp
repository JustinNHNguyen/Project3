#include "game.h"

using namespace std;

game::game(string name, float price, int releasedate, int reviews, int players) {
    this->name = name;
    this->price = price;
    this->releasedate = releasedate;
    this->reviews = reviews;
    this->players = players;
}
string game::getname() {
    return this->name;
}

float game::getprice() {
    return this->price;
}

int game::getrelease() {
    return this->releasedate;
}

int game::getreviews() {
    return this->reviews;
}

int game::getplayers() {
    return this->players;
}

void game::swap(game& swapee) {
    string temp = this->name;
    this->name = swapee.getname();
    swapee.name = temp;

    float temp3 = this->price;
    this->price = swapee.getprice();
    swapee.price = temp3;

    int temp2 = this->releasedate;
    this->releasedate = swapee.getrelease();
    swapee.releasedate = temp2;
    
    temp2 = this->reviews;
    this->reviews = swapee.getreviews();
    swapee.reviews = temp2;

    temp2 = this->players;
    this->players = swapee.getplayers();
    swapee.players = temp2;
}

//game::~game(){

//}
