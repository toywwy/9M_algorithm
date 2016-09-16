#include<iostream>
#include<vector>
#define SIZE 8

using namespace std;


int arr[SIZE] = { 234,4,24,1, 423,43,545,133 };
int L[SIZE / 2];
int R[SIZE / 2];



void mergeSort(int start, int end, int half)
{
	int sCnt = half - start; // half는 start에는 열려있고 end에는 닫혀있기 때문이다.
	int eCnt = end - half + 1;
	int idx = 0;

	while (idx < sCnt)
	{
		L[idx] = arr[start + idx];
		idx++;
	}

	idx = 0;
	while (idx < eCnt)
	{
		R[idx] = arr[half+idx];
		idx++;
	}

	// 입력 했고 // 정렬
	idx = start;

	int rightIdx = 0;
	int leftIdx = 0;
	

	while (rightIdx < sCnt && leftIdx <eCnt)//둘중하나라도 카운트만큼하면
	{
		if (L[leftIdx] > R[rightIdx])
			arr[idx++] = R[rightIdx++];//작은애를 넣어야함.
		else
			arr[idx++] = L[leftIdx++];
	}


	//남은거
	while (rightIdx < sCnt)
		arr[idx++] = R[rightIdx++];
	
	while (leftIdx < eCnt)
		arr[idx++] = L[leftIdx++];
	
}

void devide(int start, int end)
{
	if (start >= end)
		return;

	int half = (start + end) / 2;

	devide(start,half );
	devide(half+1 , end);

	mergeSort(start, end, (half+1));
}


int main(void)
{
	
	devide(0, SIZE - 1);

	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";
	cout << endl;


	return 0;
}