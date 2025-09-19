class Spreadsheet {
public:
    bool isChar(char ch) {
        if (ch >= 'A' && ch <= 'Z')
            return true;
        return false;
    }
    // int n = 0;
    vector<vector<int>> grid;

    Spreadsheet(int rows) {
        grid.resize(rows+1 , vector<int>(26 , 0));
    }

    void setCell(string cell, int value) {
        int c = cell[0] - 'A';
        string str = "";
        for (int i = 1; i < cell.length(); i++) {
            str += cell[i];
        }

        int r = stoi(str);

        grid[r][c] = value;
    }

    void resetCell(string cell) {
        int c = cell[0] - 'A';
        string str = "";
        for (int i = 1; i < cell.length(); i++) {
            str += cell[i];
        }

        int r = stoi(str);

        grid[r][c] = 0;
    }

    int getValue(string formula) {
        int sum = 0;
        int i = 1;
        bool f1 = false, f2 = false; // f1 -> true if X is cell reference same for f2
        int val1, val2;
        int r, c;
        string str1 = "";
        string str2 = "";
        
        if (isChar(formula[i])) {
            c = formula[i] - 'A';
            f1 = true;
            i++;
        }
        while (formula[i] != '+') {
            str1 += formula[i];
            i++;
        }
        i++;
        r = stoi(str1);

        if(f1){
            val1 = grid[r][c];
        }else{
            val1 = r;
        }

        if (isChar(formula[i])) {
            c = formula[i] - 'A';
            f2 = true;
            i++;
        }
        while (i < formula.length()) {
            str2 += formula[i];
            i++;
        }
        i++;
        r = stoi(str2);

        if(f2){
            val2 = grid[r][c];
        }else{
            val2 = r;
        }

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */