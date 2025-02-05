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
        vector<int> res;
        int i = low;
        int j = mid;

        while (i < mid && j < high) {
            if (v1[i] <= v1[j]) {
                res.push_back(v1[i++]);
            } else {
                res.push_back(v1[j++]);
            }
        }

        while (i < mid) res.push_back(v1[i++]);
        while (j < high) res.push_back(v1[j++]);

        for (int k = 0; k < res.size(); ++k) {
            v1[low + k] = res[k];
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
    vector<int> v = {3, 25, 7, 4, 4, 3};
    MS ms(v);
    ms.solve();
    ms.peek();
    return 0;
}