#include "pch.h"
#include <gtest/gtest.h>
#include "../MyFunctions/T02_CalculateShipping.h"

using namespace std;

namespace ShippingTests
{
    const int N = 89;

    TEST(CalculateShipping, ZeroWeight)
    {
        EXPECT_NEAR(CalculateShipping(0, false, N), 0.0, 0.001);
    }

    TEST(CalculateShipping, Small_NoExpress)
    {
        EXPECT_NEAR(CalculateShipping(0.5, false, N), 3.0, 0.001);
    }

    TEST(CalculateShipping, Small_Express)
    {
        EXPECT_NEAR(CalculateShipping(0.5, false, N), 4.5, 0.001);
    }

    TEST(CalculateShipping, Medium_NoExpress)
    {
        EXPECT_NEAR(CalculateShipping(3.0, false, N), 5.0, 0.001);
    }

    TEST(CalculateShipping, Large_Express)
    {
        EXPECT_NEAR(CalculateShipping(10.0, true, N), 15.0, 0.001);
    }

    TEST(CalculateShipping, NegativeThrows)
    {
        EXPECT_THROW(CalculateShipping(-2.0, true, N), std::invalid_argument);
    }

    struct ShippingCase
    {
        double weight;
        bool express;
        double expected;
    };

    class ShippingParameterizedTest : public ::testing::TestWithParam<ShippingCase> {};

    TEST_P(ShippingParameterizedTest, HandlesVariousCases)
    {
        ShippingCase c = GetParam();
        EXPECT_NEAR(CalculateShipping(c.weight, c.express, N), c.expected, 0.001);
    }

    INSTANTIATE_TEST_CASE_P(
        ShippingTestsBonus,
        ShippingParameterizedTest,
        ::testing::Values(
            ShippingCase{ 0.0,  false, 0.0 },
            ShippingCase{ 0.5,  false, 3.0 },
            ShippingCase{ 0.5,  false,  4.5 },
            ShippingCase{ 3.0,  false, 5.0 },
            ShippingCase{ 3.0,  true,  7.5 },
            ShippingCase{ 10.0, true, 10.0 },
            ShippingCase{ 10.0, true,  15.0 }
        )
    );
}
