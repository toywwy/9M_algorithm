/*
문제 : LCA
문제 번호: 11437
풀이법 : LCA - Lowest Common Ancestor
날짜 : 161008
기타 : 
dp [현재노드] = { 첫번쨰 부모, 두번째 부모, 세번쨰 부모 ,,,,,}
이런식으로 원래는 2^k 승으로 하나본데 모든걸 다 저장해 봤다.

포인트는 초반에 레벨을 세팅함으로써 그노드가 어느레벨에 위치해 있는지 알게 됨으로써
트리를 구성했다고 볼수가있다.

depth[k] = depth[x] + 1;//굳 정보다...진짜로

dp를 초기화하는 부분은


k = dp[k][0];
한마디로 dp[dp[dp[k]]]] 이런 느낌으로 부모가 상승한다는 걸 알수있다.
그걸 바탕으로 dp 맵을 구성할 수 가 있다.
*/


#include <iostream>
#include <vector>
#define N 50000
using namespace std;
typedef pair<int, int> P;

int depth[N+2]; //갯수가 50000만개
vector<int> dp[N+2];//각노드에서의 부모를....
vector<int> input[N+2];


void recur(int x)//init 하는 부분임
{
	for (int k : input[x])
	{
		if (depth[k]==0)
		{
			depth[k] = depth[x] + 1;//굳 정보다...진짜로
			dp[k].push_back(x);//이게 첫번쨰 부모가될거야.
			recur(k);
		}
	}
}

int main(void)
{
	int n;
	cin >> n;
	int a, b;


	for(int i = 0 ; i < n-1;i++)
	{
		scanf("%d %d", &a, &b);
		input[a].push_back(b);//생각해보면 
		input[b].push_back(a);//생각해보면 
	}

	//1이 루트이고아래로 내려가는구조이다.
	depth[1] = 1;
	recur(1);

	//그냥 구조는 만들었고 이제 맨아래서부터 채워야함.
	
	//레벨을 알아야 구성이 가능하다.
	//dp 초기화
	for (int i = 1; i <= n; i++)
	{
		int k = i;
		while(depth[k] != 1)//1이되면 끝난다.
		{
			k = dp[k][0];//자기 첫번쨰..
			dp[i].push_back(k);
		}
	}

	int q,temp,diff,c;
	cin >> q;

	while (q--)
	{
		scanf("%d %d", &a, &b);
		
		if (a == b)
		{
			printf("%d\n",a);
			continue;
		}

		if (depth[a] < depth[b])
		{
			temp = a;
			a = b;
			b = temp;
		}
		
		diff = depth[a] - depth[b];

		c = 1;
		
		if (dp[a][diff] == b)
		{
			cout << b << endl;
		}
		else
		{
			while (dp[a][c + diff] != dp[b][c]) c++;
			cout << dp[b][c] << endl;
		}
	}

	return 0;
}