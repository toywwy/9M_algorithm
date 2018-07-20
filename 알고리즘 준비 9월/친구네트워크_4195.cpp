/*
���� : ģ�� ��Ʈ��ũ
���� ��ȣ: 4195
Ǯ�̹� : disjoint set
��¥ : 18.07.19
��Ÿ :

return �ÿ� ��� root �� �����ؾ� ��ġ �ӵ��� ���ϼ��� �ִ�.

*/
#include<iostream>
#include<string>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef pair<string, string> P;

// ģ�� ������ �� F�� �־�����, �� ���� 100,000�� ���� �ʴ´�. 
//���ĺ� �빮�� �Ǵ� �ҹ��ڷθ� �̷���� ���� 20 ������ ���ڿ��̴�.

map<string, string> arr;//arr["str"] �̷������� �����̰����ϴ�.
map<string, int> arrCnt;//���� ���� �����Ѵ�.

string retrieve(string str)
{
	if (arr[str] == "") return str;
	else return arr[str] = retrieve(arr[str]);//str�� ��� �� �����ָ鼭 �����Ѵ�.
}

int main(void)
{

	ios::sync_with_stdio(false); cin.tie(0);
	int C;
	cin >> C;

	for (int itr = 0; itr < C; itr++)
	{
		int N;
		string str1, str2;
		cin >> N;
		arrCnt.clear();
		arr.clear();

		for (int i = 0; i < N; i++)
		{
			cin >> str1 >> str2;
			//10������ string input�� 
			string root1, root2;

			root1 = retrieve(str1);
			root2 = retrieve(str2);

			//�ڱ��ڽ��� Ȧ�� ��Ʈ�϶�
			if (arrCnt[root1] == 0) arrCnt[root1]++;
			if (arrCnt[root2] == 0) arrCnt[root2]++;

			//ī��Ʈ�ϴ°� ����.
			if (root1 != root2) //merge �������� ū�ɷ� ������Ų��. �� 60ms ���̳���. �ӵ���
			{
				if (arrCnt[root1] > arrCnt[root2])
				{
					arr[root2] = root1;
					arrCnt[root1] += arrCnt[root2];
					cout << arrCnt[root1] << "\n";
				}
				else
				{
					arr[root1] = root2;
					arrCnt[root2] += arrCnt[root1];
					cout << arrCnt[root2] << "\n";
				}
			}
			else cout << arrCnt[root1] << "\n";

		}
	}


	return 0;
}