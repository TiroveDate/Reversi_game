#include <stdio.h>
#include <stdlib.h>

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

void print_object(int n) {
    char a;
    if (n == Dark) {
        a = 'D';
    } else if (n == Light) {
        a = 'L';
    } else {
        a = ' ';
    }
    printf("%2c", a);
}

void print_board() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            print_object(board[y][x]);
        }
        printf("\n");
    }
}

int main(void) {
    init_board();
    place_object_first();
    print_board();
    return 0;
}