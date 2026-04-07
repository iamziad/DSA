#include "../include/backtracking.h"
#include <stdio.h>

int rat_cheese(int rt, int ct, char grid[rt][ct], int r, int c, char path[], int *len) {
    if (grid[r][c] == 'c') {
        path[*len] = 0;
        return 1;
    }

    if (c + 1 < ct && grid[r][c + 1] != '#') {
        path[(*len)++] = 'r';
        if(rat_cheese(rt, ct, grid, r, c + 1, path, len)) return 1;
        path[--(*len)] = 0;
    }

    if (r + 1 < rt && grid[r + 1][c] != '#') {
        path[(*len)++] = 'd';
        if(rat_cheese(rt, ct, grid, r + 1, c, path, len)) return 1;
        path[--(*len)] = 0;
    }

    return 0;
}
