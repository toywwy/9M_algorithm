#include<iostream>
#include<string>
using namespace std;

int fail[10];//pi��� �� ���� �´� ���ϴ�.

int main(void)
{

	string str;
	getline(cin, str);

	int strLen = str.length();

	int i = 1,j = 0;//0 ���ʿ� ����
	int match = 1;
	while(j < strLen && i<strLen)
	{
		if (str[i] == str[j++]) fail[i++] = match++;
		else {
			//i�� ���� ������ �м��غ����Ѵ�.
			if (match > 1)
			{
				int temp = fail[match - 2];
				match = 1;
				match += temp;//�ش��ϴ� �κи��� �°� �����ϴ°� KMP�� �����̴�.
				j = temp;
			}
			else
			{
				i++;
				match = 1;//�ٽ� �ʱ�ȭ.
				j = 0;//�� �ٽ� ó������  j���ƴҼ�����.
			}
			
		}
	}
	



	//����� Ȯ��
	for (int i = 0; i < strLen; i++)
		cout << fail[i] << endl;




	return 0;
}