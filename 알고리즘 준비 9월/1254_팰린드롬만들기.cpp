/*
���� : �Ӹ���Ҹ����
���� ��ȣ: 1254
Ǯ�̹� : 
��¥ : 161116
��Ÿ : Ȧ�� ¦�� �� ��츦 ������ Ǯ����.
����� ������.

�ε����� �ߴٷ�� �Ѵ�. ����κб��� üũ�� ������ ���ؼ� -1�� ���ִ¹ٶ��� ���� Ʋ���� ���Ծ���.
ab�� üũ�� �����༭

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(void)
{

	string str;
	cin >> str;

	int result = 0;
	int res = 0;

	if (str.size() % 2 == 0)//¦��
	{
		int mid = str.size() / 2;
		//�̰� �̵��..
		while (mid < str.size())
		{
			int left = mid - 1;
			int right = mid;

			bool c = true;

			while (right < str.size())//���������� üũ�Ҽ�����
			{
				if (str[left--] != str[right++])
				{
					c = false;
					break;
				}
			}

			if (c) break;
			//Ȧ��üũ

			left = mid - 1;
			right = mid + 1;//�׳��ϴ� .. ó������ ���ϸ��
			c = true;
			while (right < str.size())
			{
				if (str[left--] != str[right++])
				{
					c = false;
					break;
				}
			}

			if (c)
			{
				res += 1;
				break;
			}

			mid++;
			res += 2;
		}

	}
	else//Ȧ��
	{
		int mid = str.size()/2;
		//��ģ��Ƴ�

		while (mid < str.size())//�̷��� �ؾ� �ε��������� �ȳ���
		{
				//¦��üũ
				int right = mid;
				int left = mid - 1;
				bool c = true;
				if (right!=str.size()/2)//ó���� �ǳʶ۷���
				{
				
					while (right < str.size())//���������� üũ�Ҽ�����
					{
						if (str[left--] != str[right++])
						{
							c = false;
							break;
						}
					}


					if (c)
					{
						res -= 1;
						break;
					}
				}
				//Ȧ��üũ

				left = mid - 1;
				right = mid + 1;//�׳��ϴ� .. ó������ ���ϸ��
				c = true;
				while (right < str.size())
				{
					if (str[left--] != str[right++])
					{
						c = false;
						break;
					}
				}

				if (c)
					break;
				
			mid++;
			res += 2;
		}


	}
	cout << (str.size() + res) << endl;


	return 0;
}
