class Solution {
public:
    //产品不能多买，优惠券可以多次使用
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = 0, n = price.size();
        for (int i = 0; i < n; ++i) {
            res += price[i] * needs[i];
        }
        for (auto offer : special) {//优惠券可以多次使用, 每次都遍历所有优惠券
            bool isValid = true;
            for (int j = 0; j < n; ++j) {
                if (needs[j] - offer[j] < 0) isValid = false;//产品不能多买，遇到不需要的标记false
                needs[j] -= offer[j];
            }
            if (isValid) {
                res = min(res, shoppingOffers(price, special, needs) + offer.back());
            }
            for (int j = 0; j < n; ++j) {
                needs[j] += offer[j];
            }
        }
        return res;
    }
};
