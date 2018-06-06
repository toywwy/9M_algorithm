#include<iostream>
#include<string>
#include<vector>

using namespace std;

short fail[1000002];//pi��� �� ���� �´� ���ϴ�.
int resCnt;
int main(void)
{
	vector<int> idx;
	string str, ori;

	getline(cin, ori);
	getline(cin, str);//��� ���� ����� �ؾ��Ѵ�.

	int strLen = str.length();
	int oriLen = ori.length();

	int match = 0;
	for (int i = 1, j = 0; i<strLen; ++i) {

		while (j>0 && str[i] != str[j]) j = fail[j - 1];

		if (str[i] == str[j]) fail[i] = ++j;
	}

	for (int i=0,j=0; i < oriLen && j < strLen;)
	{
		if (ori[i] == str[j++]) {
			i++;
			match++;
			if (match == strLen)
			{
				resCnt++;
				idx.push_back(i - strLen + 1);

				j = match = fail[match - 1];
			}
		}
		else {

			if (match > 0)
			{
				j = match = fail[match - 1];
			}
			else
			{
				j = match = 0;//�ٽ� �ʱ�ȭ.
				i++;
			}
		}

	}

	cout << resCnt << endl;
	for (int k = 0; k < idx.size(); k++)
	{
		cout << idx[k] << endl;
	}

	return 0;
}