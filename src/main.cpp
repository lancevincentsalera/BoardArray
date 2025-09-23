#include <iostream>
#include "boardarray.h"
using namespace std;

int main() {
	Entry* player1 = new Entry();
	Board* board = new BoardArray();
    char ans;
    int score;
	do {
		cout << "Op: ";
		cin >> ans;
        switch (ans) {
            case 'a':
        		cout << "Enter name: ";
                cin.ignore(); 
        		getline(cin, player1->name);
        		cout << "Enter college: ";
        		cin >> player1->college;
        		cout << "Enter score: ";
        		cin >> player1->score;
        		board->add(player1);
                break;
            case 'p':
                board->print();
                break;
            case 'x':
                cout << "Exiting";
                break;
            default:
                cout << "Invalid operation" << endl;
        }
	} while (ans != 'x');
    
	return 0;
}