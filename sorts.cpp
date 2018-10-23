//11:20
#include <iostream>
#include <algorithm>
using namespace std;
int arr[10] = { 7,10,3,0,1,5,6,8,2,4 };
void print() {
	for (int i = 0; i < 10; i++) cout << arr[i] << " ";
	cout << endl;
}
void swap(int&a, int&b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void quick(int left, int right) {
	int i = left;
	int j = right;
	int p = arr[(i + j) / 2];
	while (i <= j) {
		while (arr[i] < p)i++;
		while (arr[j] > p)j--;
		if (i<=j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (j > left) quick(left, j);
	if (i < right) quick(i, right);
}
int marr[10];
void merge(int left, int right) {
	if (left == right) return;
	int m = (left + right) / 2;
	merge(left, m);
	merge(m + 1, right);
	int i = left; int j = m + 1; int index = left;

	while (i <= m && j <= right) {
		if (arr[i] < arr[j]) { marr[index] = arr[i]; index++; i++; }
		else { marr[index] = arr[j]; j++; index++; }
	}
	while (i <= m) { marr[index] = arr[i]; ; index++; i++;
	}
	while(j<=right) { marr[index] = arr[j]; j++; index++; }
	//끝난 거 넣어주기
	while (left <= right) {
		arr[left] = marr[left];
		left++;
	}
}
void down(int me, int end) {//나부터 자식 비교하며 내려감
	//cout << "me: " << arr[me] << endl;
	int left = (me * 2)+ 1;
	int right = left + 1;
	int p=me;
	while (left<end && right<end) {
		//p = me;
		if (left <= 9&&arr[left] > arr[p]) p = left;
		if (right <= 9&&arr[p] < arr[right]) p = right;
		if (me == p)return;
		swap(arr[p], arr[me]);
		me = p;
		left = (me * 2) + 1;
		right = left + 1;
	}
}
void makeheap() {//맨끝 부모부터 최상위까지 돌리며 힙 구성
	int n =10;
	for (int i = (n-1) / 2; i >= 0; i--) {
		down(i,10);
		//print();
	}
}
void heap() {//maekheap하고 자식과 부모 바꿔주며 돌리며 저장
	makeheap();
	//print();
	for (int i = 9; i > 0; i--) {
		swap(arr[i], arr[0]);
		//print();
		down(0,i);
	}
}
void bubble() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < (9 - i); j++) {
			if (arr[j] > arr[j + 1]) { swap(arr[j], arr[j + 1]); }
		}
	}
}
void insert() {
	
	for (int i = 1; i < 10; i++) {
		cout << "i : " << arr[i] << endl;
		for (int j = 0; j <i; j++) {
			if (arr[i] < arr[j]) {//i 저장 j+1~i-1을 j+2 ~ i까지 밀고 j+11 자리에 i 들어감
				int tmp = arr[i];
				//뒤로 밀기
				for (int k =i-1; k >=j; k--) {
					arr[k + 1] = arr[k];
				}
				arr[j] = tmp;
			}
		}
	}
}
void selection() {
	int mmax = 0; int mindex;
	for (int i = 9; i >1; i--) {
		mmax = arr[0]; mindex = 0;
		for (int j = 1; j <= i; j++) {
			if (arr[j] > mmax) {
				mmax = arr[j]; mindex = j;
			}
		}
		swap(arr[mindex],arr[i]);
	}
}
int main(int argc, char** argv) {

	print();
	//quick(0, 9);
	//merge(0, 9);
	//bubble();
	//insert();
	//selection();
	heap();
	print();
	return 0;
}