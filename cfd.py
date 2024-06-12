import bisect

class SortedList:
    def __init__(self):
        self._list = []

    def insert(self, value):
        bisect.insort(self._list, value)

    def remove(self, value):
        index = bisect.bisect_left(self._list, value)
        if index < len(self._list) and self._list[index] == value:
            del self._list[index]

    def get_value_at_index(self, index):
        if 0 <= index < len(self._list):
            return self._list[index]
        else:
            raise IndexError("Index out of range")

    def __str__(self):
        return str(self._list)

def max_local(a):
    q = [0]*len(a)
    x = SortedList()
    for i in range(a):
        x.insert(a[i])
    for i in range(1, len(a), 2):
        

    return a

t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    q = max_local(a)
    print(*q)