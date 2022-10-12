#include "my_matrix_oop.h"

MyMatrix::MyMatrix() : MyMatrix(3, 3) {}

MyMatrix::MyMatrix(int rows, int cols) : _rows(rows), _cols(cols) {
  if (_rows < 0 || _cols < 0) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  allocateMatrix();
}

MyMatrix::MyMatrix(const MyMatrix& other)
    : _rows(other._rows), _cols(other._cols) {
  allocateMatrix();
  for (int i = 0; i < other._rows; i++) {
    for (int j = 0; j < other._cols; j++) {
      _matrix[i][j] = other._matrix[i][j];
    }
  }
}

MyMatrix::MyMatrix(MyMatrix&& other)
    : _rows(other._rows), _cols(other._cols), _matrix(other._matrix) {
  other._rows = other._cols = 0;
  other._matrix = nullptr;
}

MyMatrix::~MyMatrix() { deleteMatrix(); }

void MyMatrix::deleteMatrix() {
  if (_matrix) {
    for (int i = 0; i < _rows; i++) {
      delete[] _matrix[i];
    }
  }
  delete[] _matrix;
}

void MyMatrix::allocateMatrix() {
  _matrix = new double*[_rows];
  for (int i = 0; i < _rows; i++) {
    _matrix[i] = new double[_cols]();
  }
}

void MyMatrix::init_matrix_2(double count) {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      _matrix[i][j] = count += 76;
    }
  }
}

void MyMatrix::sum_matrix(const MyMatrix& other) {
  if (_rows != other._rows || _cols != other._cols) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      _matrix[i][j] = _matrix[i][j] + other._matrix[i][j];
    }
  }
}
bool MyMatrix::eq_matrix(const MyMatrix& other) {
  bool res = true;
  if (_rows > 0 && _cols > 0 && other._rows > 0 && other._cols > 0) {
    if (_rows == other._rows && _cols == other._cols) {
      for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
          if (fabs(_matrix[i][j] - other._matrix[i][j]) >= 0.000001) {
            res = false;
          }
        }
      }
    } else {
      res = false;
    }
  } else {
    res = false;
  }
  return res;
}
void MyMatrix::sub_matrix(const MyMatrix& other) {
  if (_rows != other._rows || _cols != other._cols) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      _matrix[i][j] = _matrix[i][j] - other._matrix[i][j];
    }
  }
}
void MyMatrix::mul_number(const double num) {
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      _matrix[i][j] = _matrix[i][j] * num;
    }
  }
}
void MyMatrix::mul_matrix(const MyMatrix& other) {
  if (_cols != other._rows) {
    throw std::out_of_range(
        "the number of columns  not equal to the number of rows of the ");
  }
  MyMatrix result(_rows, other._cols);
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < other._cols; j++) {
      for (int k = 0; k < _cols; k++) {
        _matrix[i][j] = _matrix[i][j] * other._matrix[i][j];
      }
    }
  }
  deleteMatrix();
  _rows = result._rows;
  _cols = result._cols;
  _matrix = result._matrix;
  result._matrix = nullptr;
}
MyMatrix MyMatrix::transpose() {
  MyMatrix res_matrix(_rows, _cols);
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      res_matrix._matrix[j][i] = _matrix[i][j];
    }
  }
  return res_matrix;
}

MyMatrix MyMatrix::minor_matrix(int i, int j) {
  MyMatrix res_matrix(_rows - 1, _cols - 1);
  int rows = 0;
  int columns = 0;
  for (int k = 0; k < _rows; k++) {
    for (int m = 0; m < _cols; m++) {
      if (k != i && m != j) {
        res_matrix._matrix[rows][columns] = _matrix[k][m];
        columns++;
        if (columns == _cols - 1) {
          rows++;
        }
      }
    }
    columns = 0;
  }
  return res_matrix;
}
double MyMatrix::determinant() {
  double res = 0;
  if (_rows != _cols) {
    throw std::out_of_range("matrix is ​​not square");
  }
  if (_cols == 1) {
    res = _matrix[0][0];
  } else if (_cols == 2) {
    res = _matrix[0][0] * _matrix[1][1] - _matrix[1][0] * _matrix[0][1];
  } else if (_cols > 2) {
    int i = 0;
    for (int j = 0; j < _cols; j++) {
      MyMatrix buf_matrix = minor_matrix(i, j);
      res += pow(-1, i + j) * _matrix[i][j] * minor_matrix(i, j).determinant();
    }
  }
  return res;
}

