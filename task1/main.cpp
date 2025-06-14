#include "voting.h"
#include <iostream>
#include <string>

int main() {
    VotingSystem votingSystem;  // Создаем объект системы голосования
    
    // Обработка файла с фамилиями
    std::cout << "Чтение файла students.txt..." << std::endl;
    votingSystem.enrolled("students.txt");   // Метод enrolled для загрузки фамилий из файла
    std::cout << "Прочитано фамилий: " << votingSystem.getVotedCount() << std::endl;
    std::cout << "Найдено дубликатов: " << votingSystem.getDuplicateCount() << std::endl;
    
    // Ввод фамилий с клавиатуры
    std::string input;
    while (true) {
        std::cout << "Введите фамилию (или 'end' для завершения): ";
        std::getline(std::cin, input);
        
        // Проверяем, не ввел ли пользователь команду завершения
        if (input == "end") {
            break;
        }
        
        if (input.empty()) {
            std::cout << "Пустая строка игнорируется" << std::endl;
        }
        
        votingSystem.unenrolled(input);  // Добавляем фамилию в систему через метод unenrolled
    }
    
    // Вывод результатов
    votingSystem.printResults();
    
    return 0;
}
