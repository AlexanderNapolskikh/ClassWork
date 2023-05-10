#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

#define random(a,b) (a + rand()%(b + 1 - a))
using namespace std;

template <typename T>
void deleteStr(T**&, int);

// task_1

void srArif() {

    double a, b, c, d;

    cout << "Input 4 number :: ";
    cin >> a >> b >> c >> d;

    double sum = a + b + c + d;

    cout << " \nResult:: " << sum / 4;

}

// task_2

void outChetNumb() {

    for (int i = 0; i < 40; i+=2)
    {
        cout << " " << i;
    }
}

// task_3

void outTr() {

    int a;

    cout << " Input a(int): ";
    cin >> a;

    cout << endl;

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << " " << "*";
        }

        cout << endl;
    }
}

// task_4

void whatRaz() {

    int numb;
    int raz = 0;

    cout << " Input some numb: ";
    cin >> numb;

    for (;numb != 0; raz++, numb/=10)
    {
    }

    cout << "\n Result: (is " << raz << " numb) !!";
}

// task_5

template <typename T>
T* createArray(int size) {

    T* array = new T[size];
    return array;
}

void fillArray(int* array, int a , int b) {

    int size = _msize(array) / sizeof(array[0]);

    if (a > b) swap(a, b);

    for (int i = 0; i < size; i++)
    {
        array[i] = random(a, b);
    }
}

void fillArray(float* array, double a, double b) {

    int size = _msize(array) / sizeof(array[0]);

    if (a > b) swap(a, b);

    int prot_a = a * 1000;
    int prot_b = b * 1000;

    for (int i = 0; i < size; i++)
    {
      array[i] = (double) random(prot_a, prot_b) / 1000;
    }

}

template <typename T>
void showArray(T* array) {

    int size = _msize(array) / sizeof(array[0]);

    cout << " Result: ";

    for (int i = 0; i < size; i++)
    {
        cout << " " << array[i];
    }
}

// task_6

template <typename T>
T** createArray(int size1, int size2) {

    T** array = new T*[size1];
  
    for (int i = 0; i < size1; i++)
    {
        array[i] = new T[size2];
    }

    return array;
}

void fillArray(int** array, int a, int b) {

    int size1 = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);

    if (a > b) swap(a, b);

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            array[i][j] = random(a, b);
        }
    }
}

void fillArray(float** array, double a, double b) {

    int size1 = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);

    if (a > b) swap(a, b);

    int prot_a = a * 1000;
    int prot_b = b * 1000;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            array[i][j] = (double) random(prot_a, prot_b) / 1000;
        }
    }
}

template <typename T>
void showArray(T** array) {

    int size1 = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);

    cout << " Result: " << endl;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            cout << " " << array[i][j];
        }
        cout << endl;
    }
}

template <typename T>
void showMaxSumStr(T* array) {

    int size1 = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);

    float sum_curr = 0;
    float sum_buf = 0;
    int index_str = -1;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            sum_buf += array[i][j];
        }

        if (sum_buf > sum_curr) {
            sum_curr = sum_buf;
            index_str = i;
        }
        sum_buf = 0;
    }

    cout << " Result: index(" << index_str << ") is the big";
}

// task_7

template <typename T>
void copy_array(T** pullArray, T** &pushArray) {

    int size1 = _msize(pullArray) / sizeof(pullArray[0]);
    int size2 = _msize(pullArray[0]) / sizeof(pullArray[0][0]);

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            pushArray[i][j] = pullArray[i][j];
        }
    }
}


// task_8

template <typename T>
void deleteStr(T** &array, int index) {

    int size1 = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);
    index -= 1;

    T** buf = new T * [size1 - 1];

    for (int i = 0; i < index; i++)
    {
        buf[i] = array[i];
    }

    for (int i = index + 1; i < size1; i++)
    {
        buf[i - 1] = array[i];
    }

    delete[] array[index];
    array = buf;
}


// task_9

template <typename T>
void addStrToArray(T** &array,T* arrayAdd, int position) {

    position -= 1;

    int size1 = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);

    T** buf = createArray<T>(size1 + 1, size2);
    // Сразу вставить
    buf[position] = arrayAdd;

    // Далее разбросать существующие
    for (int i = 0; i < position; i++)
    {
        buf[i] = array[i];
    }

    for (int i = position + 1; i < size1 + 1; i++)
    {
        buf[i] = array[i - 1];
    }

    delete[] array;
    array = buf;
}

// task_10

