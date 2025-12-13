// C++ program to swap alternate elements in an array
#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapAlternate(int arr[], int n)
{
    for (int i = 0; i < n - 1; i += 2)
    {
        if (i + 1 < n)
            swap(arr[i], arr[i + 1]);
    }
    // internal working of swap function
    /*
    void swap(int &arr[i], int &arr[i + 1]){
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
    */
}

int main()
{
    int evenArr[6] = {5, 2, 9, 7, 10, 6};
    int oddArr[5] = {1, 3, 4, 8, 12};

    cout << "Original even array: ";
    printArray(evenArr, 6);

    swapAlternate(evenArr, 6);
    cout << "After swapping alternate elements in even array: ";
    printArray(evenArr, 6);

    cout << "Original odd array: ";
    printArray(oddArr, 5);

    swapAlternate(oddArr, 5);

    cout << "After swapping alternate elements in odd array: ";
    printArray(oddArr, 5);

    return 0;
}