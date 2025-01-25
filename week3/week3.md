# Note for COMP0005 Week 3

Jan 24 Zhouzhou

## Selection Sort

For each iteration, starts the iteration at i, find the minimal number at j, let's say, [j]. Then swap [i] and [j]. Each time a minimal number is found, let i + 1. The main idea here is:

-   Always find the smallest number.
-   Make them a sequence in order.
-   The sequence must be sorted.

For this algorithm, the complexity is O(n^2). 

## Insertion Sort

There are many explanations for Insertion Sort but below might be the simplest one: For each iteration, starts at i, i = 1 initially, keep swaping [i] and its previous value until the previous value is smaller than [i]. Each time we stop swapping, let i + 1. The main idea here is:

-   Scan from left to right.
-   Swap from right to left.
-   Keep swapping values until meeting smaller value.

The complexity is still O(n^2).
