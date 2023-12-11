#include <iostream>
#include <vector>
using namespace std;

void print_table(const vector<vector<int>>& arr) {
    for (const auto & i : arr) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}


bool if_simple(const vector<vector<int>>& arr, int size){
    for (int i = 0; i < size; i++)
        if (arr[i][i] == 1)
            return false;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (arr[i][j] != arr[j][i])
                return false;

    return true;
}

bool if_simple(const vector<vector<int>>& arr){ // wrapper
    return if_simple(arr, arr.size());
}


bool if_contains_loops(const vector<vector<int>>& arr, int size){
    for (int i = 0; i < size; i++)
        if (arr[i][i])
            return true;
    return false;
}

bool if_contains_loops(const vector<vector<int>>& arr){ // wrapper
    return if_contains_loops(arr, arr.size());
}


void print_edges(const vector<vector<int>>& arr, int size){
    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++)
            if (arr[i][j])
                cout << i + 1 << " " << j + 1 << endl;
}

void print_edges(const vector<vector<int>>& arr){
    print_edges(arr, arr.size());
}


void set_table_by_edges(vector<vector<int>>& arr, const vector<vector<int>>& edges_list, int edges){
    for (int i = 0; i < edges; i++){
        arr[edges_list[i][0] - 1][edges_list[i][1] - 1] = 1;
        arr[edges_list[i][1] - 1][edges_list[i][0] - 1] = 1;
    }
}

void set_table_by_edges(vector<vector<int>>& arr, const vector<vector<int>>& edges_list){ // wrapper
    set_table_by_edges(arr, edges_list, edges_list.size());
}


void print_vertex_degrees(const vector<vector<int>>& arr, int size){
    int cnt = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            if (arr[i][j])
                cnt++;
        cout << cnt << endl;
        cnt = 0;
    }

}

void print_vertex_degrees(const vector<vector<int>>& arr){ // wrapper
    print_vertex_degrees(arr, arr.size());
}

void print_all_sources(const vector<vector<int>>& arr, int size){
    vector<int> sources;

    for (int i = 0; i < size; i++) {
        bool isSource = true;
        for (int j = 0; j < size; j++) {
            if (arr[j][i]) {
                isSource = false;
                break;
            }
        }
        if (isSource) {
            sources.push_back(i + 1);
        }
    }

    cout << sources.size() << " ";
    for (int source : sources) {
        cout << source << " ";
    }
    cout << endl;
}

void print_all_drains(const vector<vector<int>>& arr, int size){
    vector<int> drains;

    for (int i = 0; i < size; i++) {
        bool isSource = true;
        for (int j = 0; j < size; j++) {
            if (arr[i][j]) {
                isSource = false;
                break;
            }
        }
        if (isSource) {
            drains.push_back(i + 1);
        }
    }

    cout << drains.size() << " ";
    for (int drain : drains) {
        cout << drain << " ";
    }
    cout << endl;
}

bool isCyclic(const vector<vector<int>>& arr, int size){
    // не написал
}

bool is_tree(const vector<vector<int>>& arr, int size){
    // не написал
}
