#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class qs{
private:
    vector<int> v1;
    void quickSort(int low, int high){
        if(low < high){
            int pivotIndex = part(low, high);
            quickSort(low, pivotIndex - 1);
            quickSort(pivotIndex + 1, high);
        }
    }
    int part(int low, int high){
        int pivot = v1[high];
        int i = low - 1;
        for(int j = low; j != high; ++j) if(v1[j] <= pivot) swap(v1[++i], v1[j]);
        swap(v1[i + 1], v1[high]);
        return (i+1);
    }
public:
    qs(vector<int> v): v1(v) {}
    void print(){
        quickSort(0, v1.size() - 1);
        for(int n: v1) cout << n << "  ";
        cout<< endl;
    }
};
int main(){
    vector<int> v = {7,65,6,45,342, 34, 92, 86, 9,78,93,254,386,27,349,12,33,65,7685,64,32,455,46};
    qs q = qs(v);
    q.print();
    return 0;
}