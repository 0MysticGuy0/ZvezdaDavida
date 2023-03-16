// ZvezdaDavida.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
****************************************
<< "    ****  ***    ***    ***     \n" >>
<< "    *   * *   * *   *  *   *    \n" >>
<< "    *   * *   * *   *  *   *    \n" >>
<< "    ****  *   * *****  *   *    \n" >>
<< "    *   * *   * *   *  *   *    \n" >>
<< "    *   * *   * *   * *******   \n" >>
<< "    ****  *   * *   * *     *   \n";>>
****************************************
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

////////////////////////////////////////////////////////
COORD position = { 0,0 }; //позиция x и y
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

void setColor(ConsoleColor text, ConsoleColor background = Black)
{
    SetConsoleTextAttribute(hConsole, (WORD)((background << 4) | text));
}
////////////////////////////////////////////////////////
void buildStarNums(int n,char c,int cs) {
    
    for (int i = 0; i <= n + n / 3; i++) {
        if ((i + 1) % 2 == 0) continue;
        for (int j = 0; j < n; j++) {
            bool t1 = (i < n) && (j >= (n / 2 + 1 - (i / 2 + 1)) && j <= (n / 2 + (i / 2)));
            bool t1_c = (i < n) && ((i == n - 1) || (j == (n / 2 + 1 - (i / 2 + 1)) || j == (n / 2 + (i / 2))));
            bool t2 = (i >= n / 3) && (j >= (n / 2 + 1 - (n - (i - n / 3)) / 2 - 1)) && (j <= (n / 2 + (n - (i - n / 3)) / 2));
            bool t2_c = (i >= n / 3) && ((i == n / 3 + 1) || (j == (n / 2 + 1 - (n - (i - n / 3)) / 2 - 1)) || (j == (n / 2 + (n - (i - n / 3)) / 2)));
            if (t1 || t2) cout << rand() % 10;
            else cout << ' ';
        }
        cout << endl;
    }
}

void buildStar(int n,char c, int cs) {

    for (int i = 0; i <= n + n / 3; i++) {
        if ((i + 1) % 2 == 0) continue;
        for (int j = 0; j < n; j++) {
            bool t1 = (i < n) && (j >= (n / 2 + 1 - (i / 2 + 1)) && j <= (n / 2 + (i / 2)));
            bool t1_c = (i < n) && ((i == n - 1) || (j == (n / 2 + 1 - (i / 2 + 1)) || j == (n / 2 + (i / 2))));
            bool t2 = (i >= n / 3) && (j >= (n / 2 + 1 - (n - (i - n / 3)) / 2 - 1)) && (j <= (n / 2 + (n - (i - n / 3)) / 2));
            bool t2_c = (i >= n / 3) && ((i == n / 3 + 1) || (j == (n / 2 + 1 - (n - (i - n / 3)) / 2 - 1)) || (j == (n / 2 + (n - (i - n / 3)) / 2)));
            if (t1 || t2) cout << c;
            else cout << ' ';
        }
        cout << endl;
    }
}

void buildStarNumsContur(int n,char c, int cs) {

    for (int i = 0; i <= n + n / 3; i++) {
        // for (int c = 0; c < (n - i + 1) / 2; c++) cout << ' ';
        if ((i + 1) % 2 == 0) continue;
        for (int j = 0; j < n; j++) {
            bool t1 = (i < n) && (j >= (n / 2 + 1 - (i / 2 + 1)) && j <= (n / 2 + (i / 2)));
            bool t1_c = (i < n) && ((i >= n - cs) || ((j >= (n / 2 + 1 - (i / 2 + 1)) && j < (n / 2 + 1 - (i / 2 + 1) + cs)) || (j <= (n / 2 + (i / 2)) && j > (n / 2 + (i / 2)-cs))));
            bool t2 = (i >= n / 3) && (j >= (n / 2 + 1 - (n - (i - n / 3)) / 2 - 1)) && (j <= (n / 2 + (n - (i - n / 3)) / 2));
            bool t2_c = (i >= n / 3) && ((i <= n / 3 + +cs) || ((j >= (n / 2 + 1 - (n - (i - n / 3)) / 2 - 1)) && (j < (n / 2 + 1 - (n - (i - n / 3)) / 2 - 1+cs))) || ((j <= (n / 2 + (n - (i - n / 3)) / 2)) && (j > (n / 2 + (n - (i - n / 3)) / 2-cs))));

            if (t1_c || t2_c) cout << rand() % 10;
            else if (t1 || t2) cout << c;
            else cout << ' ';
            if (!(t1 || t2)) cout << "\b "; //чтобы то что выходит за границы не выводилось
        }
        cout << endl;
    }
}

void buildStarNumsConturColor(int n, char c, int cs) {

    for (int i = 0; i <= n + n / 3; i++) {
        // for (int c = 0; c < (n - i + 1) / 2; c++) cout << ' ';
        if ((i + 1) % 2 == 0) continue;
        for (int j = 0; j < n; j++) {
            bool t1 = (i < n) && (j >= (n / 2 + 1 - (i / 2 + 1)) && j <= (n / 2 + (i / 2)));
            bool t1_c = (i < n) && ((i >= n - cs) || ((j >= (n / 2 + 1 - (i / 2 + 1)) && j < (n / 2 + 1 - (i / 2 + 1) + cs)) || (j <= (n / 2 + (i / 2)) && j > (n / 2 + (i / 2) - cs))));
            bool t2 = (i >= n / 3) && (j >= (n / 2 + 1 - (n - (i - n / 3)) / 2 - 1)) && (j <= (n / 2 + (n - (i - n / 3)) / 2));
            bool t2_c = (i >= n / 3) && ((i <= n / 3 + +cs) || ((j >= (n / 2 + 1 - (n - (i - n / 3)) / 2 - 1)) && (j < (n / 2 + 1 - (n - (i - n / 3)) / 2 - 1 + cs))) || ((j <= (n / 2 + (n - (i - n / 3)) / 2)) && (j > (n / 2 + (n - (i - n / 3)) / 2 - cs))));

            if (t1_c || t2_c) {
                int num = rand() % 10; setColor((ConsoleColor)num); cout << num; setColor(White);
            }
            else if (t1 || t2) cout << c;
            else cout << ' ';
            if (!(t1 || t2)) cout << "\b "; //чтобы то что выходит за границы не выводилось
        }
        cout << endl;
    }
}
/////////////////////////
int main()
{
    srand(time(0));//real rand

    int n;//size
    int cs;//conter size
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter contur size: ";
    cin >> cs;
    cout << "\n\n";
    n *= 2;
    n++;
    system("cls");//clear screen
    SetConsoleCursorPosition(hConsole, position);

    while (1) {
        buildStarNumsConturColor(n,'*',cs);
        SetConsoleCursorPosition(hConsole, position);
    }

    return 0;
}


//First contur vars
//  bool t1_c = (i < n) && ((i == n - 1) || (j == (n / 2 + 1 - (i / 2 + 1)) || j == (n / 2 + (i / 2))));
// bool t2_c = (i >= n / 3) && ((i == n / 3 + 1) || (j == (n / 2 + 1 - (n - (i - n / 3)) / 2 - 1)) || (j == (n / 2 + (n - (i - n / 3)) / 2)));