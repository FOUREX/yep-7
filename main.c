#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void clear() {
	system("cls");
}


void pause() {
	printf("\n");
	system("pause");
}


int getIntValue(char caption[]) {
	int value;
	printf("%s (int): ", caption);
	scanf("%d", &value);
	return value;
}


int* createMatrix(int width, int height) {
	if (width <= 1 || height <= 1) {
		printf("Matrix width and height must be > 1");
		return NULL;
	}

	int* matrix = malloc((width * height) * sizeof(int));
	return matrix;
}


void fillMatrix(int* matrix, int width, int height) {
	for (int y = 1; y < height + 1; y++) {
		for (int x = 1; x < width + 1; x++) {
			int value = rand() % 20;
			matrix[(x * y) - 1] = value;
		}
	}
}


int getMatrixElement(const int* matrix, int x, int y) {
	x++;
	y++;

	return matrix[(x * y) - 1];
}


int* getMatrixColumn(const int* matrix, int height, int column) {
	int* array = malloc(height * sizeof(int));

	for (int y = 0; y < height; y++)
		array[y] = getMatrixElement(matrix, column, y);

	return array;
}


int getMaxElementInArray(const int* array, int length) {
	int maxElement = array[0];

	for (int i = 0; i < length; i++) {
		int element = array[i];

		if (element > maxElement) {
			maxElement = element;
		}
	}

	return maxElement;
}


void showArray(const int* array, int length) {
	for (int i = 0; i < length; i++)
		printf("%d ", array[i]);
}


void showMatrix(const int* matrix, int width, int height) {
	for (int y = 1; y < height + 1; y++) {
		printf("Row %d: | ", y - 1);
		for (int x = 1; x < width + 1; x++) {
			int value = matrix[(x * y) - 1];

			if (value < 10)
				printf(" ");

			printf("%d ", value);
		}
		printf("|\n");
	}
}


void showMatrixRow(const int* matrix, int width, int row) {
	printf("Row %d: | ", row);
	for (int x = 0; x < width; x++) {
		int value = getMatrixElement(matrix, x, row);

		if (value < 10)
			printf(" ");

		printf("%d ", value);
	}
	printf("|\n");
}


void anatoly_1() {
	int width, height, row;

	width = getIntValue("Width");
	height = getIntValue("Height");

	int* matrix = createMatrix(width, height);
	if (matrix == NULL) {
		return;
	}

	row = getIntValue("Row");
	if (row < 0 || row >= height) {
		printf("Row must be >= 0 and < height");
		return;
	}

	fillMatrix(matrix, width, height);
	showMatrix(matrix, width, height);
	printf("\n");
	showMatrixRow(matrix, width, row);
}


void anatoly_2() {
	int width, height;

	width = getIntValue("Width");
	height = getIntValue("Height");

	int* matrix = createMatrix(width, height);

	if (matrix == NULL)
		return;

	fillMatrix(matrix, width, height);
	showMatrix(matrix, width, height);

	printf("\nMax elements:");

	for (int column = 0; column < width; column++) {
		int* array = getMatrixColumn(matrix, height, column);
		int maxElement = getMaxElementInArray(array, width);
		printf("\nColumn %d: %d", column, maxElement);
	}
}


int main() {
	srand(time(NULL));

	int input;

	while (1) {
		clear();

		printf("FUNCTIONS\n");
		printf("1. Show matrix row\n");
		printf("2. Find a max element in matrix column\n");
		printf("3. Quit\n");

		input = getIntValue("\nSelect function");

		switch (input) {
			case 1:
				anatoly_1();
				break;
			case 2:
				anatoly_2();
				break;
			case 3:
				return 0;
			default:
				printf("Bruh, %d... Rly?", input);
				break;
		}

		pause();
	}
}
