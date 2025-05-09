#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(MainTest, BasicTest) {
	EXPECT_EQ(1 + 1, 2);
}

TEST(MainTest, StringTest) {
	std::string test_str = "Hello";
	EXPECT_EQ(test_str.size(), 5);
	EXPECT_TRUE(test_str == "Hello");
}

TEST(MainTest, VectorTest) {
	std::vector<int> numbers{1, 2, 3, 4, 5};
	EXPECT_EQ(numbers.size(), 5);
	EXPECT_EQ(numbers[0], 1);
	EXPECT_EQ(numbers.back(), 5);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}