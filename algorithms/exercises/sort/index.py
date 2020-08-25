def bubbleSort(arr):
    for i in range(0, len(arr)):
        for j in range(0, len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp

    return arr

def selectionSort(arr):
    for i in range(0, len(arr)):
        minIndex = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[minIndex]:
                minIndex = j

        if minIndex != i:
            temp = arr[i]
            arr[i] = arr[minIndex]
            arr[minIndex] = temp

    return arr

def merge(left, right):
    result = []

    while (len(left) and len(right)):
        result.append(left.pop(0)) if left[0] < right[0] else result.append(right.pop(0))

    result.extend(left)
    result.extend(right)

    return result

def mergeSort(arr):
    if len(arr) == 1:
        return arr

    midpoint = len(arr) // 2
    left = arr[:midpoint]
    right = arr[midpoint:]

    return merge(mergeSort(left), mergeSort(right))