#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class heapSort{
private:
    vector<int> v1;

    void heapify(int n, int i){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && v1[left] > v1[largest]) largest = left;
        if(right < n && v1[right] > v1[largest]) largest = right;
        if(largest != i){ swap(v1[i], v1[largest]); heapify(n, largest);}
    }

    void sort(){
        int n = v1.size();
        for(int i = n / 2 - 1; i >= 0; i--) heapify(n,i);
        for(int i = n - 1; i > 0; i--){ swap(v1[0], v1[i]); heapify(i, 0);}
    }
public:
    heapSort(vector<int> v): v1(v) {}
    void print(){
        sort();
        for(int n: v1) cout<<n<<" ";
        cout<< endl;
    }
};

int main(){
    vector<int> v = {7,3,4,8,92,4,5,4,78,3,94,53,67};
    heapSort hs = heapSort(v);
    hs.print();
}