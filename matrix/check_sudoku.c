//not sure what this does dont ues it

char* validate(int data_rows, int data_columns, int** data) {
    char* s = malloc(100 * sizeof(char));
    s = "WRONG INPUT";
    char* r = malloc(100 * sizeof(char));
    r = "OK";
    static char q[] = "OK";
    //int mat[9][9];
    for (int i = 0; i < data_rows; i++) {
        for (int j =0; j < data_columns; j++) {
             printf("a[%d][%d]:%d", data_rows, data_columns, data[data_rows][data_columns]);
        }
    }
    return q;
    /*
    for (int i = 0; i < 9; i++) {
        for (int j =0; j < 9; j++) {
            if (data[data_rows][i] == data[data_rows][j])
                return s;
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j =0; j < 9; j++) {
            if (data[i][data_columns] == data[j][data_columns])
                return s;
        }
    }
    return r;
    */
}
