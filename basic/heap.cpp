//
// Created by Younghusband on 2024/9/3.
//


#include <vector>

using namespace std;


void heapify(vector<int>& data, int i, int heapSize) {
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if(left < heapSize && data[left] > data[largest]) {
        largest = left;
    }

    if(right < heapSize && data[right] > data[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(data[i], data[largest]);
        heapify(data, largest, heapSize);
    }
}


void heapSort(vector<int>& data) {
    int n = data.size();
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(data, i, n);
    }

    for(int i = n - 1; i > 0; i--) {
        swap(data[0], data[i]);
        heapify(data, 0, i);
    }
}



