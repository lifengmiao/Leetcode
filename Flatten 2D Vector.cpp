
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        row_start = vec2d.begin();
        row_end = vec2d.end();
    }

    int next() {
        int out = (*row_start)[column_cur];
        column_cur++;
        return out;
    }

    bool hasNext() {
        while(row_start!=row_end && column_cur==(*row_start).size()) { //use 'while' instead of 'if' for test case "[[1],[]]"
            row_start++;
            column_cur=0;
        }
        return row_start!=row_end;
    }
private:
    vector<vector<int>>::iterator row_start, row_end;
    int column_cur = 0;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
