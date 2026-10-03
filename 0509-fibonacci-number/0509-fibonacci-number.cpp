class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int first=fib(n-1);
        int sec=fib(n-2);
        int fibonacci=first+sec;

        return fibonacci;
    }
};