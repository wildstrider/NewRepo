#pragma once

template <typename T> void push_rows_front(T**& arr, int& rows, int cols);
template <typename T> void push_rows_back(T**& arr, int& rows, int cols);
template <typename T> void insert_rows(T**& arr, int& rows, int cols);
template <typename T> void Add_rows(T**& arr, int& rows, int cols);

template <typename T> void pop_rows_front(T**& arr, int& rows, int cols);
template <typename T> void pop_rows_back(T**& arr, int& rows, int cols);
template <typename T> void erase_rows(T**& arr, int& rows, int cols, int index);
template <typename T> void Delete_rows(T**& arr, int& rows, int cols);
template <typename T> void rows_arr(T**& arr, int rows, int cols);