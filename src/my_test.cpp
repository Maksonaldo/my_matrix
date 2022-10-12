#include <gtest/gtest.h>

#include "my_matrix_oop.h"

TEST(Test_eq_matrix, Test_1) {
  bool test = false;
  MyMatrix matrix(3, 3);
  MyMatrix matrix2(3, 3);
  matrix.init_matrix_2(312312312.23423);
  matrix2.init_matrix_2(312312312.23423);
  if (matrix2 == matrix) {
    test = true;
  }
  ASSERT_EQ(1, matrix.eq_matrix(matrix2));
  ASSERT_EQ(1, test);
}

TEST(Test_eq_matrix, Test_2) {
  bool test = false;
  MyMatrix matrix(3, 3);
  MyMatrix matrix2(3, 3);
  matrix.init_matrix_2(33.123);
  matrix2.init_matrix_2(33.123);
  if (matrix2 == matrix) {
    test = true;
  }
  ASSERT_EQ(1, matrix.eq_matrix(matrix2));
  ASSERT_EQ(1, test);
}

TEST(Test_eq_matrix, Test_3) {
  bool test = false;
  MyMatrix matrix(3, 6);
  MyMatrix matrix2(3, 6);
  matrix.init_matrix_2(11);
  matrix2.init_matrix_2(11);
  if (matrix2 == matrix) {
    test = true;
  }

  ASSERT_EQ(1, test);
  ASSERT_EQ(1, matrix.eq_matrix(matrix2));
}
TEST(Test_eq_matrix, Test_4) {
  bool test = false;
  MyMatrix matrix(3, 6);
  MyMatrix matrix2(6, 6);
  matrix.init_matrix_2(11);
  matrix2.init_matrix_2(11);
  if (matrix2 == matrix) {
    test = true;
  }

  ASSERT_EQ(0, test);
  ASSERT_EQ(0, matrix.eq_matrix(matrix2));
}

TEST(Test_eq_matrix, Test_5) {
  bool test = false;
  MyMatrix matrix(0, 0);
  MyMatrix matrix2(0, 1);
  matrix.init_matrix_2(999999);
  matrix2.init_matrix_2(999999);
  if (matrix2 == matrix) {
    test = true;
  }
  ASSERT_EQ(0, test);
  ASSERT_EQ(0, matrix.eq_matrix(matrix2));
}
TEST(Test_eq_matrix, Test_6) {
  MyMatrix matrix(3, 3);
  MyMatrix matrix2(3, 3);
  matrix.init_matrix_2(312312312.23423);
  matrix2.init_matrix_2(0);
  ASSERT_EQ(0, matrix.eq_matrix(matrix2));
}
TEST(Test_sum_matrix, Test_1) {
  MyMatrix matrix(4, 4);
  MyMatrix matrix2(4, 4);
  matrix2.init_matrix_2(4543.24);
  matrix.sum_matrix(matrix2);
  ASSERT_EQ(1, matrix.eq_matrix(matrix2));
}

TEST(Test_sum_matrix, Test_2) {
  MyMatrix matrix(12, 12);
  MyMatrix matrix2(12, 12);
  matrix2.init_matrix_2(3423423.23423);
  matrix.sum_matrix(matrix2);
  ASSERT_EQ(1, matrix.eq_matrix(matrix2));
}
TEST(Test_sum_matrix, Test_3) {
  MyMatrix matrix(3, 6);
  MyMatrix matrix2(3, 6);
  matrix2.init_matrix_2(435345.1232);
  matrix = matrix2 + matrix;

  ASSERT_EQ(1, matrix.eq_matrix(matrix2));
}

TEST(Test_sum_matrix, Test_4) {
  MyMatrix matrix(12, 6);
  MyMatrix matrix2(12, 6);
  matrix2.init_matrix_2(543533543.232);
  matrix = matrix2 + matrix;

  ASSERT_EQ(1, matrix.eq_matrix(matrix2));
}
TEST(Test_sum_matrix, Test_5) {
  MyMatrix matrix(12, 6);
  MyMatrix matrix2(12, 6);
  matrix2.init_matrix_2(23423.2342342);
  matrix += matrix2;
  ASSERT_EQ(1, matrix.eq_matrix(matrix2));
}

