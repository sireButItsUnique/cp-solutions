#include <bits/stdc++.h>
using namespace std;

int main() {
	int speed, limit;
	cout << "Enter the speed limit: ";
	cin >> limit;
	cout << "Enter the recorded speed of the car: ";
	cin >> speed;

	if (speed > limit) {
		if (speed <= limit + 20) {
			cout << "You are speeding and your fine is $100.";
			return 0;
		}
		if (speed <= limit + 30) {
			cout << "You are speeding and your fine is $270.";
			return 0;
		}
		cout << "You are speeding and your fine is $500.";
		return 0;
	}
	cout << "Congratulations, you are within the speed limit!";
}