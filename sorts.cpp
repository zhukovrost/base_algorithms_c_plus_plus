#include <iostream>
#include <vector>
#include <array>
using namespace std;

void print_vector(vector<int>& a){
    for (int i : a){
        cout << i << " ";
    }
    cout << endl;
}

void reset_vector(vector<int>& a){
    a = {1, 2, 5, 4, 2, 3, 4};
    cout << "Vector reset..." << endl;
    print_vector(a);
}

int find_max(vector<int>& a){
    int max = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

void bubble_sort(vector<int>& a){
    for (int i = 0; i < a.size() - 1; ++i){
        bool were_swaps = false;
        for (int j = 0; j < a.size() - i - 1; ++j){
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                were_swaps = true;
            }
        }
        if (!were_swaps)
            break;
    }
}

void selection_sort(vector<int>& a){
    int min_inx;
    for (int i = 0; i < a.size() - 1; ++i){
        min_inx = i;
        for (int j = i + 1; j < a.size(); ++j){
            if (a[j] < a[min_inx])
                min_inx = j;
        }
        if (min_inx != i)
            swap(a[i], a[min_inx]);
    }
}

void insertion_sort(vector<int>& a){
    for (int i = 1; i < a.size(); ++i){
        int j = i - 1;
        int key = a[i];
        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

void counting_sort(vector<int>& a){
    int max = find_max(a);
    vector<int> count(max + 1);
    vector<int> result(a.size());

    for (int i : a){
        ++count[i];
    }
    for (int i = 1; i <= max; ++i){
        count[i] += count[i - 1];
    }
    for (int i : a){
        result[count[i] - 1] = i;
        --count[i];
    }
    a = result;
}

// Function to partition the vector and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = (low - 1);     // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of the smaller element
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at (i + 1), so the pivot is at the right position
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quicksort function
void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find pivot element such that
        // elements smaller than pivot are on the left
        // elements greater than pivot are on the right
        int pivot = partition(arr, low, high);

        // Recursively sort elements before and after the pivot
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

// Wrapper function for quicksort
void quick_sort(vector<int>& arr) {
    int n = arr.size();
    quick_sort(arr, 0, n - 1);
}

int main(){

    vector<int> numbers;
    
    reset_vector(numbers);
    cout << "Bubble sort" << endl;
    bubble_sort(numbers);
    print_vector(numbers);

    reset_vector(numbers);
    cout << "Selection sort" << endl;
    selection_sort(numbers);
    print_vector(numbers);

    reset_vector(numbers);
    cout << "Insertion sort" << endl;
    insertion_sort(numbers);
    print_vector(numbers);

    reset_vector(numbers);
    cout << "Counting sort" << endl;
    counting_sort(numbers);
    print_vector(numbers);

    reset_vector(numbers);
    cout << "Quick sort..." << endl;
    quick_sort(numbers);
    print_vector(numbers);

    return 0;
}