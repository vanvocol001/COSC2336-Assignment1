/** @file test-libstats.cpp
 *
 * @brief Unit tests for Assignment Functions: Review of Functions and
 *   Arrays
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VS Code Server 3.9.3
 * @note   assg : Assignment Functions
 * @date   June 1, 2021
 *
 * Assignment Functions: review of functions and arrays.  This is the
 * file containing the unit tests for this assignment.  It uses the
 * catch2 unit test framework. You should start by defining the
 * calculateMean() function to return a result of 0.  Then
 * incrementally code so that you pass the unit tests for
 * calculateMean.  Repeat this to define calculateStandardDeviation,
 * uncomment the unit tests for the second function, then
 * incrementally add code till you pass the defined tests.
 */
#include "catch.hpp"
#include "libstats.hpp"
#include <cmath>
#include <iostream>
using namespace std;

/** Task 1: sumOfValues() test case
 * Uncomment the following test case block and write your
 * code to pass these tests for the Task 1 implementation
 * of the sumOfValues() function.
 */

   TEST_CASE("<sumOfValues()> function tests", "[task1]")
   {
   SECTION("test array of 0 item, result should be 0.0 by default")
   {
    // can't actually assign an empty array, so create an array with a value,
    // but ask function to sum up as if array has no values.
    double x[] = {1.0};
    CHECK(sumOfValues(0, x) == Approx(0.0) );
   }

   SECTION("test summing array of 1 item")
   {
    double x[] = {3.0};
    CHECK(sumOfValues(1, x) == Approx(3.0) );
   }

   SECTION("test summing array of 2 items")
   {
    double x[] = {3.5, 5.2};
    CHECK(sumOfValues(2, x) == Approx(8.7) );
   }

   SECTION("test summing when sum is 0")
   {
    double x[] = {-1.5, 1.5, -1.2, 1.2, 0.0, 2.7, -2.7};
    CHECK(sumOfValues(7, x) == Approx(0.0) );
   }

   SECTION("test general summing")
   {
    double x[] = {5.1, 8.2, 3.3, 7.4, 9.5,
                  2.6, 7.7, 5.8, 4.9, 5.0,
                  2.1, 1.2, 9.3, 8.4, 9.5,
                  3.6, 5.7, 2.8, 5.9, 8.0,
                  8.1, 9.2};
    CHECK(sumOfValues(22, x) == Approx(133.3) );
   }

   SECTION("test summing more general case and 8 digits of precision")
   {
    double x[] = { 671.64241375,  887.58460132,  767.85753248,  848.324912,
                   -182.18919084, -133.45585287, -767.88955111, -277.36345661,
                   -837.42289395, -191.26413373, -318.54064004,  132.40635604,
                   130.12160027, -151.27562141, -789.4257901, -578.68535002,
                   -7.72868331,  959.6752345, -738.27468728, -560.421842  };
    // more rounding than usual, so increase margin a bit for acceptable equivalance
    CHECK(sumOfValues(20, x) == Approx(-1136.3250429038976).margin(0.000000001) );
   }

   SECTION("test a negative summation")
   {
    double x[] = {-5.1, -2.2, -3.3, 4.4, -7.5, 0.6, -2.7, -8.8, -6.9, -1.1};
    CHECK(sumOfValues(10, x) == Approx(-32.6) );
   }

   SECTION("test summing using different size parameters")
   {
    double x[] = {-5.55, -3.33, -1.11, 1.11, 3.33, 5.55};
    CHECK(sumOfValues(1, x) == Approx(-5.55) );
    CHECK(sumOfValues(2, x) == Approx(-8.88) );
    CHECK(sumOfValues(3, x) == Approx(-9.99) );
    CHECK(sumOfValues(4, x) == Approx(-8.88) );
    CHECK(sumOfValues(5, x) == Approx(-5.55) );
    // more rounding than usual, so increase margin a bit for acceptable equivalance
    CHECK(sumOfValues(6, x) == Approx(0.0).margin(0.000000001) );
   }
   }
 

