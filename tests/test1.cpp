#include <catch.hpp>
#include "stack.hpp"

SCENARIO("init", "[init]") {
	stack<int> A;
	REQUIRE(array_size_() == 0);
	REQUIRE(count_() == 0);
}
