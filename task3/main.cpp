#include "task3.h"
#include <iostream>

int main() {
    try {
        const std::string imagePath = "kkk.jpg";
        const std::string outputFile = "output.txt";
        
        ImageHash imageHash(imagePath); // Создаем объект для работы с хешем изображения
        
        std::string originalHash = imageHash.calculateSHA256();  // Вычисляем и выводим исходный хеш изображения
        std::cout << "Original Image SHA256: " << originalHash << "\n";
        
        imageHash.modifySinglePixel();   //  Модифицируем один пиксель в изображении
        
        std::string modifiedHash = imageHash.calculateSHA256();   // Вычисляем и выводим хеш измененного изображения
        std::cout << "Modified Image SHA256: " << modifiedHash << "\n";
        
        // Сравниваем хеши до и после изменения
        bool hashesMatch = (originalHash == modifiedHash);
        std::cout << "Hashes Match: " << (hashesMatch ? "Yes" : "No") << "\n";
        
        // Сохраняем результаты в файл
        imageHash.saveResultsToFile(outputFile, originalHash, modifiedHash, hashesMatch);
        std::cout << "Results saved to " << outputFile << "\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    
    return 0;
}
