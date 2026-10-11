# TxtIntr — Практическое задание 2

Реализация интерфейса с параметрами в командной строке.
Вариант 5 — статистический калькулятор.

## Поддерживаемые операции

- `average` — среднее арифметическое
- `median` — медиана

Количество операндов: от 5 до 7.

## Структура проекта

calculator/
├── main.cpp
├── Makefile
└── .gitignore

## Сборка

cd calculator
make

## Примеры запуска

./calculator -o average 10 20 30 40 50
./calculator -o median 1 2 3 4 5 6
./calculator -o median 7 1 5 3 9 2 4
./calculator -h

## Ссылка на репозиторий

https://github.com/mikseek/TxtIntr
