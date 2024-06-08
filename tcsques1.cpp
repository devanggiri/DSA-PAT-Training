// Alice and Bob are batch mates and Alice got placed in a well-reputed product-based company.
// Bob is demanding a treat from Alice. Alice is ready to give a treat and has ordered N pizzas from the nearest restaurant.
// The pizzas can have at most K different flavors (it is not necessary that there should be one pizza of each flavor), numbered from 1 to K.
// Bob is on a diet and he can only eat pizza of at most (K-1) flavors, but he can eat as many pizzas of that flavor as he wants.
// He wants to choose the maximum possible number of pizzas which are contiguous such that all pizzas in the sequence have at most (K-1) distinct flavors.

// This program finds the longest subarray with at most (K-1) distinct elements.

#include <bits/stdc++.h>
using namespace std;

// Function to print the length of the longest subarray with at most (K-1) distinct elements
void longest(vector<int>& a, int n, int k) {
    unordered_map<int, int> freq;

    int start = 0, end = 0, now = 0, l = 0;
    for (int i = 0; i < n; i++) {

        // Mark the element visited
        freq[a[i]]++;

        // If it's visited the first time, increase the counter of distinct elements by 1
        if (freq[a[i]] == 1)
            now++;

        // When the counter of distinct elements increases beyond (K-1), reduce it
        while (now > k) {

            // From the left, reduce the number of times the element is visited
            freq[a[l]]--;

            // If the reduced visited time element is not present in the further segment,
            // then decrease the count of distinct elements
            if (freq[a[l]] == 0)
                now--;

            // Increase the subsegment marker
            l++;
        }

        // Check the length of the longest sub-segment
        // If greater than the previous best, update it
        if (i - l + 1 > end - start + 1)
            end = i, start = l;
    }

    // Print the length of the longest sub-segment
    cout << (end - start + 1);
}

// Driver program to test the above function
int main() {
    int n, k;
    cin >> n >> k;
    k = k - 1;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    longest(a, n, k);
    return 0;
}
