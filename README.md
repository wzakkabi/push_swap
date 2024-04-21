# push_swap

## Description
`push_swap` is a sorting algorithm project that involves sorting stacks of integers using only a limited set of stack operations. This project is implemented in C and focuses on efficiency and optimization.

## Features
- Implements the following stack operations:
  - `sa`: Swap the first two elements of stack A.
  - `sb`: Swap the first two elements of stack B.
  - `ss`: Swap the first two elements of both stack A and stack B simultaneously.
  - `pa`: Push the first element of stack B onto stack A.
  - `pb`: Push the first element of stack A onto stack B.
  - `ra`: Rotate stack A (shift all elements up by one).
  - `rb`: Rotate stack B (shift all elements up by one).
  - `rr`: Rotate both stack A and stack B simultaneously.
  - `rra`: Reverse rotate stack A (shift all elements down by one).
  - `rrb`: Reverse rotate stack B (shift all elements down by one).
  - `rrr`: Reverse rotate both stack A and stack B simultaneously.
- Implements an efficient sorting algorithm to minimize the number of operations required.
- Provides visualization of the sorting process for better understanding.

## Getting Started
To use `push_swap`, follow these steps:

1. Clone the repository to your local machine:
```shell
git clone https://github.com/wzakkabi/push_swap.git
```
2. Compile the source files:
```shell
make
```
3. Run the executable with a list of integers as arguments:
```shell
./push_swap 5 3 1 4 2
```

## Algorithm
The `push_swap` algorithm consists of the following steps:
1. Divide the stack into groups based on their order.
2. Sort each group individually.
3. Combine the sorted groups to obtain the final sorted stack.

## Visualization
Optionally, you can visualize the sorting process using the `checker` program:
if you are using mac
```shell
chmod +x checker_Mac
```
or linux
```shell
chmod +x checker_linux
```

## Contributing
Contributions to `push_swap` are welcome! If you'd like to contribute, please follow these guidelines:
- Fork the repository.
- Create a new branch for your feature or bug fix.
- Make your changes and ensure they adhere to the project's coding style.
- Test your changes thoroughly.
- Submit a pull request detailing the changes you've made.

## Credits
The `push_swap` project was created by [walid zakkabi]. Special thanks to [(https://www.1337.ma/en/) and (https://www.42network.org)] for their contributions and support.

## Contact
If you have any questions, suggestions, or issues regarding `push_swap`, feel free to contact [wzakkabi@gmail.com] or open an issue on the GitHub repository.
