#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

unsigned long long fibonacciRekursif1(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacciRekursif1(n - 1) + fibonacciRekursif1(n - 2);
}

unsigned long long fibonacciRekursif(long long int num){
    if(num == 0 || num == 1){
        return num;
    }
    else{
        return fibonacciRekursif(num - 1) + fibonacciRekursif(num - 2);
    }
}

unsigned long long fibonacciDP(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    vector<unsigned long long> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

template<typename Func>
double time(Func func, int n) {
    auto start = high_resolution_clock::now();
    func(n);
    auto end = high_resolution_clock::now();
    duration<double, nano> duration = end - start;
    return duration.count();
}



int main() {
    int n_values[] = {50};

    for (int n : n_values) {
        unsigned long long result_rekursif = fibonacciRekursif(n);
        unsigned long long result_dp = fibonacciDP(n);

		double rtime = time(fibonacciRekursif, n);
		double dptime = time(fibonacciDP, n);
		
		
        cout << "n = " << n << endl;
        cout << "Rekursif: " << result_rekursif << ", waktu: " << fixed<<setprecision(6) <<rtime << " miliseconds" << endl;
        cout << "Dynamic Programming: " << result_dp << ", waktu rata-rata: " <<fixed<< setprecision(6) << dptime <<" miliseconds" << endl;
        cout << endl;
    }

    return 0;
}

