class Solution {
public:
    struct trieNode {
        vector<int> indx; //save indx of word in words which with prefix at curr node
        vector<trieNode*> children;
        trieNode(): children(26, nullptr) {}
    };
    trieNode* buildTree(vector<string>& words) {
        trieNode* root = new trieNode();
        for(int i=0; i<words.size(); i++) {
            trieNode* t = root; //can't change root, must use tmp node
            for(int j=0; j<words[i].length(); j++) {
                if(!t->children[words[i][j]-'a'])
                    t->children[words[i][j]-'a']=new trieNode();
                t = t->children[words[i][j]-'a'];
                t->indx.push_back(i);
            }
        }
        return root;
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        trieNode* root = buildTree(words);
        vector<string> list;
        vector<vector<string>> rst;
        for (string it:words) {
            list.push_back(it);
            dfs(words, 1, root, list, rst);
            list.pop_back();
        }
        return rst;
    }
    
    void dfs(vector<string>& words, int level, trieNode* root, vector<string>& list,  vector<vector<string>>& rst) {
        if(level>=words[0].length()) { //level = num of lines filled currently
            rst.push_back(list);
            return;
        }
        string str = ""; //prefix for current level
        for(int i=0; i<level; i++ ) {
            str += list[i][level];
        }
        trieNode* t = root; //can't change root, must use tmp node
        for(int i=0; i<str.length();i++) {
            if(!t->children[str[i]-'a']) return;
            t = t->children[str[i]-'a'];
        }
        vector<int> index = t->indx; //all words with prefix str
        for(int j=0; j<index.size(); j++){ //travers all words with prefix str
            list.push_back(words[index[j]]);
            dfs(words, level+1, root, list, rst);
            list.pop_back();
        }
    }
};
