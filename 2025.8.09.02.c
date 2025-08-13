#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct MParam {
    uint8_t row;
    uint8_t column;
    float **data;
} *Matrix;

// 创建矩阵
Matrix create_matrix(uint8_t r, uint8_t c) {
    Matrix m = malloc(sizeof(struct MParam));
    m->row = r;
    m->column = c;
    m->data = malloc(r * sizeof(float *));
    for (int i = 0; i < r; i++)
        m->data[i] = malloc(c * sizeof(float));
    return m;
}

// 释放矩阵
void free_matrix(Matrix m) {
    for (int i = 0; i < m->row; i++)
        free(m->data[i]);
    free(m->data);
    free(m);
}

// 输入矩阵
void input_matrix(Matrix m) {
    for (int i = 0; i < m->row; i++)
        for (int j = 0; j < m->column; j++)
            scanf("%f", &m->data[i][j]);
}

// 打印矩阵
void print_matrix(Matrix m) {
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < m->column; j++)
            printf("%6.2f ", m->data[i][j]);
        printf("\n");
    }
}

// 转置
Matrix transpose(Matrix m) {
    Matrix t = create_matrix(m->column, m->row);
    for (int i = 0; i < m->row; i++)
        for (int j = 0; j < m->column; j++)
            t->data[j][i] = m->data[i][j];
    return t;
}

// 乘法
Matrix multiply(Matrix a, Matrix b) {
    Matrix r = create_matrix(a->row, b->column);
    for (int i = 0; i < a->row; i++)
        for (int j = 0; j < b->column; j++) {
            r->data[i][j] = 0;
            for (int k = 0; k < a->column; k++)
                r->data[i][j] += a->data[i][k] * b->data[k][j];
        }
    return r;
}

int main() {
    uint8_t r, c;
    printf("行数 列数: ");
    scanf("%hhu %hhu", &r, &c);

    Matrix A = create_matrix(r, c);
    printf("输入矩阵元素：\n");
    input_matrix(A);

    Matrix At = transpose(A);
    Matrix R = multiply(A, At);

    printf("A × A^T =\n");
    print_matrix(R);

    free_matrix(A);
    free_matrix(At);
    free_matrix(R);
    return 0;
}