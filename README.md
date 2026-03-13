# **Vending machine emulator by *Gamala/Davydov/Fedorenko***
Консольное приложение на **C++23**, имитирующее работу вендингового автомата. Поддерживает товары разных видов, обработку денежных данных, расчет сдачи, инвентарь и админ-панель.

---
Основные возможности
- **Покупка товаров** - выбор по ID, внесение денег и покупка
- **Разные типы продуктов**:
- **Инвентарь и отчёты** - просмотр остатков, низкий уровень запасов
- **Обработка денег** - внесение купюр, расчёт сдачи
- **Админ-панель** (защищена паролем):
  - Пополнение товаров
  - Изменение цен
  - Добавление новых продуктов
- **CLI** - парсер команд
---

## Сборка и запуск

### Минимальные требования
- CMake 
- Компилятор C++ с поддержкой C++23

### Этапы сборки
```bash
# 1. Клонируем репозиторий и переходим внутрь проекта
git clone https://github.com/LuLvovich/Vending.git
cd Vending

# 2. Создаём папку сборки и переходим в папку сборки
mkdir build
cd build

# 3. Генерируем Makefile / проект
cmake ..

# 4. Компилируем
# Linux / macOS
make -j4
# универсальный способ (подходит для Windows)
cmake --build . 
```
### Запуск
```bash
./vending          # Linux / macOS
.\vending.exe      # Windows
```
```
# Unit-тесты
# Linux / macOS
./tests
# Windowы
.\tests.exe        
```
## Структура проекта
```
Vending/
├── include/                 # Заголовочные файлы
│   ├── VendingMachine.h
│   ├── Inventory.h
│   ├── InventoryReport.h
│   ├── MoneyHandler.h
│   ├── ChangeCalculator.h
│   ├── AdminPanel.h
│   ├── CLIParser.h
│   └── Product-Liquid-Solid.h
├── src/                     # Реализация классов
│   ├── Inventory.cpp
│   ├── Product-Liquid-Solid.cpp
│   ├── CLIParser.cpp
│   ├── AdminPanel.cpp
│   ├── InventoryReport.cpp
│   ├── VendingMachine.cpp
│   ├── MoneyHandler.cpp
│   └── ChangeCalculator.cpp
├── tests/                   # Google Test
│   ├── test_inventory.cpp
│   ├── test_main.cpp
│   ├── test_product.cpp
│   └── test_vending.cpp
├── main.cpp
├── CMakeLists.txt
└── README.md
```

## Команды для CLI
Все команды (кроме `add`) поддерживают **сокращения по первой букве** (регистр не имеет значения).  
Примеры:  
• `i` вместо `inventory`  
• `s 1` вместо `select 1`  
• `d 100` вместо `deposit 100`  
• `b` вместо `buy`  
• `a` вместо `admin`  
• `r 1 10` вместо `refill 1 10`  
• `p 1 60` вместо `price 1 60`  
• `q` вместо `quit`  
• `e` вместо `exitadmin`

| Команда             | Описание                                      | Пример                  |
|---------------------|-----------------------------------------------|-------------------------|
| `inventory`         | Показать отчёт по инвентарю                   | `inventory` или `i`     |
| `select N`          | Выбрать товар по ID                           | `select 1` или `s 1`    |
| `deposit X`         | Внести деньги                                 | `deposit 100` или `d 100` |
| `buy`               | Купить выбранный товар                        | `buy` или `b`           |
| `admin`             | Войти в админ-режим                           | `admin` или `a`         |
| `refill ID QTY`     | Пополнить товар (админ)                       | `refill 1 10` или `r 1 10` |
| `price ID VALUE`    | Изменить цену (админ)                         | `price 1 60` или `p 1 60` |
| `add`               | Добавить новый товар (админ)                          | `add`   |
| `quit`              | Выход                                         | `quit` или `q`          |