template <typename T>
void deleteStlb(T** &array, int index) {

    index -= 1;

    int size1 = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);

    T** buf = createArray<T>(size1, size2 - 1);

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < index; j++)
        {
            buf[i][j] = array[i][j];
        }

        for (int j = index + 1; j < size2; j++)
        {
            buf[i][j - 1] = array[i][j];
        }
    }

    for (int i = 0; i < size1; i++)
    {
        delete[] array[i];
    }

    delete[] array;
    array = buf;
}

// task_11

template <typename T>
double searchMinEl(T** array) {

    double min = array[0][0];
    int size1 = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (min > array[i][j]) {
                min = array[i][j];
            }
        }
    }

    cout << " Result min_el: " << min;
    return min;
}

template <typename T>
int searchMinStr(T** array, double min) {

    int size1 = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (min == array[i][j]) {
                return i;
            }
        }
    }

    return -1;
}

// task_12

int firtstIn(string str, string sub_str) {

    for (int i = 0, flag = false; i < str.length(); i++)
    {
        // Захват первого совпадения
        if (str[i] == sub_str[0]) {

            flag = true;
            for (int j = 1; j < sub_str.length(); j++)
            {
                if (str[i + j] != sub_str[j]) {
                    flag = false;
                    i += j;
                    break;
                }
            }

            // Возвращение индекса при успешной проверке
            if (flag == true) {
                return i;
            }
        }
    }

    return -1;
}

// task_13

int numSymbolInDocument(string way) {

    fstream in(way);
    string str;

    int num = 0;

    if (in.is_open())
    {
        while (getline(in,str))
        {
            num += str.length();
        }

    }
    else {
        cout << " Errot opening file!!!";
        return -1;
    }

    return num;
}

// task_14

struct Car
{
    string Color;
    string Model;

    // Инициализация, если понадобиться)
    void startInit() {
        
        cout << " Color:";
        cin >> Color;

        cout << " Model:";
        cin >> Model;
    }

    void showCar() {
        cout << " Color: " << Color << " || Model: " << Model;
    }

};

void main()
{
    srand(time(NULL));

    // 1
    //srArif();

    // 2
    //outChetNumb();

    // 3
    //outTr();

    // 4
    //whatRaz();

    // 5
    /*float* array = createArray<float>(10);
    fillArray(array,5.5, 12.321);
    showArray(array);*/

    // 6
   /* int** array = createArray<int>(4,5);
    fillArray(array, 1.11, 9.23);
    showArray(array);
    showMaxSumStr(array);*/

    // 7

    /*int** array1 = createArray<int>(2, 15);
    fillArray(array1, 0, 7);
    showArray(array1);
    cout << endl;
    int** array2 = createArray<int>(2, 15);
    copy_array(array1, array2);
    showArray(array2);*/

    // 8
    /*int** array = createArray<int>(8, 4);
    fillArray(array, 0, 7);
    showArray(array);
    cout << endl;
    deleteStr(array, 3);
    showArray(array);*/

    // 9
    /*int** array = createArray<int>(8, 4);
    fillArray(array, 0, 7);
    int size = _msize(array[0]) / sizeof(array[0][0]);
    showArray(array);
    cout << endl;
    int* array_dop = createArray<int>(size);
    fillArray(array_dop, 0, 7);
    showArray(array_dop);
    addStrToArray(array, array_dop, 3);
    cout << endl << endl;
    showArray(array);*/

    // 10

    /*int** array = createArray<int>(8, 4);
    fillArray(array, 0, 7);
    showArray(array);
    deleteStlb(array, 4);
    showArray(array);*/

    // 11

    /*int** array = createArray<int>(8, 4);
    fillArray(array, 0, 7);
    showArray(array);
    double min = searchMinEl(array);
    deleteStr(array, searchMinStr(array, min) + 1);
    cout << endl;
    showArray(array);*/

    // 12

   /* string str = "Love hiktory histo";
    string sub_str = "his";

    cout << " Result first in: " << firtstIn(str, sub_str);*/

    // 13

   /* string way = "Test.txt";

    cout << " Result numSym_Document : " << numSymbolInDocument(way);*/

    // 14

    Car* array_Car = new Car[3];

    // Инициализация ( также возможна инициалиация методом в структуре)
    array_Car[0].Color = "Black";
    array_Car[1].Color = "White";
    array_Car[2].Color = "Green";

    array_Car[0].Model = "Sab";
    array_Car[1].Model = "Tiga";
    array_Car[2].Model = "Sitroen";

    for (int i = 0; i < 3; i++)
    {
        array_Car[i].showCar();
        cout << endl;
    }
    
}
