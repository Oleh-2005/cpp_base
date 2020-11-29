#include<iostream> 
#include<windows.h>
#include<fstream>
#include <string>
#include<ctime>
#include<vector>
using namespace std;

//class Cat {
//private:
//	string name;
//	string breed;
//	int age;
//	int*numbers;  // * - вказівник 
//	int size;
//public:
//	/*Cat() {
//		cout << "Defaul constructor " << endl;
//	}*/
//
//	/*void fill(const int size) {
//		for (int i = 0; i < size; i++) {
//			int a = rand() % 20 + 1;
//			numbers[i] = a;
//			cout << "KKK" << numbers[i] << "GGG" << a << endl;
//		}
//	}*/
//	void PrintFill(int size) {
//		for (int i = 0; i < size; i++) {
//			int a = rand() % 20 + 1;
//			numbers[i] = a;
//
//			cout << "Numbers ["<<i<<"] ="<<numbers[i]<<endl;
//		}
//	}
//	Cat(string name , string breed , int age,int size) { // Конструктор
//		cout << "Overload constructure" << endl;
//		this->name = name;
//		this->breed = breed;
//		this->age = age;
//		this->size=size;
//		numbers = new int[size];
//	}
//	~Cat() {
//		cout << "Destructor" << endl;
//		delete[] numbers;
//	}
//	void Print() {
//		cout << "Name : " << this->name << "\nBreed : " << this->breed
//			<< "\nAge : " << this->age<<endl;
//	}
//};
class Buy {
public:
struct User {

	string ID;
	int buy;
	short sale;
	string data;
};
	void Bbuy(string id) {
		int BUY = 0;
		User users;
		cout << "\nEnter price : ";
		cin >> BUY;
		vector<User>vector;
		ifstream ina(R"(D:\My c++\CPP_base\Class work\Class.txt)");
		if (ina.is_open()) {
			while (ina >> users.ID)
			{
				ina >> users.buy >> users.sale >> users.data ;
				vector.push_back(users);
			}
		}
		int u = 0;
		for (int i = 0; i < vector.size(); i++) {
			if (BUY >= 1000) {
				if (id == vector[i].ID&&vector[i].sale<10) {
					vector[i].sale++;
					ofstream na(R"(D:\My c++\CPP_base\Class work\Class.txt)");
					if (na.is_open()) {
						for (int i = 0; i < vector.size(); i++) {
							na << vector[i].ID << " " << vector[i].buy << " " << vector[i].sale << " " << vector[i].data << endl;
						}
					}
					na.close();
				}
				else if (id == vector[i].ID && vector[i].sale >= 10) {
					ofstream na(R"(D:\My c++\CPP_base\Class work\Class.txt)");
					if (na.is_open()) {
						for (int i = 0; i < vector.size(); i++) {
							na << vector[i].ID << " " << vector[i].buy << " " << vector[i].sale << " " << vector[i].data << endl;
						}
					}
					na.close();
				}
			}
			if (id == vector[i].ID) {
				vector[i].buy = vector[i].buy + BUY;
				long BBUY = 0;
				BBUY = (vector[i].buy / 100) * vector[i].sale;
				vector[i].buy = vector[i].buy - BBUY;
				cout << "\nYou pay " << vector[i].buy << endl;
				cout << "\nYour sale is " << vector[i].buy << endl;
				ofstream na(R"(D:\My c++\CPP_base\Class work\Class.txt)");
				if (na.is_open()) {
					for (int i = 0; i < vector.size(); i++) {
						na << vector[i].ID << " " << vector[i].buy << " " << vector[i].sale << " " << vector[i].data << endl;
					}
				}
				na.close();
			}
		}
		ina.close();
	}
	void Menu() {
		int exit = 0;
		while (exit == 0) {
			int want = 0;
			cout << "\nIf you have sale card press 1\nIf you want to create sale card press 2\nIf you want to return press 3" << endl;
			cout << "---> ";
			cin >> want;
			if (want == 1) {
				User users;
				vector<User>vector;
				ifstream ina(R"(D:\My c++\CPP_base\Class work\Class.txt)");
				if (ina.is_open()) {
					while (ina >> users.ID)
					{
						ina >> users.buy >> users.sale >> users.data;
						vector.push_back(users);
					}
				}
				string number;
				cout << "Please.Enter your card number " << endl;
				cout << "---> ";
				cin >> number;
				int ok = 0;
				for (int i = 0; i < vector.size(); i++) {
					if (vector[i].ID == number) {
						ok++;

					}
					else {

					}
				}
				if (ok > 0) {
					Bbuy(number);

				}
				else {
					cout << "\n\nYou enter incorrect card number !!!\n\n";
					exit++;
				}
			}
			else if (want == 2) {
				User users;
				long card = 0;
				card = rand() % 899999999 + 1000000000;
				cout << "Your card number is " << card;
				string day;
				cout << "\nEnter data of creating card : ";
				cin >> day;
				vector<User>vector;
				ofstream na(R"(D:\My c++\CPP_base\Class work\Class.txt)",ios::app);
				if (na.is_open()) {
					na << card << " " << 0 << " " << 0 <<" "<<day<< endl;
				}
				na.close();
				exit++;
			}
			else if (want == 3) {
				exit++;
			}
			else {
				cout << "\nYou enter incorrect number of action !!!\n" << endl;
			}
		}
	}
	void BuY() {
		int exit = 0;
		while (exit == 0) {
			int want = 0;
			cout << "If you want to buy something enter 1\nIf you want to exit enter 2\n ";
			cout << "Enter number of action : ";
			cin >> want;
			if (want == 1) {
				Menu();
			}
			else if (want == 2) {
				exit++;
			}
			else {
				cout << "\n\nYou enter incorrect number of action !!!\n\n";
			}
		}
	}

};
int main() {
	srand(unsigned(time(0)));

	Buy first;
	first.BuY();
	//Cat murzik("Murzik","British",3,10);
	////murzik.Print();
	//murzik.PrintFill(10);
	system("pause");
	return 0;
}