/** Task 2: calculateMean() test cases
 * Uncomment the following test case block and write your code
 * to pass these tests for the calculateMean() function.
 */

   TEST_CASE("<calculateMean()> function tests", "[task2]")
   {
   SECTION("test mean of array of 1 item")
   {
    double x[] = {3.1};
    CHECK(calculateMean(1, x) == Approx(3.1) );
   }

   SECTION("test mean of array of 2 items")
   {
    double x[] = {3.2, 5.4};
    CHECK(calculateMean(2, x) == Approx(4.3) );
   }

   SECTION("test mean when sum is 0 thus mean is 0")
   {
    double x[] = {-1.1, 1.1, -1.9, 1.9, 0.0, 2.4, -2.4};
    CHECK(calculateMean(7, x) == Approx(0.0) );
   }

   SECTION("test basic calculation of mean")
   {
    double x[] = {5.1, 8.2, 3.3, 7.4, 9.5,
                  2.6, 7.7, 5.8, 4.9, 5.0,
                  2.1, 1.2, 9.3, 8.4, 9.5,
                  3.6, 5.7, 2.8, 5.9, 8.0,
                  8.1, 9.2};
    CHECK(calculateMean(22, x) == Approx(6.0590909090909095) );
   }

   SECTION("test mean of only first 10 elements of previous")
   {
    double x[] = {5.1, 8.2, 3.3, 7.4, 9.5,
                  2.6, 7.7, 5.8, 4.9, 5.0};
    CHECK(calculateMean(10, x) == Approx(5.95) );
   }

   SECTION("test mean of more general case and 8 digits of precision")
   {
    double x[] = { 671.64241375,  887.58460132,  767.85753248,  848.324912,
                   -182.18919084, -133.45585287, -767.88955111, -277.36345661,
                   -837.42289395, -191.26413373, -318.54064004,  132.40635604,
                   130.12160027, -151.27562141, -789.4257901, -578.68535002,
                   -7.72868331,  959.6752345, -738.27468728, -560.421842  };
    // more rounding than usual, so increase margin a bit for acceptable equivalance
    CHECK(calculateMean(20, x) == Approx(-56.816252145499995).margin(0.000000001) );
   }

   SECTION("test mean of more general cases")
   {
    double x[] = { 6.11, 14.22, 9.33,  3.44, 7.55,
                   12.66,  5.77, 3.88, 18.99, 2.11,
                   7.22, 19.33, 4.44,  5.55, 8.66,
                   0.77,  7.88};
    // more rounding than usual, so increase margin a bit for acceptable equivalance
    CHECK(calculateMean(17, x) == Approx(8.11235294117647).margin(0.000000001) );
   }

   SECTION("test a negative average")
   {
    double x[] = {-5.1, -2.2, -3.3, 4.4, -7.5, 0.6, -2.7, -8.8, -6.9, -1.5};
    CHECK(calculateMean(10, x) == Approx(-3.3) );
   }

   SECTION("test using size parameter correctly")
   {
    double x[] = {-5.1, -3.2, -1.3, 1.3, 3.2, 5.1};
    CHECK(calculateMean(1, x) == Approx(-5.1) );
    CHECK(calculateMean(2, x) == Approx(-4.15) );
    CHECK(calculateMean(3, x) == Approx(-3.2) );
    CHECK(calculateMean(4, x) == Approx(-2.075) );
    CHECK(calculateMean(5, x) == Approx(-1.02) );
    // more rounding than usual, so increase margin a bit for acceptable equivalance
    CHECK(calculateMean(6, x) == Approx(0.0).margin(0.000000001) );
   }
   }
 

