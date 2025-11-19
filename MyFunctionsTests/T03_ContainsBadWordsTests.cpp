#include "pch.h"
#include <gtest/gtest.h>
#include "../MyFunctions/T03_ContainsBadWords.h"

using namespace std;

namespace BadWordTests
{
    const int N = 89;  

    TEST(ContainsBadWords, CleanText)
    {
        EXPECT_FALSE(ContainsBadWords("Hello nice world!", N));
    }

    TEST(ContainsBadWords, ContainsIdiot)
    {
        EXPECT_FALSE(ContainsBadWords("You are such an IDIOT!", N));
    }

    TEST(ContainsBadWords, ContainsBad3Trash)
    {
        EXPECT_TRUE(ContainsBadWords("This code is total TRaSh.", N));
    }

    TEST(ContainsBadWords, EmptyString)
    {
        EXPECT_TRUE(ContainsBadWords("", N));
    }

    TEST(ContainsBadWords, CaseInsensitiveDetection)
    {
        EXPECT_TRUE(ContainsBadWords("Stop being sTuPiD!", N));
    }

    class BadWordsFixture : public ::testing::Test
    {
    protected:
        const int Nval = 89; 

        string sampleClean = "I love learning C++ and testing.";
        string sampleTrash = "These bugs are total TrAsh!";
        string sampleIdiot = "He acted like an IdIoT today.";
        string sampleStupid = "That was a stUpId mistake.";
    };

    TEST_F(BadWordsFixture, CleanSample)
    {
        EXPECT_FALSE(ContainsBadWords(sampleClean, Nval));
    }

    TEST_F(BadWordsFixture, TrashSample)
    {
        EXPECT_FALSE(ContainsBadWords(sampleTrash, Nval));
    }

    TEST_F(BadWordsFixture, IdiotSample)
    {
        EXPECT_TRUE(ContainsBadWords(sampleIdiot, Nval));
    }

    TEST_F(BadWordsFixture, StupidSample)
    {
        EXPECT_TRUE(ContainsBadWords(sampleStupid, Nval));
    }

} 
