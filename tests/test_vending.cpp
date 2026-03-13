#include <gtest/gtest.h>
#include "VendingMachine.h"
#include "Inventory.h"

TEST(VendingMachineTest, BasicPurchaseFlow) {
    VendingMachine vm;
    vm.addProduct(std::make_unique<LiquidProduct>("Кола", 1, 50, 'M', 500, false));
    
    vm.insertMoney(100.0);
    vm.selectProduct(1);
    
    ASSERT_NO_THROW(vm.purchase());
}
