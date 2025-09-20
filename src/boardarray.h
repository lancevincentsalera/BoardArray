#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT

            for (int i = 0; i < SIZE; i++){
                if (entry->compare(&array[i])){
                    for(int j = SIZE - 1; j > i; j--){
                        array[j] = array[j - 1];
                        }
                    array[i] = *entry;
                    index++;
                    return;
                }
            }

            cout << entry->name << "'s score is too low to be added!" << endl;
            
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};