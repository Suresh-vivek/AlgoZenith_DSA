/*

 Find the XOR of numbers from 1 to n.

 For N = 2
1 ^ 2
= 3


For N = 3
(1 ^ 2) ^ 3
= 3 ^ 3
= 0


For N = 4
(1 ^ 2 ^ 3) ^ 4
= 0 ^ 4
= 4


For N = 5
(1 ^ 2 ^ 3 ^ 4) ^ 5
= 4 ^ 5
= 1


For N = 6
(1 ^ 2 ^ 3 ^ 4 ^ 5) ^ 6
= 1 ^ 6
= 7


For N = 7
(1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6) ^ 7
= 7 ^ 7
= 0


For N = 8
(1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7) ^ 8
= 0 ^ 8
= 8


For N = 9
(1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8) ^ 9
= 8 ^ 9
= 1


For N = 10
(1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9) ^ 10
= 1 ^ 10
= 11


For N = 11
(1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9 ^ 10) ^ 11
= 11 ^ 11
= 0


For N = 12
(1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9 ^ 10 ^ 11) ^ 12
= 0 ^ 12
= 12
We can see the following pattern in the above output.

When N is a multiple of 4 then answer is equal to N.
When N % 4 is equal to 1 then answer is equal to 1.
When N % 4 is equal to 2 then answer is equal to N+1.
When N % 4 is equal to 3 then answer is equal to 0.


simlarly to find xor from L to R we can find xor from 1 to L-1 and xor from 1 to R 
and xor their result 


*/


int findXor(int n){
    if(n%4==0){
        return n;
    }
    else if(n%4==1){
        return 1;
    }
    else if(n%4==2){
        return n+1;
    }
    else if(n%4==3){
        return 0;
    }

}

int findXOR(int L, int R){
    // Write your code here.
    int a = findXor(L-1);
    int b = findXor(R);

    return a^b;
    
    }