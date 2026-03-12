#include <gtest/gtest.h>
#include "Inventory.h"

TEST(InventoryTest, AddAndFindProduct) {
    Inventory inv;
    inv.AddLiquidProduct(1, "Кола", 50, 'M', 500, false);
    
    ASSERT_TRUE(inv.IdExists(1));
    ASSERT_EQ(inv.GetCount(), 1);
    
    Product* p = inv.FindById(1);
    ASSERT_NE(p, nullptr);
    ASSERT_EQ(p->GetName(), "Кола");
    ASSERT_EQ(p->GetPrice(), 50);
}

TEST(InventoryTest, GiveProduct) {
    Inventory inv;
    inv.AddLiquidProduct(1, "Кола", 50, 'M', 500, false);
    
    ASSERT_TRUE(inv.GiveProduct(1));
    ASSERT_EQ(inv.GetCount(), 1);
}

TEST(InventoryTest, MaxProductsLimit) {
    Inventory inv;
    for (int i = 1; i <= 60; i++) {
        inv.AddLiquidProduct(i, "Test", 10, 'S', 100, false);
    }
    ASSERT_THROW(inv.AddLiquidProduct(61, "Extra", 10, 'S', 100, false), std::runtime_error);
}
