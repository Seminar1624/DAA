#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int profit;
    int weight;
};

bool cmp(Item a, Item b) {
    return (double)a.profit / a.weight > (double)b.profit / b.weight;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int cap;
    cout << "Enter capacity: ";
    cin >> cap;

    vector<Item> arr(n);
    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].profit >> arr[i].weight;
    }

    sort(arr.begin(), arr.end(), cmp); // sort by profit/weight ratio

    double total = 0.0;

    for (int i = 0; i < n; i++) {
        if (cap == 0)
            break;

        if (arr[i].weight <= cap) {
            // Take the whole item
            cap -= arr[i].weight;
            total += arr[i].profit;
        } else {
            // Take the fractional part
            total += arr[i].profit * ((double)cap / arr[i].weight);
            cap = 0; // bag is full now
        }
    }

    cout << "\nTotal profit: " << total << endl;

    return 0;
}
