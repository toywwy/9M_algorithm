#include<iostream>
#include<cstdio>

using namespace std;


union BYTE {
	unsigned char byte;
	class _bit {
	public:
		unsigned char b0 : 1;
		unsigned char b1 : 1;
		unsigned char b2 : 1;
		unsigned char b3 : 1;
		unsigned char b4 : 1;
		unsigned char b5 : 1;
		unsigned char b6 : 1;
		unsigned char b7 : 1;
	}bit; //선언 되어있어야 쓸수있다.
};


//언제 쓸일이있을까?

int main(void)
{
	BYTE b;
	int N;
	cin >> N;
	b.byte = N;

	printf("%d", b.bit.b7);
	printf("%d", b.bit.b6);
	printf("%d", b.bit.b5);
	printf("%d", b.bit.b4);
	printf("%d", b.bit.b3);
	printf("%d", b.bit.b2);
	printf("%d", b.bit.b1);
	printf("%d\n", b.bit.b0);



	return 0;
}