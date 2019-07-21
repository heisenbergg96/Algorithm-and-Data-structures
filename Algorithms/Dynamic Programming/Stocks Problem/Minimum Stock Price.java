import java.util.Random;

public class MinimumStockPrice {

    public static void main(String args[]) {

        int n = 10;
        int stockPrices[] = new int[n];
        Random rand = new Random();
        for(int i=0; i < n; i++) {

            int num = rand.nextInt(50) + 1;
            stockPrices[i] = num;
        }

        System.out.print(calculateMaxProfit(stockPrices));
    }

    public static int calculateMaxProfit(int stockPrices[]) {

        int minimumPrice = Integer.MAX_VALUE;
        int profit = 0;
        for(int i=0; i<stockPrices.length;i++) {

            profit = Math.max(profit, stockPrices[i] - minimumPrice);
            minimumPrice = Math.min(stockPrices[i], minimumPrice);
        }

        return profit;
    }
}


