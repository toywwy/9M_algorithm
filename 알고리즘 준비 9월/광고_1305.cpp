#include <iostream>
#include<string>
using namespace std;
int arr[1000000];
int main(int argc, const char * argv[]) {
	string s;
	int sN;
	cin >> sN;
	cin >> s;
	for (int i = 1; i<sN; i++) {
		if (arr[i - 1] == 0)
			arr[i] = s[0] == s[i] ? 1 : 0;
		else
			arr[i] = s[arr[i - 1]] == s[i] ? arr[i - 1] + 1 : s[0] == s[i] ? 1 : 0;
	}

	cout << sN - arr[sN - 1] << '\n';
	return 0;
}