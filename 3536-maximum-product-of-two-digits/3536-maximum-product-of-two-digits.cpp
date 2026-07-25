class Solution {
public:
    int maxProduct (int n){
        int fm = n % 10;
        n /= 10;
        int sm = n % 10;
        n /= 10;

        if (fm < sm) swap (fm, sm);

        while (n) {
            int r = n % 10;
            n/=10;
            
            if (r >= sm && r <= fm){
                sm = r;
            } else if (r >= fm){
                sm = fm;
                fm = r;
            }

        }

        return fm * sm;
    }
};