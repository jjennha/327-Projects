#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

int grid[23][23];

void printGrid() {
    for(int i = 0; i < 23; i++) {
        for (int j = 0; j < 23; j++) {

            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}


void play(int x, int y) {
    int grains = grid[x][y];
    if (grains < 4) {
        grid[x][y]++;
    } else {
        grid[x][y] = grid[x][y] - 4;
        if (x > 0) {
            play(x - 1, y);
        }
        if (x < 22) {
            play(x + 1, y);
        }
        if (y > 0) {
            play(x, y - 1);
        }
        if (y < 22) {
            play(x, y + 1);
        }
    }
    printGrid();

}
void init(int x, int y, int h) {
    grid[y][x] = h;
    printGrid();
}
int main(int argc, char* argv[]) {
    int yInd = 1;
    while(yInd < argc/3 || argc == 1) {
        int xInd = 2; int hInd = 3;
        int y,x,h;
        while(yInd < argc) {
            y = atoi(argv[yInd]);
            x = atoi(argv[xInd]);
            h = atoi(argv[hInd]);
            init(x, y, h);
            yInd += 3;xInd += 3;hInd += 3;
        }
        play(11, 11);
        usleep(5000);
    }
    return 0;
}
