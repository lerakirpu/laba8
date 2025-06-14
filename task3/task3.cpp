#include "task3.h"
#include <openssl/sha.h>
#include <fstream>
#include <iomanip>
#include <iostream>

ImageHash::ImageHash(const std::string& imagePath) : imagePath(imagePath) {
    image = cv::imread(imagePath, cv::IMREAD_COLOR); // Загрузка изображения по переданному пути
    if (image.empty()) {
        throw std::runtime_error("Could not open or find the image");
    }
}

std::string ImageHash::calculateSHA256() {
    auto bytes = imageToBytes(); // Преобразование изображения в массив байт
    
    unsigned char hash[SHA256_DIGEST_LENGTH];  // Буфер для хранения хеша
    SHA256(bytes.data(), bytes.size(), hash); // Вычисление SHA-256 хеша
    
    return bytesToHexString(hash, SHA256_DIGEST_LENGTH);
}

void ImageHash::modifySinglePixel() {
    if (image.total() > 0) {
        cv::Vec3b& pixel = image.at<cv::Vec3b>(0, 0);  // Получение ссылки на первый пиксель изображения
        pixel[0] = (pixel[0] + 1) % 256;    // Значение изменяется по модулю 256 для избежания переполнения
    } 
}

void ImageHash::saveResultsToFile(const std::string& filename,
    const std::string& originalHash, 
    const std::string& modifiedHash, 
    bool hashesMatch) {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::runtime_error("Could not open output file");
    }
    
    outFile << "Original Image SHA256: " << originalHash << "\n"
            << "Modified Image SHA256: " << modifiedHash << "\n"
            << "Hashes Match: " << (hashesMatch ? "Yes" : "No") << "\n";
}

std::vector<unsigned char> ImageHash::imageToBytes() const {
    std::vector<unsigned char> bytes;

    // Если данные изображения хранятся непрерывно в памяти
    if (image.isContinuous()) {

        // Копируем все байты изображения сразу
        bytes.assign(image.data, image.data + image.total() * image.elemSize());
    } else {

        // Если данные не непрерывны, копируем построчно
        for (int i = 0; i < image.rows; ++i) {
            bytes.insert(bytes.end(), image.ptr(i), image.ptr(i) + image.cols * image.elemSize());
        }
    }
    return bytes;
}

std::string ImageHash::bytesToHexString(const unsigned char* data, size_t length) {
    std::stringstream ss;
    ss << std::hex << std::setfill('0');  // Настройка вывода в hex с ведущими нулями
    for (size_t i = 0; i < length; ++i) {    // Преобразование каждого байта в двузначное hex-значение
        ss << std::setw(2) << static_cast<unsigned>(data[i]);
    }
    return ss.str();
}