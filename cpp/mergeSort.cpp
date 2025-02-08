#include <iostream>
#include <vector>
using namespace std;
class ms{
private:
	vector<int> v1;
	void mergeSort(int low, int high){
		if(high - low <= 1) return;
		int mid = low + (high - low)/2 ;
		mergeSort(low, mid);
		mergeSort(mid, high);
		merge(low, mid, high);
	}
	void merge(int low, int mid, int high){
		vector<int> tmp = v1;
		int i = low;
		int j = mid;
		int k = low;
		while(i < mid && j < high){
			if(tmp[i] > tmp[j]) v1[k++] = tmp[j++]; 
			else v1[k++] = tmp[i++];
		}
		while(i < mid) v1[k++] = tmp[i++];
		while(j < high) v1[k++] = tmp[j++];
	}
public:
	ms(vector<int> v): v1(v) {}
	void print(){
		mergeSort(0, v1.size());
		for(int n: v1) cout << n << " ";
		cout << endl;
	}
};
int main(){
	vector<int> v = {7,6,5,4,3,2,56,4,73,89,24,75,63,90,245,64,6783,923,45,62};
	ms m = ms(v);
	m.print();
	return 0;
}