# Suffix Array

## About

A suffix array is a sorted array of all the suffixes of any given string. The indexes of the sorted array is called the *suffix array*.

## The Idea

Let's say we have a string S that is "ababba". To start, we'll write all the suffixes in lexicographical order.

![Image](../resources/step_1_0.png)

This sequence of strings can be stored in an array. But there's a problem: Storing the strings in a array take up O(n<sup>2</sup>) space. This is where an suffix array comes in handy.

To start, we need an empty string, as that is also considered a substring of string S.

![Image](../resources/step_1_6.png)

Now, before we actually use the algorithm, we need to preprocess our string. At the end of every string, we add $ symbol (as $ is less than all of the characters in ASCII).

![Image](../resources/step_1_7.png)

The second prepartion we need is to make the strings in the same length. The length we want is 2<sup>k</sup>, where k is the smallest possible value. For the string S, the smallest k value is 3, so we make the strings 2<sup>k</sup> = 8. Because the string is circular, if there is no more characters remaining at the end of the string, we go the beginning of the string.

![Image](../resources/step_1_8.png)

Okay! Now our string is in a workable format, we can finally use the algorithm.

## The Algorithm

### Finding k
Once we have found k, we can iterate from 0 ... k.

### k = 0
At the beginning, k = 0 is an edge case as we only get the first character of each of the suffixes (including the "$"), and we sort it.

After sorting, we assign weights starting from 0.

![Image](../resources/step_1_1.png)

### k = 1

In the next case, when k = 1, we take the first two characters and instead of writing the characters, we write the weights from the previous k = 0 iteration.

![Image](../resources/step_1_2.png)

Now for the weights:

![Image](../resources/step_1_3.png)

### k = 2

Now for the final iteration.

![Image](../resources/step_1_4.png)

### Printing the Results

Remember the indexes during each iteration? Well, after the final iteration (k = 2), we can print the indexes (as it has been sorted lexigraphically).

![Image](../resources/step_1_5.png)

### Implementing the Algorithm

See the code by clicking [here](a_suffix_array.cpp).
