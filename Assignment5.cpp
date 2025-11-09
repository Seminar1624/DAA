#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int n1 = 0; // number of comparisons in quick sort
int n2 = 0; // number of comparisons in randomized quick sort

int quick_sort_partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right]; // choose rightmost element as pivot
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
        n1++;
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quick_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivot = quick_sort_partition(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}

int randomized_quick_sort_partition(vector<int>& arr, int left, int right) {
    int pivot_index = left + rand() % (right - left + 1); // choose random pivot
    swap(arr[pivot_index], arr[right]);
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
        n2++;
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void randomized_quick_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivot = randomized_quick_sort_partition(arr, left, right);
        randomized_quick_sort(arr, left, pivot - 1);
        randomized_quick_sort(arr, pivot + 1, right);
    }
}

int main() {
    srand(time(0));

    vector<int> arr1 = {10, 7, 8, 9, 1, 5};
    int n = arr1.size();

    quick_sort(arr1, 0, n - 1);
    cout << "Sorted array using Quick Sort: ";
    for (int x : arr1) cout << x << " ";
    cout << "\nNumber of comparisons in Quick Sort: " << n1 << endl;

    vector<int> arr2 = {10, 7, 8, 9, 1, 5};
    randomized_quick_sort(arr2, 0, n - 1);
    cout << "Sorted array using Randomized Quick Sort: ";
    for (int x : arr2) cout << x << " ";
    cout << "\nNumber of comparisons in Randomized Quick Sort: " << n2 << endl;

    return 0;
}
