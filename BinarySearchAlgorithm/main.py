import math
"""
Given a sorted array of n integers and a target value, determine
if the target exists in the array, print the index of it

1. search using 2 indexes
    start = 0
    end = n - 1
    find the mid point = roof((start + end)/2)
2. If the target = A[mid], return mid
3. If the target < A[mid], discard all elements in the right search space
    including all the middle element, i.e., A[mid...high]. Now our new high would be mid - 1
4. If the target > A[mid], discard all the elemnts in the left search space, including the middle
    element. Now our new low would be mid + 1
5. Repeat the process until the target is found or our sreach space is exhausted
"""


def bin_sort(arr: [], target: int, start: int, end: int) -> int:

    mid = math.ceil((start + end)/2)
    print(start, end, mid, arr[mid])
    if target == arr[mid]:
        return mid
    elif start == end:
        return -1
    elif target < arr[mid]:
        return bin_sort(arr, target, start, mid-1)
    else:
        return bin_sort(arr, target, mid, end)


if __name__ == "__main__":
    arr = [2, 3, 5, 7, 8, 10, 12, 15, 18, 20]
    target = 12
    
    x = bin_sort(arr, target, 0, len(arr)-1)
    if x < 0:
        print(f"{target} not found in array")
    else:
        print(f'{target} found at index: {x}')