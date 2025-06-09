def count_inversions(arr):
    def merge_sort_and_count(lst):
        if len(lst) <= 1:
            return lst, 0

        mid = len(lst) // 2
        left, inv_left = merge_sort_and_count(lst[:mid])
        right, inv_right = merge_sort_and_count(lst[mid:])
        merged, inv_split = merge_and_count(left, right)

        total_inv = inv_left + inv_right + inv_split
        return merged, total_inv

    def merge_and_count(left, right):
        merged = []
        i = j = inv_count = 0
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                merged.append(left[i])
                i += 1
            else:
                merged.append(right[j])
                inv_count += len(left) - i  # todos los restantes en left son > right[j]
                j += 1

        # Añadir el resto
        merged += left[i:]
        merged += right[j:]
        return merged, inv_count

    _, total_inversions = merge_sort_and_count(arr)
    return total_inversions

if __name__ == "__main__":
    A = [1,2,4,3,5,6,8,7,9]
    n = count_inversions(A)
    print(n)


'''
T(n) = 2T(n/2) + O(n)

=> T(n) = \Theta(nlogn)
'''