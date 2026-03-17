# BMMS + SPC DSA Workshop
To run:

## Bubble Sort
1. `cd bubble_sort`
2. `g++ BubbleSort.cpp -std=c++20` OR `g++ BubbleSortSolution.cpp -std=c++20` for the solution.
3. `./a.out` or `.\a.exe` depending on operating system (Windows is `.exe`, macOS and Linux will be `a.out`)

Correct output:
```
Original vector: 5 3 9 8 4 4 6 
Sorted vector using bubble sort: 3 4 4 5 6 8 9
```

## Dynamic List
1. `cd dynamic_list`
2. `g++ Main.cpp -std=c++20`
3. `./a.out` or `.\a.exe` depending on operating system (Windows is `.exe`, macOS and Linux will be `a.out`)

Correct output:
```
Size of list: 7
Capacity of list: 8
Should print Oscar: Oscar
Should print Renad: Renad
Size of list: 0
Capacity of list: 1
Chuck Norris, John Cena, Some other dude
Size of list: 3
Capacity of list: 4
```

## Hash Map
1. `cd hash_map`
2. `g++ Main.cpp -std=c++20`
3. `./a.out` or `.\a.exe` depending on operating system (Windows is `.exe`, macOS and Linux will be `a.out`)


Correct output:
```
Renad
Not found
Fraser
Testing copy semantics
Copy constructor - get(2): Dylan
Copy assignment - get(3): Markus
After removing from original - copy1.get(2): Dylan
After removing from original - original.get(2): Not found
Testing move semantics
Move constructor - get(20): Y
Move assignment - get(100): A
After move assignment - moved2.get(99): Not found
Done.
```

## Queue
1. `cd queue`
2. `g++ Main.cpp -std=c++20`
3. `./a.out` or `.\a.exe` depending on operating system (Windows is `.exe`, macOS and Linux will be `a.out`)

Correct output:
```
Front value: 0
Queue capacity: 64
Queue size: 64
Front value: 32
Queue capacity: 32
Queue size: 32
Front value: 48
Queue capacity: 16
Queue size: 16
Queue capacity: 1
Queue size: 0
Is queue empty? 1
```

---
&copy; 2026 Dylan Armstrong