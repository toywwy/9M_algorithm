/*
���� : ���ڿ�����
���� ��ȣ: 4354
Ǯ�̹� : KMP
��¥ : 161008
��Ÿ : KMP�� �̿��ؼ� Ǯ����.
if (!(s[0] ^ '.')) break; �� �̿��ϸ� ���������� �ƴ��� �Ǵ��� �����ϴ�.

�̰Ǽ����� ������ �������

�������� IOIOI ���� �̹����� ������ �̰� ������ �ݺ��̱⶧���� ó���� �� ��� �����ϸ� �Ǳ⶧��

*/


#include<iostream>
#include<string>

using namespace std;


int main(void)
{
	while (true)
	{
		string s;
		cin >> s;

		if (!(s[0] ^ '.')) break;

		//������ *n�̴�. ������ �Ȱ����� �ݺ��ȴٰ� ���ߴ� �ƴϸ� �ٸ��� �ϳ��� �ݺ��Ǵ���?
		//abcaabcaabca
		int i = 0;
		int j = 1;
		bool check = false;
		int res = 0;

		while (j < s.size())//�ڳ����̽� �����ض� �ٵ� j�� ������ ���ٴ°� ������ �����ߴٴ°Ŵ�.
		{
			if (s[i] == s[j])
			{
				if (!check)
					res = j;

				i++;
				j++;

				check = true;
			}
			else
			{
				if (check)// �ٽ� ó������ ���縦 �ؾ��Ѵ�.
					check = i = 0;
				else
					j++;
			}
		}

		if(check)
			cout << (s.size() / res) << endl;
		else
			cout << 1 << endl;

	}

	return 0;
}




//#include<iostream>
//
//using namespace std;
//
//char s[1000001];
//int f[1000001];
//int main() {
//	
//	while (true) {
//		scanf("%s", s);
//
//		if (!(s[0] ^ '.')) //s[0] ^ '.' ������ xor ������ 0�����ϱ� //== �� xor�� ��ü�����ϴ�.
//			break;
//
//		int i = 1;
//		int j = 0;
//		f[0] = -1;
//
//		while (s[i] != NULL)
//		{
//			if (j < 0 | s[j] == s[i])
//				f[++i] = ++j;
//			else
//				j = f[j];//�갡 -1�� ����Ű�� �Ǹ� ��
//		}
//
//		printf("%d\n", i / (i - f[i]));
//	}
//	return 0;
//}