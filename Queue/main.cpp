#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <random>
#include "Queue.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	TQueue<int> q;
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_real_distribution<float> distr(0, 1);
	double rnd = distr(eng);
	double P = 0, Q = 0;
	int N = 0, Start = 0;
	int count_p = 0, count_q = 0;
	int i = 0;

	cout << "Enter probability of push" << endl;
	cin >> P;
	cout << "Enter probability of pop" << endl;
	cin >> Q;
	cout << "Enter number of elements in the queue" << endl;
	cin >> N;
	cout << "Enter amount of elements the queue had at the start" << endl;
	cin >> Start;

	if (Start > N) {
		cout << "ERROR: start amount of elements exceeds overall amount" << endl;
		return 0;
	}
	if (Q > P && Start == 0) {
			cout << "ERROR: pops empty queue" << endl;
			return 0;
	}
	
	for (i = 0; i < Start; i++) {
		q.push(1);
	}

	i = Start;
	while (i < N && i > 0) {
		rnd = distr(eng);
		if (rnd < P) {
			q.push(1);
			count_p++;
			i++;
		}
		if (rnd < Q) {
			q.pop();
			count_q++;
			i--;
		}
	}
	cout << "Number of pushes equals " << count_p << endl;
	cout << "Number of pops equals " << count_q << endl;
	return 0;
}