TEST(Test_sub_matrix, Test_1) {
  MyMatrix matrix(4, 4);
  MyMatrix matrix2(4, 4);
  MyMatrix zero_matrix(4, 4);
  matrix.init_matrix_2(4543.24);
  matrix2.init_matrix_2(4543.24);
  matrix.sub_matrix(matrix2);
  ASSERT_EQ(1, matrix.eq_matrix(zero_matrix));
}

TEST(Test_sub_matrix, Test_2) {
  MyMatrix matrix(12, 12);
  MyMatrix matrix2(12, 12);
  MyMatrix zero_matrix(12, 12);
  matrix.init_matrix_2(3423423.23423);
  matrix2.init_matrix_2(3423423.23423);

  matrix.sub_matrix(matrix2);

  ASSERT_EQ(1, matrix.eq_matrix(zero_matrix));
}
TEST(Test_sub_matrix, Test_3) {
  MyMatrix matrix(3, 6);
  MyMatrix matrix2(3, 6);
  MyMatrix zero_matrix(3, 6);
  matrix.init_matrix_2(435345.1232);
  matrix2.init_matrix_2(435345.1232);
  matrix = matrix2 - matrix;

  ASSERT_EQ(1, matrix.eq_matrix(zero_matrix));
}

TEST(Test_sub_matrix, Test_4) {
  MyMatrix matrix(12, 6);
  MyMatrix matrix2(12, 6);
  MyMatrix zero_matrix(12, 6);
  matrix.init_matrix_2(543533543.232);
  matrix2.init_matrix_2(543533543.232);
  matrix = matrix2 - matrix;

  ASSERT_EQ(1, matrix.eq_matrix(zero_matrix));
}
TEST(Test_sub_matrix, Test_5) {
  MyMatrix matrix(12, 6);
  MyMatrix matrix2(12, 6);
  MyMatrix zero_matrix(12, 6);
  matrix.init_matrix_2(23423.2342342);
  matrix2.init_matrix_2(23423.2342342);
  matrix -= matrix2;

  ASSERT_EQ(1, matrix.eq_matrix(zero_matrix));
}

TEST(Test_mul_matrix, Test_1) {
  MyMatrix matrix(3, 3);
  MyMatrix matrix2(3, 3);
  MyMatrix zero_matrix(3, 3);
  matrix2.init_matrix_2(23423.2342342);
  matrix.mul_matrix(matrix2);
  ASSERT_EQ(1, matrix.eq_matrix(zero_matrix));
}
TEST(Test_mul_matrix, Test_2) {
  MyMatrix matrix(3, 3);
  MyMatrix matrix2(3, 3);
  MyMatrix zero_matrix(3, 3);
  matrix2.init_matrix_2(3);

  matrix = matrix * matrix2;
  ASSERT_EQ(1, matrix.eq_matrix(zero_matrix));
}
TEST(Test_mul_matrix, Test_3) {
  MyMatrix matrix(3, 3);
  MyMatrix matrix2(3, 3);
  MyMatrix zero_matrix(3, 3);
  matrix2.init_matrix_2(3);

  matrix *= matrix2;
  ASSERT_EQ(1, matrix.eq_matrix(zero_matrix));
}
TEST(Test_mul_matrix, Test_4) {
  MyMatrix matrix(3, 5);
  MyMatrix matrix2(5, 5);
  MyMatrix zero_matrix(3, 5);
  matrix2.init_matrix_2(12);
  matrix *= matrix2;
  ASSERT_EQ(1, matrix.eq_matrix(zero_matrix));
}
TEST(Test_mul_number, Test_1) {
  MyMatrix matrix(7, 7);
  MyMatrix zero_matrix(7, 7);
  matrix.mul_number(124543.2131);
  ASSERT_EQ(1, matrix.eq_matrix(zero_matrix));
}
TEST(Test_mul_number, Test_2) {
  MyMatrix matrix(7, 7);
  MyMatrix zero_matrix(7, 7);
  matrix = matrix * 423423.234;
  ASSERT_EQ(1, matrix.eq_matrix(zero_matrix));
}

