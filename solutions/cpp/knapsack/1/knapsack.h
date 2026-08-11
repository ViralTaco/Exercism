#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
#include <queue>
#include <algorithm>

namespace knapsack {

    struct Item {
        int weight;
        int value;
    };

    struct Node {
        int level;
        int profit;
        int weight;
        double bound;

        // Comparator for priority queue (Max-heap based on bound)
        bool operator<(const Node& other) const {
            return bound < other.bound;
        }
    };

    // Computes the upper bound of profit using Fractional Knapsack logic
    inline double get_bound(Node u, int n, int W, const std::vector<Item>& items) {
        if (u.weight >= W) return 0;

        double profit_bound = u.profit;
        int j = u.level + 1;
        int total_weight = u.weight;

        while (j < n && total_weight + items[j].weight <= W) {
            total_weight += items[j].weight;
            profit_bound += items[j].value;
            j++;
        }

        if (j < n) {
            profit_bound += (double)(W - total_weight) * items[j].value / items[j].weight;
        }

        return profit_bound;
    }

    inline int maximum_value(int max_weight, std::vector<Item> items) {
        if (max_weight <= 0 || items.empty()) return 0;

        // Sort items by value/weight ratio to maximize pruning efficiency
        std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return (double)a.value / a.weight > (double)b.value / b.weight;
        });

        int n = items.size();
        std::priority_queue<Node> pq;
        Node u, v;

        u.level = -1; u.profit = 0; u.weight = 0;
        u.bound = get_bound(u, n, max_weight, items);
        pq.push(u);

        int max_profit = 0;

        while (!pq.empty()) {
            u = pq.top();
            pq.pop();

            if (u.bound > max_profit) {
                v.level = u.level + 1;

                // Branch 1: Include next item
                v.weight = u.weight + items[v.level].weight;
                v.profit = u.profit + items[v.level].value;

                if (v.weight <= max_weight && v.profit > max_profit) {
                    max_profit = v.profit;
                }

                v.bound = get_bound(v, n, max_weight, items);
                if (v.bound > max_profit) pq.push(v);

                // Branch 2: Exclude next item
                v.weight = u.weight;
                v.profit = u.profit;
                v.bound = get_bound(v, n, max_weight, items);
                
                if (v.bound > max_profit) pq.push(v);
            }
        }

        return max_profit;
    }

} // namespace knapsack

#endif