#include <iostream>
#include <vector>
#include <algorithm>

#include "the_lift.h"


std::vector<int> the_lift(std::vector<std::vector<int>> queues, int capacity)
{
	TheLift lift(queues, capacity);

	return lift.get_floors_queue();
}

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

void test1()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {}, {}, {5,5,5}, {}, {}, {}, {} };
	expected = {0, 2, 5, 0};


	actual = the_lift(queues, 5);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test2()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {}, {}, {1,1}, {}, {}, {}, {} };
	expected = {0, 2, 1, 0};

	actual = the_lift(queues, 5);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test3()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {}, {3}, {4}, {}, {5}, {}, {} };
	expected = {0, 1, 2, 3, 4, 5, 0};

	actual = the_lift(queues, 5);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test4()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {}, {0}, {}, {}, {2}, {3}, {} };
	expected = {0, 5, 4, 3, 2, 1, 0};

	actual = the_lift(queues, 5);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test5()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {3}, {2}, {0}, {2}, {}, {}, {5}};
	expected = {0, 1, 2, 3, 6, 5, 3, 2, 0};

	actual = the_lift(queues, 5);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test6()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {}, {}, {5,5,5}, {}, {}, {}, {}};
	expected = {0, 2, 5, 0};

	actual = the_lift(queues, 5);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test7()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {}, {}, {4,4,4,4}, {}, {2,2,2,2}, {}, {}};
	expected = {0, 2, 4, 2, 4, 2, 0};

	actual = the_lift(queues, 2);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test8()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {3}, {2}, {0}, {2}, {}, {}, {5}};
	expected = {0, 1, 2, 3, 6, 5, 3, 2, 0};

	actual = the_lift(queues, 5);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test9()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {3,3,3,3,3,3}, {}, {}, {}, {}, {}, {}};
	expected = {0, 3, 0, 3, 0};

	actual = the_lift(queues, 5);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test10()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {}, {0, 0, 0, 6}, {}, {}, {}, {6, 6, 0, 0, 0, 6}, {}};
	expected = {0, 1, 5, 6, 5, 1, 0, 1, 0};

	actual = the_lift(queues, 5);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test11()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {}, {}, {}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {}, {}, {}};
	expected = {0, 3, 1, 3, 1, 3, 1, 0};

	actual = the_lift(queues, 5);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test12()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {2,1,2,2}, {2}, {0, 1, 1, 0, 0}};
	expected = {0, 1, 2, 0, 1, 2, 1, 0, 2, 1, 0, 2, 0, 2, 0};

	actual = the_lift(queues, 1);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test13()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {2,2,4}, {5,3,5}, {5,3}, {5,1,1,0,2}, {}, {}};
	expected = {0, 1, 2, 3, 4, 5, 3, 2, 1, 0, 1, 3, 5, 0};

	actual = the_lift(queues, 4);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test14()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {4, 6, 2, 4, 6}, {5,11,10,2,9}, {7,1,8}, {5,11,6}, {5,3,10,9,1}, {8}, {3,9}, {9,11,10}, {7,2,2,7,6}, {10,6}, {5}, {3,3,5,6}, {10,3}};
	expected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 11, 10, 9, 8, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 9, 8, 7, 6, 3, 2, 3, 4, 5, 6, 9, 11, 8, 7, 6, 0};

	actual = the_lift(queues, 5);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

void test15()
{
	std::vector<std::vector<int>> queues; std::vector<int> actual, expected;

	queues = { {3,3,3,2}, {3,0}, {3}, {}};
	expected = {0, 1, 2, 3, 1, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 1, 3, 0};

	actual = the_lift(queues, 1);

	if (actual.size() != expected.size()) {
		std::cout << "FAILED" << std::endl;
		show_results(actual, expected);
		return;
	}

	for (int i = 0; i < actual.size(); i++) {
		if (actual[i] != expected[i]) {
			std::cout << "FAILED" << std::endl;
			show_results(actual, expected);
			return;
		}
	}

	std::cout << "SUCCESS" << std::endl;
}

int main(int argc, const char *argv[])
{
	std::cout << "Test1" << std::endl;
	test1();
	std::cout << std::endl;

	std::cout << "Test2" << std::endl;
	test2();
	std::cout << std::endl;

	std::cout << "Test3" << std::endl;
	test3();
	std::cout << std::endl;

	std::cout << "Test4" << std::endl;
	test4();
	std::cout << std::endl;

	std::cout << "Test5" << std::endl;
	test5();
	std::cout << std::endl;

	std::cout << "Test6" << std::endl;
	test6();
	std::cout << std::endl;

	std::cout << "Test7" << std::endl;
	test7();
	std::cout << std::endl;

	std::cout << "Test8" << std::endl;
	test8();
	std::cout << std::endl;

	std::cout << "Test9" << std::endl;
	test9();
	std::cout << std::endl;

	std::cout << "Test10" << std::endl;
	test10();
	std::cout << std::endl;

	std::cout << "Test11" << std::endl;
	test11();
	std::cout << std::endl;

	std::cout << "Test12" << std::endl;
	test12();
	std::cout << std::endl;

	std::cout << "Test13" << std::endl;
	test13();
	std::cout << std::endl;

	std::cout << "Test14" << std::endl;
	test14();
	std::cout << std::endl;

	std::cout << "Test15" << std::endl;
	test15();
	std::cout << std::endl;
	return 0;
}
