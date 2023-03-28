# 701 Assignment 1
## Beck Busch - bbus692 - 975040349

# Task 2
## b)
| N=10 | Addition | Subtraction | Multiplication |
|------|----------|-------------|----------------|
| Attempt 1 | 80859 | 81154 | 1021059 |
| Attempt 2 | 80924 | 80918 | 1021107 |
| Attempt 3 | 80858 | 80986 | 1021168 |
## c)
Change cpu settings > Generate .qip > Compile > Program > Generate BSP > Build and Run  
Here is an example of the terminal output during a test:
```
This application performs NxN matrix operations  
N is 10, the operation is Multiplication  
*Large number*  
timestamp_start_time = 115 ticks
timestamp_end_time = 94366 ticks

timestamp measurement = 94251 ticks
timestamp measurement overhead = 106 ticks
Actual time  = 94145 ticks
Timestamp timer frequency = 50000000
This program is now complete
```
### Matrix Multiplication Function with varying Cache sizes

| Configuration | Attempt 1 | Attempt 2 | Attempt 3 |
|---------------|-----------|-----------|-----------|
| 1Kb Data, 0Kb Inst | 731269 | 731010 | 731192 |
| 4Kb Data, 0Kb Inst | 718747 | 718860 | 718664 |
| 16Kb Data, 0Kb Inst | 711668 | 711653 | 711764 |
| 0Kb Data, 1Kb Inst | 405398 | 405465 | 405465 |
| 0Kb Data, 4Kb Inst | 405465 | 405493 | 405495 |
| 0Kb Data, 16Kb Inst | 405413 | 405369 | 405413 |
| **16Kb Data, 1Kb Inst** | **94079** | **94026** | **94145** |

From these results we can tell that increasing the Data cache has a decent impact on processing speed, tapering off after about 4Kb. Instruction cache on the other hand has a massive effect when 1Kb is used, but this effect does not increase with more memory. Therefore I have determined the optimum space usage to be **16Kb of Data Cache and 1Kb of Instruction Cache**.

![Graph of average tick count vs cache sizes](graph.png)