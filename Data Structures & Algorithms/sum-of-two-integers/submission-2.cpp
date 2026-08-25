class Solution {
public:

    void printbinary(int x){
        cout << x << ": ";
        for (int i=31;i>=0;i--){
            cout << ((x>>i)&1);
        }
        cout << endl;
    }

    int addone(int a){
        int ans = 0;
        int next = 0;
        int b = 1;
        // a+b
        for (int i=0;i<31;i++){
            int res = ((a>>i)&1) ^ ((b>>i)&1);
            res ^= next;
            ans |= ((1LL<<i)*res);
            int andd = (((a>>i)&1) & ((b>>i)&1)) | (next & ((b>>i)&1)) | (((a>>i)&1) & next);
            if (andd==1){
                next = 1;
            }
            else{
                next = 0;
            }
        }
        return ans;
    }

    int getSum(int a, int b) {
        printbinary(0x7FFFFFFF);
        printbinary(0xFFFFFFFF);
        if (a<b){
            swap(a,b);
        }
        int ans = 0;
        int next = 0;
        // a+b
        for (int i=0;i<32;i++){
            int res = ((a>>i)&1) ^ ((b>>i)&1);
            res ^= next;
            ans |= ((1LL<<i)*res);
            int andd = (((a>>i)&1) & ((b>>i)&1)) | (next & ((b>>i)&1)) | (((a>>i)&1) & next);
            if (andd==1){
                next = 1;
            }
            else{
                next = 0;
            }
        }
        if (ans > (0x7FFFFFFF)){
            ans = ~(ans ^ (0xFFFFFFFF));
        }
        return ans;
    }
};
