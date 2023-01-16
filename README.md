# push_swap

Sorting problem, with the idea to minimize the actions, not the runtime.

Given 2 stacks, where an arbitrary number of integers is laying on the first stack, are used to sort the given numbers.
The actions that can be taken are:

![Unbenannt](https://user-images.githubusercontent.com/104910768/212731341-47fa5e44-13a3-4f50-9b33-319e3a67f61e.JPG)

My solutions works with the generale idea to devide the stacks in substacks of n / 2, n / 4, n / 8 ... numbers until the smallest one has 5 or less numbers.
After sorting this small stack, one can move on while restarting the whole sorting for the next larger substack and so on.