/** Task 3: differenceOfValues() test cases
 * Uncomment the following test case block and write your code
 * to pass these tests for the differenceOfValues() function.
 */

   TEST_CASE("<differenceOfValues()> function tests", "[task3]")
   {
   SECTION("test differences of an empty array, resulting array should remain unchanged")
   {
    int numValues = 0;
    double values[] = {3.1};
    double differand = 1.5;
    differenceOfValues(numValues, values, differand);
    CHECK(values[0] == Approx(3.1) );
   }

   SECTION("test differences of array of 1 value")
   {
    int numValues = 1;
    double values[] = {3.1};
    double differand = 1.5;
    differenceOfValues(numValues, values, differand);
    CHECK(values[0] == Approx(1.6) );
   }

   SECTION("test differences of array of 2 value")
   {
    int numValues = 2;
    double values[] = {3.1, -3.1};
    double differand = 1.5;
    differenceOfValues(numValues, values, differand);
    CHECK(values[0] == Approx(1.6) );
    CHECK(values[1] == Approx(-4.6) );
   }

   SECTION("test negative differences of array of 3 value")
   {
    int numValues = 3;
    double values[] = {4.1, -2.1, 8.1};
    double differand = -5.5;
    differenceOfValues(numValues, values, differand);
    CHECK(values[0] == Approx(9.6) );
    CHECK(values[1] == Approx(3.4) );
    CHECK(values[2] == Approx(13.6) );
   }

   SECTION("test differences all negative")
   {
    int numValues = 5;
    double values[] = {4.1, 2.1, 8.1, 7.6, 5.4};
    double differand = 10.1;
    differenceOfValues(numValues, values, differand);
    CHECK(values[0] == Approx(-6.0) );
    CHECK(values[1] == Approx(-8.0) );
    CHECK(values[2] == Approx(-2.0) );
    CHECK(values[3] == Approx(-2.5) );
    CHECK(values[4] == Approx(-4.7) );
   }

   SECTION("test a small difference")
   {
    int numValues = 5;
    double values[] = {4.1, 2.3, 8.8, 7.6, -5.4};
    double differand = 0.001;
    differenceOfValues(numValues, values, differand);
    CHECK(values[0] == Approx(4.099) );
    CHECK(values[1] == Approx(2.299) );
    CHECK(values[2] == Approx(8.799) );
    CHECK(values[3] == Approx(7.599) );
    CHECK(values[4] == Approx(-5.401) );
   }

   SECTION("test a large difference")
   {
    int numValues = 5;
    double values[] = {4.1, 2.3, 8.8, 7.6, -5.4};
    double differand = 1234.1234;
    differenceOfValues(numValues, values, differand);
    CHECK(values[0] == Approx(-1230.0234) );
    CHECK(values[1] == Approx(-1231.8234) );
    CHECK(values[2] == Approx(-1225.3234) );
    CHECK(values[3] == Approx(-1226.5234) );
    CHECK(values[4] == Approx(-1239.5234) );
   }

   SECTION("test zero difference")
   {
    int numValues = 5;
    double values[] = {4.1, 2.3, 8.8, 7.6, -5.4};
    double differand = 0;
    differenceOfValues(numValues, values, differand);
    CHECK(values[0] == Approx(4.1) );
    CHECK(values[1] == Approx(2.3) );
    CHECK(values[2] == Approx(8.8) );
    CHECK(values[3] == Approx(7.6) );
    CHECK(values[4] == Approx(-5.4) );
   }
   }
 

/** Task 4: squareOfValues() test cases
 * Uncomment the following test case block and write your code
 * to pass these tests for the squareOfValues() function.
 */

   TEST_CASE("<squareOfValues()> function tests", "[task4]")
   {
   SECTION("test squares of an empty array, resulting array should remain unchanged")
   {
    int numValues = 0;
    double values[] = {3.1};
    squareOfValues(numValues, values);
    CHECK(values[0] == Approx(3.1) );
   }

   SECTION("test squares of array of 1 value")
   {
    int numValues = 1;
    double values[] = {3.1};
    squareOfValues(numValues, values);
    CHECK(values[0] == Approx(9.61) );
   }

   SECTION("test squares of array of 2 value")
   {
    int numValues = 2;
    double values[] = {3.1, -3.1};
    squareOfValues(numValues, values);
    CHECK(values[0] == Approx(9.61) );
    CHECK(values[1] == Approx(9.61) );
   }

   SECTION("test squares of 0")
   {
    int numValues = 4;
    double values[] = {0, 0.0, 0.00, 0.000};
    squareOfValues(numValues, values);
    CHECK(values[0] == Approx(0.0).margin(0.00000001) );
    CHECK(values[1] == Approx(0.0).margin(0.00000001) );
    CHECK(values[3] == Approx(0.0).margin(0.00000001) );
    CHECK(values[4] == Approx(0.0).margin(0.00000001) );
   }

   SECTION("test some whole nuber squares")
   {
    int numValues = 8;
    double values[] = {-9, -5, -3, -1, 1, 3, 5, 9};
    squareOfValues(numValues, values);
    CHECK(values[0] == Approx(81.0) );
    CHECK(values[1] == Approx(25.0) );
    CHECK(values[2] == Approx(9.0) );
    CHECK(values[3] == Approx(1.0) );
    CHECK(values[4] == Approx(1.0) );
    CHECK(values[5] == Approx(9.0) );
    CHECK(values[6] == Approx(25.0) );
    CHECK(values[7] == Approx(81.0) );
   }

   SECTION("test squares of small values")
   {
    int numValues = 4;
    double values[] = {0.01, -0.0005, -0.9e-8, 0.0033};
    squareOfValues(numValues, values);
    CHECK(values[0] == Approx(pow(0.01, 2.0)).margin(0.00000001) );
    CHECK(values[1] == Approx(pow(-0.0005, 2.0)).margin(0.00000001) );
    CHECK(values[2] == Approx(pow(-0.9e-8, 2.0)).margin(0.00000001) );
    CHECK(values[3] == Approx(pow(0.0033, 2.0)).margin(0.00000001) );
   }

   SECTION("test squaes of large values")
   {
    int numValues = 4;
    double values[] = {5.5e6, 7.1234e8, -3.9128e5, -8.91e6};
    squareOfValues(numValues, values);
    CHECK(values[0] == Approx(pow(5.5e6, 2.0)).margin(0.00000001) );
    CHECK(values[1] == Approx(pow(7.1234e8, 2.0)).margin(0.00000001) );
    CHECK(values[2] == Approx(pow(-3.9128e5, 2.0)).margin(0.00000001) );
    CHECK(values[3] == Approx(pow(-8.91e6, 2.0)).margin(0.00000001) );
   }
   }
 

