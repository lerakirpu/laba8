#include <iostream>
#include "task2.h"

int main() {
    HashTable priceTable;

    // Добавляем товары
    priceTable.insert("Гвозди", 27);
    priceTable.insert("Шурупы", 30);
    priceTable.insert("Молток", 700);
    priceTable.insert("Белая краска", 350);

    // Поиск цен
    double price;
    if (priceTable.find("Гвозди", price)) {
        std::cout << "Цена гвоздей: " << price << " руб.\n";
    } else {
        std::cout << "Товар не найден\n";
    }

    // Удаление товара
    if (priceTable.remove("Белая краска")) {
        std::cout << "Краска удалена из прайса\n";
    }

    // Проверка размера таблицы
    std::cout << "Всего товаров в прайсе: " << priceTable.size() << "\n";

    return 0;
}
