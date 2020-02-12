// Program to find best buying and selling days
#include <stdio.h>

// solution structure
struct Interval
{
    int buy;
    int sell;
};

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{
    // Prices must be given for at least two days
    if (n == 1)
        return;

    int count = 0; // count of solution pairs

    // solution vector
    struct Interval sol[n/2 + 1];

    // Traverse through given price array
    int i = 0;
    while (i < n-1)
    {
        printf("for i :%d\n", i);
        // Find Local Minima. Note that the limit is (n-2) as we are
        // comparing present element to the next element.
        while ((i < n-1) && (price[i] >= price[i+1])) {
            printf("value of i while finding minima:%d\n", i);
            i++;
        }

        // If we reached the end, break as no further solution possible
        if (i == n-1)
            break;

        // Store the index of minima
        printf("value of i before buy is set:%d\n", i);
        sol[count].buy = i++;
        printf("value of i after buy is set:%d\n", i);

        // Find Local Maxima.  Note that the limit is (n-1) as we are
        // comparing to previous element
        while ((i < n) && (price[i] >= price[i-1])) {
            printf("value of i while finding maxima:%d\n", i);
            i++;
        }

        // Store the index of maxima
        printf("value of i before sell is set:%d\n", i);
        sol[count].sell = i-1;
        printf("value of i after sell is set:%d\n", i);

        // Increment count of buy/sell pairs
        count++;
    }

    // print solution
    if (count == 0)
        printf("There is no day when buying the stock will make profitn");
    else
    {
       for (int i = 0; i < count; i++)
          printf("Buy on day: %d\t Sell on day: %d\n", sol[i].buy, sol[i].sell);
    }

    return;
}

// Driver program to test above functions
int main()
{
    // stock prices on consecutive days
    //int price[] = {100, 180, 260, 310, 40, 535, 695};
    int price[] = {100, 180, 0, 310, 40, 535, 695};
    int n = sizeof(price)/sizeof(price[0]);

    // fucntion call
    stockBuySell(price, n);

    return 0;
}