/** Task 5: calculateStandardDeviation() test cases
 * Uncomment the following test case block and write your code
 * to pass these tests for the calculateStandardDeviation()
 * function.
 */

   TEST_CASE("<calculateStandardDeviation()> function tests", "[task5]")
   {
   SECTION("test standard deviation of a single value")
   {
    double x[] = {3.1};
    CHECK(calculateStandardDeviation(1, x) == Approx(0.0) );
   }

   SECTION("test standard deviation of two values")
   {
    double x[] = {3.1, 5.2};
    CHECK(calculateStandardDeviation(2, x) == Approx(1.05) );
   }

   SECTION("test when standard deviation is 0 for a set of values")
   {
    double x[] = {3.75, 3.75, 3.75, 3.75, 3.75, 3.75, 3.75, 3.75, 3.75, 3.75, 3.75};
    CHECK(calculateStandardDeviation(11, x) == Approx(0.0) );
   }

   SECTION("test basic calculation of standard deviation")
   {
    double x[] = {5.1, 8.2, 3.3, 7.4, 9.5,
                  2.6, 7.7, 5.8, 4.9, 5.0,
                  2.1, 1.2, 9.3, 8.4, 9.5,
                  3.6, 5.7, 2.8, 5.9, 8.0,
                  8.1, 9.2};
    CHECK(calculateStandardDeviation(22, x) == Approx(2.573229151176166).margin(0.00000001) );
   }

   SECTION("test another basic calculation of standard deviation")
   {
    double x[] = {-15.12,  10.34,  18.56, -16.78,  -2.90,  -5.12,   5.34, -13.56,
                  -12.78, -12.90,  12.12, -17.34,   6.56, -15.67,  -7.89,  -2.01,
                  -15.23,   5.45, -17.67,   4.89, -15.01, -12.23,  -9.45, -11.67,
                  -7.89};
    CHECK(calculateStandardDeviation(25, x) == Approx(10.441254974379277).margin(0.00000001) );
   }

   SECTION("test using size parameter 1 correctly")
   {
    double x[] = {-5, -3, -1, 1, 3, 5};
    CHECK(calculateStandardDeviation(1, x) == Approx(0.0) );
   }

   SECTION("test using size parameter 2 correctly")
   {
    // notice can't reuse x like we did before, why is that and how
    // would you fix that?
    double x[] = {-5.0, -3.0, -1.0, 1.0, 3.0, 5.0};
    CHECK(calculateStandardDeviation(2, x) == Approx(1.0) );
   }

   SECTION("test using size parameter 3 correctly")
   {
    // notice can't reuse x like we did before, why is that and how
    // would you fix that?
    double x[] = {-5.0, -3.0, -1.0, 1.0, 3.0, 5.0};
    CHECK(calculateStandardDeviation(3, x) == Approx(sqrt(8.0 / 3.0) ) );
   }

   SECTION("test using size parameter 4 correctly")
   {
    // notice can't reuse x like we did before, why is that and how
    // would you fix that?
    double x[] = {-5.0, -3.0, -1.0, 1.0, 3.0, 5.0};
    CHECK(calculateStandardDeviation(4, x) == Approx(sqrt(20.0 / 4.0) ) );
   }

   SECTION("test using size parameter 5 correctly")
   {
    // notice can't reuse x like we did before, why is that and how
    // would you fix that?
    double x[] = {-5.0, -3.0, -1.0, 1.0, 3.0, 5.0};
    CHECK(calculateStandardDeviation(5, x) == Approx(sqrt(40.0 / 5.0) ) );
   }

   SECTION("test using size parameter 6 correctly")
   {
    // notice can't reuse x like we did before, why is that and how
    // would you fix that?
    double x[] = {-5.0, -3.0, -1.0, 1.0, 3.0, 5.0};
    CHECK(calculateStandardDeviation(6, x) == Approx(sqrt(70.0 / 6.0) ) );
   }
   }
 
