//works

int maxProfit(int* price, int n){
    if((n == 0) || (n == 1))
        return 0;
    int minPrice = INT_MAX;
    int profit = 0;
    for(int i = 0; i < n; i++){
        minPrice = (minPrice > price[i])?price[i]:minPrice;
        profit = (profit > (price[i] - minPrice))? profit: (price[i] - minPrice) ;
    }
    return profit;
}
