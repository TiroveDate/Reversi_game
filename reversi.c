#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEIGHT 8
#define WIDTH 8

int board[HEIGHT][WIDTH];
int player;

typedef enum Object {
    Empty,
    Dark,
    Light,
} Object;

bool check_lange(int y, int x) {
    if (y < 0 || x < 0 || y >= HEIGHT || x >= WIDTH) {
        return true;
    }
    return false;
}

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
            board[y][x] = Dark;
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

void print_object(Object n) {
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

bool check_direction(int y, int x, Object col, int dy, int dx) {
    y += dy;
    x += dx;

    if (board[y][x] == Empty || check_lange == false) {
        return false;
    }

    return board[y][x] == col ? true : check_direction(y, x, col, dy, dx);
}

/*
Check if there are any flippable disks around.
*/
bool check_around(int y, int x, Object col) {
    int flag = 0, check[8][2] = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
    for (int yy = y - 1; yy <= y + 1; yy++) {
        for (int xx = x - 1; xx <= x + 1; xx++) {
            if (yy != y && xx != x) {
                flag++;
                if (board[yy][xx] == col) {
                    if (check_direction(yy, xx, col, check[flag][0], check[flag][1])) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool put_disks(int y, int x, Object col) {
    if (check_lange(y, x)) {
        if (col == Dark) {
            if (check_around(y, x, Light)) {
                return true;
            }
        }
        if (col == Light) {
            if (check_around(y, x, Dark)) {
                return true;
            }
        }
    }
    return false;
}

void game() {
    printf("Let's start reversi game!\n");
    printf("Choose your side. (1: Dark 2:Light) > ");
    scanf("%d", &player);

    if (player == Dark) {
        int y = 0, x = 0;
        printf("Enter your coordinates > ");
        if (scanf("%d %d", &y, &x)) {
            if (put_disks(y, x, Dark)) {
                board[y - 1][x - 1] = Dark;
                print_board();
            } else {
                printf("You can't put this coordinates!\n");
                board[y - 1][x - 1] = Light;
            }
        }
    }
}

int main(void) {
    // printf("Size of enum Object: %zu bytes\n", sizeof(Object)); 4bytes
    init_board();   
    place_object_first();
    // test_board();    // test
    game();
    print_board();
    return 0;
}