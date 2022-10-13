#include "taylor_sine.h"

#include <assert.h>

/*Calculates sine, by taylor series equation*/

double taylor_sine(double x, int n) {
    assert(n > 0);
    /*return result variable*/
    double result = 0;
    /*Varible for storing the factorial value*/
    double fact = 1;
    /*used to store the original x-value*/
    double orgValue = x;
    /*varible used for finding the number between f.eks. 3 and 5*/
    double formerCounter = 1;
    /*used for finding the eksponent(?) engelsk?*/
    int exp = 1;
    double sign = 1;
    /*i is used as the exponent*/
    int i = 1;
    while (i < 2 * n) {
        /*finder tæller / eksponent*/
        while (exp < i) {
            x *= orgValue;
            exp++;
        }

        result += x / fact * sign;
        /*switches between being + and negative*/
        sign *= -1;

        i += 2;
        /*calculating factorial*/
        formerCounter = i - 1;
        fact = fact * formerCounter * i;
    }
    return result;
}