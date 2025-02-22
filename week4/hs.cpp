#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class hs{
private:
    vector<int> v1;
    void sort(){
        int n = v1.size();
        for(int i = n/2 - 1; i >= 0; i--) heapify(n, i);
        for(int i = n - 1; i > 0; i--) { swap(v1[0], v1[i]); heapify(i, 0); }
    }
    void heapify(int n, int i){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && v1[left] > v1[largest]) largest = left;
        if(right < n && v1[right] > v1[largest]) largest = right;
        if(largest != i){ swap(v1[largest], v1[i]); heapify(n, largest); }
    }
public:
    hs(vector<int> v): v1(v) {sort();}
    void print(){for(int n: v1) cout<< n <<endl;}
};

int main(){
    hs({2,34,75,86,75,43,0,-542,-34,-634,-213,-6,-3,-6}).print();
    return 0;
}