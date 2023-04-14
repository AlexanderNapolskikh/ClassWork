
#include"Param.h"

// Snake-game

char** createField(int size) {

	char** field = new char* [size];

	for (int i = 0; i < size; i++)
	{
		field[i] = new char[size];

		for (int j = 0; j < size; j++)
		{
			field[i][j] = '~';
		}
	}
	
	return field;
}

void renderField(char** field, int** snake, int* fruit) {

	// Очистка и генерация поля
	system("cls");

	int size = _msize(field[0]);

	for (int i = 0; i < MARGIN; i++){
		cout << endl;
	}

	int sizeSnake = _msize(snake) / sizeof(snake[0]);

	field[snake[0][0]][snake[0][1]] = char(2);
	for (int i = 1; i < sizeSnake; i++){

		field[snake[i][0]][snake[i][1]] = 'o';
	}

	field[fruit[0]][fruit[1]] = char(253);

	for (int i = 0; i < size; i++){
		for (int j = 0; j < MARGIN; j++){
			cout << "  ";
		}

		for (int j = 0; j < size; j++){
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

int** createSnake(int size) {

	int** snake = new int* [size];

	for (int i = 0; i < size; i++)
	{
		snake[i] = new int[2];
	}

	return snake;
}

void setPosition(int** snake, int y, int x) {

	int size = _msize(snake) / sizeof(snake[0]);

	for (int i = 0; i < size; i++, y++)
	{
		snake[i][0] = y;
		snake[i][1] = x;
	}

}

void setPosition(int* fruit, int y, int x) {

	fruit[0] = y;
	fruit[1] = x;
}

bool unions(int** snake, int* fruit) {

	int size = _msize(snake) / sizeof(snake[0]);
	for (int i = 0; i < size; i++)
	{
		if (snake[i][0] == fruit[0] && snake[i][1] == fruit[1]) {
			return false;
		}
	}

	return true;
}

int main()
{
	srand(time(NULL));

	// Создание объектов
	char** field = createField(SIZE_FIELD);
	int** snake = createSnake(MIN_SIZE_SNAKE);
	int* fruit = new int[2];
	
	// Выставление первоначальных позиций
	setPosition(snake, SIZE_FIELD / 2, SIZE_FIELD / 2);
	do {
		setPosition(fruit, random(0, SIZE_FIELD - 1), random(0, SIZE_FIELD - 1));
	} while (!unions(snake, fruit));

	// Отрисовка
	renderField(field, snake, fruit);



}
