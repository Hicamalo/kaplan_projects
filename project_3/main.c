#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N (3) // Размер квадратной матрицы
#define DIAG_COUNT (N*N -1 - 3)

// Функция для определения суммы элементов в столбцах без отрицательных элементов
int sumColumns(int matrix[N][N]) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
        int containsNegative = 0;
        for (int i = 0; i < N; i++) {
            if (matrix[i][j] < 0) {
                containsNegative = 1;
                break;
            }
        }
        if (!containsNegative) {
            for (int i = 0; i < N; i++) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int minDiagonalSum(int matrix[N][N]) {
    int sum_array[2*N - 1]; /* Суммы всех диагоналей, параллельной побочной */
    int diags[DIAG_COUNT];

    int sum;
    for (int row=0; row<2*N-1; ++row) {
        sum = 0;
        for (int col=0; col<=row; ++col) {
            if (col<N && row-col<N) {
                sum += matrix[col][row-col];
            }
        }
        sum_array[row] = sum;
    }

    // Находим минимум среди сумм
    int min = sum_array[1];
    for (size_t i = 0; i < (2*N - 1); ++i) {
        if (i == 0 || i == (2*N - 2) || i == ((2*N) / 2) - 1) {
            continue;
        }
        if (sum_array[i] < min) {
            min = sum_array[i];
        }
    }

    return min;
}



int main() {
    int matrix[N][N];

    printf("Введите элементы матрицы %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = sumColumns(matrix);
    printf("Сумма элементов в столбцах без отрицательных элементов: %d\n", sum);

    int minSum = minDiagonalSum(matrix);
    printf("Минимум среди сумм модулей элементов диагоналей, параллельных побочной диагонали: %d\n", minSum);

    return 0;
}
