# earley_algorithm
 ## Сборка
 - mkdir build && cd build
 - cmake -DBUILD_TESTS=ON .. или cmake .. первая команда, если хотите подключить тестирование
 - make
 - (optional) make coverage - генерирует файл с CodeCoverage index.html, который лежит в build/coverage


## Запуск
- ./bin/LR1_parser запускает программу
- ./bin/Test запускает тестирование
