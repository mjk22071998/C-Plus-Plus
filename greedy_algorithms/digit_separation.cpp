/**
 * @file digit_separation.cpp
 * @brief This file contains the DigitSeparation class for separating digits of large numbers.
 * https://www.log2base2.com/c-examples/loop/split-a-number-into-digits-in-c.html
 * @details
 * @author [Muhammad Junaid Khalid](https://github.com/mjk22071998)
 */

#include <algorithm>    /// For reveresing the vector
#include <cmath>        /// For abs() function
#include <iostream>     /// For input/output operations
#include <vector>       /// For std::vector to store separated digits
#include <cassert>      /// For assert() function to check for errors
#include <cstdint>      /// For int64_t data type to handle large numbers

/**
 * @namespace
 * @brief Greedy Algorithms
 */
namespace greedy_algorithms{

/**
 * @brief A class that provides methods to separate the digits of a large
 * positive number.
 */
    class DigitSeparation {
    public:
        /**
         * @brief Default constructor for the DigitSeparation class.
         */
        DigitSeparation() {}

        /**
         * @brief Separates the digits of a large positive number into a vector in
         * reverse order.
         *
         * @param largeNumber The large number to separate digits from.
         * @return A vector of digits in reverse order.
         */
        std::vector<std::int64_t> digitSeparationReverseOrder(
            std::int64_t largeNumber) const;

        /**
         * @brief Separates the digits of a large positive number into a vector in
         * forward order.
         *
         * @param largeNumber The large number to separate digits from.
         * @return A vector of digits in forward order.
         */
        std::vector<std::int64_t> digitSeparationForwardOrder(
            std::int64_t largeNumber) const;
    };

    /**
     * @brief Implementation of digitSeparationReverseOrder method.
     *
     * @param largeNumber The large number to separate digits from.
     * @return A vector of digits in reverse order.
     */
    std::vector<std::int64_t> DigitSeparation::digitSeparationReverseOrder(
        std::int64_t largeNumber) const {
        std::vector<std::int64_t> result;
        if (largeNumber != 0) {
            while (largeNumber != 0) {
                result.push_back(std::abs(largeNumber % 10));
                largeNumber /= 10;
            }
        } else {
            result.push_back(0);
        }
        return result;
    }

    /**
     * @brief Implementation of digitSeparationForwardOrder method.
     *
     * @param largeNumber The large number to separate digits from.
     * @return A vector of digits in forward order.
     */
    std::vector<std::int64_t> DigitSeparation::digitSeparationForwardOrder(
        std::int64_t largeNumber) const {
        std::vector<std::int64_t> result = digitSeparationReverseOrder(largeNumber);
        std::reverse(result.begin(), result.end());
        return result;
    }
}

/**
 * @brief self test implementation
 * @return void
 */
static void tests(){
    greedy_algorithms::DigitSeparation ds;

    // Test case: Positive number
    std::int64_t number = 1234567890;
    std::vector<std::int64_t> expectedReverse = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<std::int64_t> expectedForward = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::vector<std::int64_t> reverseOrder = ds.digitSeparationReverseOrder(number);
    assert(reverseOrder == expectedReverse);
    std::vector<std::int64_t> forwardOrder = ds.digitSeparationForwardOrder(number);
    assert(forwardOrder == expectedForward);

    // Test case: Single digit number
    number = 5;
    expectedReverse = {5};
    expectedForward = {5};
    reverseOrder = ds.digitSeparationReverseOrder(number);
    assert(reverseOrder == expectedReverse);
    forwardOrder = ds.digitSeparationForwardOrder(number);
    assert(forwardOrder == expectedForward);

    // Test case: Zero
    number = 0;
    expectedReverse = {0};
    expectedForward = {0};
    reverseOrder = ds.digitSeparationReverseOrder(number);
    assert(reverseOrder == expectedReverse);
    forwardOrder = ds.digitSeparationForwardOrder(number);
    assert(forwardOrder == expectedForward);

    // Test case: Large number
    number = 987654321012345;
    expectedReverse = {5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    expectedForward = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5};
    reverseOrder = ds.digitSeparationReverseOrder(number);
    assert(reverseOrder == expectedReverse);
    forwardOrder = ds.digitSeparationForwardOrder(number);
    assert(forwardOrder == expectedForward);

    // Test case: Negative number
    number = -987654321012345;
    expectedReverse = {5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    expectedForward = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5};
    reverseOrder = ds.digitSeparationReverseOrder(number);
    assert(reverseOrder == expectedReverse);
    fowardOrder = ds.digitSeparationForwardOrder(number);
    assert(forwardOrder == expectedForward);
}

    
/**
 * @brief main function
 * @return 0 on successful exit
 */
int main() {
    tests(); // run self test implementation

    return 0;
}
