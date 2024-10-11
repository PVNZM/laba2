#include "functions.h"

int main() {
    int taskChoice;
    char continueResponse;

    do {
        std::cout << "Задача 1: Обработка списка целых чисел" << std::endl;
        std::cout << "Задача 2: Добавление средних элементов в дек" << std::endl;
        std::cout << "Задача 3: Удаление элементов с нечетными порядковыми номерами" << std::endl;
        std::cout << "Задача 4: Фильтрация слов из файла по длине" << std::endl;
        std::cout << "Задача 5: Удаление элементов между первым и вторым отрицательными" << std::endl;
        std::cout << "Задача 6: Добавление последовательностей в дек" << std::endl;
        std::cout << "Задача 7: Нахождение средних элементов вектора" << std::endl;
        std::cout << "Задача 8: Применение парного среднего месечения" << std::endl;
        std::cout << "Задача 9: Подсчет векторов, содержащих все элементы V0" << std::endl;
        std::cout << "Задача 10: Группировка слов по последней букве" << std::endl;
        std::cout << "Выберите задачу (1-10): ";
        std::cin >> taskChoice;

        switch (taskChoice) {
            case 1: {
                int N;
                std::cout << "Введите количество целых чисел (делится на 3): ";
                std::cin >> N;

                // Проверяем, что введенное количество положительно и делится на 3
                if (N <= 0 || N % 3 != 0) {
                    std::cerr << "Ошибка: количество чисел должно быть положительным и делиться на 3." << std::endl;
                    return 1;
                }

                std::vector<int> numbers(N);
                std::cout << "Введите " << N << " целых чисел: ";

                for (int i = 0; i < N; ++i) {
                    std::cin >> numbers[i];
                }

                process_numbers(numbers);

                break;
            }
            case 2: {
                std::deque<int> D;
                int size;

                // Проверка на нечетное количество элементов, больше или равное 5
                do {
                    std::cout << "Введите количество элементов дека (нечетное и >= 5): ";
                    std::cin >> size;
                } while (size < 5 || size % 2 == 0); // Повторяем ввод, пока условие не выполнено

                D.resize(size);
                std::cout << "Введите элементы дека: ";
                std::copy_n(std::istream_iterator<int>(std::cin), size, D.begin());
                add_middle_elements_to_deque(D);
                break;
            }
            case 3: {
                std::vector<int> V;
                int size;
                std::cout << "Введите количество элементов вектора: ";
                std::cin >> size;
                V.resize(size);
                std::cout << "Введите элементы вектора: ";
                std::copy_n(std::istream_iterator<int>(std::cin), size, V.begin());
                remove_odd_indexed_elements(V);
                std::cout << "Вектор после удаления элементов с нечетными порядковыми номерами: ";
                for (int num : V) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
                break;
            }
            case 4: {
                std::string input_file = "name1.txt"; 
                std::string output_file = "name2.txt"; 
                int K;  

                std::cout << "Введите максимальную длину слова (K): ";
                std::cin >> K;  // Ввод значения K с клавиатуры

                if (K < 0) { // Проверка на отрицательное значение
                    std::cerr << "Длина слова не может быть отрицательной." << std::endl;
                    return 1; // Завершение программы с ошибкой
                }

                // Вызов функции для фильтрации
                filter_words_by_length(input_file, output_file, K);
    
                std::cout << "Фильтрация завершена. Проверьте файл: " << output_file << std::endl;

                return 0;

            }
            case 5: {
                std::list<int> L;
                std::cout << "Введите числа (введите 'end' для завершения ввода):" << std::endl;

                // Считываем числа до тех пор, пока не будет введено 'end'
                std::string input;
                while (std::cin >> input && input != "end") {
                    try {
                        int number = std::stoi(input);
                        L.push_back(number);
                    } catch (...) {
                        std::cerr << "Ошибка: введите целое число или 'end' для завершения." << std::endl;
                    }
                }

                // Вызов функции для удаления элементов между отрицательными
                remove_between_negatives(L);

                // Вывод результата
                std::cout << "Результат:" << std::endl;
                for (int num : L) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;

                break;
            }
            case 6: {
                int N;
                std::cout << "Введите число N (> 0): ";
                std::cin >> N;

                if (N <= 0) {
                    std::cerr << "Ошибка: N должно быть больше 0." << std::endl;
                    return 1;
                }

                std::deque<int> D;
    
                // Заполнение дека
                fill_deque(N, D);

                // Вывод содержания дека
                std::cout << "Содержимое дека: ";
                for (int num : D) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;

                break;
            }
            case 7: {
                int N;
                std::cout << "Введите количество элементов в векторе (нечетное и >= 3): ";
                std::cin >> N;

                if (N < 3 || N % 2 == 0) {
                    std::cerr << "Ошибка: количество элементов должно быть нечетным и >= 3." << std::endl;
                    return 1;
                }

                std::vector<int> V(N);
                std::cout << "Введите элементы вектора: ";
                for (int i = 0; i < N; ++i) {
                    std::cin >> V[i];
                }

                int prev, mid, next;

                // Находим средние элементы
                find_middle_elements(V, prev, mid, next);

                // Выводим результаты
                std::cout << "Средние элементы: " << prev << ", " << mid << ", " << next << std::endl; 

                break;
            }
            case 8: {
                int N;
                std::cout << "Введите количество элементов в списке (не менее 2): ";
                std::cin >> N;

                if (N < 2) {
                    std::cerr << "Ошибка: количество элементов должно быть не менее 2." << std::endl;
                    return 1;
                }

                std::list<int> L;
                std::cout << "Введите элементы списка: ";
                for (int i = 0; i < N; ++i) {
                    int value;
                    std::cin >> value;
                    L.push_back(value);
                }

                std::vector<double> V; // Вектор для хранения результатов

                // Заполняем вектор средними арифметическими
                calculate_pairwise_means(L, V);

                // Выводим результаты
                std::cout << "Средние арифметические: ";
                for (double mean : V) {
                    std::cout << mean << " ";
                }
                std::cout << std::endl;

                break;
            }
            case 9: {
                int sizeV0;
                std::cout << "Введите количество элементов в векторе V0: ";
                std::cin >> sizeV0;

                std::vector<int> V0(sizeV0);
                std::cout << "Введите элементы вектора V0: ";
                for (int i = 0; i < sizeV0; i++) {
                    std::cin >> V0[i];
                }

                int N;
                std::cout << "Введите количество векторов (N): ";
                std::cin >> N;

                // проверяем, что N больше 0
                if (N <= 0) {
                    std::cout << "Количество векторов должно быть больше 0." << std::endl;
                    return 1; // Завершаем программу с ошибкой
                }

                std::vector<std::vector<int>> vectors(N);
                for (int i = 0; i < N; i++) {
                    int sizeVi;
                    std::cout << "Введите количество элементов в векторе V" << (i + 1) << ": ";
                    std::cin >> sizeVi;

                    // проверяем, что sizeVi больше 0
                    if (sizeVi <= 0) {
                        std::cout << "Количество элементов в векторе должно быть больше 0." << std::endl;
                        return 1; // Завершаем программу с ошибкой
                    }

                    vectors[i].resize(sizeVi);
                    std::cout << "Введите элементы вектора V" << (i + 1) << ": ";
                    for (int j = 0; j < sizeVi; j++) {
                        std::cin >> vectors[i][j];
                    }
                }

                int count = count_vectors_containing_all_elements(V0, vectors);
                std::cout << "Количество векторов, содержащих все элементы V0: " << count << std::endl;

                break;

            }
            case 10: {
                int n;
                std::cout << "Введите количество английских слов (все заглавные): ";
                std::cin >> n;
                std::vector<std::string> V(n);
                std::cout << "Введите " << n << " английских слов: ";
                for (int i = 0; i < n; i++) {
                    std::cin >> V[i];
                }

                group_words_by_last_letter(V);
                break;
            }
        }

        std::cout << "Хотите продолжить работу? (y/n): ";
        std::cin >> continueResponse;

    } while (continueResponse == 'y' || continueResponse == 'Y');

    std::cout << "Спасибо за использование программы!" << std::endl;
    return 0;
}
