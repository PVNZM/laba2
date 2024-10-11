#include <deque>
#include <list>
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <vector>
// Функция для обработки списка и вывода его частей
void process_numbers(const std::vector<int>& numbers);

// Функция для добавления средних элементов в дек
void add_middle_elements_to_deque(std::deque<int>& D);

// Функция для удаления элементов с нечетными порядковыми номерами
void remove_odd_indexed_elements(std::vector<int>& V);

// Функция для записи слов из файла в другой файл по длине
void filter_words_by_length(const std::string& inputFileName, const std::string& outputFileName, int K);

// Функция для удаления элементов между первым и вторым отрицательными элементами
void remove_between_negatives(std::list<int>& L);

// Функция для добавления последовательностей в дек
void fill_deque(int N, std::deque<int>& D);
// Функция для нахождения средних элементов вектора
void find_middle_elements(const std::vector<int>& V, int& prev, int& mid, int& next);

// Функция для получения вектора средних арифметических значений
void calculate_pairwise_means(const std::list<int>& L, std::vector<double>& V);

// Функция для подсчета количества векторов, содержащих все элементы V0
int count_vectors_containing_all_elements(const std::vector<int>& V0, const std::vector<std::vector<int>>& vectors);

// Новая функция для группировки слов по последней букве
void group_words_by_last_letter(const std::vector<std::string>& words);
