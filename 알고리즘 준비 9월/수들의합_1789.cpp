/*
���� : ��������
���� ��ȣ: 1789
Ǯ�̹� : ������..
��¥ : 20170702
��Ÿ :

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{

	long long S = 0, M=0;
	cin >> S; //���� S�� �Ǵ� �ּ��� ���� ������ ���ϴ� ���̴�.

	int i = 1;
	for (; M + (i + 1) < S; i++) M += i;

	if (M + i == S) cout << i << endl;
	else
	{ 
		long long m = S - M;
		
		if (m > i) cout << i << endl;
		else
		{//�ܰ踦 ���������Ѵ�.
			int h = i - 1;
			
			for (int k = h; k >= 1; k--)
			{
				M -= k;
				
				m = S - M;
				if (m > k)
				{
					cout << k << endl;
					break;
				}
			}
		}

	}



	return 0;
}
