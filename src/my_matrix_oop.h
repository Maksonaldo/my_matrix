#ifndef SRC_My_MATRIX_OOP_H_
#define SRC_My_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

class MyMatrix {
 private:
  int _rows, _cols;
  double** _matrix;

  void deleteMatrix();
  void allocateMatrix();

 public:
  MyMatrix();
  MyMatrix(int rows, int cols);
  MyMatrix(const MyMatrix& other);
  MyMatrix(MyMatrix&& other);
  ~MyMatrix();

  int getRows();
  int getCols();
  void setRows(int rows);
  void setCols(int cols);
  double& operator()(int row, int col);
  double operator()(int row, int col) const;
  MyMatrix& operator=(const MyMatrix& other);
  MyMatrix& operator+=(const MyMatrix& other);
  MyMatrix operator+(const MyMatrix& other);
  MyMatrix& operator-=(const MyMatrix& other);
  MyMatrix& operator*=(const MyMatrix& other);
  MyMatrix& operator*=(const double num);
  MyMatrix operator-(const MyMatrix& other);
  MyMatrix operator*(const MyMatrix& other);
  MyMatrix operator*(const double num);
  bool operator==(const MyMatrix& other);

  void sum_matrix(const MyMatrix& other);
  void sub_matrix(const MyMatrix& other);
  void mul_number(const double num);
  void mul_matrix(const MyMatrix& other);
  bool eq_matrix(const MyMatrix& other);

  MyMatrix calc_complements();
  MyMatrix transpose();
  MyMatrix minor_matrix(int i, int j);
  double determinant();
  MyMatrix inverse_matrix();
  void init_matrix_2(double count);
};
#endif  // SRC_My_MATRIX_OOP_H_
