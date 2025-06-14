#include "task2.h"
#include <algorithm>

HashTable::HashTable(int size) : table(size), currentSize(0) {}

size_t HashTable::hashFunction(const std::string& key) const {
    size_t hash = 0; 
    for (char ch : key) {   // Проходим по каждому символу строки
        hash = hash * 31 + ch;   // Обновляем хеш-значение
    }
    return hash % table.size();
}

void HashTable::insert(const std::string& key, double value) {
    size_t index = hashFunction(key);
    auto& chain = table[index];  // Вычисляем индекс
    
    // Проверяем, существует ли уже такой ключ
    for (auto& pair : chain) {
        if (pair.first == key) {
            pair.second = value; // Обновляем значение
            return;
        }
    }
    
    // Если ключ не найден, добавляем новую пару
    chain.emplace_back(key, value);
    currentSize++;
}

bool HashTable::remove(const std::string& key) {
    size_t index = hashFunction(key);
    auto& chain = table[index];
    
    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->first == key) {
            chain.erase(it); // Удаление элемента
            currentSize--;   // Уменьшение счетчика
            return true;    // Успешное удаление
        }
    }
    
    return false;
}

bool HashTable::find(const std::string& key, double& value) const {
    size_t index = hashFunction(key);
    const auto& chain = table[index];
    
    for (const auto& pair : chain) {
        if (pair.first == key) {
            value = pair.second;  // Записываем найденное значение
            return true;
        }
    }
    
    return false;
}

bool HashTable::isEmpty() const {
    return currentSize == 0;  // Проверка на пустоту
}

int HashTable::size() const {
    return currentSize;  // Возвращает количество элементов
} 
