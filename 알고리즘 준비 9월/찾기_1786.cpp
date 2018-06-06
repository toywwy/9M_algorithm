/*
���� : ã��
���� ��ȣ: 1786
Ǯ�̹� : KMP
��¥ : 18.4.10 
��Ÿ : ���� Ǫ�µ� ��ƴ�. ���������� �����.

*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> get_fail(string p)
{
	vector<int> fail(p.size());

	for (int i = 1, j = 0; i<p.size(); ++i) {

		if (p[i] != p[j]) j = fail[j - 1];
		//Ʋ���� ���ϴ°Ͱ� �׷��� Ʋ���� fail �Լ� ȣ���ؼ� j�� �־��ش�.
		//�׸��� �� �ڸ����� �ٽ� i�� �񱳸� �Ҽ� �ְԵȴ�.
		//j�� �ű���� ���� �����̴ϱ�. ���� ������ i�� �񱳸� �ϸ�ȴ�.
		if (p[i] == p[j]) fail[i] = ++j;
		//�´����� ���ϴ� ���� ���εд�.
	}

	return fail;
}

int main(void)
{
	string str, p;
	getline(cin, str);
	getline(cin, p);

	vector<int> ans;
	vector<int> fail;

	fail = get_fail(p);

	int strlen = str.size();
	int plen = p.size();

	for (int i = 0, j = 0; i<strlen; ++i) {
		if (str[i] != p[j]) j = fail[j - 1];

		if (str[i] == p[j])
		{
			if (j == plen - 1)
			{
				j = fail[j];
				ans.push_back(i - plen + 2);
			}
			else
				j++;
		}
	}

	int length = ans.size();

	cout << length << endl;
	for (int i = 0; i<length; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}