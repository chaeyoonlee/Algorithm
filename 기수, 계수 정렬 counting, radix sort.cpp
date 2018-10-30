int arr[10] = { 22,11,64,788,964,4,50,56,0,99 };
int n = 10;
void print() {
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl;
}
void counting() {
	int count[10];
	memset(count, 0, sizeof(count));
	for (int i = 0; i < n; i++)count[arr[i]]++;//갯수 세고
	for (int i = 1; i < n; i++)count[i] += count[i - 1];//index 누적 해 쌓고
	int tmp[10];
	for (int i = 0; i < n; i++) {
		tmp[count[arr[i]] - 1] = arr[i];//index 0부터 시작하니 -1하고
		count[arr[i]] -= 1;//이미 그 자리에 하나 넣어줬으니 뻄
	}
	for (int i = 0; i < n; i++)arr[i] = tmp[i];
}
void radix() {
	int count[10];
	int tmp[10];

	int k = 10;//10진수
	int index, pval;
	for (int d = 0; d < 3; d++) {//3자리 수 까지 100
		memset(count, 0, sizeof(count));
		pval = (int)pow((double)k, (double)d);//1,10,100
		for (int i = 0; i < n; i++) {
			index = (arr[i] / pval) % k;//그 자릿수의 마지막 자리
			count[index] += 1;
		}
		for (int i = 1; i < 10; i++) count[i] += count[i - 1];
		for (int i = n - 1; i >= 0; i--) {//뒤에서 부터
			index = (arr[i] / pval) % k;//그 자릿수의 마지막 자리
			tmp[count[index] - 1] = arr[i];
			count[index] -= 1;
		}
		for (int i = 0; i < n; i++)arr[i] = tmp[i];
		print();
	}

}