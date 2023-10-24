#include <iostream>
#include <algorithm>

using namespace std;


class DynArray
{
    int* array;
    int size;
public:
    DynArray(int sizeP) : array{ new int[sizeP] {} }, size{ sizeP }
    {
        cout << "Constructed " << this << " for " << size << " elements." << endl;
    }
    DynArray() : DynArray(10){}
    DynArray(const DynArray& object) : array{ new int[object.size]}, size{object.size}
    {
        for (int i{ 0 }; i < size; ++i)
            array[i] = object.array[i];
        cout << "Copy constructed " << this << " for " << size << " elements." << endl;
    }
    ~DynArray()
    {
        cout << "Try to free memory" << endl;
        delete[]array;
        cout << "Destructed " << this << " for " << size << " elements." << endl;
    }
    
    DynArray& randomize()
    {
        for (int i{ 0 }; i < size; ++i) array[i] = rand() % 10;
        return *this;
    }

    void print()
    {
        for (int i{ 0 }; i < size; ++i) 
            cout << array[i]<<" ";
        cout << endl;
    }

    DynArray createArray(int size) {
        DynArray newArray{ size };
        newArray.randomize();
        return newArray;
    }

    void changeArray(int newSize) {
        int* newArray = new int[newSize];

        for (int i = 0; i < newSize; i++) {
            newArray[i] = rand() % 10;
        }

        array = newArray;
        size = newSize;
    }


    int partition(int start, int end) {
        int pivot = array[end];
        int pIndex = start;
        for (int i = start; i < end; i++) {
            if (array[i] <= pivot) {
                swap(array[i], array[pIndex]);
                pIndex++;
            }
        }
        swap(array[pIndex], array[end]);
        return pIndex;
    }
    void quicksort(int start, int end) {

        if (start >= end) return;

        int pivot = partition(start,end);
        quicksort(start,pivot - 1);
        quicksort(pivot + 1, end);
    }

    void min() {
        int eq = array[0];
        for (int i = 1; i < size; i++) {
            if (array[i] < eq) {
                eq = array[i];
            }
        }
        cout << "MIN: " << eq << endl;
    }


    void max() {
        int ew = array[0];
        for (int i = 1; i < size; i++) {
            if (array[i] > ew) {
                ew = array[i];
            }
        }
        cout << "MAX: " << ew << endl;
    }
};

int main()
{
    srand(time(nullptr));
    int size=5;
    DynArray array1{ size };
    int choice=-1;
    while (choice != 0) {
        cout << "\t\tMenu\n0)Exit\n1)Fill array\n2)Print\n3)Change size array\n4)Sort array\n5)MIN\n6)MAX\nYour choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1: array1.randomize();
            break;
        case 2: array1.print();
            break;
        case 3: cout << "Input size array: ";
            cin >> size;
            array1.changeArray(size);
            break;
        case 4: array1.quicksort(0, size - 1);
            break;
        case 5: array1.min();
            break;
        case 6: array1.max();
            break;
        default: cout << "Error";
        }
    }
}
