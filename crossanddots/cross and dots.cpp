
#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

char pole[9] = { '1','2','3','4','5','6','7','8','9' }; //массив поля
int winLine[3]; //победная комбинация

void write(string p1, string p2, int l)
{
	for (int n = 0; n < 9; n++) //вывод поля
	{
		if ((n != 2) && (n != 5) && (n != 8))
			cout << pole[n] << ':';
		else
			cout << pole[n] << ':' << endl;
	}
	//вывод того, кто ходит
	if (l == 1)
		cout << p1 << ", Your turn: ";
	if (l == 2)
		cout << p2 << ", Your turn: ";
}

//проверка победы
bool check()
{
	if ((pole[0] == pole[3]) && (pole[3] == pole[6])) {
		winLine[0] = 0;
		winLine[1] = 3;
		winLine[2] = 6;
		return true;
	}
	if ((pole[1] == pole[4]) && (pole[4] == pole[7])) {
		winLine[0] = 1;
		winLine[1] = 4;
		winLine[2] = 7;
		return true;
	}
	if ((pole[2] == pole[5]) && (pole[5] == pole[8])) {
		winLine[0] = 2;
		winLine[1] = 5;
		winLine[2] = 8;
		return true;
	}
	if ((pole[0] == pole[1]) && (pole[1] == pole[2])) {
		winLine[0] = 0;
		winLine[1] = 1;
		winLine[2] = 2;
		return true;
	}
	if ((pole[3] == pole[4]) && (pole[4] == pole[5])) {
		winLine[0] = 3;
		winLine[1] = 4;
		winLine[2] = 5;
		return true;
	}
	if ((pole[6] == pole[7]) && (pole[7] == pole[8])) {
		winLine[0] = 6;
		winLine[1] = 7;
		winLine[2] = 8;
		return true;
	}
	if ((pole[0] == pole[4]) && (pole[4] == pole[8])) {
		winLine[0] = 0;
		winLine[1] = 4;
		winLine[2] = 8;
		return true;
	}
	if ((pole[6] == pole[4]) && (pole[4] == pole[2])) {
		winLine[0] = 6;
		winLine[1] = 4;
		winLine[2] = 2;
		return true;
	}

	return false;
} 

//проверка правильности ввода
bool checkInput(int s)
{
	if ((s < 1) || (s > 9)) //проверяем правильность цифры
		return false;
	
	if ((pole[s - 1] == 'x') || (pole[s - 1] == 'o')) //проверяем занятость клетки
		return false;
	return true;
} 

//выделяем победную линию
void WinningLine(int winner)
{
	if (winner == 1) {
		pole[winLine[0]] = 'X';
		pole[winLine[1]] = 'X';
		pole[winLine[2]] = 'X';
	}
	
	if (winner == 2) {
		pole[winLine[0]] = 'O';
		pole[winLine[1]] = 'O';
		pole[winLine[2]] = 'O';
	}
}

int main(int argc, char* argv[])
{
	//ввод имен
	string player1, player2;
	cout << "Write name of 1 player: ";
	cin >> player1;
	system("cls");
	cout << "Write name of 2 player: ";
	cin >> player2;
	system("cls");

	int move;
	int player = 1;
	bool winning = false;
	int winner = 0;
	int game = 0;
	bool end = false;
	bool checking = false;
	string winnername;

	do {
		//считывание хода
		system("cls");
		write(player1, player2, player);
		cin >> move;
		checking = checkInput(move);

		//заполнение поля и проверка победы
		if (checking == true) {
			if (player == 1) {
				pole[move - 1] = 'x';
				end = true;

				winning = check();
				if (winning == true)
					winner = 1;
				game++;
			}

			else {
				pole[move - 1] = 'o';
				end = true;

				winning = check();
				if (winning == true)
					winner = 2;
				game++;
			}

			//переход хода
			player++;
			if (player == 3)
				player = 1;

			if (game == 9)
				winning = true;
		}
	} while (winning != true);

	system("cls");

	//кто победил
	if (winner == 1)
		winnername = player1;
	if (winner == 2)
		winnername = player2;
	if (winner ==0)
		winnername = "Nobody";

	//создание победной линии
	WinningLine(winner);
	
	//конечный вывод
	write(player1, player2, 0);
	cout << winnername << " won!" << endl <<"Press anything to exit";
	_getch();
	return 0;
}




