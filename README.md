# SE1FA15: Sorting Floating Point Numbers and NaNs

## Background
First year assignment submission for module SE1FA15: Fundamentals and Applications of Computing.

**Brief:** _Implement a program in C++ that sorts a list of floating-point objects. Numbers should be sorted in increasing numerical order. Determine how minus zero and Not-a-Number (NaN) objects are to be sorted._

## Description
The basis for the code written here is the Bubble Sort. This is a simple sorting algorithm which looks at adjacent elements starting from left to right, compares them and switches if the first element it larger. It is named so because "large elements bubble up to their proper position" (Knuth, 2007, p.106).

The IEEE 754 standard for floating-point numbers presents the existence of negative and positive zero in computer arithmetic, where the former can be thought of by considering a small magnitude positive number that tends down to zero; and the latter could be achieved by a small magnitude negative number tending upwards to zero. Most programs will define them as equal by numerical comparison, however this program will display results in the following order:

```
1. Negative Infinity
2. Negative Numbers
3. Negative Zero
4. Positive Zero
5. Positive Values
6. Positive Infinity
7. All Not-a-Number (NaNs)
```


## References
1. Knuth, Donald Ervin. _Sorting and Searching_. Boston [u.a.]: Addison-Wesley, 2007.
2. Standards.ieee.org. 2019. 754-2019 - IEEE Standard For Floating-Point Arithmetic. [online] Available at: [<https://standards.ieee.org/content/ieee-standards/en/standard/754-2019.html>]


