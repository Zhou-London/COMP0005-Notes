#include <iostream>
#include <vector>

using namespace std;

class MS {
private:
    vector<int> v1;

    void mergeSort(int low, int high) {
        if (high - low <= 1) {
            return;
        }
        int mid = low + (high - low) / 2;

        mergeSort(low, mid);
        mergeSort(mid, high);

        merge(low, mid, high);
    }

    void merge(int low, int mid, int high) {
        int i = low;
        int j = mid;
        int k = low;
        vector<int> tmp = v1;

        while(i < mid && j < high){
            if(tmp[i] < tmp[j]){
                v1[k] = tmp[i];
                i++;
            } else {
                v1[k] = tmp[j];
                j++;
            }
            k++;
        }

        while(i<mid){
            v1[k] = tmp[i];
            i++;
            k++;
        }
        while(j<high){
            v1[k] = tmp[j];
            j++;
            k++;
        }
    }

public:
    MS(vector<int> v) {
        v1 = v;
    }

    void solve() {
        mergeSort(0, v1.size());  // Fix size issue
    }

    void peek() {
        for (int n : v1) {
            cout << n << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> v = {3, 25, 7, 4, 4, 3,32,1,41,4,5,2,324,23,52,52,3};
    MS ms(v);
    ms.solve();
    ms.peek();
    return 0;
}