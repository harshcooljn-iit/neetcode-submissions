class Solution {
public:
    int reverse(int x) {
        int y = 0;
        int MAX = ((1LL<<31) - 1);
        int MIN = -(1LL<<31);
        while (x!=0){
            int d = x%10;
            if (y>MAX/10 || y<MIN/10 || (y==MAX/10 && d>(MAX%10)) || (y==MIN/10 && d<(MIN%10))){
                return 0;
            }
            y = (y*10) + d;
            x /= 10;
        }
        return y;
    }
};
