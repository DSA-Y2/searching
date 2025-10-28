#include <iostream>
using namespace std;

/*
-------------------------------------------
 LINEAR SEARCH 
-------------------------------------------

Description:
------------
Linear Search scans each element in the array one by one
until it finds the target value or reaches the end of the array.

Works on both sorted and unsorted arrays.
Inefficient for large datasets since it checks every element.

Algorithm Steps:
----------------
1. Start from the first element (index 0).
2. Compare each element with the target.
3. If found → return the index.
4. If end is reached → return -1 (not found).

Time Complexity:
----------------
- Best Case: O(1)      → Target found at the beginning.
- Worst Case: O(n)     → Target at end or not found.
- Average Case: O(n/2) ≈ O(n)

Space Complexity:
-----------------
- O(1) → Constant extra space.

When to Use:
-------------
- Data is small or unsorted.
- No need for preprocessing (like sorting).
*/

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i; // Element found, return index.
    }
    return -1; // Element not found.
}


/*
-------------------------------------------
 LINEAR SEARCH (Recursive)
-------------------------------------------

Description:
------------
Instead of looping, the recursive version calls itself
with a smaller portion of the array each time.

The base cases:
---------------
1. If size == 0 → return -1 (empty array, not found)
2. If arr[0] == target → return 0 (found at current index)

Otherwise:
----------
- Search recursively in the rest of the array (arr + 1).

⚠️ The recursive approach is *conceptually elegant*,
   but less memory-efficient due to recursive call stack.

Time Complexity:
----------------
Same as iterative → O(n)
Space Complexity:
-----------------
O(n) → Due to recursive call stack
*/

int linearSearchRecursive(int arr[], int size, int target) {
    // Base case: array empty
    if (size == 0)
        return -1;

    // Base case: element found at first position
    if (arr[0] == target)
        return 0;

    // Recursive call: search in remaining array
    int result = linearSearchRecursive(arr + 1, size - 1, target);

    // If found in subarray, adjust index (offset by +1)
    return (result == -1) ? -1 : result + 1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    cout << "Iterative Linear Search:\n";
    int index1 = linearSearch(arr, n, target);
    if (index1 != -1)
        cout << "→ Found at index " << index1 << "\n";
    else
        cout << "→ Not found\n";

    cout << "\nRecursive Linear Search:\n";
    int index2 = linearSearchRecursive(arr, n, target);
    if (index2 != -1)
        cout << "→ Found at index " << index2 << "\n";
    else
        cout << "→ Not found\n";

    return 0;
}
