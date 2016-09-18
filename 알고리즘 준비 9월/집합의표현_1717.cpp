/*
문제 : 집합의표현
문제 번호: 1717
풀이법 : Disjoint-set, union-find(합치고 찾고하는거)
날짜 : 160916
기타 : union-find로 해결
disjoint-set
한마디로 배열을 인덱스 처럼사용을한다. 결국에 재귀를 타서 ... 루트에 다다르도록 만드는 것이다.
그리고 union은 그 두 집합을 이어주는 것이다.

참조 : http://kks227.blog.me/220791837179?Redirect=Log&from=postView

*/


#include<iostream>
#include<algorithm>

using namespace std;

int *disjoint;

int mFind(int a)
{
	if (disjoint[a] < 0)//-1 이라면 어디에도 소속이 된게 아니니까.
		return a;//자기 자신이 루트임.
	else
		return disjoint[a] = mFind(disjoint[a]);
		//이런 구조를 하는 이유는 나중에 바로 루트를 찾을수 있게 이어 놓는거다. 
		//굳이 재귀를 계속 타서 들어가는게 아니라 바로 찾아갈수 있도록
}

bool mUnion(int a, int b)
{
	int _a = mFind(a);
	int _b = mFind(b);

	if (_a == _b)
		return false;
	
	disjoint[_b] = _a;

	return true;
}



int main(void)
{
	int n, q; //n 집합 1000000, q 질문 100000

	cin >> n >> q;
	disjoint = new int[n + 1];

	fill(disjoint, disjoint + n + 1, -1);// 값은 인덱스의 값을 지니기 때문에 -1로 초기화

	//서로소집합 만들기 위함...
	//find와 union을 만들면딘다.

	int command,el1,el2;

	for (int i = 0; i < q; i++)
	{
		scanf("%d %d %d", &command, &el1, &el2);

		if (command==1) // 찾아라 mFind
		{
			if (mFind(el1) == mFind(el2))
				printf("yes\n");
			else
				printf("no\n");
		}else//합쳐라 mUnion
		{
			mUnion(el1, el2);
		}
	}
	//결과를 yes no로 출력한다.

	return 0;
}