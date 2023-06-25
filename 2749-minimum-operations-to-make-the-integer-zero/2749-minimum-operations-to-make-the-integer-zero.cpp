class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=0;i<=60;i++){
            long long diff=num1-(long long)i*(long long)num2;
            if(__builtin_popcountll(diff)<=i && num1>=num2 && diff>=i)return i;
        }
        return -1;
    }
};