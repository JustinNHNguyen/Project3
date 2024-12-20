#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>
#include "mergequicksort.cpp"
#include "game.h"

using namespace std;

//function to easily display the changeSetting functionality of the menu
void changeSetting(string& price1, string& price2, int& algorithm) {
    cout << "Enter Minimum Price: ";
    cin >> price1;
    cout << "Enter Max Price:     ";
    cin >> price2;
    cout << "Choose Algorithm\n1.Merge Sort   2.Quick Sort\n";
    cin >> algorithm;
}

//function that parses a csv file to create the vector of game objects
vector<game> parse(string filename) {
    vector<game> list;
    //ifstream for rows of the csv
    ifstream file(filename);
    string line;
    //continues until no rows left
    while(getline(file,line)) {
        //stringstream to seperate row into cells
        stringstream part(line);
        string cell;
        game temp;
        getline(part, cell, ',');
            //first get is name
            temp.setname(cell);
            //second get is releasedate, only care about year (last 2 chars)
            getline(part,cell, ',');
            size_t pos = cell.find_last_of('/');
            if (pos != string::npos) {
                temp.setrelease(stoi(cell.substr(pos+1,4)));
            } else {
                temp.setrelease(-1);
            }
            //third get is estimated players in form of 0 - ####, we will use higher range
            getline(part, cell, ',');
            pos = cell.find('-');
            if (pos != string::npos) {
                temp.setplayers(stoi(cell.substr(pos+2,cell.length()-pos+2)));
            } else {
                temp.setplayers(0);
            }
            //forth get is price
            getline(part, cell, ',');
            temp.setprice(stof(cell));
            //fifth get is review rating
            getline(part, cell, ',');
            temp.setreviews(stoi(cell));
        list.push_back(temp);
    }
    return list;
}

game getBest(vector<game> list, int price1, int price2) {
    int j = 1;
    game* best = &list[0];
    game* prev = best;
    //gets the first instance of the lower priced game
    while (!(best->getprice() >= price1))
    {
        best = &list[j];
        j++;
    }
    int i = j+1;
    game* current = &list[i];
    while (current->getprice() <= price2 && i < list.size()) {
        if (prev->getprice() > current->getprice()) {
            cout << "ERROR ERROR NOT SORTED ERROR ERROR" << endl;
            break;
        }
        // priority is Reviews > players > release > price. If any category is within ~~ margin go to next
        float diff = current->getreviews() - best->getreviews() ;
        //if review score above 10% of best than replace
        if(diff > best->getreviews()*.1) {
            best = current;
        //if difference not greater than +10% but still is higher check players
        } else if (best->getreviews() < current->getreviews()){
            diff = current->getplayers() - best->getplayers();
            //if current.players above 30%, replace 
            if(diff > best->getplayers()*.3) {
                best = current;
                //if current.players is higher check release year
            } else if (best->getplayers() < current->getplayers()) {
                // Final benchmark is release year, 
                if (best->getrelease() < current->getrelease()) {
                    best = current;
                }
                //if same releaase year check review scores 
                else if (best->getrelease() <= current->getrelease()) {
                    if (best->getreviews() < current->getreviews()) {
                        best = current;
                    }
                }
            }
        }
        i++;
        prev = current;
        current = &list[i];
    }
    return *best;
}


int main() {
    vector<game> list = parse("expanded_games.csv");
    string price1 = "_____";
    string price2 = "_____";
    int algorithm = -1;
    int runtime = 0;
    bool first = true;
    /*
    used to test parse
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i].getname() << endl;
    }
    */

    //main loop for the terminal-based menu
    while (true)
    {
        vector<game> sorted_list = list;
        game best;
        //if not the first time, then program should be running one of the sort algorithms
        if (!first) {
            cout << "Sorting . . ." << endl;
            auto begin = chrono::high_resolution_clock::now();
            if (algorithm == 1) {
                mergeSort(sorted_list, 0, list.size()-1);
            } else if (algorithm == 2) {
                quickSort(sorted_list, 0, list.size()-1);
            }
            cout << "Sort Complete. . ." << endl << "Suggesting Game. . ." << endl;
            best = getBest(sorted_list, stoi(price1), stoi(price2));
            auto end = chrono::high_resolution_clock::now();
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            runtime = chrono::duration_cast<chrono::milliseconds>(end-begin).count();
        }
        cout << "\nThe Price is just Right\n\n";
        cout << "$" << price1 << " --- $" << price2 << endl;
        cout << "Algorithm Choice: ";
        if (algorithm == 1) {
            cout << "Merge Sort" << endl;
        } else if (algorithm == 2) {
            cout << "Quick Sort" << endl;
        } else {
            cout << "_____" << endl;
        }
        cout << "Run Time:         " << runtime << " ms" << endl;
        cout << "Suggested Game:   " << best.getname() << endl;
        if (!first) {
            cout << "1. Change Settings\n2. Exit\n";
            int choice;
            cin >> choice;
            if (choice == 1) {
                changeSetting(price1, price2, algorithm);    
            } else {
                break;
            }
        } else {
            changeSetting(price1, price2, algorithm);
            first = false;
        }
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
     
    //terminal menu
        //get price range from user 
        //choose mergeSort(list) or quickSort(list)
        //start timer
        //get sorted list of games
        //get sublist of games in price range
        //choose best game based on other variables
        //end timer
        //display best game
        //*display a paging of sublist to view all games in price range* 
        //display elapsed time
    return 0;
}