#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(is_adjacent, various) {
  EXPECT_TRUE(is_adjacent("dog", "cog"));
  EXPECT_FALSE(is_adjacent("cog", "Io"));
  EXPECT_TRUE(edit_distance_within("go", "good", 2));
  EXPECT_TRUE(edit_distance_within("car", "char", 1));
  EXPECT_TRUE(edit_distance_within("sitting", "kitten", 4));
}
