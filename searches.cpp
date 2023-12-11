#include <iostream>
#include <vector>

using namespace std;

int common_search(vector<int>& arr, int element){
    for (int i = 0; i < arr.size(); ++i){
        if (arr[i] == element)
            return i;
    }
    return -1;
}

int bin_search(vector<int>& arr, int element, int L, int R){
    while (L <= R){
        int m = L + (R - L) / 2;

        if (arr[m] == element)
            return m;

        if (arr[m] < element)
            L = m + 1;
        else
            R = m - 1;
    }

    return -1;
}

// wrapper
int bin_search(vector<int>& arr, int element){
    return bin_search(arr, element, 0, arr.size() - 1);
}
