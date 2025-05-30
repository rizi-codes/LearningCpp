#include "pointer_reference/easy_questions.h"
#include "gtest/gtest.h"

TEST(ReverseWordsTest, OneWordSentenceExtraSpaces) {
  easy_questions easy_questions;
  char str[] = {' ', ' ', 'a', 'b', 'c', ' ', ' '};

  easy_questions.reverseWords(str);
  EXPECT_STREQ("  abc  ", str);
}

TEST(ReverseWordsTest, TwoWordSentenceExtraSpaces) {
  easy_questions easy_questions;
  char str[] = {' ', ' ', 'a', 'b', 'c', 'd', ' ',
                ' ', '1', '2', '3', ' ', ' '};

  easy_questions.reverseWords(str);
  EXPECT_STREQ("  123  abcd  ", str);
}

TEST(ReverseWordsTest, OneWordSentence) {
  easy_questions easy_questions;
  char str[] = {'a', 'b', 'c'};

  easy_questions.reverseWords(str);
  EXPECT_STREQ("abc", str);
}

TEST(ReverseWordsTest, TwoWordSentence) {
  easy_questions easy_questions;
  char str[] = {'a', 'b', 'c', 'd', ' ', '1', '2', '3'};

  easy_questions.reverseWords(str);
  EXPECT_STREQ("123 abcd", str);
}

TEST(MergeSortedArraysTest, NormalArrays) {
  easy_questions easy_questions;
  int arr1[] = {1, 3, 5};
  int arr2[] = {2, 4, 6};
  int result[6] = {0};

  easy_questions.mergeSortedArrays(arr1, 3, arr2, 3, result);

  int expected[] = {1, 2, 3, 4, 5, 6};
  for (size_t i = 0; i < 6; ++i) {
    EXPECT_EQ(result[i], expected[i]);
  }
}

TEST(MergeSortedArraysTest, OneEmptyArray) {
  easy_questions easy_questions;
  int arr1[] = {1, 2, 3};
  int result[3] = {0};

  easy_questions.mergeSortedArrays(arr1, 3, nullptr, 0, result);

  int expected[] = {1, 2, 3};
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_EQ(result[i], expected[i]);
  }
}

TEST(MergeSortedArraysTest, BothEmptyArrays) {
  easy_questions easy_questions;
  int result[1] = {99}; // Dummy value to verify it stays unchanged

  easy_questions.mergeSortedArrays(nullptr, 0, nullptr, 0, result);

  EXPECT_EQ(result[0], 99);
}

TEST(MergeSortedArraysTest, ArraysWithDuplicates) {
  easy_questions easy_questions;
  int arr1[] = {1, 2, 2};
  int arr2[] = {2, 3, 4};
  int result[6] = {0};

  easy_questions.mergeSortedArrays(arr1, 3, arr2, 3, result);

  int expected[] = {1, 2, 2, 2, 3, 4};
  for (size_t i = 0; i < 6; ++i) {
    EXPECT_EQ(result[i], expected[i]);
  }
}

TEST(MergeSortedArraysTest, DifferentSizeArrays) {
  easy_questions easy_questions;
  int arr1[] = {1, 4, 7, 8};
  int arr2[] = {2};
  int result[5] = {0};

  easy_questions.mergeSortedArrays(arr1, 4, arr2, 1, result);

  int expected[] = {1, 2, 4, 7, 8};
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(result[i], expected[i]);
  }
}

TEST(ReverseString, ReverseNonEmptyOddLengthString) {
  easy_questions easy_questions{};
  char str[] = {'a', 'b', 'c', 'd', 'e'};

  easy_questions.reverseString(str);
  EXPECT_STREQ("edcba", str);
}

TEST(ReverseString, ReverseNonEmptyEvenLengthString) {
  easy_questions easy_questions{};
  char str[] = {'a', 'b', 'c', 'd'};

  easy_questions.reverseString(str);
  EXPECT_STREQ("dcba", str);
}

TEST(IncrementTest, IncrementPositive) {
  easy_questions easy_questions{};
  int value = 5;
  easy_questions.increment(&value);
  EXPECT_EQ(value, 6);
}

TEST(FindMinMaxTest, NormalCase) {
  easy_questions easy_questions{};
  int arr[] = {3, 1, 4, 2, 5};
  int min = 0, max = 0;

  easy_questions.findMinMax(arr, 5, &min, &max);

  EXPECT_EQ(min, 1);
  EXPECT_EQ(max, 5);
}

TEST(FindMinMaxTest, SingleElement) {
  easy_questions easy_questions{};
  int arr[] = {10};
  int min = 0, max = 0;

  easy_questions.findMinMax(arr, 1, &min, &max);

  EXPECT_EQ(min, 10);
  EXPECT_EQ(max, 10);
}

TEST(FindMinMaxTest, AllSameElements) {
  easy_questions easy_questions{};
  int arr[] = {7, 7, 7, 7};
  int min = 0, max = 0;

  easy_questions.findMinMax(arr, 4, &min, &max);

  EXPECT_EQ(min, 7);
  EXPECT_EQ(max, 7);
}

TEST(FindMinMaxTest, NegativeElements) {
  easy_questions easy_questions{};
  int arr[] = {-4, -1, -7, -3};
  int min = 0, max = 0;

  easy_questions.findMinMax(arr, 4, &min, &max);

  EXPECT_EQ(min, -7);
  EXPECT_EQ(max, -1);
}

TEST(FindMinMaxTest, TwoElements) {
  easy_questions easy_questions{};
  int arr[] = {100, 50};
  int min = 0, max = 0;

  easy_questions.findMinMax(arr, 2, &min, &max);

  EXPECT_EQ(min, 50);
  EXPECT_EQ(max, 100);
}

TEST(FindMinMaxTest, EmptyArray) {
  easy_questions easy_questions{};
  int min = -1, max = -1;

  easy_questions.findMinMax(nullptr, 0, &min, &max);

  EXPECT_EQ(min, -1);
  EXPECT_EQ(max, -1);
}

TEST(FindMinMaxTest, NullArrayWithSize) {
  easy_questions easy_questions{};
  int min = -1, max = -1;

  easy_questions.findMinMax(nullptr, 5, &min, &max);

  EXPECT_EQ(min, -1);
  EXPECT_EQ(max, -1);
}
