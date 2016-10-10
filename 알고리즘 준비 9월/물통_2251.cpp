/*
���� : ����
���� ��ȣ: 2251
Ǯ�̹� : DFS
��¥ : 161011
��Ÿ : DFS ��͸� �����µ� 
�Ͼ� ���� �ִ� ��� ��Ȳ�� ���ؼ� üũ�� �ϸ�ȴ�. 

BFS�����ε� BFS���� DFS�� �ڽ�..

091�̴� ���࿡

base�� ��� ���� �ֺ��� (base�� ���� ��� ������ )

�׸��� �� ��쿡�� ���뿡 ���� ���Ƽ� �ٸ� ������ �ѹ��� ����ϴ� ��찡�ִ�.

�׸��� ���°�� ... �̷����ؼ� ��͸� ���������.

�׳� ����Ž���� �غ��°Ŵ�.

*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

unsigned char check[201][201][201];
int arr[3]; //������Ҷ� ����

vector<int> res;
int tSize[3];

void recur(int arr[])
{
	int base;
	if (!check[arr[0]][arr[1]][arr[2]]) {

		check[arr[0]][arr[1]][arr[2]] = 1;

		if (arr[2] == 0)
			res.push_back(arr[0]);
	}
	else
		return;

	int copy[3];
	int copy2[3];

	for (int i = 0; i < 3; i++)
		copy[i] = arr[i];

	for (int ii = 0; ii < 3; ii++)
	{
		base = ii;

		if (arr[base] == 0)
			continue;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				arr[j] = copy[j];//���� ��Ȳ���� �̿��ϱ����ؼ�

			if (i != base)
			{
				//base ���� i�� �����ű�ž�
				int water = arr[base]; //�����ִ� ���Ǿ�
				int over = 0;
				arr[i] += water;
				water = 0;
				if (arr[i] > tSize[i])
				{
					over = arr[i] - tSize[i];
					arr[i] = tSize[i];
					water = over;
				}
				arr[base] = water;
				
				for (int j = 0; j < 3; j++)
				{
					for (int i = 0; i < 3; i++)
						copy2[i] = arr[i];

					recur(copy2);//���⿡�� �ι������� ��͸� ������ �ȴ�.
				}

				if (water > 0) {
					for (int j = 0; j < 3; j++)
					{
						if (j != i && j != base)
						{
							arr[j] += water;//j���ٰ� ����������.
							water = 0;
							if (arr[j] > tSize[j])
							{
								over = arr[j] - tSize[j];
								arr[j] = tSize[j];
								water = over;
							}
						}
					}

					arr[base] = water;

					for (int j = 0; j < 3; j++)
					{
						for (int i = 0; i < 3; i++)
							copy2[i] = arr[i];

						recur(copy2);//���⿡�� �ι������� ��͸� ������ �ȴ�.
					}
				}

				

			}
		}
	}
}

int main(void)
{
	//0, 1,2,������������ // ó���� 
	cin >> tSize[2] >> tSize[1] >> tSize[0];//�̰͵��� ���� ������ ������
	//a���� �����ϸ� �ǰ� c�� 0�϶� a�� ���� 

	arr[0] = tSize[0];//���� ó���� 0�� �ٵ���ִ�.
	arr[1] = 0;
	arr[2] = 0;

	recur(arr);

	sort(res.begin(), res.end());
	for (int r : res)
		cout << r << " ";
	cout << endl;

	return 0;
}

/*
ù ��° ����(�뷮�� A��)�� ��� ���� ��, �� ��° ����(�뷮�� C��)�� ������� �� �ִ� ���� ���� ��� ���س��� ���α׷��� �ۼ��Ͻÿ�.

*/