TEST(Test_mul_number, Test_3) {
  MyMatrix matrix(7, 7);
  MyMatrix zero_matrix(7, 7);
  matrix *= 234234;
  ASSERT_EQ(1, matrix.eq_matrix(zero_matrix));
}

TEST(Test_constr_copy, Test_1) {
  MyMatrix matrix(7, 7);
  matrix.init_matrix_2(3875675.2342);
  MyMatrix matrix2(matrix);

  ASSERT_EQ(1, matrix.eq_matrix(matrix2));
}

TEST(Test_constr_copy, Test_2) {
  MyMatrix matrix(2, 13);
  matrix.init_matrix_2(34534);
  MyMatrix matrix2(matrix);

  ASSERT_EQ(1, matrix.eq_matrix(matrix2));
}

TEST(Test_constr, Test_1) {
  MyMatrix matrix;
  MyMatrix matrix2;

  ASSERT_EQ(1, matrix.eq_matrix(matrix2));
}

TEST(Test_constr, Test_2) {
  MyMatrix matrix;
  MyMatrix matrix2;
  matrix.init_matrix_2(34534.324324);
  matrix2.init_matrix_2(34534.324324);

  ASSERT_EQ(1, matrix.eq_matrix(matrix2));
}

TEST(Test_constr_move, Test_1) {
  MyMatrix matrix2(3, 3);
  matrix2.init_matrix_2(12312.2342);
  MyMatrix matrix3(matrix2);
  MyMatrix matrix(std::move(matrix2));
  ASSERT_EQ(1, matrix3.eq_matrix(matrix));
}