MyMatrix MyMatrix::calc_complements() {
  MyMatrix res_matrix(_rows, _cols);
  if (_rows != _cols) {
    throw std::out_of_range("matrix is ​​not square");
  }
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      double determinant = 0.0;
      MyMatrix buf_matrix = minor_matrix(i, j);
      determinant = pow(-1, i + j) * minor_matrix(i, j).determinant();
      res_matrix._matrix[i][j] = determinant;
    }
  }
  return res_matrix;
}
MyMatrix MyMatrix::inverse_matrix() {
  if (determinant() == 0) {
    throw std::out_of_range("matrix determinant of equality 0");
  }
  MyMatrix res_matrix = transpose().calc_complements();
  res_matrix.mul_number(1 / determinant());
  return res_matrix;
}
MyMatrix MyMatrix::operator+(const MyMatrix& other) {
  sum_matrix(other);
  return *this;
}
MyMatrix MyMatrix::operator-(const MyMatrix& other) {
  sub_matrix(other);
  return *this;
}
MyMatrix& MyMatrix::operator+=(const MyMatrix& other) {
  this->sum_matrix(other);
  return *this;
}
MyMatrix& MyMatrix::operator-=(const MyMatrix& other) {
  sub_matrix(other);
  return *this;
}
MyMatrix& MyMatrix::operator*=(const MyMatrix& other) {
  mul_matrix(other);
  return *this;
}
MyMatrix& MyMatrix::operator*=(const double num) {
  mul_number(num);
  return *this;
}
bool MyMatrix::operator==(const MyMatrix& other) { return eq_matrix(other); }
MyMatrix MyMatrix::operator*(const MyMatrix& other) {
  mul_matrix(other);
  return *this;
}

MyMatrix MyMatrix::operator*(const double num) {
  mul_number(num);
  return *this;
}

MyMatrix& MyMatrix::operator=(const MyMatrix& other) {
  if (other._rows != _rows || other._cols != _cols) {
    deleteMatrix();
    _rows = other._rows;
    _cols = other._cols;
    allocateMatrix();
  }
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      _matrix[i][j] = other._matrix[i][j];
    }
  }
  return *this;
}

double& MyMatrix::operator()(int row, int col) {
  if ((row < 0 || row >= _rows) || (col < 0 || col >= _cols)) {
    throw std::out_of_range("index is outside the matrix");
  }
  return _matrix[row][col];
}
double MyMatrix::operator()(int row, int col) const {
  if ((row < 0 || row >= _rows) || (col < 0 || col >= _cols)) {
    throw std::out_of_range("index is outside the matrix");
  }
  return _matrix[row][col];
}

int MyMatrix::getRows() { return _rows; }
int MyMatrix::getCols() { return _cols; }

void MyMatrix::setRows(int rows) {
  MyMatrix result(*this);
  deleteMatrix();
  if (rows < _rows) {
    _rows = rows;
  }
  _matrix = new double*[rows];
  for (int i = 0; i < rows; i++) {
    _matrix[i] = new double[_cols]();
  }
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      _matrix[i][j] = result._matrix[i][j];
    }
  }
  _rows = rows;
}
void MyMatrix::setCols(int cols) {
  MyMatrix result(*this);
  deleteMatrix();
  if (cols < _cols) {
    _cols = cols;
  }
  _matrix = new double*[_rows];
  for (int i = 0; i < _rows; i++) {
    _matrix[i] = new double[cols]();
  }
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      _matrix[i][j] = result._matrix[i][j];
    }
  }
  _cols = cols;
}
