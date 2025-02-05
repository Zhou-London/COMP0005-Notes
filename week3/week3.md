# Note for COMP0005 Week 3

Jan 24 Zhouzhou

## Selection Sort

For each iteration, starts the iteration at i, find the minimal number at j, let's say, [j]. Then swap [i] and [j]. Each time a minimal number is found, let i + 1. The main idea here is:

- Always find the smallest number.
- Make them a sequence in order.
- The sequence must be sorted.

For this algorithm, the complexity is O(n^2).

## Insertion Sort

There are many explanations for Insertion Sort but below might be the simplest one: For each iteration, starts at i, i = 1 initially, keep swaping [i] and its previous value until the previous value is smaller than [i]. Each time we stop swapping, let i + 1. The main idea here is:

- Scan from left to right.
- Swap from right to left.
- Keep swapping values until meeting smaller value.

The complexity is still O(n^2).

## Merge Sort

This could be the hardest sorting algorithm. The principle is that we spilt the array to be left one and right one, then assume that each one is sorted. After mergign these two sub-arrays we can get the final array which is sorted. We apply this principle on the array again and again, till the sub-array only contains 1 or 2 elements. And then we trace back to the origin array.

To implement this algorithm, we can write the following code.

    def mergeSort(list, low, high):
        if high <= low:
            return

        mid = low + (high - low) // 2

        mergeSort(low, mid)
        mergeSort(mid + 1, high)

        if list[mid] < list[mid + 1]:
            return

        merge(low, mid, high)

Knowing you are confused, I will now explain the code line by line. first we passed three arguments to this function, which are list, low, and high. low and high stands for the first index and the end index of the current array.

    def mergeSort(list, low, high):

If high is smaller than low, it reaches the base condition. We just end the function. If it is not sorted, we sort the left one and the right one. If **this left one** is not sorted, we further sort the left one and right one of **this left one**...

    mergeSort(low, mid)
    mergeSort(mid + 1, high)

If the mid value is smaller than the next value, and each half array is already sorted, then we can say that the whole array is sorted.

    if list[mid] < list[mid + 1]:
        return

If the mid value is not smaller than the next value, and each half array is already sorted, then we just merge them together.

    merge(low, mid, high)

So now, we have to think about, how can we write function **merge**.

    def merge(list, low, mid, high):
        res = [len(list)]

        i = low
        j = mid
        for k in range(low, high + 1):
            if i > mid:
                res[k] = list[j]
                j += 1
            elif j > high:
                res[k] = list[i]
                i += 1
            elif list[i] > list[j]:
                res[k] = list[j]
                j += 1
            elif list[j] > list[i]:
                res[k] = list[i]
                i += 1

This code is actually much more easier. We use two index to point to the low and mid, which are the start of two sub-arrays. And we always pick up the smaller one and push it to our **res**. If either index is out of range, we just keep moving another index. Finally we generated a new list which is the merged version of that two sub-arrays.

I also wrote a C++ version, it is more detailed and elegant.
