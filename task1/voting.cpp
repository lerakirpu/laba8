#include "voting.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>

size_t VotingSystem::customHash(const std::string& surname) const {
    size_t hash = 0;
    const size_t prime = 31;  // Простое число для хеширования
    
    for (char c : surname) {
        // Преобразуем символ в нижний регистр и добавляем в хеш
        hash = hash * prime + static_cast<size_t>(tolower(c));
    }
    
    return hash;
}

void VotingSystem::enrolled(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filePath << std::endl;
        return;
    }

    std::string surname;
    while (std::getline(file, surname)) {
        if (surname.empty()) continue;
        
        size_t hash = customHash(surname);
        
        if (votedHashes.find(hash) != votedHashes.end()) {
            duplicateCount++;
            std::cout << "Дубликат: " << surname << std::endl;
        } else {
            votedHashes.insert(hash);
            votedSurnames.push_back(surname);
            std::cout << "Добавлен: " << surname << std::endl;
        }
    }
    
    file.close();
}

void VotingSystem::unenrolled(const std::string& surname) {
    if (surname.empty()) return;
    
    size_t hash = customHash(surname);
    
    if (votedHashes.find(hash) != votedHashes.end()) {
        duplicateCount++;
        std::cout << "Дубликат: " << surname << std::endl;
    } else {
        votedHashes.insert(hash);   // Добавляем хеш в множество
        votedSurnames.push_back(surname);   // Добавляем фамилию в вектор
        std::cout << "Добавлен: " << surname << std::endl;
    }
}

void VotingSystem::printResults() const {
    std::cout << "\nРезультаты голосования:\n";
    std::cout << "Количество дубликатов: " << votedSurnames.size() << std::endl;
    std::cout << "Количество голосующих: " << duplicateCount << std::endl;
    std::cout << "Фамилии голосующих:\n";
    
    for (const auto& surname : votedSurnames) {
        std::cout << "- " << surname << std::endl;
    }
}
