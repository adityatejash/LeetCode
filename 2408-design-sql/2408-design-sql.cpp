class SQL {
private: 

    struct Row {
        int id;
        vector<string> data;
    };

    struct Table {
        int tableSize;

        int id;
        vector<Row> rows; 
    };

    unordered_map<string, Table> tables;

public:

    SQL(vector<string>& names, vector<int>& columns) {
        for (int i=0; i<names.size(); i++) {
            tables[names[i]] = {columns[i], 1, {}};
        }
    }
    
    bool ins(string name, vector<string> row) {
        auto it = tables.find(name);

        if (it == tables.end()) return false;

        Table &table = it->second;

        if (row.size() != table.tableSize) return false;

        table.rows.push_back({table.id++, row});

        return true;
    }
    
    void rmv(string name, int rowId) {
        auto it = tables.find(name);

        if (it == tables.end()) return;

        Table &table = it->second;

        for (int i=0; i<table.rows.size(); i++) {

            if (rowId == table.rows[i].id) {
                table.rows.erase(table.rows.begin() + i);
                return;
            }
        }
    }
    
    string sel(string name, int rowId, int columnId) {
        auto it = tables.find(name);

        if (it == tables.end()) return "<null>";

        Table &table = it->second;

        for (auto& row : table.rows){

            if (row.id == rowId) {
                if (columnId < 1 || columnId > table.tableSize) return "<null>";
                
                return row.data[columnId - 1];
            }
        }

        return "<null>";
    }
    
    vector<string> exp(string name) {
        vector<string> result;

        auto it = tables.find(name);

        if (it == tables.end()) return result;

        Table &table = it->second;

        for (auto &row : table.rows) {

            string s = to_string(row.id);

            for (auto &value : row.data){
                s += "," + value;
            }

            result.push_back(s);
        }

        return result;
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */