#include "QS.h"

QS::QS() {
    array = NULL;
    size = 0;
    cap = 0;
}

QS::~QS() {
    delete array;
    array = NULL;
    size = 0;
}

void QS::sortAll() {
    if(size == 0) {
        return;
    }

    sort(0, size - 1);
}

void QS::sort(int left, int right) {
    if (left < right) {
        int pivot = medianOfThree(left, right);
        int i = left;
        int j = right;

        while(i < j) {
            while(array[i] <= array[pivot]) {
                i++;
            }

            while(array[j] >= array[pivot]) {
                j--;
            }

            if(i <= j) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }

        sort(left, j);
        sort(i, right);
    }
}

int QS::medianOfThree(int left, int right) {
    int middle = (left + right) / 2;

    if(left >= right || left < 0 || right < 0 || left >= size || right >= size) {
        return -1;
    }

    while(array[left] > array[middle] || array[middle] > array[right]) {
        if (array[left] > array[middle]) {
            int temp = array[left];
            array[left] = array[middle];
            array[middle] = temp;
        }

        if (array[middle] > array[right]) {
            int temp = array[middle];
            array[middle] = array[right];
            array[right] = temp;
        }
    }

    return middle;
}

int QS::partition(int left, int right, int pivotIndex) {
    if (array == NULL || left >= right || left < 0 || right < 0 || left >= size || right >= size || pivotIndex < left || pivotIndex > right) {
        return -1;
    }

    if (right - left == 1) {
        if (array[left] > array[right]) {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }

        return right;
    }

    int pivot = array[pivotIndex];
    int temp = array[left];
    array[left] = array[pivotIndex];
    array[pivotIndex] = temp;
    int up = left + 1;
    int down = right;

    while (up < down){
        if (array[up] == array[down]){
            up++;
        }

        while (array[up] < pivot && up < right) {
            up++;
        }

        while (array[down] > pivot && down > left) {
            down--;
        }

        if (up < down) {
        int temp = array[up];
        array[up] = array[down];
        array[down] = temp;
        }
    }

    int temp2 = array[left];
    array[left] = array[down];
    array[down] = temp2;

    return down;
}

string QS::getArray() const {
    string arrayString = "";
    for (int i = 0; i < size; i++) {
        arrayString += to_string(array[i]);

        if (i != size - 1) {
            arrayString += ",";
        }
    }

    return arrayString;
}

int QS::getSize() const {
    return size;
}

bool QS::addToArray(int value) {
    if (size == cap) {
        return false;
    }

    array[size] = value;
    size++;

    return true;
}

bool QS::createArray(int capacity) {
    if (cap > 0){
        delete array;
        array = NULL;
        size = 0;
    }

    if (capacity <= 0) {
        return false;
    }

    array = new int[capacity];
    cap = capacity;

    return true;
}

void QS::clear() {
    delete array;
    array = NULL;
    size = 0;
}