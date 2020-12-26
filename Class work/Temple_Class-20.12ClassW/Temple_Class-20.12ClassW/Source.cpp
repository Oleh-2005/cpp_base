#include<iostream> 
#include<windows.h>
#include<fstream>
#include<string>
#include<ctime>
#include<vector>
using namespace std;
//class Dog {
//private:
//	string name;
//	string breed;
//	int age;
//public:
//	Dog(string name, string breed, int age) {
//		this->age = age;
//		this->name = name;
//		this->breed = breed;
//	}
//	void Print() {
//		cout << "\n\n\t\tDOG\n\n";
//		cout << "\nAge : " << this->age << "\nName : " << this->name << "\nBreed : " << this->breed << endl;
//
//	}
//	Dog() {
//
//	}
//};
//class Cat {
//private:
//	string name;
//	string breed;
//	int age;
//public:
//	Cat(string name,string breed,int age) {
//		this->age = age;
//		this->name = name;
//		this->breed = breed;
//	}
//	void Print() {
//		cout << "\n\n\t\tCAT\n\n";
//		cout << "\nAge : " << this->age << "\nName : " << this->name << "\nBreed : " << this->breed << endl;
//
//	}
//	Cat() {
//
//	}
//};
//
//template <typename T>
//class Animal {
//private:
//	T animal;
//public:
//	Animal(T animal) {
//		this->animal = animal;
//	
//	}
//	void ShowAnimal() {
//		this->animal.Print();
//	}
//};

