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
	ms(vector<int> v): v1(v) { mergeSort(0, v1.size()); }
	void print(){ for(int n: v1) cout << n << endl; }
};
int main(){
	ms({6,8,0,49,58,90,23,843,759,84,75,1,67,98,34,75,1,0,93,84,4,79,58,743}).print();
	return 0; 
}