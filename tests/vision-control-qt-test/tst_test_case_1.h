#ifndef TST_TEST_CASE_1_H
#define TST_TEST_CASE_1_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(test_case_1, DefaultEventsHandlerTest)
{
  EXPECT_EQ(1, 1);
  ASSERT_THAT(0, Eq(0));
}

#endif // TST_TEST_CASE_1_H
