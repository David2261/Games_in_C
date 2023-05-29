// Copyright 2022 podsamar
#include <stdio.h>

#include <stdlib.h>

#include <math.h>

void input_dimens(int * cnt1, int * cnt2);
void input_matrix(double ** matrix, int
  const * cnt1, int
  const * cnt2);
void cofactor(float num[25][25], int f);
void transpose(float num[25][25], float fac[25][25], int r);
float determinant(float a[25][25], float k);
void output(double ** matrix,
  int * cnt1);
void exit_print_na();
int main() {
  int count1, count2;
  input_dimens(& count1, & count2);
  double ** matr = malloc(count1 * sizeof(double * ));
  input_matrix(matr, & count1, & count2);
  output(matr, & count1);
  return 0;
}

void input_dimens(int * cnt1, int * cnt2) {
  int dim1, dim2;
  if (scanf("%d %d", & dim1, & dim2) == 2) {
    if (dim1 == dim2 && dim1 > 0) {
      * cnt1 = dim1;
      * cnt2 = dim2;
    } else {
      exit_print_na();
    }
  } else {
    exit_print_na();
  }
}
void input_matrix(double ** matrix, int
  const * cnt1, int
  const * cnt2) {
  double tm;
  for (int i = 0; i < * cnt1; i++) {
    matrix[i] = malloc( * cnt2 * sizeof(double));
  }
  for (int i = 0; i < * cnt1; i++) {
    for (int j = 0; j < * cnt2; j++) {
      if (scanf("%lf", & tm) == 1) {
        matrix[i][j] = tm;
      } else {
        exit_print_na();
      }
    }
  }
}

void output(double ** matrix,
  int * cnt1) {
  float m[25][25];
  float df = * cnt1;
  for (int i = 0; i < * cnt1; i++) {
    for (int j = 0; j < * cnt1; j++) {
      m[i][j] = matrix[i][j];
    }
  }
  if (determinant(m, df) == 0) {
    exit_print_na();
  } else {
    cofactor(m, * cnt1);
  }
  for (int i = 0; i < * cnt1; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void exit_print_na() {
  printf("%s", "n/a");
  exit(1);
}

float determinant(float a[25][25], float k) {
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  if (k == 1) {
    return (a[0][0]);
  } else {
    det = 0;
    for (c = 0; c < k; c++) {
      m = 0;
      n = 0;
      for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
          b[i][j] = 0;
          if (i != 0 && j != c) {
            b[m][n] = a[i][j];
              if (n < (k - 2)) {
                  n++;
              } else {
              n = 0;
              m++;
            }
          }
        }
      }
      det = det + s * (a[0][c] * determinant(b, k - 1));
      s = -1 * s;
    }
  }
  return (det);
}
void cofactor(float num[25][25], int f) {
  float b[25][25], fac[25][25];
  int p, q, m, n, i, j;
  for (q = 0; q < f; q++) {
    for (p = 0; p < f; p++) {
      m = 0;
      n = 0;
      for (i = 0; i < f; i++) {
        for (j = 0; j < f; j++) {
          if (i != q && j != p) {
            b[m][n] = num[i][j];
            if (n < (f - 2)) {
                n++;
            } else {
              n = 0;
              m++;
            }
          }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, fac, f);
}
void transpose(float num[25][25], float fac[25][25], int r) {
  int i, j;
  float b[25][25], inverse[25][25], d;
  for (i = 0; i < r; i++) {
    for (j = 0; j < r; j++) {
      b[i][j] = fac[j][i];
    }
  }
  d = determinant(num, r);
  for (i = 0; i < r; i++) {
    for (j = 0; j < r; j++) {
      inverse[i][j] = b[i][j] / d;
    }
  }
  for (i = 0; i < r; i++) {
    for (j = 0; j < r; j++) {
        if (j != r-1) {
            printf("%f ", inverse[i][j]);
        } else {
            printf("%f", inverse[i][j]);
        }
    }
      if (i != r-1) {
          printf("%s", "\n");
      }
  }
}
