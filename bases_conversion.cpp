#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int charToInt(char c) { return (int)(c - 48); }
char intToChar(int i) { return (char)(i + 48); }

int main()
{
	// Read user info
	string input_string;
	cout << "Input number: "; cin >> input_string;
	int input_base, output_base;
	cout << "Input base: "; cin >> input_base;
	cout << "Output base: "; cin >> output_base;

	// Convert n to base 10
	int n = 0;
	int p = input_string.size();
	for (char c : input_string) n += charToInt(c) * (int)pow(input_base, --p);

	// Find highest power to start conversion with
	p = 0;
	while (pow(output_base, p++) <= n); p -= 2;

	// Convert base 10 to output_base
	string output_string;
	int d, r, q;
	while (p >= 0)
	{
		d = (int)pow(output_base, p--);
		r = n % (int)d;
		q = (int)(n / d);
		n -= q * d;
		output_string.push_back(intToChar(q));
	}
	cout << "ouput number:" << output_string << endl;

	return 0;
}