#include "pch.h"
#include <gtest/gtest.h>
#include "../MyFunctions/T01_IsValidEmail.h"
using namespace std;

namespace EmailTests
{
    TEST(IsValidEmail, ValidEmail)
    {
        EXPECT_TRUE(IsValidEmail("test@example.com"));
    }

    TEST(IsValidEmail, MissingAt)
    {
        EXPECT_FALSE(IsValidEmail("testexample.com"));
    }

    TEST(IsValidEmail, NoPartBeforeAt)
    {
        EXPECT_FALSE(IsValidEmail("@example.com"));
    }

    TEST(IsValidEmail, NoDotAfterAt)
    {
        EXPECT_FALSE(IsValidEmail("user@examplecom"));
    }

    TEST(IsValidEmail, ShortDomain)
    {
        EXPECT_FALSE(IsValidEmail("u@a.c"));  
    }
}
