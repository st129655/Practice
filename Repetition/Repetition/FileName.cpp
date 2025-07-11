#include<iostream>
#include<ctime>
#include<algorithm>
void menu() {
	std::cout << "\n";
	std::cout << "Выберите действие, которое хотите сделать." << "\n";
	std::cout << "1 - заполнить массив рандомными числами" << "\n";
	std::cout << "2 - добавить элемент в конец массива" << "\n";
	std::cout << "3 - добавить элемент в начало массива" << "\n";
	std::cout << "4 - вывести массив на экран" << "\n";
	std::cout << "5 - сортировка массива по возрастанию (петушиным методом)" << "\n";
	std::cout << "ZOV" << "\n";
}

int* initarray(int len) {
	int* array = nullptr;
	array = new int[len];
	for (int i = 0; array!=nullptr && i < len; ++i) {
		array[i] = 0;
	}
	return array;
}
void randarray(int* a, int len, int max = 99, int min = 1) {
	for (int i = 0; i < len; ++i) {
		a[i] = rand() % (max - min + 1) + min;
	}
}
void addtoend(int** a, int* len, int num) {
	int* newarray = new int[*len + 1];
	for (int i = 0; i < *len; ++i) {
		newarray[i] = (*a)[i];
	}
	newarray[*len] = num;
	*a = newarray;
	(*len)++;
	delete a;
}
void addtobegin(int** a, int* len, int num) {
	int* newarray = new int[*len + 1];
	for (int i = 0; i < *len; ++i) {
		newarray[i+1] = (*a)[i];
	}
	newarray[0] = num;
	*a = newarray;
	(*len)++;
	delete a;
}
void printarray(int* a, int len) {
	for (int i = 0; i < len; ++i) {
		std::cout << a[i] << " ";
	}
}
void sortarray(int* a, int len) {
	std::sort(a, a + len);
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int len;
	std::cin >> len;
	int* a = initarray(len);
	randarray(a, len);
	printarray(a, len);
	std::cout << "\n";
	bool ind = 1;
	while (ind) {
		menu();
		int choice;
		std::cin >> choice;
		switch (choice) {

		case 1: {
			randarray(a, len);
			break;
		}

		case 2: {
			int num;
			std::cin >> num;
			addtoend(&a, &len, num);
			break;
		}

		case 3: {
			int num;
			std::cin >> num;
			addtobegin(&a, &len, num);
			break;
		}

		case 4: {
			printarray(a, len);
			break;
		}

		case 5: {
			sortarray(a, len);
			break;
		}

		default: {
			ind = 0;
			break;
		}
		}
	}
	delete a;
	return EXIT_SUCCESS;
}