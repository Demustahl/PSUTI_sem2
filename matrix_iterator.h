#include "header.h"

class Matrix_iterator {
public:
  Matrix_iterator(int c, int r);
  ~Matrix_iterator();
  double &operator()(int i, int j);
  Matrix_iterator &operator=(const Matrix_iterator &m);
  Matrix_iterator &operator+=(Matrix_iterator &m);
  void full_massiv() {
    srand(time(0));
    cout << "Заполнение массива: ";
    for (int i = 0; i < c_size; i++) {
      cout << endl;
      for (int j = 0; j < r_size; j++) {
        p[i][j] = (rand() % 10000) / (double)99;
        cout << p[i][j] << "\t";
      }
    }
    cout << endl;
  }
  double found_max() {
    assert(p != 0);
    double max = p[0][0];
    for (int i = 0; i < c_size; ++i) {
      for (int j = 0; j < r_size; ++j) {
        if (max < p[i][j])
          max = p[i][j];
      }
    }
    return max;
  }

private:
  int c_size, r_size;
  double **p;
};

Matrix_iterator::Matrix_iterator(int c, int r) : c_size(c), r_size(r) {
  p = new double *[c];
  assert(p != 0);
  for (int i = 0; i < c; ++i) {
    p[i] = new double[r];
    assert(p[0] != 0);
  }
}

Matrix_iterator::~Matrix_iterator() {
  for (int i = 0; i < c_size; ++i) {
    delete[] p[i];
  }
  delete[] p;
}

inline double &Matrix_iterator::operator()(int i, int j) {
  assert(i >= 0 && i <= c_size && j >= 0 && j <= r_size);
  return p[i][j];
}

Matrix_iterator &Matrix_iterator::operator=(const Matrix_iterator &m) {
  assert(m.c_size == c_size && m.r_size == r_size);
  int i, j;
  for (i = 0; i < c_size; ++i)
    for (j = 0; j < r_size; ++j)
      p[i][j] = m.p[i][j];
  return *this;
}

Matrix_iterator &Matrix_iterator::operator+=(Matrix_iterator &m) {
  assert(m.c_size == c_size && m.r_size == r_size);
  int i, j;
  for (i = 0; i < c_size; ++i)
    for (j = 0; j < r_size; ++j)
      p[i][j] += m.p[i][j];
  return *this;
}