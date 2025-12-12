#include <iostream>
#include <climits>
using namespace std;

int getMin(int num[], int n) {
    int minimum = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(num[i] < minimum)
            minimum = num[i];
    }
    return minimum;
}

int getMax(int num[], int n) {
    int maximum = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(num[i] > maximum)
            maximum = num[i];
    }
    return maximum;
}

int main() {
    int size;
    cout << "Enter size of array : ";
    cin >> size;

    if(size > 100) {
        cout << "Size too large!" << endl;
        return 0;
    }

    int num[100];

    cout << "Enter array elements : " << endl;
    for(int i = 0; i < size; i++) {
        cin >> num[i];
    }

    cout << "Maximum value is " << getMax(num, size) << endl;
    cout << "Minimum value is " << getMin(num, size) << endl;
}
