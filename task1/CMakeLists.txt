cmake_minimum_required(VERSION 3.10)
project(VotingSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем все исходные файлы
add_executable(voting_system
    main.cpp
    voting.cpp
)
