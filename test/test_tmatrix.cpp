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
	TDynamicMatrix<int> m(2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			m[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> n = m;
	EXPECT_EQ(n, m);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
		m[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> n = m;
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(4);

	EXPECT_EQ(4, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(2);
	ASSERT_NO_THROW(m[0][0] = 3);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(2);
	ASSERT_ANY_THROW(m[-2][0] = 3);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(2);
	ASSERT_ANY_THROW(m[10000][0] = 3);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m;
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m;
	TDynamicMatrix<int> n;
	ASSERT_NO_THROW(m = n);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> n(2);
	m = n;
	EXPECT_EQ(m.size(), n.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> n(2);
	ASSERT_NO_THROW(m = n);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(4), n(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			m[i][j] = n[i][j] = i;
	}
	EXPECT_TRUE(m == n);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(4);
	for (int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++)
		m[i][j] = i;
	}
	EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(4), n(7);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			m[i][j] = n[i][j] = i;
	}
	EXPECT_FALSE(m == n);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> n(3);
	ASSERT_NO_THROW(m + n);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> n(2);
	ASSERT_ANY_THROW(m + n);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> n(3);
	ASSERT_NO_THROW(m * n);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> n(2);
	ASSERT_ANY_THROW(m * n);
}

