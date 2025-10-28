#include <iostream>
using namespace std;

/*
----------------------------------------------------------
BINARY SEARCH — Recursive Implementation
----------------------------------------------------------

Description:
------------
Binary Search is an efficient algorithm for finding a target
element in a **sorted** array.

It works by repeatedly dividing the search interval in half:
1. Compare the target with the middle element.
2. If equal → target found.
3. If target < mid → search the left half.
4. If target > mid → search the right half.

This version uses **recursion** to perform the divide step.

REQUIREMENT: The array must be **sorted**.

Algorithm Steps:
----------------
1. Compute mid = low + (high - low) / 2
   (avoids overflow vs using (low + high)/2)
2. If arr[mid] == target → return mid.
3. If arr[mid] > target → recursively search left half.
4. If arr[mid] < target → recursively search right half.
5. Stop when low > high → target not found.

Time Complexity:
----------------
- Best Case: O(1)
- Worst Case: O(log n)
- Average Case: O(log n)

Space Complexity:
-----------------
- O(log n) due to recursive call stack.

When to Use:
------------
- Dataset is sorted.
- Fast lookups are needed.
*/

int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high)
        return -1;  // Base case: target not found

    int mid = low + (high - low) / 2;  // Prevent overflow

    if (arr[mid] == target)
        return mid;  // Target found
    else if (target < arr[mid])
        return binarySearchRecursive(arr, low, mid - 1, target);  // Search left
    else
        return binarySearchRecursive(arr, mid + 1, high, target); // Search right
}


/*
----------------------------------------------------------
BINARY SEARCH — Iterative Implementation
----------------------------------------------------------

Description:
------------
This version uses a **loop** instead of recursion.

The logic is the same — continually narrow the range
[low, high] until the target is found or the range is empty.

Advantages:
-----------
 More memory efficient (O(1) space)
 No function call overhead
 Better for large arrays

Time Complexity:
----------------
- O(log n)

Space Complexity:
-----------------
- O(1)

When to Use:
------------
- For production or performance-sensitive environments.
*/

int binarySearchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;  // Found
        else if (target < arr[mid])
            high = mid - 1;  // Move left
        else
            low = mid + 1;   // Move right
    }

    return -1;  // Not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int idx1 = binarySearchRecursive(arr, 0, n - 1, target);
    int idx2 = binarySearchIterative(arr, n, target);

    cout << "Recursive: ";
    (idx1 != -1) ? cout << "Found at index " << idx1 << endl : cout << "Not found\n";

    cout << "Iterative: ";
    (idx2 != -1) ? cout << "Found at index " << idx2 << endl : cout << "Not found\n";

    return 0;
}