TEST(Test_transpose, Test_1) {
  MyMatrix matrix(3, 3);
  MyMatrix matrix2(3, 3);

  matrix2(0, 0) = 1;
  matrix2(0, 1) = 4;
  matrix2(0, 2) = 7;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 5;
  matrix2(1, 2) = 8;
  matrix2(2, 0) = 3;
  matrix2(2, 1) = 6;
  matrix2(2, 2) = 9;

  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;
  MyMatrix result = matrix.transpose();

  ASSERT_EQ(1, matrix2.eq_matrix(result));
}
TEST(Test_transpose, Test_2) {
  MyMatrix matrix(3, 3);
  MyMatrix matrix2(3, 3);

  matrix2(0, 0) = 3243.23423;
  matrix2(0, 1) = 234423.2323;
  matrix2(0, 2) = 712312;
  matrix2(1, 0) = 345345.234;
  matrix2(1, 1) = 134235;
  matrix2(1, 2) = 8;
  matrix2(2, 0) = 546546.234;
  matrix2(2, 1) = 63423432.12312;
  matrix2(2, 2) = 97465644;

  matrix(0, 0) = 3243.23423;
  matrix(0, 1) = 345345.234;
  matrix(0, 2) = 546546.234;
  matrix(1, 0) = 234423.2323;
  matrix(1, 1) = 134235;
  matrix(1, 2) = 63423432.12312;
  matrix(2, 0) = 712312;
  matrix(2, 1) = 8;
  matrix(2, 2) = 97465644;
  MyMatrix result = matrix.transpose();

  ASSERT_EQ(1, matrix2.eq_matrix(result));
}
TEST(Test_determinant, Test_1) {
  MyMatrix matrix(3, 3);
  double result = 6632438589;
  matrix(0, 0) = 123;
  matrix(0, 1) = 3453;
  matrix(0, 2) = 345;
  matrix(1, 0) = 345;
  matrix(1, 1) = 345;
  matrix(1, 2) = 234;
  matrix(2, 0) = 8896;
  matrix(2, 1) = 5679;
  matrix(2, 2) = 8;
  double matrix_result = matrix.determinant();

  ASSERT_EQ(result, matrix_result);
}
TEST(Test_determinant, Test_2) {
  MyMatrix matrix(3, 3);
  double result = -1;
  matrix(0, 0) = 2;
  matrix(0, 1) = 5;
  matrix(0, 2) = 7;
  matrix(1, 0) = 6;
  matrix(1, 1) = 3;
  matrix(1, 2) = 4;
  matrix(2, 0) = 5;
  matrix(2, 1) = -2;
  matrix(2, 2) = -3;
  double matrix_result = matrix.determinant();
  ASSERT_EQ(result, matrix_result);
}
TEST(Test_determinant, Test_3) {
  MyMatrix matrix(5, 5);
  double result = 0;
  matrix.init_matrix_2(4554);
  double matrix_result = matrix.determinant();
  ASSERT_EQ(result, matrix_result);
}
TEST(Test_calc_complements, Test_1) {
  MyMatrix matrix(3, 3);
  MyMatrix result(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 0;
  matrix(1, 1) = 4;
  matrix(1, 2) = 2;
  matrix(2, 0) = 5;
  matrix(2, 1) = 2;
  matrix(2, 2) = 1;
  MyMatrix matrix_result = matrix.calc_complements();
  result(0, 0) = 0;
  result(0, 1) = 10;
  result(0, 2) = -20;
  result(1, 0) = 4;
  result(1, 1) = -14;
  result(1, 2) = 8;
  result(2, 0) = -8;
  result(2, 1) = -2;
  result(2, 2) = 4;
  ASSERT_EQ(1, result.eq_matrix(matrix_result));
}

TEST(Test_calc_complements, Test_2) {
  MyMatrix matrix(3, 3);
  MyMatrix result(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;
  MyMatrix matrix_result = matrix.calc_complements();
  result(0, 0) = -3;
  result(0, 1) = 6;
  result(0, 2) = -3;
  result(1, 0) = 6;
  result(1, 1) = -12;
  result(1, 2) = 6;
  result(2, 0) = -3;
  result(2, 1) = 6;
  result(2, 2) = -3;
  ASSERT_EQ(1, matrix_result.eq_matrix(matrix_result));
}
TEST(Test_invers, Test_1) {
  MyMatrix matrix(3, 3);
  MyMatrix result(3, 3);
  matrix(0, 0) = 2;
  matrix(0, 1) = 5;
  matrix(0, 2) = 7;
  matrix(1, 0) = 6;
  matrix(1, 1) = 3;
  matrix(1, 2) = 4;
  matrix(2, 0) = 5;
  matrix(2, 1) = -2;
  matrix(2, 2) = -3;
  MyMatrix matrix_result = matrix.inverse_matrix();
  result(0, 0) = 1;
  result(0, 1) = -1;
  result(0, 2) = 1;
  result(1, 0) = -38;
  result(1, 1) = 41;
  result(1, 2) = -34;
  result(2, 0) = 27;
  result(2, 1) = -29;
  result(2, 2) = 24;
  ASSERT_EQ(1, result.eq_matrix(matrix_result));
}
TEST(Test_invers, Test_2) {
  MyMatrix matrix(3, 3);
  MyMatrix result(3, 3);
  matrix(0, 0) = 243;
  matrix(0, 1) = 53;
  matrix(0, 2) = 7.43;
  matrix(1, 0) = 63;
  matrix(1, 1) = 332;
  matrix(1, 2) = 412;
  matrix(2, 0) = 53;
  matrix(2, 1) = -245;
  matrix(2, 2) = -356;
  MyMatrix matrix_result = matrix.inverse_matrix();
  result(0, 0) = 0.00824798;
  result(0, 1) = -0.00815028;
  result(0, 2) = -0.0092602;
  result(1, 0) = -0.0211621;
  result(1, 1) = 0.0415467;
  result(1, 2) = 0.0476405;
  result(2, 0) = 0.0157917;
  result(2, 1) = -0.0298059;
  result(2, 2) = -0.0369739;
  ASSERT_EQ(1, result.eq_matrix(matrix_result));
}
TEST(Test_invers, Test_3) {
  MyMatrix matrix(3, 3);
  MyMatrix result(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = -2;
  matrix(0, 2) = 1;
  matrix(1, 0) = -2;
  matrix(1, 1) = 2;
  matrix(1, 2) = -0.5;
  matrix(2, 0) = 1;
  matrix(2, 1) = -0.5;
  matrix(2, 2) = 0;
  MyMatrix matrix_result = matrix.inverse_matrix();
  result(0, 0) = 1;
  result(0, 1) = 2;
  result(0, 2) = 4;
  result(1, 0) = 2;
  result(1, 1) = 4;
  result(1, 2) = 6;
  result(2, 0) = 4;
  result(2, 1) = 6;
  result(2, 2) = 8;
  ASSERT_EQ(1, result.eq_matrix(matrix_result));
}

TEST(Test_getRows_getCols, Test_1) {
  MyMatrix matrix(3, 3);
  MyMatrix matrix2(0, 0);
  MyMatrix matrix3(6, 1);

  ASSERT_EQ(3, matrix.getRows());
  ASSERT_EQ(3, matrix.getCols());
  ASSERT_EQ(0, matrix2.getRows());
  ASSERT_EQ(0, matrix2.getCols());
  ASSERT_EQ(6, matrix3.getRows());
  ASSERT_EQ(1, matrix3.getCols());
}
TEST(Test_const_operator, Test_1) {
  MyMatrix const matrix(1, 1);
  matrix(0, 0);
}
TEST(Test_setRows_setCols, Test_1) {
  MyMatrix matrix(3, 3);
  MyMatrix result(5, 5);
  result(0, 0) = 76;
  result(0, 1) = 152;
  result(0, 2) = 228;
  result(0, 3) = 0;
  result(0, 4) = 0;
  result(1, 0) = 304;
  result(1, 1) = 380;
  result(1, 2) = 456;
  result(1, 3) = 0;
  result(1, 4) = 0;
  result(2, 0) = 532;
  result(2, 1) = 608;
  result(2, 2) = 684;
  result(2, 3) = 0;
  result(2, 4) = 0;
  result(3, 0) = 0;
  result(3, 1) = 0;
  result(3, 2) = 0;
  result(3, 3) = 0;
  result(3, 4) = 0;
  result(4, 0) = 0;
  result(4, 1) = 0;
  result(4, 2) = 0;
  result(4, 3) = 0;
  result(4, 4) = 0;
  matrix.init_matrix_2(0);
  matrix.setRows(5);
  matrix.setCols(5);

  ASSERT_EQ(1, result.eq_matrix(matrix));
}
TEST(Test_setRows_setCols, Test_2) {
  MyMatrix matrix(3, 3);
  MyMatrix result(1, 1);
  result(0, 0) = 76;
  matrix.init_matrix_2(0);
  matrix.setRows(1);
  matrix.setCols(1);
  ASSERT_EQ(1, result.eq_matrix(matrix));
}

TEST(Test_operator_determinant_throw, Test_10) {
  MyMatrix matrix(1, 1);
  double result = 123;
  matrix(0, 0) = 123;

  double matrix_result = matrix.determinant();
  ASSERT_EQ(matrix_result, result);
}

TEST(Test_operator_eq_throw, Test_8) {
  try {
    MyMatrix matrix(7, 7);
    MyMatrix matrix2(3, 3);
    matrix = matrix2;
  } catch (std::exception& ex) {
    std::cout << ex.what();
  }
}
///
// TEST(Test_throw, Test_1) {
//     try {
//         MyMatrix matrix(-1, -1);
//     } catch (std::exception& ex) {
//         std::cout << ex.what();
//     }
// }
// TEST(Test_throw, Test_2) {
//   try {
//     MyMatrix matrix(4, 4);
//     MyMatrix matrix2(4, 5);
//     matrix2.init_matrix_2(4543.24);
//     matrix.sum_matrix(matrix2);
//   } catch(std::exception& ex) {
//     std::cout << ex.what();
//   }
// }

// TEST(Test_throw, Test_3) {
//   try {
//     MyMatrix matrix(4, 4);
//     MyMatrix matrix2(4, 5);
//     matrix2.init_matrix_2(4543.24);
//     matrix.sub_matrix(matrix2);
//   } catch(std::exception& ex) {
//     std::cout << ex.what();
//   }
// }
// TEST(Test_throw, Test_4) {
//   try {
//     MyMatrix matrix(2, 3);
//     MyMatrix result(2, 3);
//     matrix(0, 0) = 1;
//     matrix(0, 1) = 2;
//     matrix(0, 2) = 3;
//     matrix(1, 0) = 0;
//     matrix(1, 1) = 4;
//     matrix(1, 2) = 2;
//     MyMatrix matrix_result = matrix.calc_complements();
//     result(0, 0) = 0;
//     result(0, 1) = 10;
//     result(0, 2) = -20;
//     result(1, 0) = 4;
//     result(1, 1) = -14;
//     result(1, 2) = 8;
//   } catch(std::exception& ex) {
//     std::cout << ex.what();
//   }
// }
// TEST(Test_throw_invers, Test_5) {
//   try {
//     MyMatrix matrix(3, 3);
//     matrix(0, 0) = 1;
//     matrix(0, 1) = 2;
//     matrix(0, 2) = 3;
//     matrix(1, 0) = 4;
//     matrix(1, 1) = 5;
//     matrix(1, 2) = 6;
//     matrix(2, 0) = 7;
//     matrix(2, 1) = 8;
//     matrix(2, 2) = 9;
//     MyMatrix matrix_result = matrix.inverse_matrix();
//   } catch(std::exception& ex) {
//     std::cout << ex.what();
//   }
// }
// TEST(Test_operator_throw, Test_6) {
//   try {
//     MyMatrix matrix(-7, 7);
//   } catch(std::exception& ex) {
//     std::cout << ex.what();
//   }
// }
// TEST(Test_operator_const_throw, Test_7) {
//   try {
//     MyMatrix const matrix(-7, 7);
//   } catch(std::exception& ex) {
//     std::cout << ex.what();
//   }
// }
// TEST(Test_operator_determinant_throw, Test_9) {
//   try {
//     MyMatrix matrix(2, 3);
//     double result = 6632438589;
//     matrix(0, 0) = 123;
//     matrix(0, 1) = 3453;
//     matrix(0, 2) = 345;
//     matrix(1, 0) = 345;
//     matrix(1, 1) = 345;
//     matrix(1, 2) = 234;
//   double matrix_result = matrix.determinant();
//   } catch(std::exception& ex) {
//     std::cout << ex.what();
//   }
// }
// TEST(Test_mul_throw, Test_11) {
//   try {
//     MyMatrix matrix(3, 5);
//     MyMatrix matrix2(5, 1);
//     matrix2.init_matrix_2(11);
//     matrix.mul_matrix(matrix2);
//   } catch(std::exception& ex) {
//     std::cout << ex.what();
//   }
// }
// TEST(Test_operator_throw, Test_12) {
//   try {
//     MyMatrix matrix(2, 3);
//     matrix(-2, 1) = 0;
//     EXPECT_EQ(1, matrix.eq_matrix(matrix));
//   } catch(std::exception& ex) {
//     std::cout << ex.what();
//   }
// }
// TEST(Test_operator_const_throw, Test_13) {
//   try {
//     MyMatrix const matrix(2, 3);
//     matrix(3, 1);
//   } catch(std::exception& ex) {
//     std::cout << ex.what();
//   }
// }
// TEST(Test_mul_matrix_throw, Test_14) {
//   try {
//     MyMatrix matrix(5, 5);
//     MyMatrix matrix2(3, 5);
//     matrix *= matrix2;
//   } catch(std::exception& ex) {
//     std::cout << ex.what();
//   }
// }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
