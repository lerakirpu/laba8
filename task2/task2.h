#ifndef TASK2_H
#define TASK2_H

#include <string>
#include <vector>
#include <list>
#include <utility>

class HashTable {
private:
    static const int DEFAULT_SIZE = 10;
    std::vector<std::list<std::pair<std::string, double>>> table;
    int currentSize;

    size_t hashFunction(const std::string& key) const;

public:
    HashTable(int size = DEFAULT_SIZE);
    
    void insert(const std::string& key, double value);
    bool remove(const std::string& key);
    bool find(const std::string& key, double& value) const;
    bool isEmpty() const;
    int size() const;
};

#endif 
