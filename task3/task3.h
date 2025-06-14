#ifndef TASK3_H
#define TASK3_H

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

class ImageHash {
public:
    ImageHash(const std::string& imagePath);
    
    std::string calculateSHA256();
    void modifySinglePixel();
    void saveResultsToFile(const std::string& filename,
        const std::string& originalHash, 
        const std::string& modifiedHash, 
        bool hashesMatch);
    
    const cv::Mat& getImage() const { return image; }

private:
    cv::Mat image;
    std::string imagePath;
    
    std::vector<unsigned char> imageToBytes() const;
    static std::string bytesToHexString(const unsigned char* data, size_t length);
};

#endif 