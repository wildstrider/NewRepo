#pragma once
#include <iostream>

template <typename T> void fillrand(T** arr, int rows, int cols, T x);

template <typename T> void fillrand(T** arr, int rows, int cols, T x)
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			arr[i][j] = x;
		}
	}

}