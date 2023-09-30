#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2, 0, 0, 1, -1 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1, 1, -1, 0, 0 };

int path(char** maze, int rows, int cols, int k, int x, int y, int endX, int endY) {
	int i;
	if (x == endX && y == endY && k == 0) {
		return 1;
	}

	int paths = 0;

	for (i = 0; i < 12; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && maze[newX][newY] != '1') {
			char temp = maze[newX][newY];
			maze[newX][newY] = 'X';
			paths += path(maze, rows, cols, (k - 1), newX, newY, endX, endY);
			maze[newX][newY] = temp;
		}
	}
	return paths;
}

int main(void) {
	int rows, cols, k, i, j, startX, startY, endX, endY;
	printf("Input :\n");
	scanf("%d %d %d", &rows, &cols, &k);
	char** maze = (char**)malloc(rows * sizeof(char*));
	for (i = 0; i < rows; i++) {
		maze[i] = (char*)malloc(cols * sizeof(char));
	}

	if (maze == NULL) exit;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			scanf("%s", &maze[i][j]);
		}
	}
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (maze[i][j] == 'S') {
				startX = i;
				startY = j;
			}
			else if (maze[i][j] == 'E') {
				endX = i;
				endY = j;
			}
		}
	}

	int total = path(maze, rows, cols, k, startX, startY, endX, endY);
	printf("Output :\n");
	printf("%d\n", total);

	for (i = 0; i < cols; i++) {
		free(maze[i]);
	}
	free(maze);
	return 0;
}