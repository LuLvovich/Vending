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
make -j4          # Linux / macOS
cmake --build .   # универсальный способ (подходит для Windows)
```
### Запуск
```bash
./vending          # Linux / macOS
.\vending.exe      # Windows
```
## Структура проекта
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

## Команды для CLI
