#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Heapify function
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;          // Assume root is largest
    int left = 2 * i + 1;     // Left child
    int right = 2 * i + 2;    // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(vector<int>& arr)
{
    int n = arr.size();

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move current maximum to the end
        swap(arr[0], arr[i]);

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

// Display array
void display(vector<int>& arr)
{
    for (int x : arr)
        cout << x << " ";

    cout << endl;
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original Array: ";
    display(arr);

    heapSort(arr);

    cout << "Sorted Array:   ";
    display(arr);

    return 0;
}
