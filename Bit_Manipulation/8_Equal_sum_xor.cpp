/*
Given a positive integer N, Your task is to complete the function countValues which returns an integer denoting the count of all integers i such that
0 <= i <= n and n+i = n^i where ^ denotes a XOR operation.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case in a new line output will be the count of such positive integers.

Constraints:
1<=T<=100
1<=N<=1000

Example(To be used only for expected output):
Input
2
7
12
Output
1
4

Explanation:
For first test case
7^i = 7+i holds only for only for i = 0
7+0 = 7^0 = 7
For second test case
12^i = 12+i hold only for i = 0, 1, 2, 3
for i=0, 12+0 = 12^0 = 12
for i=1, 12+1 = 12^1 = 13
for i=2, 12+2 = 12^2 = 14
for i=3, 12+3 = 12^3 = 15


Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

*/

/*You are required to complete this method */
int countValues (int n)
{
   //Your code here 
   
   int count =0;
   
   while(n>0){
       if((n&1)==0){
           count++;
       }
       n >>=1;
   }
   return (1<<count);
}
 