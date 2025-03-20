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
        printf("--");
    }
    printf("\n");
}

void print_number() {
    printf(" ");
    for (int x = 0; x < WIDTH; x++) {
        printf("%2d", x + 1);
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
    print_line();
    for (int y = 0; y < HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WIDTH; x++) {
            print_object(board[y][x]);
        }
        printf("%2d\n", y + 1);
    }
    print_number();
}

int main(void) {
    init_board();   
    place_object_first();
    // test_board();    // test
    print_board();
    return 0;
}