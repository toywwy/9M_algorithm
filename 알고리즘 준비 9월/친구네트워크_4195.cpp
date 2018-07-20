/*
문제 : 친구 네트워크
문제 번호: 4195
풀이법 : disjoint set
날짜 : 18.07.19
기타 :

return 시에 계쏙 root 로 갱신해야 서치 속도를 줄일수가 있다.

*/
#include<iostream>
#include<string>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef pair<string, string> P;

// 친구 관계의 수 F가 주어지며, 이 값은 100,000을 넘지 않는다. 
//알파벳 대문자 또는 소문자로만 이루어진 길이 20 이하의 문자열이다.

map<string, string> arr;//arr["str"] 이런식으로 접근이가능하다.
map<string, int> arrCnt;//갯수 값만 저장한다.

string retrieve(string str)
{
	if (arr[str] == "") return str;
	else return arr[str] = retrieve(arr[str]);//str을 모두 쭉 정해주면서 가야한다.
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
			//10만개의 string input이 
			string root1, root2;

			root1 = retrieve(str1);
			root2 = retrieve(str2);

			//자기자신이 홀로 루트일때
			if (arrCnt[root1] == 0) arrCnt[root1]++;
			if (arrCnt[root2] == 0) arrCnt[root2]++;

			//카운트하는게 문제.
			if (root1 != root2) //merge 작은것을 큰걸로 머지시킨다. 약 60ms 차이났다. 속도가
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