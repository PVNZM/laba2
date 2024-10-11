#include "functions.h"
#include <iostream>
#include <numeric> // Добавили для доступа к std::adjacent_difference
#include <map>

void process_numbers(const std::vector<int>& numbers) {
    size_t size = numbers.size();

    // Проверяем, что количество чисел делится на 3
    if (size % 3 != 0) {
        std::cerr << "Ошибка: количество чисел должно делиться на 3." << std::endl;
        return;
    }

    size_t third = size / 3;

    // Первая треть (оригинальный порядок)
    for (size_t i = 0; i < third; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl; // Перенос строки

    // Вторая треть (обратный порядок)
    for (size_t i = third; i < 2 * third; ++i) {
        std::cout << numbers[2 * third - (i - third + 1)] << " ";
    }
    std::cout << std::endl; // Перенос строки

    // Последняя треть (обратный порядок)
    for (size_t i = 2 * third; i < 3 * third; ++i) {
        std::cout << numbers[3 * third - (i - 2 * third + 1)] << " ";
    }
    std::cout << std::endl; // Перенос строки
}

void add_middle_elements_to_deque(std::deque<int>& D) {
    // Определяем индекс среднего элемента
    int middleIndex = D.size() / 2;

    // Собираем 5 средних элементов
    std::vector<int> middleElements;
    for (int i = middleIndex - 2; i <= middleIndex + 2; ++i) {
        middleElements.push_back(D[i]);
    }

    // Добавляем средние элементы в начало дека
    D.insert(D.begin(), middleElements.begin(), middleElements.end()); // Используем один вызов insert

    // Выводим результат
    std::cout << "Дек после добавления средних элементов: ";
    for (const auto& elem : D) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void remove_odd_indexed_elements(std::vector<int>& V) {
    auto i = V.begin(); // Устанавливаем итератор на начало вектора
    int count = 1; // Счетчик для порядкового номера элемента

    while (i != V.end()) {
        if (count % 2 != 0) { // Если порядковый номер нечетный
            i = V.erase(i); // Удаляем элемент и обновляем итератор
        } else {
            ++i; // Переходим к следующему элементу
        }
        ++count; // Увеличиваем порядковый номер
    }
}

void filter_words_by_length(const std::string& inputFileName, const std::string& outputFileName, int K) {
    std::ifstream infile(inputFileName);
    if (!infile) {  
        std::cerr << "Ошибка при открытии файла для чтения: " << inputFileName << std::endl;
        return;  
    }

    std::ofstream outfile(outputFileName);
    if (!outfile) {  
        std::cerr << "Ошибка при открытии файла для записи: " << outputFileName << std::endl;
        infile.close();  
        return;  
    }

    std::string word;
    bool has_written = false;
    std::cout << "Начинаем чтение слов из файла: " << inputFileName << std::endl;

    while (infile >> word) {
        std::cout << "Читаем слово: " << word << std::endl;
        if (word.size() <= K) {
            if (outfile << word << " ") {  // Проверка успешности записи
                has_written = true;
                std::cout << "Записали слово: " << word << std::endl;  // Отладочное сообщение
            } else {
                std::cerr << "Ошибка при записи слова: " << word << std::endl; // Сообщение об ошибке
            }
        }
    }

    if (!has_written) {
        std::cout << "Не найдено слов подходящей длины в файле." << std::endl;
    } else {
        std::cout << "Запись завершена. Проверьте файл: " << outputFileName << std::endl;
    }

    infile.close();
    outfile.close();
}

void remove_between_negatives(std::list<int>& L) {
    // Шаг 1: Найти первый отрицательный элемент
    auto first_neg = std::find_if(L.begin(), L.end(), [](int x) { return x < 0; });

    // Если нет отрицательных элементов, завершаем
    if (first_neg == L.end()) {
        return;
    }

    // Шаг 2: Найти второй отрицательный элемент
    auto second_neg = std::find_if(std::next(first_neg), L.end(), [](int x) { return x < 0; });

    if (second_neg != L.end()) {
        // Удаляем элементы между первым и вторым отрицательными элементами (не включая их)
        L.erase(std::next(first_neg), second_neg);
    } else {
        // Если второй отрицательный элемент не найден,
        // удаляем все элементы после первого отрицательного
        L.erase(std::next(first_neg), L.end());
    }
}
struct Sequence {
    int current;
    Sequence() : current(1) {}
    
    int operator()() {
        return current++;
    }
};

struct BackwardSequence {
    int current;
    BackwardSequence(int start) : current(start) {}
    
    int operator()() {
        return current--;
    }
};
void fill_deque(int N, std::deque<int>& D) {
    // Добавляем последовательность 1, 2, ..., N в дек
    Sequence seq;
    std::generate_n(std::back_inserter(D), N, seq);
    
    // Добавляем последовательность N, N-1, ..., 1 в дек
    BackwardSequence backward_gen(N);
    std::generate_n(std::back_inserter(D), N, backward_gen);
}

void find_middle_elements(const std::vector<int>& V, int& prev, int& mid, int& next) {
    if (V.size() < 3 || V.size() % 2 == 0) {
        throw std::invalid_argument("Вектор должен иметь нечетное количество элементов и не менее 3.");
    }

    std::vector<int> sorted_V = V; // Создаем копию вектора для сортировки
    std::sort(sorted_V.begin(), sorted_V.end()); // Сортируем вектор

    // Находим индекс центрального элемента
    int mid_index = sorted_V.size() / 2;

    // Центральный элемент
    mid = sorted_V[mid_index];

    // Находим элемент перед центральным
    prev = *std::max_element(sorted_V.begin(), sorted_V.begin() + mid_index);

    // Находим элемент после центрального
    next = *std::min_element(sorted_V.begin() + mid_index + 1, sorted_V.end());
}


void calculate_pairwise_means(const std::list<int>& L, std::vector<double>& V) {
    if (L.size() < 2) {
        return; // Вектор не может быть заполнен, если в списке меньше 2 элементов.
    }

    std::vector<int> temp(L.begin(), L.end()); // Копируем список в временный вектор
    std::adjacent_difference(temp.begin(), temp.end(), std::back_inserter(V),
        [](int a, int b) { return (a + static_cast<double>(b)) / 2.0; }); // Считаем среднее

    V.erase(V.begin()); // Удаляем первый элемент, так как он не нужен
}

int count_vectors_containing_all_elements(const std::vector<int>& V0, const std::vector<std::vector<int>>& vectors) {
    std::multiset<int> multisetV0(V0.begin(), V0.end());
    int count = 0;

    for (const auto& v : vectors) {
        std::multiset<int> multisetVi(v.begin(), v.end());
        // Правильный порядок аргументов для std::includes
        if (std::includes(multisetVi.begin(), multisetVi.end(), multisetV0.begin(), multisetV0.end())) {
            count++;
        }
    }

    return count;
}

void group_words_by_last_letter(const std::vector<std::string>& V) {
    std::multimap<char, std::string> M;

    for (const auto& word : V) {
        char lastLetter = word.back();
        M.emplace(lastLetter, word);
    }

    std::cout << "Группировка слов по последней букве:\n";
    for (auto it = M.rbegin(); it != M.rend(); ++it) {
        std::cout << "Ключ: " << it->first << ", Значение: " << it->second << std::endl;
    }
}
