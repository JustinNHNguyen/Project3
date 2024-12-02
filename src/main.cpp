#include <vector>
#include <string>
#include <iostream>
//#include "game.h"
using namespace std;


void changeSetting(string& price1, string& price2, int& algorthim) {
    cout << "Enter Minimum Price: ";
    cin >> price1;
    cout << "Etner Max Price:  ";
    cin >> price2;
    cout << "Choose Algorithm\n1.Merge Sort   2.Quick Sort\n";
    cin >> algorthim;
}

int main() {
    //vector<game> list; 
    //parse csv to create game objects -> insert into vector
    string price1 = "_____";
    string price2 = "_____";
    int algorithm = -1;
    int runtime = 0;
    bool first = true;
    //game best("_____", 0, 0, 0, 0);
    while (true)
    {
        if (!first) {
            //start timer
            if (algorithm == 1) {
                //mergeSort(list);
            } else if (algorithm == 2) {
                //quickSort(list);
            }
            //vector<game> subList = getsublist(price1, price2, list);
            
            //best = getBest(sublist);
            
            //end timer
        }
        cout << "The Price is just Right\n\n";
        cout << "$" << price1 << " --- $" << price2 << endl;
        cout << "Algorithm Choice: ";
        if (algorithm == 1) {
            cout << "Merge Sort" << endl;
        } else if (algorithm == 2) {
            cout << "Quick Sort" << endl;
        } else {
            cout << "_____" << endl;
        }
        cout << "Run Time: " << runtime << " ms" << endl;
        cout << "Suggested Game: " << "best.getname()" << endl;
        if (!first) {
            cout << "1. See Other Games\n2. Change Settings\n3. Exit\n";
            int choice;
            cin >> choice;
            if (choice == 1) {
                //pageResults(subList);
            } else if (choice == 2) {
                changeSetting(price1, price2, algorithm);    
            } else {
                break;
            }
        } else {
            changeSetting(price1, price2, algorithm);
            first = false;
        }
        cout << "\n\n\n\n\n\n\n";
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