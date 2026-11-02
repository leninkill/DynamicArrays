#include <iostream>

using namespace std;

void createArray(int *&pA, int *n) { // int *&pA это передача адреса по ссылке, нужна, чтобы менять адрес
    cout << "Type count of elements in array: " << endl;
    cin >> *n;

    pA = new int[*n];
    int i;

    cout << "Type " << *n << " elements: " << endl;

    for (i = 0; i < *n; i++) {
        cin >> pA[i];
    }
}

void typeArray(int *pA, int n) {
    for (int i = 0; i < n; i++) {
        cout << pA[i] << "\t";
    }
    cout << endl;
}

void deleteElementArray(int *pA, int *n, int nElement) {
    if (0 <= nElement and nElement < *n) {
        for (int i = nElement; i < *n - 1; i++) {
            pA[i] = pA[i + 1];
        }
        (*n)--;
    }
}

int main() {
    float *a = new float;

    *a = 10;

    cout << *a << endl;

    delete a;
    // a = nullptr;
    cout << *a << endl;

    int n; // длина массива, которая будет изменяться при добавлении и удалении элемента

    int size; // размер памяти выделенной под массив, при удалении элементов не уменьшится

    int *pA; //

    createArray(pA, &n);

    size = n;

    typeArray(pA, n);

    for (int i = 0; i < n; i++) {
        if (pA[i] % 2 == 1) {
            deleteElementArray(pA, &n, i);
            i--; // чтобы не проскачить элемент после удаленного, ведь он встал на место i-ого элемента и его тоже нужно проверить на нечетность
        }
    }

    typeArray(pA, n);

    delete[] pA;

    return 0;
}