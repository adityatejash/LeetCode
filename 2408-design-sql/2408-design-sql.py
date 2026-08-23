class SQL:

    class Row :
        def __init__(self, id, data):
            self.id = id
            self.data = data

    class Table:
        def __init__(self, tableSize):
            self.tableSize = tableSize
            self.id = 1
            self.rows = []

    def __init__(self, names: List[str], columns: List[int]):
                self.tables = {}
        
                for i in range (len(names)):
                    self.tables[names[i]] = self.Table(columns[i])  

    def ins(self, name: str, row: List[str]) -> bool:
        if name not in self.tables:
            return False

        table = self.tables[name]

        if len(row) != table.tableSize:
            return False

        table.rows.append (
            self.Row(table.id, row)
        )

        table.id += 1

        return True

    def rmv(self, name: str, rowId: int) -> None:
        if name not in self.tables:
            return

        table = self.tables[name]

        for i in range(len(table.rows)):

            if table.rows[i].id == rowId:
                table.rows.pop(i)
                return

    def sel(self, name: str, rowId: int, columnId: int) -> str:
        if name not in self.tables:
            return "<null>"

        table = self.tables[name]

        for row in table.rows:

            if row.id == rowId:
                if columnId < 1 or columnId > table.tableSize:
                    return "<null>"

                return row.data[columnId-1]

        return "<null>"

    def exp(self, name: str) -> List[str]:
        result = []

        if name not in self.tables:
            return result

        table = self.tables[name]

        for row in table.rows:
            s = str(row.id)

            for value in row.data:
                s += "," + value

            result.append(s)

        return result
        
# Your SQL object will be instantiated and called as such:
# obj = SQL(names, columns)
# param_1 = obj.ins(name,row)
# obj.rmv(name,rowId)
# param_3 = obj.sel(name,rowId,columnId)
# param_4 = obj.exp(name)