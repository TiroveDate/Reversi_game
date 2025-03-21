#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEIGHT 8
#define WIDTH 8

int board[HEIGHT][WIDTH];

enum Object {
    Empty,
    Dark,
    Light,
};

void init_board() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            board[y][x] = Empty;
        }
    }
}

void test_board() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            board[y][x] = Light;
        }
    }
}

void place_object_first() {
    for (int y = HEIGHT / 2 - 1; y <= HEIGHT / 2; y++) {
        for (int x = WIDTH / 2 - 1; x <= WIDTH / 2; x++) {
            if (y == x) {
                board[y][x] = Dark;
            } else {
                board[y][x] = Light;
            }
        }
    }   
}

void print_line() {
    printf(" ");
    for (int x = 0; x < WIDTH; x++) {
        printf("---");
    }
    printf("\n");
}

void print_number() {
    for (int x = 0; x < WIDTH; x++) {
        printf("%3d", x + 1);
    }
}

void print_object(int n) {
    char a;
    if (n == Dark) {
        a = 'D';
    } else if (n == Light) {
        a = 'L';
    } else {
        a = ' ';
    }
    printf("|%2c", a);
}

void print_board() {
    print_line();
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            print_object(board[y][x]);
        }
        printf("%2d\n", y + 1);
        print_line();
    }
    print_number();
}

/*
Check if there are any flippable disks around.
*/
bool check_around(int y, int x, int col) {
    for (int yy = y - 1; yy <= y + 1; yy++) {
        for (int xx = x - 1; xx <= x + 1; xx++) {
            if (board[yy][xx] == col) {
                return true;
            }
        }
    }
    return false;
}

bool judge_disks(int y, int x) {
    if (board[y][x] != Empty) {
        if (board[y][x] == Dark) {
            if (check_around(y, x, Light)) {

            }
        } else {
            if (check_around(y, x, Dark)) {
                
            }
        }
    }
    return false;
}

int main(void) {
    init_board();   
    place_object_first();
    // test_board();    // test
    print_board();
    return 0;
}