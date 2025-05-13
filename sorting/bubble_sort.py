#hi
def bubble_sort(arr):
  n=len(arr)
  for i in range(n):
    swapped=False
    for  j in range(0,n-i-1):
      if arr[j]> arr[j+1]:
        arr[j],arr[j+1]=arr[j+1],arr[j]
        swapped=True
    if not swapped:
      break
  return arr

arr=[9,8,5,3,4,2,5,1]
sorted_arr=bubble_sort(arr)
print(sorted_arr)
