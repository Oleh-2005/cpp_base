#include<iostream> 
#include<windows.h>
#include<fstream>
#include <string>
#include<ctime>
#include<vector>
using namespace std;
//class Wheicle { // Транспорт
//public:
//	virtual void drive() = 0;
//	void DriverLicenc() {
//		cout << "\nDriver has licence ... \n";
//	}
//};
//class Car : public Wheicle {
//public:
//	void drive() override
//	{
//		cout << "Drive by car ...     " <<endl;
//	}
//};
//class Truck :public Wheicle {
//public:
//	void drive()override {
//		cout << "Drive bu truck ... " << endl;
//	}
//};
//class Driver {
//public:
//	void drive(Wheicle& wheicle) {
//		cout << "==============DRIVER================" << endl;
//		wheicle.drive();
//		wheicle.DriverLicenc();
//	}
//};

//class Train {
//public:
//	Train() {
//		GetTrainInfo();
//	}
//	void GetTrainInfo(){
//		for (int i = 0; i < 3; i++) {
//			vagons[i].GetInfo();
//	    }
//	}
//
//private:
//	class Vagon {
//	public:
//		Vagon(string type, int seat_count) {
//			this->type = type;
//			this->seat_count = seat_count;
//		}
//		void GetInfo() {
//			cout << "\nType : " << this->type << endl << "Seats : " << this->seat_count << endl;
//		}
//	private:
//		string type;
//		int seat_count;
//	};
//	static const int xx = 3;
//	Vagon vagons[xx]{
//
//		Vagon("PRT",90),
//		Vagon("Couple",75),
//		Vagon("Lux",60)
//
//	};
//};

class Room {
public:
	int LONG;
	int Sh;
	int floor;
	Room(int LONG, int Sh, int floor) {
		this->LONG = LONG;
		this->floor = floor;
		this->Sh = Sh;
		/*Show();
		S();*/
	}
	Room() {

	}
	
	   
	void S() {
		int Ss = 0;
		Ss = LONG * Sh;
		cout << "\nYour square : " << Ss << endl;
	}
	void Show() {
		cout << "\nYour room in " << floor << " floor .\n" << "Long of your`s room " << LONG << endl << "Width of your`s room " << Sh << endl;
	}
};
    class House {
    public:
		void TotalSquare(Room *rooms,int a) {
			int aa = 0;
			for (int i = 0; i < a+1; i++) {
				int Ss = 0;
				Ss = rooms[i].LONG * rooms[i].Sh;
				aa = aa + Ss;
			}
			cout << "======TOTAL SQUARE======" << endl;
			cout << "======" << aa << "======" << endl;
		}
		void LevelSquare(Room* rooms, int a) {
			cout << "\n\nEnter number of level where you which square you want to know : ";
			int le = 0;
			cin >> le;
			int aa = 0;
			for (int i = 0; i < a+1; i++) {
				if (rooms[i].floor == le) {
					int Ss = 0;
					Ss = rooms[i].LONG * rooms[i].Sh;
					aa = aa + Ss;
				}
			}
			cout << "\n======TOTAL SQUARE ON LEVEL======\n";
			cout << "======" << aa << "======"<<endl;

		}
		void Show(Room* rooms, int a) {
			cout << "======ROOMS IN YOUR HOUSE======"<<endl;
			cout << "======" << a+1 << "======" << endl<<endl;
			cout << "======ROOMS DATA======" << endl;
			for (int i = 0; i < a+1; i++) {
				cout << "Langs of " << i << " room is " << rooms[i].LONG << "\tWidth of this room is " << rooms[i].Sh
					<< "  Level of this room is " << rooms[i].floor << endl;
			}
		}
		void REenter(Room* &rooms, int a) {
			cout << "Enter number of room which data you want to change : ";
			int af = 0;
			cin >> af;
			cout << "\nEnter new langs of room : ";
			int ll = 0;
			cin >> ll;
			cout << "\nEnter new width of room : ";
			int ww = 0;
			cin >> ww;
			int fff = 0;
			cout << "\nEnter new floor of room : ";
			cin >> fff;
			rooms[af].LONG = ll;
			rooms[af].Sh = ww;
			rooms[af].floor = fff;

		}
		void Kitchen(Room*& rooms, int a) {
			cout << "\nEnter new langs of kitchen : ";
			int ll = 0;
			cin >> ll;
			cout << "\nEnter new width of kitchen : ";
			int ww = 0;
			cin >> ww;
			int fff = 0;
			cout << "\nEnter new floor of kitchen : ";
			cin >> fff;
			rooms[a].Sh = ww;
			rooms[a].floor = fff;
			rooms[a].LONG = ll;



		}
    private:
		    
    };


int main() {
	srand(unsigned(time(NULL)));

	/*Car car;
	car.drive();
	Truck truck;
	truck.drive();
	car.DriverLicenc();
	truck.DriverLicenc();
	Car tar;
	Driver driver;
	driver.drive(tar);*/

	//cout << "Enter long of room : ";
	//int Long = 0;
	//cin >> Long;
	//cout << "\nEnter number of floor : ";
	//int floor = 0;
	//cin >> floor;
	//cout << "\nEnter width : ";
	//int Sh = 0;
	//cin >> Sh;
	//Room(Long, Sh, floor);
	cout << "\nEnter numbe of rooms : ";
	int a = 0;
	cin >> a;
	int* mas = new int[a];
	int* Ssh = new int[a];
	int* ffloor = new int[a];
	for (int i = 0; i < a; i++) {
		int LonG = 0;
		cout << "\nEnter langs of room : ";
		cin >> LonG;
		mas[i] = LonG;
		int SH = 0;
		cout << "\nEnter width of room : ";
		cin >> SH;
		Ssh[i] = SH;
		int Ffloor = 0;
		cout << "\nEnter floor of room : ";
		cin >> Ffloor;
		ffloor[i] = Ffloor;
	}
	Room* rooms ;
	rooms = new Room[a+1];
	int p = 0;
	for (int i = 0; i < a; i++) {
		rooms[i].LONG = mas[i];
		rooms[i].Sh = Ssh[i];
		rooms[i].floor = ffloor[i];

	}
	int Longg = 0;
	cout << "\nEnter langs of kitchen : ";
	cin >> Longg;
	int SHH= 0;
	cout << "\nEnter width of kitchen : ";
	cin >> SHH;
	int Ffloorr = 0;
	cout << "\nEnter floor of kitchen : ";
	cin >> Ffloorr;
	rooms[a].LONG = Longg;
	rooms[a].Sh = SHH;
	rooms[a].floor = Ffloorr;
	
	House house;
	int exit = 0;
	while (exit == 0) {
		int want = 0;
		cout << "\nEnter 0 if you want to exit\nEnter 1 if you want to see all rooms \nEnter 2 if you want to change data of room\nEnter 3 if you want to change data of kitchen\nEnter 4 if you want to know tottal square\n";
		cout << "Enter 5 if you want to know tottal square on level\n";
		cout << "----> ";
		cin >> want;
		if (want == 0) {
			exit++;
		}
		else if (want == 1) {
	        house.Show(rooms, a);

		}
		else if (want == 2) {
	        house.REenter(rooms, a);

		}
		else if (want == 3) {
	        house.Kitchen(rooms, a);

		}
		else if (want == 4) {
	        house.TotalSquare(rooms,a);

		}
		else if (want == 5) {
	        house.LevelSquare(rooms, a);

		}
		else {
			cout << "\n\n\t\tYOU ENTER INCORRECT DATA\n\n";
		}
	}
	delete[] rooms;
	system("pause");
	return 0;
}