//template<typename T,typename T2>
//class Animal {
//private:
//	T animal;
//	T2 animal2;
//public:
//	Animal(T animal, T2 animal2) {
//		this->animal = animal;
//		this->animal2 = animal2;
//	}
//	void ShowAnimal() {
//		this->animal.Print();
//		this->animal2.Print();
//	}
//};
//class Dog {
//private:
//	string name;
//	string breed;
//	int age;
//public:
//	Dog() {
//
//	}
//	Dog(string name, string breed, int age) {
//		this->age = age;
//		this->breed = breed;
//		this->name = name;
//	}
//	void Print() {
//		cout << "\nName : " << this->name << "\nBreed : " << this->breed << "\nAge : " << this->age << endl;
//	}
//};
//class Cat {
//private :
//	string name;
//	string breed;
//	int age;
//public:
//	Cat() {
//
//	}
//	Cat(string name , string breed , int age) {
//		this->age = age;
//		this->breed = breed;
//		this->name = name;
//	}
//	void Print() {
//		cout << "\nName : " << this->name << "\nBreed : " << this->breed << "\nAge : " << this->age << endl;
//	}
//};
//template<typename T , typename T2 , typename T3>
class Book {
public:
	string name;
	int money;
	string avtor;
	string company;
	Book(string name ,string avtor,string company,int money) {

	}
	Book() {

	}
};
class Megazine {
public:
	string name;
	int money;
	Megazine(string name,int money) {

	}
	Megazine() {

	}
}; 
class Audio {
public:
	string name;
	int money;
	string avtor;
	int number;
	Audio(string name, string avtor,int number,int money) {

	}
	Audio() {

	}
};
class CShop {
private:
	Book book;
	Audio audio;
	Megazine me;
public:
	CShop(Book *books,Audio *audios,Megazine *me,int a,int b,int c) {
		int exit = 0;
		while (exit == 0) {
			int want = 0;
			cout << "\nEnter 1 if you want to see all data\nEnter 2 if you want to see maximal price\nEnter 3 if you want to see minimal price\nEnter 4 if you want to sort data\nEnter 5 if you want to see arithmetic mean\nEnter 6 if you want to exit\n";
			cout << "----> ";
			cin >> want;
			if (want == 1) {
				Print(books,audios,me,a,b,c);
			}
			else if (want == 2) {
				Max(books, audios, me, a, b, c);
			}
			else if (want == 3) {
				Min(books, audios, me, a, b, c);
			}
			else if (want == 4) {
				SortMas(books, audios, me, a, b, c);
			}
			else if (want == 5) {
				Arifm(books, audios, me, a, b, c);
			}
			else if (want == 6) {
				exit++;
			}
		}
	}
	void Print(Book* books, Audio* audios, Megazine* me, int a, int b, int c) {
		cout << "Number of books : " << a << "\nNumber of audios : " << b << "\nNumber of magazines : " << c << endl;
		cout << "\n\n\t\tBOOKS\n\n";
		for (int i = 0; i < a; i++) {
			cout << "Price : " << books[i].money << "\tName : " << books[i].name << "\tAuthor : " << books[i].avtor << "\tPublishing house : " << books[i].company << endl;
		}
		cout << "\n\n\t\tAUDIOS\n\n";
		for (int i = 0; i < b; i++) {
			cout << "Price : " << audios[i].money << "\tName : " << audios[i].name << "\tAuthor : " << audios[i].avtor << "\tNumber of songs : " << audios[i].number << endl;
		}
		cout << "\n\n\t\tMEGAZINES\n\n";
		for (int i = 0; i < c; i++) {
			cout << "Price : " << me[i].money << "\tName : " << me[i].name << endl;
		}
		cout << endl << endl;
	}
	void SortMas(Book* books, Audio* audios, Megazine* me, int a, int b, int c) {
		for (int i = 0; i < a-1; i++) {
			for (int j = 0; j < a ; j++) {
				if (books[i].money > books[j].money) {
					swap(books[i].money, books[j].money);
				}
			}
		}
		cout << endl;
		for (int i = 0; i < a; i++) {
			cout << books[i].money;
		}
	}
	void Arifm(Book* books, Audio* audios, Megazine* me, int a, int b, int c) {
		int ar = 0;
		int are = 0;
		int aref = 0;
		for (int i = 0; i < a; i++) {
			ar += books[i].money;
		}
		for (int i = 0; i < b; i++) {
			are += audios[i].money;
		}
		for (int i = 0; i < c; i++) {
			aref += me[i].money;
		}
		int par = 0;
		if (a > 0) {
			 par = ar / a;
		}
		int pare = 0;
		if (b > 0) {
			 pare = are / b;
		}
		int paref = 0;
		if (c > 0) {
			 paref = aref / c;
		}
		cout << "\nArithmetic mean of books : " << par  << "\nArithmetic mean of audios : " << pare  << "\nArithmetic mean of megazines : " << paref  << endl;
	}
	void Max(Book* books, Audio* audios, Megazine* me, int a, int b, int c) {
		int max = 0;
		for (int i = 0; i < a; i++) {
			if (books[i].money > max) {
				max = books[i].money;
			}
		}
		int maxi = 0;
		for (int i = 0; i < b; i++) {
			if (audios[i].money > maxi) {
				maxi = audios[i].money;
			}
		}
		int maximum = 0;
		for (int i = 0; i < c; i++) {
			if (me[i].money > maximum) {
				maximum = me[i].money;
			}
		}
		cout << "Maximal price of book : " << max << endl << "Maximal price of audio : " << maxi << "\nMaximal price of megazine : " << maximum << endl;
	}
	void Min(Book* books, Audio* audios, Megazine* me, int a, int b, int c) {
		int min = 0;
		if (a>0) {
			min = 1000000;
			for (int i = 0; i < a; i++) {
				if (books[i].money < min) {
					min = books[i].money;
				}
			}
		}
		int mini = 0;
		if (b > 0) {
			mini = 1000000;
			for (int i = 0; i < b; i++) {
				if (audios[i].money < mini) {
					mini = audios[i].money;
				}
			}
		}
		int minimum = 0;
		if (c > 0) {
			minimum = 1000000;
			for (int i = 0; i < c; i++) {
				if (me[i].money < minimum) {
					minimum = me[i].money;
				}
			}
		}
		cout << "Minimal price of book : " << min << endl << "Minimal price of audio : " << mini << "\nMinimal price of megazine : " << minimum << endl;

	}
};
int main() {
	srand(unsigned(time(NULL)));
	/*Cat murzik("Murzik","SuperCat",4);
	Animal<Cat> animal(murzik);
	animal.ShowAnimal();
	Dog sharik("Sharik", "Labrador", 5);
	Animal<Dog> animal2(sharik);
	cout << endl;
	animal2.ShowAnimal();*/

	//Cat murzik("Murzik", "SuperCat", 4);
	//Dog sharik("Sharik", "Pitbull", 5);
	//Animal <Dog, Cat> animal(sharik, murzik);
	//animal.ShowAnimal();
	
	int zero = 0;
	cout << "\nEnter number of books : ";
	cin >> zero;
	int AUDIO = 0;
	cout << "\nEnter number of audio : ";
	cin >> AUDIO;
	int M = 0;
	cout << "\nEnter number of megazines : ";
	cin >> M;
	Book* books = new Book[zero];
	Audio* audios = new Audio[AUDIO];
	Megazine* Me = new Megazine[M];
	for (int i = 0; i < zero; i++) {
		cout << "\nEnter book name : ";
		cin >> books[i].name;
		cout << "Enter price of book : ";
		cin >> books[i].money;
		cout << "Enter author of book : ";
		cin >> books[i].avtor;
		cout << "Enter publishing house of book : ";
		cin >> books[i].company;
	}
	for (int i = 0; i < M; i++) {
		cout << "\nEnter megazine`s name : ";
		cin >> Me[i].name;
		cout << "Enter price of megazine : ";
		cin >> Me[i].money;
	}
	for (int i = 0; i < AUDIO; i++) {
		cout << "\nEnter audio`s name : ";
		cin >> audios[i].name;
		cout << "Enter price of audio : ";
		cin >> audios[i].money;
		cout << "Enter author of audio : ";
		cin >> audios[i].avtor;
		cout << "Enter number of songs in audio : ";
		cin >> audios[i].number;
	}
	CShop shop(books, audios, Me,zero,AUDIO,M) ;
	system("pause");
	delete[] books;
	delete[] audios;
	delete[] Me;
	return 0;
}


