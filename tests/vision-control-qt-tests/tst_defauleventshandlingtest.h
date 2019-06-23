#ifndef TST_DEFAULEVENTSHANDLINGTEST_H
#define TST_DEFAULEVENTSHANDLINGTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(DefaulEventsHandlingTest, VisionControlTest)
{
  EXPECT_EQ(1, 1);
  ASSERT_THAT(0, Eq(0));
}

#endif // TST_DEFAULEVENTSHANDLINGTEST_H
