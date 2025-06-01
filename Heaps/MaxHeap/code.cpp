#include <bits/stdc++.h>
using namespace std;

class heap {
    public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1; // 0th index is not used
        size = 0; // Initialize size of heap
    }

    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deletefromHeap(){
        if(size==0){
            cout << "Heap is empty" << endl;
            return;
        }

        arr[1] = arr[size]; // Move last element to root
        size--; 

        //take root node to its correct position - heapify down
        int index = 1;
        while(index < size){
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;
            int largest = index;

            if(leftChild <= size && arr[leftChild] > arr[largest]){
                largest = leftChild;
            }
            if(rightChild <= size && arr[rightChild] > arr[largest]){
                largest = rightChild;
            }
            if(largest != index){
                swap(arr[index], arr[largest]);
                index = largest;
            } else {
                return;
            }
        }
    }

    void heapify(int arr[], int n, int i){
        int largest = i; // Initialize largest as root
        int left = 2 * i; // left child index
        int right = 2 * i + 1; // right child index

        // If left child is larger than root
        if(left <= n && arr[left] > arr[largest]){
            largest = left;
        }

        // If right child is larger than largest so far
        if(right <= n && arr[right] > arr[largest]){
            largest = right;
        }

        // If largest is not root
        if(largest != i){
            swap(arr[i], arr[largest]);
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n){
        
        int size = n;

        while(size > 1){
            // step1 : swap
            swap(arr[1], arr[size]);
            size--; // Reduce size of heap

            // step2 : heapify
            heapify(arr, size, 1);
        }

    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print(); 

    int arr[6] = {-1, 54, 53, 55, 52, 50}; // -1 is a placeholder for 0th index
    int n = 5; // Number of elements in the array
    for(int i = n/2; i > 0; i--){
        h.heapify(arr, n, i);
    }

    cout << "Array representation of Heap after heapify: ";
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    } cout << endl;

    h.heapSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;

}