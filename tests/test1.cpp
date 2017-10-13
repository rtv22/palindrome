#include <catch.hpp>
#include "stack.hpp"

SCENARIO("init", "[init]") {
	stack<int> A;
	REQUIRE(array_size_() == 0);
	REQUIRE(count_() == 0);
}

SCENARIO("Push", "[push]") {
	stack<int> A;
	A.push(1);
	A.push(2);
	REQUIRE(REQUIRE(count_() == 2));
}

SCENARIO("Pop", "[pop]") {
	stack<int> A;
	A.push(1);
	A.push(2);
	A.pop();
	REQUIRE(count_() == 1));
}
