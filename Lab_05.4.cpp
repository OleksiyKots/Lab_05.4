#include <iostream>
#include <cmath>
using namespace std;

double P0(const int K, const int N)
{
    double p = 1;
    for (int i = K; i <= N; i++)
        p *= (pow(i, 2) / pow(N, 2)) * cos(pow(N, 2) / pow(i, 2));
    return p;
}

double P1(const int K, const int N, const int i)
{
    if (i > N)
        return 1;
    else
        return (pow(i, 2) / pow(N, 2)) * cos(pow(N, 2) / pow(i, 2)) * P1(K, N, i + 1);
}

double P2(const int K, const int N, const int i)
{
    if (i < K)
        return 1;
    else
        return (pow(i, 2) / pow(N, 2)) * cos(pow(N, 2) / pow(i, 2)) * P2(K, N, i - 1);
}

double P3(const int K, const int N, const int i, double t)
{
    t *= (pow(i, 2) / pow(N, 2)) * cos(pow(N, 2) / pow(i, 2));
    if (i >= N)
        return t;
    else
        return P3(K, N, i + 1, t);
}

double P4(const int K, const int N, const int i, double t)
{
    t *= (pow(i, 2) / pow(N, 2)) * cos(pow(N, 2) / pow(i, 2));
    if (i <= K)
        return t;
    else
        return P4(K, N, i - 1, t);
}

int main()
{
    int K, N;
    cout << "K = "; cin >> K;
    cout << "N = "; cin >> N;

    cout << "(iter) P0 = " << P0(K, N) << endl;
    cout << "(rec up ++) P1 = " << P1(K, N, K) << endl;
    cout << "(rec up --) P2 = " << P2(K, N, N) << endl;
    cout << "(rec down ++) P3 = " << P3(K, N, K, 1) << endl;
    cout << "(rec down --) P4 = " << P4(K, N, N, 1) << endl;

    return 0;
}
