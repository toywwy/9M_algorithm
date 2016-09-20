#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, int> P;

//sort�ϰ� �� ���Ұǵ�??


class A
{
public:
	int a, b, c;

	A() {}
	A(int a, int b, int c) :a(a), b(b), c(c) {}

	bool operator < (A &a)
	{
		return this->c < a.c;//true�̸� ����Ī�� �Ѵ�.
	}
};


template<class X>
class priority
{
public:
	bool operator() (X &x1, X &x2)//�� ������ �����̶� �׷��Ŵ� . ��ȣ ()�� ���°� ���� ������ �ؾ���.
	{
		return x1.second < x2.second; //��� �ݴ� �ΰ����� �Ǵܵȴ�....
	}
};


//sort�� ����ϱ� ���ؼ� �̿��Ѵ�.
//template <class X> �̰� ���ø��������� �ϸ� �̸��� �ȵ� �� ���Ǹ� �����ؼ� �ؾߵ���?
class sortType
{
public:
	bool operator() (P &x1, P &x2)//�� ������ �����̶� �׷��Ŵ� . ��ȣ ()�� ���°� ���� ������ �ؾ���.
	{
		return x1.first < x2.first; //��� �ݴ� �ΰ����� �Ǵܵȴ�....
	}
}havetorename;//�ݵ�� ������ �̸����� ����ؾ� �Ǵ� ������ ����??


struct myclass {
	bool operator()  (P &x1, P &x2)
	{
		return x1.first < x2.first;
	}
} myobject;

int main(void)
{

	priority_queue < P, vector<P>, priority<P>> PQ;

	PQ.push(P(1, 23));
	PQ.push(P(2, 1));
	PQ.push(P(3, 4));
	PQ.push(P(4, 7));
	PQ.push(P(5, 13));
	PQ.push(P(6, 25));
	PQ.push(P(7, 2));
	PQ.push(P(8, 233));

	while (!PQ.empty())
	{
		P p = PQ.top();
		cout << p.first << " , " << p.second << endl;
		PQ.pop();
	}


	cout << " ----------------------------------------------" << endl;
	cout << " ----------------------------------------------" << endl;
	cout << " ----------------------------------------------" << endl << endl;

	A *arr = new A[10];

	arr[0] = A(1, 9, 12);
	arr[1] = A(2, 8, 3);
	arr[2] = A(3, 7, 1);
	arr[3] = A(4, 6, 22);
	arr[4] = A(5, 5, 9);
	arr[5] = A(6, 4, 30);
	arr[6] = A(7, 3, 4);
	arr[7] = A(8, 2, 2);
	arr[8] = A(9, 1, 11);
	arr[9] = A(10, 0, 77);

	sort(arr, arr + 10);

	for (int i = 0; i < 10; i++)
		cout << arr[i].a << " , " << arr[i].b << " , " << arr[i].c << endl;



	cout << " ----------------------------------------------" << endl;
	cout << " ----------------------------------------------" << endl;
	cout << " ----------------------------------------------" << endl << endl;



	vector<P> v;
	v.push_back(P(1, 23));
	v.push_back(P(2, 1));
	v.push_back(P(3, 4));
	v.push_back(P(4, 7));
	v.push_back(P(5, 13));
	v.push_back(P(6, 25));
	v.push_back(P(7, 2));
	v.push_back(P(8, 233));


	sort(v.begin(), v.end(), havetorename);


	for (P p : v)
		cout << p.first << " , " << p.second << endl;


	return 0;
}