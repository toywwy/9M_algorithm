/*
문제 : 물통
문제 번호: 2251
풀이법 : DFS
날짜 : 161011
기타 : DFS 재귀를 돌리는데 
일어 날수 있는 모든 상황에 대해서 체크를 하면된다. 

BFS문제인데 BFS보단 DFS에 자신..

091이다 만약에

base를 모두 각각 둬본다 (base란 물을 어디서 따를지 )

그리고 이 경우에도 물통에 물이 남아서 다른 곳으로 한번더 줘야하는 경우가있다.

그리고 없는경우 ... 이렇게해서 재귀를 돌려보면되.

그냥 완전탐색을 해보는거다.

*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

unsigned char check[201][201][201];
int arr[3]; //물계산할때 쓸꺼

vector<int> res;
int tSize[3];

void recur(int arr[])
{
	int base;
	if (!check[arr[0]][arr[1]][arr[2]]) {

		check[arr[0]][arr[1]][arr[2]] = 1;

		if (arr[2] == 0)
			res.push_back(arr[0]);
	}
	else
		return;

	int copy[3];
	int copy2[3];

	for (int i = 0; i < 3; i++)
		copy[i] = arr[i];

	for (int ii = 0; ii < 3; ii++)
	{
		base = ii;

		if (arr[base] == 0)
			continue;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				arr[j] = copy[j];//같은 상황에서 이용하기위해서

			if (i != base)
			{
				//base 에서 i로 물을옮길거야
				int water = arr[base]; //쓸수있는 물의양
				int over = 0;
				arr[i] += water;
				water = 0;
				if (arr[i] > tSize[i])
				{
					over = arr[i] - tSize[i];
					arr[i] = tSize[i];
					water = over;
				}
				arr[base] = water;
				
				for (int j = 0; j < 3; j++)
				{
					for (int i = 0; i < 3; i++)
						copy2[i] = arr[i];

					recur(copy2);//여기에서 두방향으로 재귀를 만들어야 된다.
				}

				if (water > 0) {
					for (int j = 0; j < 3; j++)
					{
						if (j != i && j != base)
						{
							arr[j] += water;//j에다가 물을따른다.
							water = 0;
							if (arr[j] > tSize[j])
							{
								over = arr[j] - tSize[j];
								arr[j] = tSize[j];
								water = over;
							}
						}
					}

					arr[base] = water;

					for (int j = 0; j < 3; j++)
					{
						for (int i = 0; i < 3; i++)
							copy2[i] = arr[i];

						recur(copy2);//여기에서 두방향으로 재귀를 만들어야 된다.
					}
				}

				

			}
		}
	}
}

int main(void)
{
	//0, 1,2,라고생각을하자 // 처음엔 
	cin >> tSize[2] >> tSize[1] >> tSize[0];//이것들은 각각 물통의 사이즈
	//a부터 시작하면 되고 c가 0일때 a의 값을 

	arr[0] = tSize[0];//물이 처음에 0에 다들어있다.
	arr[1] = 0;
	arr[2] = 0;

	recur(arr);

	sort(res.begin(), res.end());
	for (int r : res)
		cout << r << " ";
	cout << endl;

	return 0;
}

/*
첫 번째 물통(용량이 A인)이 비어 있을 때, 세 번째 물통(용량이 C인)에 담겨있을 수 있는 물의 양을 모두 구해내는 프로그램을 작성하시오.

*/