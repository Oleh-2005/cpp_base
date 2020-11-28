#include<iostream>
#include<windows.h>
#include<fstream>
#include <string>
#include<ctime>
#include<vector>

using namespace std;

class Account {
	const double euro = 34.1;
	const double BTC_USA = 28.51;
public:
	struct User {
		string name;
		string LastName;
		string ID;
		string PIN;
		int balance;
		short failur;
	};
	double Balance;
	void Create() {
		User user;
		cout << "Enter your name : ";
		cin >> user.name;
		cout << "\nEnter your last name : ";
		cin >> user.LastName;
		int ID[9];
		for (int i = 0; i < 9; i++) {
			int a = (rand()) % 10;
			ID[i] = a;
		}
		cout << "Your ID : " ;
		for (int i = 0; i < 9; i++) {
			cout << ID[i];
		}
		int Pin[9];
		for (int i = 0; i < 9; i++) {
			int a = (rand()) % 10;
			Pin[i] = a;
		}
		cout << "\nYour PIN-code : ";
		for (int i = 0; i < 9; i++) {
			cout << Pin[i];
		}
		cout << endl << endl;
		ofstream in(R"(D:\My c++\CPP_base\Home work\StorageForHomeWork_1.txt)", ios::app);
		if (in.is_open()) {
			in << user.name << " " << user.LastName << " " << ID[0] << ID[1] << ID[2] << ID[3] << ID[4] << ID[5] << ID[6] << ID[7] << ID[8]<<" "<<Pin[0] << Pin[1] << Pin[2] << Pin[3] << Pin[4] << Pin[5] << Pin[6] << Pin[7] << Pin[8]<<" "<<0<<" "<<0<<endl;

		}
		in.close();
	}
	void MenuForUser(int size , int u) {
		User users;
		vector<User>vector;
		ifstream ina(R"(D:\My c++\CPP_base\Home work\StorageForHomeWork_1.txt)");
		if (ina.is_open()) {
			while (ina >> users.name)
			{
				ina >> users.LastName >> users.ID>>users.PIN>>users.balance>>users.failur;
				vector.push_back(users);
			}
		}
		ina.close();
		int exit = 0;
		while (exit == 0) {
			short want = 0;
			cout << "If you want to see your balance press 1\nIf you want to put money in the account  press 2\nIf you want to withdraw money from the account press 3\nIf you want to exit press 4";
			cout << "\n----> ";
			cin >> want;
			cout << endl;
			if (want == 4) {
				exit++;
			}
			else if (want == 1) {
				cout << "\n\n\t\t\t////Your personal information\\\\\\\\\n\n";
				cout << "Your name : " << vector[u].name << endl << "Your Last name : " << vector[u].LastName << endl << "Your ID : " << vector[u].ID << endl << "Your PIN-code : " << vector[u].PIN << endl << "Your balance : " << vector[u].balance << endl;
			}
			else if (want == 2) {
				int money = 0;
				cout << "Enter how much money you want to put in your account : ";
				cin >> money;
				cout << endl;
				vector[u].balance = vector[u].balance + money;
				ofstream on(R"(D:\My c++\CPP_base\Home work\StorageForHomeWork_1.txt)");
				for (int i = 0; i < vector.size(); i++) {
					on << vector[i].name << " " << vector[i].LastName << " " << vector[i].ID << " " << vector[i].PIN << " " << vector[i].balance << " " << vector[i].failur << endl;
				}
				on.close();
			}
			else if (want == 3) {
				int money = 0;
				cout << "Enter how much money do you want to withdraw from your account : ";
				cin >> money;
				cout << endl;
				vector[u].balance = vector[u].balance - money;
				ofstream on(R"(D:\My c++\CPP_base\Home work\StorageForHomeWork_1.txt)");
				for (int i = 0; i < vector.size(); i++) {
					on << vector[i].name << " " << vector[i].LastName << " " << vector[i].ID << " " << vector[i].PIN << " " << vector[i].balance << " " << vector[i].failur << endl;
				}
				on.close();
			}
			else {
				cout << "\nYou enter incorrect number of action !!!\n" << endl;
			}
		}
	}
	void Login() {
		User user;
		string number;
		cout << "Enter your account number : ";
		cin >> number;
		string pin_c ;
		cout << "Enter your PIN-code : ";
		cin >> pin_c;
		short fail = 0;
		int xxx = 0;
		vector<User>Vector;
		ifstream in(R"(D:\My c++\CPP_base\Home work\StorageForHomeWork_1.txt)");
		if (in.is_open()) {
			short OK = 0;
			int u = 0;
			while (in>>user.name) {
				in  >> user.LastName >> user.ID >> user.PIN>>user.balance>>user.failur;
				Vector.push_back(user);
			}
			for (int i = 0; i < Vector.size(); i++) {
				if (number == Vector[i].ID && pin_c == Vector[i].PIN) {
					OK++;
					xxx = u;
				}
				if (Vector[i].failur >= 3&& number == Vector[i].ID) {
					fail = fail + 3;
					break;
				}
				if (Vector[i].ID == number && Vector[i].PIN != pin_c) {
					fail++;
					xxx = u;
					Vector[xxx].failur++;
				}
				u++;
			}

			if (fail < 3) {
				if (OK == 0) {
			        ofstream inn(R"(D:\My c++\CPP_base\Home work\StorageForHomeWork_1.txt)");
					cout << "\nYou enter incorrect PIN-code or number of account !" << endl;
					for (int i = 0; i < Vector.size(); i++) {
						inn << Vector[i].name << " " << Vector[i].LastName << " " << Vector[i].ID << " " << Vector[i].PIN << " " << Vector[i].balance << " " << Vector[i].failur << endl;
					}
		            inn.close();
				}
				else {
					int size = Vector.size();
					MenuForUser( size, xxx);
					fail = 0;
				}
			}
			else {
				fail = 3;
				ofstream inn(R"(D:\My c++\CPP_base\Home work\StorageForHomeWork_1.txt)");

				for (int i = 0; i < Vector.size(); i++) {
					inn << Vector[i].name << " " << Vector[i].LastName << " " << Vector[i].ID << " " << Vector[i].PIN << " " << Vector[i].balance << " " << Vector[i].failur << endl;
				}
				cout << "\n\n\t\t\t\tYour account is blocked !!!\n\n";
				inn.close();
			}
		}
		in.close();

	}
}; 
void StartMenu() {
	Account first;
	int exit = 0;
	while (exit == 0) {
		int want = 0;
		cout << "If you want to create new account enter 1\nIf you want to login enter 2\nIf you want to exit enter 3 " << endl;
		cout << "----> ";
		cin >> want;
		cout << endl;
		if (want == 1) {
			first.Create();
			
		}
		else if (want == 2) {
			first.Login();
			
		}
		else if (want == 3) {
			exit++;
		}
		else {
			cout << "Error . You enter incorrect data . Try one more time ." << endl;
		}
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	StartMenu();

}