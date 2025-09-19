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

        void add(Entry* entry) 
        {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT
            if(index == 0)
            {
                array[0] = *entry;
                index++;
                return;
            }

            int pos = 0;
            for(int i = 0; i < index; i++)
            {
                if(entry->score > array[i].score)
                {
                    pos = i;
                    break;
                }
                pos++;
            }

            if(index < SIZE)
            {
                for(int i = index; i > pos; i--)
                {
                    array[i] = array[i-1];
                }
                array[pos] = *entry;
                index++;
            }
            else if(pos < SIZE)
            {
                if(entry->score <= array[SIZE-1].score)
                {
                    cout<<entry->score<<"'s score is too low to be added!'"<<endl;
                    return;
                }
                for(int i = SIZE - 1; i > pos; i--)
                {
                    array[i] = array[i-1];
                }
                array[pos] = *entry;
            }
            else
            {
                cout<<entry->name<<"'s score is too low to be added!"<<endl;
            }

        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};