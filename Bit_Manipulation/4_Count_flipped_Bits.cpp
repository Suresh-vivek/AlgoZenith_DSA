/*
You are given two integers 'A' and 'B'.



Your objective is to determine the number of bit positions where the corresponding bits of ‘A’ and ‘B’ differ, i.e., the number of bits that need to be flipped in ‘A’ to obtain ‘B’.



Example:
A = 7
B = 12
Output : 3

A = 0111
B = 1100
We need to flip the 1st, 2nd, and 4th bit of ‘A’ from the LSB to get ‘B’
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
11 18
Sample Output 1:
3
Explanation Of Sample Input 1:
A = 10010
B = 01011
We need to flip the 1st, 4th and 5th bit of ‘A’ from the LSB to get ‘B’.
Sample Input 2:
13 9
Sample Output 2:
1
Explanation Of Sample Input 2:
A = 1101
B = 1001
We need to flip the 3rd bit of ‘A’ from the LSB to get ‘B’.
Constraints:
1 <= A, B <= 10^6
Time Limit: 1 sec

*/

int flipBits(int A, int B){
    // Write your code here.
    int x = A^B;

    int count =0 ;

    while(x!=0){
        x = (x &(x-1));
        count++;
    }
    return count;
}