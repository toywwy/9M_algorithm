#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dpIdx = 1;

vector<int> arr[1000002];//이부분이 양방향이 되어야하는건데 .....
int dp[1000002];
int res[2][1000002];
bool flag[1000002];

int main(void)
{
	int n;
	cin >> n;


	int a, b;

	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d", &a, &b);
		arr[b].push_back(a);
		arr[a].push_back(b);
	}
	//이렇게 되면 각자의 부모를 알수있게된다.
	//dp에 갯수만 채우면 되는거다...

	dp[0] = 1;
	queue<int> q;
	flag[1] = 1;
	for (int a : arr[1])//1항상 존재
	{
		if (!flag[a])
		{
			flag[a] = 1;
			q.push(a);
			dp[dpIdx] += 1;
		}
	}
	dpIdx++;

	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			for (int k : arr[q.front()])
			{
				if (!flag[k])
				{
					flag[k] = 1;
					q.push(k);
					dp[dpIdx] += 1;
				}
			}
				
			q.pop();
		}
		dpIdx++;
	}

	res[0][0] = 0;
	res[1][0] = dp[0];
	for (int i = 1; i < dpIdx - 1; i++)
	{//0 번지 선택안함
	 //1번지 선택
		res[0][i] += res[1][i - 1];//선택안함 //이전 선택한거에서 가져온다.
		res[1][i] += res[0][i - 1] + dp[i];//선택
	}

	dpIdx -= 2; //for문 증가 인덱스로 사용 -2

	if (res[0][dpIdx] < res[1][dpIdx])
	{
		cout << res[0][dpIdx] << endl;
	}
	else
	{
		cout << res[1][dpIdx] << endl;
	}


	return 0;
}


/*


9
1 2
1 3
2 4
3 5
3 6
4 7
4 8
4 9

문제를 잘못이해했다 ...

이예제를 돌려보면 

이게 얼리어탑터는 중복이 되게 나타날수 있기때문에 재귀를 타면서 dp를 하면 문제를 해결 할 수 있을 것이다.
시간 개많이 썼다 진짜 아까워...


*/