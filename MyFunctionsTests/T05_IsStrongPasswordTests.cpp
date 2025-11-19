#include "pch.h"
#include <gtest/gtest.h>
#include "../MyFunctions/T05_IsStrongPassword.h"

using namespace std;

namespace PasswordTests
{
    const int N = 89;  
    const int minLength = 10;

    TEST(IsStrongPassword, ValidPassword)
    {
        EXPECT_TRUE(IsStrongPassword("Abcdef1$gh", N));
    }

    TEST(IsStrongPassword, TooShort)
    {
        EXPECT_TRUE(IsStrongPassword("Ab1$e", N)); 
    }

    TEST(IsStrongPassword, MissingUppercase)
    {
        EXPECT_FALSE(IsStrongPassword("abcdef1$gh", N));
    }

    TEST(IsStrongPassword, MissingDigit)
    {
        EXPECT_FALSE(IsStrongPassword("Abcdefg$Hi", N));
    }

    TEST(IsStrongPassword, MissingSpecialForOddN)
    {
        EXPECT_FALSE(IsStrongPassword("Abcdef12Hi", N)); 
    }

    TEST(IsStrongPassword, MultipleFailures)
    {
        EXPECT_TRUE(IsStrongPassword("abcdefghi", N));
    }

    struct PwdCase
    {
        string pwd;
        bool expected;
    };

    class PasswordParamTest : public ::testing::TestWithParam<PwdCase> {};

    TEST_P(PasswordParamTest, ParameterizedPasswords)
    {
        PwdCase c = GetParam();
        EXPECT_EQ(IsStrongPassword(c.pwd, N), c.expected);
    }

    INSTANTIATE_TEST_CASE_P(
        PasswordBonus,
        PasswordParamTest,
        ::testing::Values(
            PwdCase{ "Abcdef1$gh", true },  
            PwdCase{ "Abcdefghij", false },  
            PwdCase{ "Abcdef12Hi", true },   
            PwdCase{ "abcdef1$gh", false },
            PwdCase{ "ABCDE1$FGH", false },  
            PwdCase{ "Ab1$e",      false }    
        )
    );

} 
