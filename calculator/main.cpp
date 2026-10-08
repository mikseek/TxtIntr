#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>

void printHelp() {
    std::cout << "Использование: calculator [опции] <числа...>\n"
              << "Опции:\n"
              << "  -o, --operation <тип>  Тип операции (average, median)\n"
              << "  -h, --help             Показать эту справку\n"
              << "Пример: calculator -o average 10 20 30 40 50\n"
              << "Примечание: Количество операндов должно быть от 5 до 7.\n";
}

int main(int argc, char* argv[]) {
    std::string operation;
    std::vector<double> operands;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-h" || arg == "--help") {
            printHelp();
            return 0;
        } else if (arg == "-o" || arg == "--operation") {
            if (i + 1 < argc) {
                operation = argv[++i];
            } else {
                std::cerr << "Ошибка: Не указан тип операции после " << arg << std::endl;
                return 1;
            }
        } else {
            try {
                operands.push_back(std::stod(arg));
            } catch (...) {
                std::cerr << "Ошибка: Некорректное число '" << arg << "'" << std::endl;
                return 1;
            }
        }
    }

    if (operation.empty()) {
        std::cerr << "Ошибка: Не задана операция. Используйте -h для справки." << std::endl;
        return 1;
    }

    if (operands.size() < 5 || operands.size() > 7) {
        std::cerr << "Ошибка: Для статистических операций требуется от 5 до 7 операндов. Введено: " 
                  << operands.size() << std::endl;
        return 1;
    }

    double result = 0.0;

    if (operation == "average" || operation == "avg") {
        double sum = std::accumulate(operands.begin(), operands.end(), 0.0);
        result = sum / operands.size();
    } 
    else if (operation == "median" || operation == "med") {
        std::vector<double> sorted_ops = operands;
        std::sort(sorted_ops.begin(), sorted_ops.end());
        
        size_t n = sorted_ops.size();
        if (n % 2 == 0) {
            result = (sorted_ops[n/2 - 1] + sorted_ops[n/2]) / 2.0;
        } else {
            result = sorted_ops[n/2];
        }
    } 
    else {
        std::cerr << "Ошибка: Неизвестная операция '" << operation << "'" << std::endl;
        return 1;
    }

    std::cout << "Результат операции '" << operation << "': " << result << std::endl;
    return 0;
}
