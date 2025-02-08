#include <iostream>
#include <vector>

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
        for(int j = low; j != high; ++j){
            if(v1[j] <= pivot){
                int temp = v1[++i];
                v1[i] = v1[j];
                v1[j] = temp;
            }
        }

        int temp = v1[i + 1];
        v1[i + 1] = v1[high];
        v1[high] = temp;

        return (i+1);
    }
public:
    qs(vector<int> v): v1(v) {}

    void print(){
        quickSort(0, v1.size() - 1);
        for(int n: v1){
            cout<< n << " ";
        }
        cout<<endl;
    }
};

int main(){
    vector<int> v = {6,2,3,42,5,5,6,43,67,4,53,82,9};
    qs q = qs(v);
    q.print();
    return 0;
}