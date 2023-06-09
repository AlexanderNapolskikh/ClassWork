﻿
#include"Param.h"

// Список направлений
enum Dir
{
	NO = -1,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

// Прототипы
char** createField(int);
void renderField(char**, int**, int*);
int** createSnake(int);
void setPosition(int**, int, int);
void setPosition(int*, int, int);
bool gameOver(int**);
bool unions(int**, int*);
void push(int**&, int*);
bool eat(int**&, int*, int*);
int* step(int**, Dir&, Dir&);
Dir keyboard();

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

	int sizeF = _msize(field) / sizeof(field);

	for (int i = 0; i < sizeF; i++)
	{
		for (int j = 0; j < sizeF; j++)
		{
			field[i][j] = '~';
		}
	}

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

// Head - dead
// Окончание игры
bool gameOver(int** snake) {

	int size = _msize(snake) / sizeof(snake[0]);

	for (int i = 1; i < size; i++)
	{
		if (snake[i][0] == snake[0][0] && snake[i][1] == snake[0][1]) {
			return true;
		}
	}

	return false;
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

void push(int**& snake, int* oldTail)
{
	int sizeSnake = _msize(snake) / sizeof(snake[0]);
	int** bufSnake = new int* [sizeSnake + 1];

	for (int i = 0; i < sizeSnake; i++)
	{
		bufSnake[i] = snake[i];
	}

	bufSnake[sizeSnake] = new int[2]{ oldTail[0], oldTail[1] };
	delete[] snake;
	snake = bufSnake;
}

bool eat(int** &snake, int* fruit, int* oldTail) {

	// Проверка пересечения с фруктом в последующем
	if (!unions(snake,fruit))
	{
		push(snake, oldTail);
		return true;
	}

	return false;
}

int* step(int** snake, Dir &side, Dir &oldS) {

	int size = _msize(snake) / sizeof(snake[0]);
	int* oldTail = new int[2]{ snake[size - 1][0],snake[size - 1][1] };
	
	// Вход змейки в саму себя
	if ((side == UP && oldS == DOWN) ||
		(side == DOWN && oldS == UP) ||
	 (side == RIGHT && oldS == LEFT) ||
     (side == LEFT && oldS == RIGHT))
	{
		side = oldS;
	}

	// голова меняет позицию
	switch (side)
	{
	case UP:

		// хвост меняет позицию
		for (int i = size - 1; i > 0; i--)
		{
			swap(snake[i], snake[i - 1]);
		}

		if (snake[1][0] == 0) {
			snake[0][0] = SIZE_FIELD - 1;
		}
		else {
			snake[0][0] = snake[1][0] - 1;
		}
		snake[0][1] = snake[1][1];
		break;
	case DOWN:

		// хвост меняет позицию
		for (int i = size - 1; i > 0; i--)
		{
			swap(snake[i], snake[i - 1]);
		}

		if (snake[1][0] == SIZE_FIELD - 1) {
			snake[0][0] = 0;
		}
		else {
			snake[0][0] = snake[1][0] + 1;
		}
		snake[0][1] = snake[1][1];
		break;
	case LEFT:

		// хвост меняет позицию
		for (int i = size - 1; i > 0; i--)
		{
			swap(snake[i], snake[i - 1]);
		}

		if (snake[1][1] == 0) {
			snake[0][1] = SIZE_FIELD - 1;
		}
		else {
			snake[0][1] = snake[1][1] - 1;
		}
		snake[0][0] = snake[1][0];
		break;
	case RIGHT:

		// хвост меняет позицию
		for (int i = size - 1; i > 0; i--)
		{
			swap(snake[i], snake[i - 1]);
		}

		if (snake[1][1] == SIZE_FIELD - 1) {
			snake[0][1] = 0;
		}
		else {
			snake[0][1] = snake[1][1] + 1;
		}

		snake[0][0] = snake[1][0];
		break;

	default:
		side = oldS;
	}

	oldS = side;

	return oldTail;
}

Dir keyboard() {
	
	
	if (_kbhit()) {

		switch (_getch())
		{
		case 'w':
			return UP;
		case 's':
			return DOWN;
		case 'a':
			return LEFT;
		case 'd':
			return RIGHT;
		}
	}
	else {
		return NO;
	}


}

int main()
{

	// Snake work
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
	
	// Старый хвост
	int* oldTail = nullptr;

	// Текущее направление
	Dir sSide = UP;
	// Хранящееся направление
	Dir buf;
	// Прошлое направление
	Dir oldS = sSide;

	// Test code
	while (true)
	{
		Sleep(SPEED);

		buf = keyboard();
		
		if (buf != NO) {
			sSide = buf;
		}

		delete[] oldTail;
		oldTail = step(snake, sSide, oldS);

		if (eat(snake, fruit, oldTail)) {
			do
			{
				setPosition(fruit, random(0, SIZE_FIELD - 1), random(0, SIZE_FIELD - 1));
			} while (!(unions(snake, fruit)));
		}

		if (gameOver(snake)) {

			system("cls");
			cout << endl << "_________GAME OVER_________" << endl;
			break;
		}

		renderField(field, snake, fruit);
	}

	
	

}
