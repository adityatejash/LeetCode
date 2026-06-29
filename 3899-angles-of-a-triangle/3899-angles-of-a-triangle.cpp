class Solution {
public:
    double angle(double a, double b, double c) {
        double val = (a*a + b*b - c*c) / (2.0*a*b);
        return acos(val) * 180.0 / M_PI;
    }

    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];


        if (a + b <= c || b + c <= a || a + c <= b) return {};

        vector<double> ans(3);
        ans[0] = angle(b, c, a);
        ans[1] = angle(a, c, b);
        ans[2] = angle(a, b, c);

        sort(ans.begin(), ans.end());
        
        return ans;
    }
};