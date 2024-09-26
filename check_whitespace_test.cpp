#include <gtest/gtest.h>

#include "check_whitespace.h"

TEST(strip, EmptyString) {
    char *result = strip("");
    ASSERT_STREQ("", result);
    free(result);
}

TEST(strip, NoWhitespace) {
    char *result = strip("frog");
    ASSERT_STREQ("frog", result);
    free(result);
}

TEST(strip, WhitespaceOnFront) {
    char *result = strip("   frog");
    ASSERT_STREQ("frog", result);
    free(result);
}

TEST(strip, WhitespaceOnBack) {
    char *result = strip("frog  ");
    ASSERT_STREQ("frog", result);
    free(result);
}

TEST(strip, WhitespaceOnBothEnds) {
    char *result = strip("  frog     ");
    ASSERT_STREQ("frog", result);
    free(result);
}

TEST(is_clean, EmptyString) {
    ASSERT_TRUE(is_clean(""));
}

TEST(is_clean, NoWhitespace) {
    ASSERT_TRUE(is_clean("University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnFront) {
    ASSERT_FALSE(is_clean("   University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnBack) {
    ASSERT_FALSE(is_clean("University of Minnesota Morris  "));
}

TEST(is_clean, WhitespaceOnBothEnds) {
    ASSERT_FALSE(is_clean(" University of Minnesota Morris"    ));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}