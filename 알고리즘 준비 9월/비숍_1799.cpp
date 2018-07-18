/*
문제 : 비숍
문제 번호: 1799
풀이법 : 백트래킹
날짜 : 18.07.02
기타 :

대각선들를 visit로 체크하는 방법이 새로운 포인트인듯.


우상좌하 대각선의 경우에는 visit[x+y] 로 체크가가능하다.

좌상우하 대각선의 경우에는 x-y를 하면된다. 하지만 그럼 음수가 나오는 부분이 생기기 때문에 N-x-y 를해준다.
N은 숫자 이기때문에
visit[N-1+x-y] 이런식으로 체크


문제의 해결포인트 
시간 복잡도를 줄여야 한다. 
검정판, 흰판은 각각 독립한다 나누어서 생각하자.
 
2^(10*10)  -> 100개
2^(5*5) + 2^(5*5) -> 50개만 비교해보면된다 나머지 50개는 필요없기 때문이라고 생각.

*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int arr[12][12]; //,10]

int N, M,len, mMax;

int dx[4] = { -1, 1, 1, -1 }; //왼쪽 위 대각선 부터 시계방향으로 ㄱ
int dy[4] = { -1, -1, 1, 1 };

int visit1[24];
int visit2[24];

void recur(int level, int cnt, bool c)
{
	if (level < len)
	{
		int x, y, value = 0;

		if (c == true) value = 2 * level - 1;
		else value = 2 * level;

		y = value / N;
		x = value % N;


		if (arr[y][x] == 1 && 
			visit1[x + y] == false && 
			visit2[N - 1 - y + x] == false)
		{
				visit1[x + y] = true;
				visit2[N - 1 - y + x] = true;

				recur(level + 1, cnt + 1, c);

				visit1[x + y] = false;
				visit2[N - 1 - y + x] = false;
		}
		
		recur(level + 1, cnt, c);
		
	}
	else {
		mMax = max(mMax, cnt);
		int k = mMax;
	}

}


int main(void)
{
	cin >> N;
	len = N*N;
	bool chk;
	int len1, len2;
	
	if (len % 2 == 0) {//짝수
		chk = false;
	}
	else {//홀수 - 문제는 홀수일때 짝수들어갈때
		len1= (len + 1) / 2;
		chk = true;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];


	//두개로 나눠서 합산을 하면 된다.
	int res = 0;
	
	mMax = 0;
	recur(0, 0, true);//홀수부
	res += mMax;

	mMax = 0;
	if(chk==true) len--;
	//짝수였다면 서로 같기때문에 문제가안된다.
	//하지만 홀수일때는 값을 더 받게 된다.

	recur(0, 0, false);//짝수일때는 
	res += mMax;

	cout << res << endl;


	return 0;
}