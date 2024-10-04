#include <iostream>
#include <cmath>
using namespace std;
double P0(const int N)
{
	double P = 0;
	for (int k = 1; k <= N; k++) {
		P += (pow(k, 2)) / (pow(N, 2)) * cos(1. * (pow(N, 2)) / (pow(k, 2)));
	}
	return P;
}

double P1(const int N, const int k)
{
	if (k > N)
		return 0;
	else
		return  (pow(k, 2)) / (pow(N, 2)) * cos(1. * (pow(N, 2)) / (pow(k, 2))) + P1(N, k + 1);
}
double P2(const int N, const int k)
{
	if (k < 1)
		return 0;
	else
		return (pow(k, 2)) / (pow(N, 2)) * cos(1. * (pow(N, 2)) / (pow(k, 2))) + P2(N, k - 1);
}
double P3(const int N, const int k, double t)
{
	t = t + (pow(k, 2)) / (pow(N, 2)) * cos(1. * (pow(N, 2)) / (pow(k, 2)));
	if (k >= N)
		return t;
	else
		return P3(N, k + 1, t);
}
double P4(const int N, const int k, double t)
{
	t = t + (pow(k, 2)) / (pow(N, 2)) * cos(1. * (pow(N, 2)) / (pow(k, 2)));
	if (k <= 1)
		return t;
	else
		return P4(N, k - 1, t);
}

int main()
{
	int k = 1;
		int N;
	cout << "N = "; cin >> N;
	cout << "(iter) P0 = " << P0(N) << endl;
	cout << "(rec up ++) P1 = " << P1(N, k) << endl;
	cout << "(rec up --) P2 = " << P2(N, N) << endl;
	cout << "(rec down ++) P3 = " << P3(N, k, 0) << endl;
	cout << "(rec down --) P4 = " << P4(N, N, 0) << endl;
	return 0;
}