#include<iostream>
#include<string>

using namespace std;
class Point {
	int X = 0;
	int Y = 0;
public:
	void SetPoints() {
		int x = 0;
		int y = 0;
		int action = 0;
		cout << "\nIf you want to change X enter 1  \nIf you want to change Y enter 2" << endl;
		cout << "Enter number of action : ";
		cin >> action;
		if (action == 1) {
			cout << "New X : ";
			cin >> x;
			X = x;

		}
		if (action == 2) {
			cout << "New Y : ";
			cin >> y;
			Y = y;
		}
		else {
			cout << "Wrong number ";
		}
	}
	void CreatePoints() {
		cout << "Enter point X : ";
		cin >> X;
		cout << "Enter point Y : ";
		cin >> Y;
	}
	void Print() {
		cout << "Point X : " << X << "\nPoint Y : " << Y << endl;

	}
};

int main() {

	Point first;
	first.CreatePoints();
	first.Print();
	first.SetPoints();
	first.Print();
	cout << endl;
	system("pause");
	return 0;
}