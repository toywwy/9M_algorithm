/*
문제 : 문자열제곱
문제 번호: 4354
풀이법 : KMP
날짜 : 161008
기타 : KMP를 이용해서 풀었따.
if (!(s[0] ^ '.')) break; 를 이용하면 같은것인지 아닌지 판단이 가능하다.

이건솔찍히 굉장히 쉬운문제고

어려울려면 IOIOI 차라리 이문제가 어려운듯 이건 무조건 반복이기때문에 처음만 잘 잡고 시작하면 되기때문

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

		//무조건 *n이다. 무조건 똑같은게 반복된다고 봐야대 아니면 다른게 하나씩 반복되던가?
		//abcaabcaabca
		int i = 0;
		int j = 1;
		bool check = false;
		int res = 0;

		while (j < s.size())//코너케이스 주의해라 근데 j가 끝까지 갔다는건 끝까지 조사했다는거다.
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
				if (check)// 다시 처음부터 조사를 해야한다.
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
//		if (!(s[0] ^ '.')) //s[0] ^ '.' 같으면 xor 했을때 0나오니까 //== 은 xor로 대체가능하다.
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
//				j = f[j];//얘가 -1을 가리키게 되면 끝
//		}
//
//		printf("%d\n", i / (i - f[i]));
//	}
//	return 0;
//}