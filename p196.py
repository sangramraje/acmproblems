def column_name_to_index(col):
    """Convert a column name to a column index (e.g., 'A' -> 0, 'B' -> 1)."""
    index = 0
    for c in col:
        index = index * 26 + ord(c) - ord('A') + 1
    return index - 1

def parse_cell_reference(ref):
    """Parse a cell reference to get its row and column indices."""
    i = 0
    while ref[i].isalpha():
        i += 1
    col = ref[:i]
    row = int(ref[i:]) - 1
    return row, column_name_to_index(col)

def evaluate_cell(row, col, cells, values, calculated):
    """Evaluate a cell recursively."""
    if calculated[row][col]:
        return values[row][col]

    cell = cells[row][col]
    if not cell.startswith('='):
        values[row][col] = int(cell)
    else:
        sum_val = 0
        for ref in cell[1:].split('+'):
            r, c = parse_cell_reference(ref)
            sum_val += evaluate_cell(r, c, cells, values, calculated)
        values[row][col] = sum_val
    
    calculated[row][col] = True
    return values[row][col]

def evaluate_spreadsheet(spreadsheet):
    rows, cols = map(int, spreadsheet.pop(0).split())
    cells = [row.split() for row in spreadsheet]
    values = [[0] * cols for _ in range(rows)]
    calculated = [[False] * cols for _ in range(rows)]

    for i in range(rows):
        for j in range(cols):
            # print(i, j)
            evaluate_cell(i, j, cells, values, calculated)

    return [' '.join(map(str, row)) for row in values]


def run_for_single_sheet(spreadsheet):
    evaluated = evaluate_spreadsheet(spreadsheet)
    for row in evaluated:
        print(row)


# Example usage
# spreadsheet = [
#     "3 4",
#     "10 34 37 =A1+B1+C1",
#     "40 17 34 =A2+B2+C2",
#     "=A1+A2 =B1+B2 =C1+C2 =D1+D2"
# ]

if __name__ == "__main__":
    num_sheets = int(input())
    for sheet_number in range(num_sheets):
        sheet = []
        cols_rows = input()
        num_rows = int(cols_rows.split()[1])
        num_cols = int(cols_rows.split()[0])
        sheet.append(f"{num_rows} {num_cols}")
        for row_number in range(num_rows):
            sheet.append(input())
        # print(sheet_number, sheet)
        run_for_single_sheet(sheet)
	
#spreadsheet = [
#    "3 4",
#    "10 34 37 =A1+A2+A3",
#    "40 17 34 =A2+B2+C2",
#    "=A1+A2 =B1+B2 =C1+C2 =D1+D2"
#]


