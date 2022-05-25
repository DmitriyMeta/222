#include<ctime>
#include <iostream>
#include <cstdlib>
using namespace std;


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    unsigned int start_time = clock();
    for (int j = 0; j < 100; j++) {
        int arr[1000];
        for (int i = 0; i < int((sizeof(arr) / sizeof(arr[0]))); i++)
            arr[i] = rand() % 100 + 1;
        int n = sizeof(arr) / sizeof(arr[0]);

        heapSort(arr, n);
    }
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << search_time / 1000.0 << endl;
}