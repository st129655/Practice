#include<iostream>
#include<ctime>
void printarray(int* a, int len) {
	for (int i = 0; i < len; ++i) {
		std::cout << a[i] << " ";
	}
}

int* initarray(int len) {
	int* array = nullptr;
	array = new int[len];
	for (int i = 0; array != nullptr && i < len; ++i) {
		array[i] = 0;
	}
	return array;
}

void randarray(int* a, int len, int min = 1, int max = 100) {
	for (int i = 0; i < len; ++i) {
		a[i] = rand() % max + min;
	}
}

void addtoend(int** a, int* len, int num) {
	int* newArray = new int[*len + 1];
	for (int i = 0; i < *len; ++i) {
		newArray[i] = (*a)[i];
	}
	newArray[*len] = num;
	(*len)++;
	delete a;
}

void addtobegin(int** a, int* len, int num) {
	int* newArray = new int[*len + 1];
	for (int i = 0; i < *len; ++i) {
		newArray[i + 1] = (*a)[i];
	}
	newArray[0] = num;
	(*len)++;
	delete a;
}

void sortarray(int* a, int len) {
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (a[i] < a[j]) {				// 5 4 2 // 4 5 2 // 4 2 5//
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void printmenu() {
	std::cout << "Выберите действие, которое вы хотите сделать с массивом." << "\n";
	std::cout << "1 - заполнить массив случайными  числами от 1 до 100" << "\n";
	std::cout << "2 - добавить элемент в конец массива" << "\n";
	std::cout << "3 -  добавить элемент в начало массива" << "\n";
	std::cout << "4 - сортировать массив по возрастанию" << "\n";
	std::cout << "5 - вывести массив на экран" << "\n";
}
int main(int argc, char* argv[]) {
	//постановка задачи: инициализировать массив и уметь: 
	//заполнять его случ.числами,добавлять элементы в начало и конец, выводить массив
	srand(time(0));
	setlocale(LC_ALL, "ru");
	std::cout << "Введите количество элементов массива";
	int len;
	std::cin >> len;
	int* array = initarray(len);
	bool ind = true;
	while (ind) {
		printmenu();
		int choice;
		std::cin >> choice;
		switch (choice) {

		case 1: {
			randarray(array, len);
			break;
		}

		case 2: {
			int num;
			std::cin >> num;
			addtoend(&array, &len, num);
			break;
		}

		case 3: {
			int num;
			std::cin >> num;
			addtobegin(&array, &len, num);
			break;
		}

		case 4: {
			sortarray(array, len);
			break;
		}

		case 5: {
			printarray(array, len);
			break;
		}

		default: {
			ind = false;
			break;
		}
		}
	}
	return 0;
}