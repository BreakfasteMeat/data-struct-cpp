#include <iostream>
#include <stdlib.h>
using namespace std;


class ArrayList : public List {
    int cap;
    int size;
    int* arr;

public:
    ArrayList() {
        cap = 5;
        size = 0;
        arr = (int*)calloc(cap, sizeof(int));
    }

    void add(int num) {
        if (size == cap) {
            cap *= 1.5;
            arr = (int*)realloc(arr, cap * sizeof(int));
            for (int i = size; i < cap; i++) arr[i] = 0;
        }
        arr[size++] = num;
    }

    void print() {
        cout << endl << endl << "SIZE: " << size << " || CAPACITY: " << cap << endl;
        for (int i = 0; i < size; i++) {
            cout << "[" << arr[i] << "]";
        }
        cout << endl << endl;
    }

    int get(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Index out of bounds!" << endl;
            return -1;
        }
        return arr[pos];
    }

    int remove(int num) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == num) {
                // Shift all elements left to fill the gap
                for (int j = i; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                size--;
                return num;
            }
        }
        cout << "Number not found!" << endl;
        return -1; // Number not found
    }

    void addHead(int num) {
        if (size == cap) {
            cap *= 1.5;
            arr = (int*)realloc(arr, cap * sizeof(int));
            for (int i = size; i < cap; i++) arr[i] = 0;
        }

        // Shift all elements to the right
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = num;
        size++;
    }

    void addTail(int num) {
        add(num); // Same as add() since it appends at the end
    }

    void removeAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Index out of bounds!" << endl;
            return;
        }

        // Shift elements to the left
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void addAt(int pos, int num) {
        if (pos < 0 || pos > size) {
            cout << "Index out of bounds!" << endl;
            return;
        }

        if (size == cap) {
            cap *= 1.5;
            arr = (int*)realloc(arr, cap * sizeof(int));
            for (int i = size; i < cap; i++) arr[i] = 0;
        }

        // Shift elements to the right
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = num;
        size++;
    }

    int removeAll(int num) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == num) {
                removeAt(i);
                i--; // Adjust index after removal
                count++;
            }
        }
        return count;
    }
};
