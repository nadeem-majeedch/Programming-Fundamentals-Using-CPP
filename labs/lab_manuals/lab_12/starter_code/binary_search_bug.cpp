// Lab 12 · binary_search_bug.cpp — bug-hunt file (TRACE ON PAPER FIRST).
//
// This binary search MIXES two disciplines: high starts at n (half-open)
// but the loop uses low <= high (closed). Trace key=9 on [2,4,6,8]:
//   low=0 high=4 mid=2 -> a[2]=6 < 9 -> low=3
//   low=3 high=4 mid=3 -> a[3]=8 < 9 -> low=4
//   low=4 high=4 mid=4 -> a[4] reads OUT OF BOUNDS (undefined behavior)
//
// Task: pick ONE discipline and make the code obey it everywhere:
//   closed:  high = n-1; while (low <= high); high = mid - 1
//   half-open: high = n;   while (low < high);  high = mid
// Then verify: 2->0, 8->3, 9->-1, 1->-1, empty array -> -1.
//
// Build: g++ -std=c++17 -Wall -Wextra -pedantic binary_search_bug.cpp -o bs

#include <iostream>

int binarySearch(const int* a, int n, int key)
{
    int low{0};
    int high{n};              // half-open start...
    while (low <= high)       // ...closed loop: the mix is the bug
    {
        int mid{low + (high - low) / 2};
        if (a[mid] == key)
            return mid;
        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int a[4]{2, 4, 6, 8};
    for (int k : {2, 8, 9, 1})
        std::cout << k << " -> " << binarySearch(a, 4, k) << '\n';
    return 0;
}
