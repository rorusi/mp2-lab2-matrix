#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> cm(m);

	EXPECT_EQ(m, cm);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(5);

	EXPECT_EQ(m.size(), 5);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(5);
	m[0][1] = 3;
	EXPECT_EQ(m[0][1], 3);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-1][0] = 3);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m[6][0] = 3);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(5);
	m[0][3] = 2;
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	size_t size = 3;
	TDynamicMatrix<int> m1(size), m2(size);
	m1[1][2] = 5;
	m2 = m1;
	EXPECT_EQ(m2, m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	size_t size1 = 3, size2 = 4;
	TDynamicMatrix<int> m1(size1), m2(size2);
	m1[1][2] = 5;
	m2 = m1;
	EXPECT_EQ(m2.size(), size1);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	size_t size1 = 3, size2 = 4;
	TDynamicMatrix<int> m1(size1), m2(size2);
	m1[1][2] = 5;
	m2 = m1;
	EXPECT_EQ(m2, m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	size_t size = 3;
	TDynamicMatrix<int> m1(size), m2(size);
	m1[1][2] = 5;
	m2[1][2] = 5;
	EXPECT_EQ(m1 == m2, true);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	size_t size = 3;
	TDynamicMatrix<int> m1(size);
	m1[1][2] = 5;
	EXPECT_EQ(m1 == m1, true);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	size_t size1 = 3, size2 = 4;
	TDynamicMatrix<int> m1(size1), m2(size2);
	m1[1][2] = 5;
	m2[1][2] = 5;
	EXPECT_EQ(m1==m2, false);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	size_t size = 3;
	TDynamicMatrix<int> m1(size), m2(size), m3(size), m4(size);
	m1[1][2] = 5; m1[0][0] = 1;
	m2[1][2] = 3; m2[2][2] = 5;
	m3 = m1 + m2;
	m4[1][2] = 8; m4[0][0] = 1; m4[2][2] = 5;
	EXPECT_EQ(m3, m4);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	size_t size1 = 3, size2 = 4;
	TDynamicMatrix<int> m1(size1), m2(size2);
	m1[1][2] = 5;
	m2[1][2] = 5;
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	size_t size = 3;
	TDynamicMatrix<int> m1(size), m2(size), m3(size), m4(size);
	m1[1][2] = 5; m1[0][0] = 1;
	m2[1][2] = 3; m2[2][2] = 5;
	m3 = m1 - m2;
	m4[1][2] = 2; m4[0][0] = 1; m4[2][2] = -5;
	EXPECT_EQ(m3, m4);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	size_t size1 = 3, size2 = 4;
	TDynamicMatrix<int> m1(size1), m2(size2);
	m1[1][2] = 5;
	m2[1][2] = 5;
	ASSERT_ANY_THROW(m1 - m2);
}

