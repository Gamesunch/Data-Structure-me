#include <iostream>

using namespace std;

class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) { //Recursive Heap
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void resize() {
        capacity *= 2;
        int* newHeap = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
    }

public:
    MaxHeap(int initialCapacity = 10) {
        capacity = initialCapacity;
        heap = new int[capacity];
        size = 0;
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void insert(int value) {
        if (size == capacity) {
            resize();
        }

        heap[size] = value;
        size++;
        heapifyUp(size - 1);
    }

    int deleteMax() {
        if (size == 0) {
            cout << "Heap is empty. Cannot delete." << endl;
            return -1; 
        }

        int maxVal = heap[0];
        heap[0] = heap[--size];
        heapifyDown(0);
        return maxVal;
    }

    void display() {
        if (size == 0) {
            cout << "Heap is empty." << endl;
            return;
        }

        for (int i = 0; i < size; ++i)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap;
    char command;
    int value;

    while (cin >> command) {
        if (command == 'e') break;

        if (command == 'a') {
            cin >> value;
            maxHeap.insert(value);
        } else if (command == 'd') {
            int deleted = maxHeap.deleteMax();
            if (deleted != -1) {
                cout << deleted << endl;
            }
        } else if (command == 'p') {
            maxHeap.display();
        }
    }

    return 0;
}

/*
a 18
a 19
a 2
a 10
p
a 258
a 95
p
a 102
a 36
a 98
p
p
a 71
p
a 11
p
a 71
p
d
d
a 150
p
d
d
d
d
p
e
*/
