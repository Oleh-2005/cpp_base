
#include<iostream> 
#include<windows.h>
#include<fstream>
#include <string>
#include<ctime>
#include<vector>
using namespace std;
class Monitor {
public:
	struct Mon {
	float price ;
	float Diagonal;
	string country;
	string model;
	string Display_resolution;
	int id;
	int Pixel_density;
	double weight;
	};
			Mon mon;
	
	void Print() {
		cout << "\n\n\t\t\tALL DATA\n\n";
		ifstream ina(R"(D:\My c++\CPP_base\Home work\StorageHome.txt)");
		if (ina.is_open()) {
			while (ina >> mon.id)
			{
				ina >> mon.price >> mon.Diagonal >> mon.country >> mon.model >> mon.weight >> mon.Display_resolution >> mon.Pixel_density;
				cout << "ID : " << mon.id << " Price : " << mon.price << " Diagonal : " << mon.Diagonal << " Made in " << mon.country << " Weight : " << mon.weight << " Display resolution : " << mon.Display_resolution << " Pixel density : " << mon.Pixel_density << endl;
			}
		}
		cout << endl << endl;
	}
	void Add() {
		int exit = 0;
		while (exit == 0) {
			int want = 0;
			cout << "\nIf you want to add new data enter 1\nIf you want to return enter 2" << endl;
			cout << "----> ";
			cin >> want;
			if (want == 1) {
				//vector<Mon>vector;
				ifstream ina(R"(D:\My c++\CPP_base\Home work\StorageHome.txt)");
				if (ina.is_open()) {
					while (ina >> mon.id)
					{
						ina >> mon.price >> mon.Diagonal >> mon.country>> mon.model>> mon.weight>> mon.Display_resolution>> mon.Pixel_density;
						//vector.push_back(mon);
					}
				}
				ina.close();
				mon.id++;
				cout << "\nEnter price of monitor : ";
				cin >> mon.price;
				cout << "\nEnter size of diagonal : ";
				cin >> mon.Diagonal;
				cout << "\nEnter place where monitor was made : ";
				cin >> mon.country;
				cout << "\nEnter model of monitor : ";
				cin >> mon.model;
				cout << "\nEnter weight of monitor : ";
				cin >> mon.weight;
				cout << "\nEnter display resolution of monitor : ";
				cin >> mon.Display_resolution;
				cout << "\nEnter pixel density of monitor : ";
				cin >> mon.Pixel_density;
				ofstream na(R"(D:\My c++\CPP_base\Home work\StorageHome.txt)", ios::app);
				if (na.is_open()) {
					na << mon.id << " " << mon.price << " " << mon.Diagonal << " " << mon.country << " " << mon.model << " " << mon.weight << " " << mon.Display_resolution << " " << mon.Pixel_density << endl;
				}
				na.close();
			}
			else if (want == 2) {
				exit++;
				cout << endl;
			}
			else {
				cout << "\n\nYou enter incorrect number of action ! Try one more time .\n\n";
			}
		}
	}
	Monitor() {
		int exit = 0;
		while (exit == 0) {
			int want = 0;
			cout << "If you want to see all data enter 1\nIf you want to add new data enter 2\nIf you want to exit enter 3\n" << endl;
			cout << "----> ";
			cin >> want;
			if (want == 1) {
				Print();
			}
			else if (want == 2) {
				Add();
			}
			else if (want == 3) {
				exit++;
			}
			else {
				cout << "\n\nYou enter incorrect number of action ! Try one more time .\n\n";
			}

		}
	}
};
int main() {
	srand(unsigned(time(NULL)));
	Monitor monitor;

	system("pause");
	return 0;
}



