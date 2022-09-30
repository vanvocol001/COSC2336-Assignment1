/** @file libstats.cpp
 *
 * @brief Implementation file for Assignment Functions: Review of
 *   Functions and Arrays
 *
 * @author Jane Programmer
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VS Code Server 3.9.3
 * @note   assg : Assignment Functions
 * @date   June 1, 2021
 *
 * Assignment Functions: review of functions and arrays.  This is
 * the file where you should implement the functions calculateMean() and
 * calculateStandardDeviation() as described in the assignment.
 */
#include <cmath>
#include <iostream>
using namespace std;
double const SQUARED = 2.0;

/** @brief Sum values of array
 *
 * Given an array of double values (and the number of values in the
 * array), sum up the values and return the resulting sum as the
 * result.  Mathematically this function implements the summation
 * operation, where we assume we want to sum up all values from index
 * i=0 to i=n-1.
 *
 * @param numValues The number of values in the array to sum up.
 * @param values An array of double values we are to calculate
 *   the sum of and return.  This is a constant parameter because
 *   we do not change the values in any way in this function, only
 *   sum them and return their resulting sum.
 *
 * @returns double Returns the resulting sum of the array values.
 *   This function handles arrays of size 0, where the sum of
 *   such an empty array is assumed to be 0.0.
 */
// write your implementation of the sumOfValues() function here
double sumOfValues(int numValues, double const values[])
{
  double sum = 0;
  for (int i = 0; i < numValues; i++)
  {
    sum += values[i];
  }
  return sum;
}
/** @brief Calculate mean value of array
 *
 * Calculate the mean (or average) of the given array of values.  This
 * functions works on a list of integers, but since the mean can be a
 * real valued number, it returns a double result.  The values are
 * passed in as an array, along with the number of values in the array
 * as parameters.
 *
 * @param numValues The number of values being input to the
 *   function.
 * @param values An array of doubles, the values to calculate the
 *   mean of.  This is a const parameter because we will not
 *   change the original values in any way, only calculate their
 *   mean.
 *
 * @returns A double result, the calculated mean or average of the
 *   list of values.
 */
// write your implementation of the calculateMean() function here
double calculateMean(int numValues, double const values[])
{
  double mean = sumOfValues(numValues, values) / numValues;
  return mean;
}
/** @brief Difference of values
 *
 * Given an array of values and a value to subtract (the differand),
 * Subtract the differend from each value in the array.  This funciton
 * is a void function, it does not return an explicit result.  However,
 * The function calculates the difference between each value and stores
 * the result back into the original array to be returned to the caller.
 *
 * @param numValues The number of values being input to the
 *   function.
 * @param values An array of doubles, the values to calculate the
 *   differences of.  The difference is stored back in this array
 *   of values to be returned to the caller.
 * @param differand The value to subtract from each of the values in
 *   the input array.
 */
// write your implementation of the differenceOfValues() function here
double differenceOfValues(int numValues, double values[], double differand)
{
  for (int i = 0; i < numValues; i++)
  {
    values[i] = values[i] - differand;
  }
  return 0;
}
/** @brief Square of values
 *
 * Given an array of values, calculate the square of
 * each value, value^2.  Replace the original value in the
 * array with its squared value.  The array is passed by
 * reference, so we return the squared values implicitly back
 * in the original array.
 *
 * @param numValues The number of values being input to the
 *   function.
 * @param values An array of doubles, the values to square and return
 *   to the caller.  The squared value is stored back in this array of
 *   values to be returned to the caller.
 */
// write your implementation of the squareOfValues() function here
double squareOfValues(int numValues, double values[])
{
  for (int i = 0; i < numValues; i++)
  {
    values[i] = pow(values[i],SQUARED);
  }
  return 0;
}
/** @brief standard deviation of values
 *
 * Calculate the standard deviation of the given list of values.
 * This function works on a list of integers, but since the
 * standard deviation can be a real valued number, it returns
 * a double result.  The values are passed in as an array, along
 * with the number of values in the array as parameters.
 *
 * @param numValues The number of values being input to the
 *   function.
 * @param values An array of doubles, the values to calculate the
 *   standard deviation of.
 *
 * @returns A double result, the calculated mean or average of the
 *   list of values.
 */
// write your implementation of the calculateStandardDeviation() function here
double calculateStandardDeviation(int numValues, double values[])
{
  double mean = calculateMean(numValues, values);
  differenceOfValues(numValues, values, mean);
  squareOfValues(numValues, values);
  double meanSquaredDifferences = calculateMean(numValues, values);
  double result = sqrt(meanSquaredDifferences);
  return result;
}