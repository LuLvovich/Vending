#include <gtest/gtest.h>
#include "Product-Liquid-Solid.h"

TEST(ProductTest, LiquidProductCreation) {
    LiquidProduct cola("Кола", 1, 50, 'M', 500, false);
    ASSERT_EQ(cola.GetName(), "Кола");
    ASSERT_EQ(cola.GetPrice(), 50);
    ASSERT_EQ(cola.GetVolumeML(), 500);
    ASSERT_FALSE(cola.GetIsSparkling());
}

TEST(ProductTest, PriceValidation) {
    Product p("Тест", 1, 50, 'M');
    ASSERT_NO_THROW(p.ChangePrice(100));
    ASSERT_THROW(p.ChangePrice(-10), std::invalid_argument);
}
