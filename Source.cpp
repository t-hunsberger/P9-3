#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayRun(int values[], int size) {
    bool inRun = false;
    for (int i = 0; i < size; ++i) {
        if (i > 0 && values[i] == values[i - 1]) {
            if (!inRun) {
                cout << "(" << values[i];
                inRun = true; 
            }
            else {
                cout << " " << values[i];
            }
        } 
        else {
            if (inRun) { 
                cout << ")";
                inRun = false; 
            }
            cout << " " << values[i];
        }
    }
    if (inRun) {
        cout << ")";
    }
}

bool hasRun(int values[], int size) {
    for (int i = 1; i < size; ++i) {
        if (values[i] == values[i - 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(nullptr));

    int dice[20];
    bool foundRun = false;

    do {
        // Generate sequence of 20 random six-sided die rolls
        for (int i = 0; i < 20; ++i) {
            dice[i] = rand() % 6 + 1;
        }

        // Check if the sequence has a run
        foundRun = hasRun(dice, 20);

        if (foundRun) {
            cout << "has run:";
        }
        else {
            cout << "no run:";
        }

        // Display the sequence with runs marked
        displayRun(dice, 20);
        cout << endl;

    } while (!foundRun);

    return 0;
}


