cmake_minimum_required(VERSION 3.10)
project(ImageHashComparison)

set(CMAKE_CXX_STANDARD 17)

# Находим необходимые библиотеки
find_package(OpenCV REQUIRED)
find_package(OpenSSL REQUIRED)

# Основной исполняемый файл
add_executable(ImageHashComparison
    main.cpp
    task3.cpp
)

# Подключаем заголовочные файлы
target_include_directories(ImageHashComparison PRIVATE .)

# Линкуем библиотеки
target_link_libraries(ImageHashComparison
    ${OpenCV_LIBS}
    OpenSSL::Crypto
)
