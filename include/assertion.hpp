#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <functional>

// Inspire from Google Assertion library

// Generic macro for binary operators
#define ASSERT(expr1, expr2, op) \
	do { \
		if ((expr1) op (expr2)) { \
			std::cerr << "Assertion failed: " << #expr1 << " " << #op << " " << #expr2 << "\n"; \
			std::cerr << "File: " << __FILE__ << "\n"; \
			std::cerr << "Line: " << __LINE__ << "\n"; \
			std::cerr << "Function: " << __FUNCTION__ << "\n"; \
			std::abort(); \
		} \
	} while (0)

#ifdef UNIT_ASSERTION
	#define ASSERT_TRUE(expr) \
		do { \
			if (!(expr)) { \
				std::cerr << "Assertion failed: " << #expr << "\n"; \
				std::cerr << "File: " << __FILE__ << "\n"; \
				std::cerr << "Line: " << __LINE__ << "\n"; \
				std::cerr << "Function: " << __FUNCTION__ << "\n"; \
				std::abort(); \
			} \
		} while (0)

	#define ASSERT_FALSE(expr) \
		do { \
			if ((expr)) { \
				std::cerr << "Assertion failed: " << #expr << "\n"; \
				std::cerr << "File: " << __FILE__ << "\n"; \
				std::cerr << "Line: " << __LINE__ << "\n"; \
				std::cerr << "Function: " << __FUNCTION__ << "\n"; \
				std::abort(); \
			} \
		} while (0)
#endif // UNIT_ASSERTION

#ifdef SPEC_ASSERTION
	#define ASSERT_EQ(expr1, expr2) ASSERT(expr1, expr2, ==)
	#define ASSERT_NE(expr1, expr2) ASSERT(expr1, expr2, !=)
	#define ASSERT_LT(expr1, expr2) ASSERT(expr1, expr2, <)
	#define ASSERT_LE(expr1, expr2) ASSERT(expr1, expr2, <=)
	#define ASSERT_GT(expr1, expr2) ASSERT(expr1, expr2, >)
	#define ASSERT_GE(expr1, expr2) ASSERT(expr1, expr2, >=)
#endif // SPEC_ASSERTION

