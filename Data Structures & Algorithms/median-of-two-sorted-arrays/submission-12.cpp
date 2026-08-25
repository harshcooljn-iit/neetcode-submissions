class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        if (n>m){
            swap(n,m);
            swap(a,b);
        }
        int half = (n+m)/2;
        int lo = 0, hi = n-1;
        int i=-1,j=half-1;
        while (lo<=hi){
            int mid = (lo+hi)>>1;
            int rem = half - (mid+1);
            if (a[mid]<=b[rem]){
                if (b[rem-1]<=a[mid+1]){
                    i=mid;
                    j=rem-1;
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            else{
                break;
            }
        }
        cout << i << ' ' << j << endl;
        int l1,l2,r1,r2;
        if (i==-1){
            l1 = -1;
        }
        else{
            l1 = a[i];
        }
        if (j==-1){
            l2 = -1;
        }
        else{
            l2 = b[j];
        }
        if (i+1<n){
            r1 = a[i+1];
        }
        else{
            r1 = 1e9;
        }
        if (j+1<m){
            r2 = b[j+1];
        }
        else{
            r2 = 1e9;
        }

        if ((n+m)&1){
            return min(r1,r2);
        }
        else{
            return (max(l1,l2)+min(r2,r1))/2.0;
        }

    }
};
