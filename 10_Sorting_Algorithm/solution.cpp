#include <iostream>
#include <algorithm>
using namespace std;

// Function to print all elements of the array
void printArr(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\n";
}

// -------------------- Bubble Sort --------------------
// Compares adjacent elements and swaps them
// if they are in the wrong order.
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {

        // Compare adjacent elements
        for (int j = 0; j < n - 1 - i; j++) {

            // Swap if the left element is greater
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

// -------------------- Selection Sort --------------------
// Finds the smallest element from the unsorted part
// and places it at the correct position.
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {

        // Assume the current element is the smallest
        int minIdx = i;

        // Find the actual smallest element
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx])
                minIdx = j;
        }

        // Place the smallest element at position i
        swap(a[i], a[minIdx]);
    }
}

// -------------------- Insertion Sort --------------------
// Takes one element at a time and inserts it
// into its correct position in the sorted part.
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {

        // Element that needs to be inserted
        int key = a[i];

        // Start comparing with the previous element
        int j = i - 1;

        // Move larger elements one position to the right
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        // Insert the key at its correct position
        a[j + 1] = key;
    }
}

// -------------------- Quick Sort --------------------
// Places the pivot at its correct position
// and returns the pivot's index.
int partition(int a[], int low, int high) {

    // Choose the last element as the pivot
    int pivot = a[high];

    // Index of the smaller element
    int i = low - 1;

    // Compare each element with the pivot
    for (int j = low; j < high; j++) {

        // If element is smaller than or equal to pivot
        if (a[j] <= pivot) {
            i++;

            // Put the smaller element on the left side
            swap(a[i], a[j]);
        }
    }

    // Put the pivot in its correct position
    swap(a[i + 1], a[high]);

    // Return the pivot's position
    return i + 1;
}

// Quick Sort function
void quickSort(int a[], int low, int high) {

    // Continue only if there are at least two elements
    if (low < high) {

        // Find the correct position of the pivot
        int pi = partition(a, low, high);

        // Sort the left part
        quickSort(a, low, pi - 1);

        // Sort the right part
        quickSort(a, pi + 1, high);
    }
}

// -------------------- Merge Function --------------------
// Merges two already sorted parts of the array.
void merge(int a[], int l, int m, int r) {

    // Size of the left and right parts
    int n1 = m - l + 1;
    int n2 = r - m;

    // Temporary arrays for left and right parts
    int L[n1], R[n2];

    // Copy elements into the left array
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];

    // Copy elements into the right array
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    // i = index for left array
    // j = index for right array
    // k = index for original array
    int i = 0;
    int j = 0;
    int k = l;

    // Compare elements from both arrays
    // and put the smaller one into the original array
    while (i < n1 && j < n2) {

        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    // Copy remaining elements from left array
    while (i < n1)
        a[k++] = L[i++];

    // Copy remaining elements from right array
    while (j < n2)
        a[k++] = R[j++];
}

// -------------------- Merge Sort --------------------
// Divides the array into smaller parts,
// sorts them, and then merges them.
void mergeSort(int a[], int l, int r) {

    // Continue if there is more than one element
    if (l < r) {

        // Find the middle position
        int m = l + (r - l) / 2;

        // Sort the left half
        mergeSort(a, l, m);

        // Sort the right half
        mergeSort(a, m + 1, r);

        // Merge the two sorted halves
        merge(a, l, m, r);
    }
}

// -------------------- Main Function --------------------
int main() {
    int n;

    // Read the number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    // Store the original array
    int orig[n];

    // Read array elements
    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
        cin >> orig[i];

    // Temporary array used for each sorting algorithm
    int a[n];

    // -------- Bubble Sort --------
    // Copy the original array before sorting
    copy(orig, orig + n, a);

    bubbleSort(a, n);

    cout << "Bubble Sort: ";
    printArr(a, n);


    // -------- Selection Sort --------
    // Copy the original array again
    copy(orig, orig + n, a);

    selectionSort(a, n);

    cout << "Selection Sort: ";
    printArr(a, n);


    // -------- Insertion Sort --------
    // Copy the original array again
    copy(orig, orig + n, a);

    insertionSort(a, n);

    cout << "Insertion Sort: ";
    printArr(a, n);


    // -------- Quick Sort --------
    // Copy the original array again
    copy(orig, orig + n, a);

    quickSort(a, 0, n - 1);

    cout << "Quick Sort: ";
    printArr(a, n);


    // -------- Merge Sort --------
    // Copy the original array again
    copy(orig, orig + n, a);

    mergeSort(a, 0, n - 1);

    cout << "Merge Sort: ";
    printArr(a, n);

    return 0;
}
