class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> rst;
        // Key : diff1,diff2... single character is "" 
        // Value : list of strings grouped together
        unordered_map<string, vector<string>> mMap;
        for(int i=0; i<strings.size(); i++) {
            string diff = "";
            for(int j=0; j<strings[i].length()-1; j++) {
                if(strings[i][j+1]-strings[i][j]>=0)
                    diff += to_string(strings[i][j+1]-strings[i][j])+",";
                else
                    diff += to_string(strings[i][j+1]-strings[i][j]+26)+",";
            }
            if(!mMap.count(diff))
                mMap[diff] = vector<string>{strings[i]};
            else
                mMap[diff].push_back(strings[i]);
        }
        for (auto it = mMap.begin(); it!=mMap.end(); it++) {
            rst.push_back(it->second);
        }
        return rst;
    }
};
