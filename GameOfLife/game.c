#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define WIDTH 25
#define HEIGHT 80

int near(int **massive, int **buffer);
void logic(int **massive, int **buffer);

int main() {
    int data[WIDTH][HEIGHT];
    int buffer[WIDTH][HEIGHT];
    near(data, buffer);

    return 0;
}

// Counter death NPS
int near(int **massive, int **buffer) {
    int count = 0;

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            count += 1;
        }
    }
    return count;
}


void logic(int **massive, int **buffer) {
    _getch();
    while (1) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                // Game field
            }
        }
        switch ((c = _getch())) {
            // ESC
            case 27:
                exit();
                break;
            // First -> Sixth
            case 49:
                fread();
                break;
            case 50:
                fread();
                break;
            case 51:
                fread();
                break;
            case 52:
                fread();
                break;
            case 53:
                fread();
                break;
            // Out
            default:
                break;
        }
    }
}



