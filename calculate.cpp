//9:00
#include<iostream>
//#include<fstream>
using namespace std;
int mmin;
int mmax;
int N;
int arr[4];
int nums[12];

void dfs(int caled, int numtocal) {
	//������� ������ ��� �ٽ�ٸ� return ���簪
	//cout << caled << "\n";
	;	if (numtocal == N) {
		//cout << endl;
		if (caled < mmin) mmin = caled;
		if (caled > mmax) mmax = caled;
		//cout << "min " << mmin << " max " << mmax << endl;
	}

	for (int i = 0; i < 4; i++) {
		if (arr[i] != 0) {
			if (i == 0) {//cout << caled<<"+"<<nums[numtocal]<<endl;
				arr[i]--;
				dfs(caled + nums[numtocal], numtocal + 1);
				arr[i]++;

			}
			else if (i == 1) {
				//cout << caled << "-" << nums[numtocal] << endl;
				arr[i]--;
				dfs(caled - nums[numtocal], numtocal + 1);
				arr[i]++;
			}
			else if (i == 2) {
				//cout << caled << "*" << nums[numtocal] << endl;
				arr[i]--;
				dfs(caled * nums[numtocal], numtocal + 1);
				arr[i]++;
			}
			else {
				//cout << caled << "/" << nums[numtocal] << endl;
				arr[i]--;
				dfs((int)(caled / nums[numtocal]), numtocal + 1);
				arr[i]++;
			}

		}

	}

}

int main(int argc, char** argv)
{
	//ifstream fin("input.txt");
	int test_case;
	int T;
	//fin >> T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (register int i = 0; i < 4; i++) {
			//������ ���Է�
			cin >> arr[i];
		}
		for (register int i = 0; i < N; i++) {
			//������ ���Է�
			cin >> nums[i];
		}
		mmin = 100000000;
		mmax = -100000000;
		//�Լ�
		dfs(nums[0], 1);
		int ans = mmax - mmin;
		cout << "#" << test_case << " " << ans << "\n";
	}
	//	system("pause");
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}