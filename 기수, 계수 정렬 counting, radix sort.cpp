int arr[10] = { 22,11,64,788,964,4,50,56,0,99 };
int n = 10;
void print() {
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl;
}
void counting() {
	int count[10];
	memset(count, 0, sizeof(count));
	for (int i = 0; i < n; i++)count[arr[i]]++;//���� ����
	for (int i = 1; i < n; i++)count[i] += count[i - 1];//index ���� �� �װ�
	int tmp[10];
	for (int i = 0; i < n; i++) {
		tmp[count[arr[i]] - 1] = arr[i];//index 0���� �����ϴ� -1�ϰ�
		count[arr[i]] -= 1;//�̹� �� �ڸ��� �ϳ� �־������� �M
	}
	for (int i = 0; i < n; i++)arr[i] = tmp[i];
}
void radix() {
	int count[10];
	int tmp[10];

	int k = 10;//10����
	int index, pval;
	for (int d = 0; d < 3; d++) {//3�ڸ� �� ���� 100
		memset(count, 0, sizeof(count));
		pval = (int)pow((double)k, (double)d);//1,10,100
		for (int i = 0; i < n; i++) {
			index = (arr[i] / pval) % k;//�� �ڸ����� ������ �ڸ�
			count[index] += 1;
		}
		for (int i = 1; i < 10; i++) count[i] += count[i - 1];
		for (int i = n - 1; i >= 0; i--) {//�ڿ��� ����
			index = (arr[i] / pval) % k;//�� �ڸ����� ������ �ڸ�
			tmp[count[index] - 1] = arr[i];
			count[index] -= 1;
		}
		for (int i = 0; i < n; i++)arr[i] = tmp[i];
		print();
	}

}