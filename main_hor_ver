// Dont forget the if-statement before calling this function that
// if start_row = end_row  { paint_horizontal }
void paint_horizontal(int* start_row, int* start_col, int* end_col, char** canvas) {
    char STAR = '*';
    char PLUS = '+';
    char HORIZONTAL_LINE = '-';
    int j;

    for(j = *start_col; j <= *end_col; j++){
        if (canvas[*start_row][j] != STAR) {
            canvas[*start_row][j] = PLUS;
        } else {
            canvas[*start_row][j] = HORIZONTAL_LINE;
        }
    }
}

// Dont forget the if-statement before calling this function that
// if start_col = end_col  { paint_horizontal }
void paint_vertical(int* start_row, int* start_col, int* end_row, char** canvas) {
    char VERTICAL_LINE = '|';
    char STAR = '*';
    char PLUS = '+';
    int i;

    for(i = *start_row; i <= *end_row; i++) {
        if (canvas[i][*start_col] != STAR) {
            canvas[i][*start_col] = PLUS;
        } else {
            canvas[i][*start_col] = VERTICAL_LINE;
        }
    }
}
