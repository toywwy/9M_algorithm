/*
���� : KMP�� ��KMP�ϱ�?
���� ��ȣ: 2902
Ǯ�̹� : ���ڿ�, KMP
��¥ : 161008
��Ÿ : �ణ�� KMP�� �̿��ϴ� ��������
*/


#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int len;
	scanf("%d", &len);

	int resCnt = 0;

	string s;
	cin >> s;

	int idx = 1;

	bool res = true;
	int trueCnt = 0;
	while (idx + 2 < s.size())
	{
		if (s[idx - 1] == 'I')
		{
			if (s[idx] == 'O')
			{
				if (s[idx + 1] != 'I')
					res = false;
			}
			else
				res = false;
		}
		else res = false;

		if (res)
		{
			idx += 2;
			trueCnt++;

			if (trueCnt == n)//����ó��
			{
				resCnt += 1;
				trueCnt = n-1;
			}
		}
		else
		{
			idx += 1;
			trueCnt = 0;
			res = true;
		}
	}

	cout << resCnt << endl;
	return 0;
}