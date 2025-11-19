#include "pch.h"
#include <gtest/gtest.h>
#include "../MyFunctions/T04_PassedExam.h"

using namespace std;

namespace ExamTests
{
    const int N = 89;   

    TEST(PassedExam, BelowLimit)
    {
        EXPECT_TRUE(PassedExam(30, N));   
    }

    TEST(PassedExam, EqualToLimit)
    {
        EXPECT_FALSE(PassedExam(45, N));   
    }

    TEST(PassedExam, AboveLimit)
    {
        EXPECT_TRUE(PassedExam(46, N));    
    }

    TEST(PassedExam, ZeroPoints)
    {
        EXPECT_FALSE(PassedExam(0, N));    
    }

    TEST(PassedExam, MaxPoints)
    {
        EXPECT_FALSE(PassedExam(100, N));  
    }

    TEST(PassedExam, NegativeThrows)
    {
        EXPECT_THROW(PassedExam(-5, N), std::invalid_argument);
    }

    TEST(PassedExam, AboveHundredThrows)
    {
        EXPECT_THROW(PassedExam(150, N), std::invalid_argument);
    }

    struct ExamCase
    {
        double points;
        bool expected;   
    };

    class ExamParamTest : public ::testing::TestWithParam<ExamCase> {};

    TEST_P(ExamParamTest, CheckPassingCases)
    {
        ExamCase c = GetParam();
        EXPECT_EQ(PassedExam(c.points, N), c.expected);
    }

    INSTANTIATE_TEST_CASE_P(
        ExamBonus,
        ExamParamTest,
        ::testing::Values(
            ExamCase{ 45, false },   
            ExamCase{ 46, false },  
            ExamCase{ 30, false },   
            ExamCase{ 0,  true },   
            ExamCase{ 100, true }    
        )
    );

} 
