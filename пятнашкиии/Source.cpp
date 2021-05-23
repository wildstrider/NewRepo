
#include <iostream>
#include <conio.h>
using namespace std;

int temp;

void show_arr(int arr[][4], int r, int c)
{
    for (int i = 0; i < r; i++) {

        for (int j = 0; j < c; j++) {

            printf(" %3d", arr[i][j]);
        }
        cout << endl;
    }

}

void swap_up(int arr[][4], int r, int c) {

    for (int i = 0; i < r; i++) {

        for (int j = 0; j < c; j++) {

            if (arr[i][j] == 0 && i == 0) {

                continue;
            }

            if (arr[i][j] == 0) {

                temp = arr[i][j];
                arr[i][j] = arr[i - 1][j];
                arr[i - 1][j] = temp;
            }

        }
    }

}

void swap_down(int arr[][4], int r, int c) {

    int y = 0;
    for (int i = 0; i < r; i++) {

        if (y != 0)
            break;

        for (int j = 0; j < c; j++) {

            if (arr[i][j] == 0 && i == r - 1) {

                continue;
            }

            if (arr[i][j] == 0) {

                temp = arr[i][j];
                arr[i][j] = arr[i + 1][j];
                arr[i + 1][j] = temp;
                y++;
            }

        }
    }
}

void swap_left(int arr[][4], int r, int c) {

    for (int i = 0; i < r; i++) {

        for (int j = 0; j < c; j++) {

            if (arr[i][j] == 0 && j == 0) {

                continue;
            }

            if (arr[i][j] == 0) {

                temp = arr[i][j];
                arr[i][j] = arr[i][j - 1];
                arr[i][j - 1] = temp;
            }

        }
    }
}

void swap_right(int arr[][4], int r, int c) {

    for (int i = 0; i < r; i++) {

        for (int j = 0; j < c; j++) {

            if (arr[i][j] == 0 && j == c - 1) {

                continue;
            }

            if (arr[i][j] == 0) {

                temp = arr[i][j];
                arr[i][j] = arr[i][j + 1];
                arr[i][j + 1] = temp;
                break;
            }

        }
    }
}

int main()
{
    const int r = 4;
    const int c = 4;
    int arr[r][c] = { {8,6,2,4}, {10,3,7,1}, {15,13,0,9}, {14,11,5,12} };
    char x = 0;
    setlocale(LC_ALL, "rus");

    show_arr(arr, r, c);

    while (x != 122)
    {
        cout << endl;
        cout << "\tИгра пятнашки."
            "\nРазместите все цифры по порядку (0 пустая клетка)"
            "\nДля перемещения ипользуйте клавиши w - вверх, s - вниз, a - влево, d - вправо, z -  выход." << endl;

        switch (x = _getch())
        {
        case 119:
            swap_up(arr, r, c);
            system("cls");
            show_arr(arr, c, r);
            break;
        case 115:
            swap_down(arr, r, c);
            system("cls");
            show_arr(arr, c, r);
            break;
        case 97:
            swap_left(arr, r, c);
            system("cls");
            show_arr(arr, c, r);
            break;
        case 100:
            swap_right(arr, r, c);
            system("cls");
            show_arr(arr, c, r);
            break;
        case 122:
            return 0;
        }
    }

}