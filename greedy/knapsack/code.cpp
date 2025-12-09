#include <iostream>
#include <vector>
using namespace std;

class Item
{
public:
    int value;
    int weight;

    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &items)
{
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    for (Item &item : items)
    {
        if (W == 0)
            break;

        if (item.weight <= W)
        {
            totalValue += item.value;
            W -= item.weight;
        }
        else
        {
            double fraction = (double)W / item.weight;
            totalValue += item.value * fraction;
            W = 0;
        }
    }

    return totalValue;
}

int main()
{
    int n = 3;
    int CAPACITY = 15;

    vector<Item> items;

    items.push_back(Item(10, 2));
    items.push_back(Item(5, 3));
    items.push_back(Item(15, 5));
    items.push_back(Item(7, 7));
    items.push_back(Item(6, 1));
    items.push_back(Item(18, 4));
    items.push_back(Item(3, 1));

    double maxValue = fractionalKnapsack(CAPACITY, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}