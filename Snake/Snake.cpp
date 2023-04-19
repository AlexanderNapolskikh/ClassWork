
#include"Param.h"

// Список направлений
enum Dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

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

// build _ _ _
bool fruitEat(int** snake, int* fruit) {

	if (snake[0][0] == fruit[0] && snake[0][1] == fruit[1]) {
		return true;
	}

	return false;
}
// _ _ _

void step(int** snake, Dir side) {

	int size = _msize(snake) / sizeof(snake[0]);


	// голова меняет позицию
	switch (side)
	{
	case UP:

		if (snake[0][0] - 1 == snake[1][0]) {
			break;
		}

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

		if (snake[0][0] + 1 == snake[1][0]) {
			break;
		}

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

		if (snake[0][1] - 1 == snake[1][1]) {
			break;
		}

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

		if (snake[0][1] + 1 == snake[1][1]) {
			break;
		}

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

	// Test code
	while (true)
	{
		int side;
		Dir sSide;

		cin >> side;

		switch (side)
		{
		case 0:
			sSide = UP;
			break;
		case 1:
			sSide = DOWN;
			break;
		case 2:
			sSide = LEFT;
			break;
		case 3:
			sSide = RIGHT;
			break;
		}

		step(snake, sSide);

		renderField(field, snake, fruit);

	}

	
	

}
