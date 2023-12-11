#include <iostream>
#include <cmath>

using namespace std;

// это я начал идти по курсам мшп, но советую сразу смотреть advanced_structs.cpp

struct StackLIFO{
public:
    void push(int x){
        arr[t++] = x;
    }
    int top(){
        return arr[t - 1];
    }
    int pop(){
        return arr[--t];
    }
private:
    int max_n = 128;
    int t = 0;
    int arr[128]{};
};

struct StackFIFO{
public:
    void push(int x){
        arr[R] = x;
        R = (R + 1) % max_n;
    }
    int top(){
        return arr[L];
    }
    int pop(){
        int t = top();
        L = (L + 1) % max_n;
        return t;
    }
    int size(){
        if (R <= L)
            return R - L;
        else
            return L - R;
    }
private:
    int max_n = 128;
    int L = 0;
    int R = 0;
    int arr[128]{};
};

struct Deque{
public:
    void pushFront(int x){
        L = (L + max_n - 1) % max_n;
        arr[L] = x;
    }
    void pushBack(int x){
        R = (R + 1) % max_n;
        arr[R] = x;
    }

    int front(){
        return arr[L];
    }
    int back(){
        return arr[R];
    }

    int popFront(){
        int t = front();
        L = (L + 1) % max_n;
        return t;
    }
    int popBack(){
        int t = back();
        R = (R + max_n - 1) % max_n;
        return t;
    }

    int size(){
        if (L < R)
            return R - L + 1;
        else
            return max_n + R - L + 1;
    }

    void clear(){
        L = 0;
        R = 0;
        arr[0] = 0;
    }

    void show(){
        for (int i : arr){
            cout << i << " ";
        }
        cout << endl;
    }
private:
    int max_n = 32;
    int L = 0;
    int R = -1;
    int arr[32]{};
};

struct Heap{
public:
    int getLayers(){
        int n = 0, sum_n = 0;
        while (sum_n < size){
            sum_n += pow(2, n);
            ++n;
        }
        return n;
    }

    void shiftUp(int i){
        while (arr[i] < arr[(i - 1) / 2] && i > 0){
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void shiftDown(int i){
        while (2 * i + 1 < size){
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int min = l;
            if (r < size && arr[r] < arr[min])
                min = r;
            if (arr[i] <= arr[min])
                return ;
            swap(arr[i], arr[min]);
            i = min;
        }
    }

    void insert(int x){
        arr[size] = x;
        size++;
        shiftUp(size - 1);
    }
    int getMin(){
        return arr[0];
    }

    int deleteElement(int i){
        int t = arr[i];
        arr[i] = arr[size - 1];
        --size;
        shiftDown(i);
        return t;
    }

    int extractMin(){
        return deleteElement(0);
    }

    void show(){
        for (int i = 0; i < size; ++i){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    int max_n = 128;
    int arr[128]{};
    int size = 0;
};
