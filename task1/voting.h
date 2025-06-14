#ifndef VOTING_H
#define VOTING_H

#include <string>
#include <vector>
#include <unordered_set>

class VotingSystem {
private:
    std::unordered_set<size_t> votedHashes;
    std::vector<std::string> votedSurnames;
    int duplicateCount = 0;

    size_t customHash(const std::string& surname) const;

public:
    void enrolled(const std::string& filePath);
    void unenrolled(const std::string& surname);
    void printResults() const;
    size_t getVotedCount() const { return votedSurnames.size(); }
    int getDuplicateCount() const { return duplicateCount; }
};

#endif
