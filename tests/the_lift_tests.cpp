#include <iostream>
#include <vector>
#include <algorithm>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "lib/the_lift.h"

namespace {

class TheLiftTest : public ::testing::Test {
	protected:

	TheLiftTest() {
	}

	virtual ~TheLiftTest() {
	}

	virtual void SetUp() {
	}

	virtual void TearDown() {
	}

};

void show_results(std::vector<int> actual, std::vector<int> expected)
{
	std::cout << "Expected: ";
	for (auto q : expected) {
		std::cout << q << " ";
	}
	std::cout << std::endl;

	std::cout << "Actual: ";
	for (auto q : actual) {
		std::cout << q << " ";
	}
	std::cout << std::endl;
}

std::vector<int> the_lift(std::vector<std::vector<int>> queues, int capacity)
{
	TheLift lift(queues, capacity);

	return lift.get_floors_queue();
}


TEST(TheLiftTest, test1)
{
	std::vector<std::vector<int>> queues;

	queues = { {}, {}, {5,5,5}, {}, {}, {}, {} };

	ASSERT_THAT(the_lift(queues, 5), testing::ElementsAre(0, 2, 5, 0));
}

TEST(TheLiftTest, test2)
{
	std::vector<std::vector<int>> queues;

	queues = { {}, {}, {1,1}, {}, {}, {}, {} };

	ASSERT_THAT(the_lift(queues, 5), testing::ElementsAre(0, 2, 1, 0));
}

TEST(TheLiftTest, test3)
{
	std::vector<std::vector<int>> queues;

	queues = { {}, {3}, {4}, {}, {5}, {}, {} };

	ASSERT_THAT(the_lift(queues, 5), testing::ElementsAre(0, 1, 2, 3, 4, 5, 0));
}

TEST(TheLiftTest, test4)
{
	std::vector<std::vector<int>> queues;

	queues = { {}, {0}, {}, {}, {2}, {3}, {} };

	ASSERT_THAT(the_lift(queues, 5), testing::ElementsAre(0, 5, 4, 3, 2, 1, 0));
}

TEST(TheLiftTest, test5)
{
	std::vector<std::vector<int>> queues;

	queues = { {3}, {2}, {0}, {2}, {}, {}, {5}};

	ASSERT_THAT(the_lift(queues, 5), testing::ElementsAre(0, 1, 2, 3, 6, 5, 3, 2, 0));
}

TEST(TheLiftTest, test6)
{
	std::vector<std::vector<int>> queues;

	queues = { {}, {}, {5,5,5}, {}, {}, {}, {}};

	ASSERT_THAT(the_lift(queues, 5), testing::ElementsAre(0, 2, 5, 0));
}

TEST(TheLiftTest, test7)
{
	std::vector<std::vector<int>> queues;

	queues = { {}, {}, {4,4,4,4}, {}, {2,2,2,2}, {}, {}};

	ASSERT_THAT(the_lift(queues, 2), testing::ElementsAre(0, 2, 4, 2, 4, 2, 0));
}

TEST(TheLiftTest, test8)
{
	std::vector<std::vector<int>> queues;

	queues = { {3}, {2}, {0}, {2}, {}, {}, {5}};

	ASSERT_THAT(the_lift(queues, 5), testing::ElementsAre(0, 1, 2, 3, 6, 5, 3, 2, 0));
}

TEST(TheLiftTest, test9)
{
	std::vector<std::vector<int>> queues;

	queues = { {3,3,3,3,3,3}, {}, {}, {}, {}, {}, {}};

	ASSERT_THAT(the_lift(queues, 5), testing::ElementsAre(0, 3, 0, 3, 0));
}

TEST(TheLiftTest, test10)
{
	std::vector<std::vector<int>> queues;

	queues = { {}, {0, 0, 0, 6}, {}, {}, {}, {6, 6, 0, 0, 0, 6}, {}};

	ASSERT_THAT(the_lift(queues, 5), testing::ElementsAre(0, 1, 5, 6, 5, 1, 0, 1, 0));
}

TEST(TheLiftTest, test11)
{
	std::vector<std::vector<int>> queues;

	queues = { {}, {}, {}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {}, {}, {}};

	ASSERT_THAT(the_lift(queues, 5), testing::ElementsAre(0, 3, 1, 3, 1, 3, 1, 0));
}

TEST(TheLiftTest, test12)
{
	std::vector<std::vector<int>> queues;
	std::vector<int> actual, expected;

	queues = { {2,1,2,2}, {2}, {0, 1, 1, 0, 0}};
	actual = the_lift(queues, 1);
	expected = {0, 1, 2, 0, 1, 2, 1, 0, 2, 1, 0, 2, 0, 2, 0};

	ASSERT_EQ(actual.size(), expected.size()) << "Failed with different size";

	for (int i = 0; i < actual.size(); i++) {
		EXPECT_EQ(actual[i], expected[i]) << "Failed with different elements" << i;
	}
}

TEST(TheLiftTest, test13)
{
	std::vector<std::vector<int>> queues;
	std::vector<int> actual, expected;

	queues = { {2,2,4}, {5,3,5}, {5,3}, {5,1,1,0,2}, {}, {}};

	actual = the_lift(queues, 4);
	expected = {0, 1, 2, 3, 4, 5, 3, 2, 1, 0, 1, 3, 5, 0};

	ASSERT_EQ(actual.size(), expected.size()) << "Failed with different size";

	for (int i = 0; i < actual.size(); i++) {
		EXPECT_EQ(actual[i], expected[i]) << "Failed with different elements" << i;
	}
}

TEST(TheLiftTest, test14)
{
	std::vector<std::vector<int>> queues;
	std::vector<int> actual, expected;

	queues = { {4, 6, 2, 4, 6}, {5,11,10,2,9}, {7,1,8}, {5,11,6}, {5,3,10,9,1}, {8}, {3,9}, {9,11,10}, {7,2,2,7,6}, {10,6}, {5}, {3,3,5,6}, {10,3}};

	actual = the_lift(queues, 5);
	expected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 11, 10, 9, 8, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 9, 8, 7, 6, 3, 2, 3, 4, 5, 6, 9, 11, 8, 7, 6, 0};
	
	ASSERT_EQ(actual.size(), expected.size()) << "Failed with different size";

	for (int i = 0; i < actual.size(); i++) {
		EXPECT_EQ(actual[i], expected[i]) << "Failed with different elements" << i;
	}
}

TEST(TheLiftTest, test15)
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {3,3,3,2}, {3,0}, {3}, {}};

	actual = the_lift(queues, 1);
	expected = {0, 1, 2, 3, 1, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 1, 3, 0};

	ASSERT_EQ(actual.size(), expected.size()) << "Failed with different size";

	for (int i = 0; i < actual.size(); i++) {
		EXPECT_EQ(actual[i], expected[i]) << "Failed with different elements" << i;
	}
}

};

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
