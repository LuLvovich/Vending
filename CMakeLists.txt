cmake_minimum_required(VERSION 3.20)
project(VendingMachine CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vending 
    main.cpp
    src/Inventory.cpp
    src/Product-Liquid-Solid.cpp
    src/CLIParser.cpp
    src/AdminPanel.cpp
    src/InventoryReport.cpp
    src/VendingMachine.cpp
    src/MoneyHandler.cpp
    src/ChangeCalculator.cpp
)

target_include_directories(vending PRIVATE include)

#Для гугл теста 
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(tests 
    tests/test_main.cpp
    tests/test_inventory.cpp
    tests/test_product.cpp
    tests/test_vending.cpp
    src/Inventory.cpp
    src/Product-Liquid-Solid.cpp
    src/CLIParser.cpp
    src/AdminPanel.cpp
    src/InventoryReport.cpp
    src/VendingMachine.cpp
    src/MoneyHandler.cpp
    src/ChangeCalculator.cpp
)
target_include_directories(tests PRIVATE include)
target_link_libraries(tests GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

gtest_discover_tests(tests)
