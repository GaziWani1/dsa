#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int profit, weight;
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> arr)
{
    sort(arr.begin(), arr.end(), cmp);

    double totalProfit = 0.0;

    for (auto item : arr)
    {
        if (W >= item.weight)
        {
            W -= item.weight;
            totalProfit += item.profit;
        }
        else
        {
            totalProfit += item.profit * ((double)W / item.weight);
            break;
        }
    }

    return totalProfit;
}

int main()
{
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;

    cout << "Max Profit = " << fractionalKnapsack(W, items);
    return 0;
}