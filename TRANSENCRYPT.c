#include <stdio.h>
#include <string.h>

int main() {
    printf("Enter the data to be encrypted: ");
    char ch, data[30][30], output[100], seq[] = "MEGABUCK";
    int i, j, k, Columns = 0, Rows = 0, seq_No = 0, len = strlen(seq);
    
    while ((ch = getchar()) != '\n') {
        data[Rows][Columns++] = ch;
        if(Columns == len){
            Rows++;
            Columns=0;
        }
    }
    if (Columns != 0) {
        for (i = Columns; i < len; i++) {
            data[Rows][i] = '.';
        }
        Rows++;
    }
    for (i = 0; i < len; i++) {
        seq_No = 0;
        for (j = 0; j < len; j++) { 
            if (seq[i] > seq[j])
                seq_No++; 
        }
        for (j = 0; j < Rows; j++) { 
            if ((seq_No * Rows) + j >= Rows * len)
                break;
            output[(seq_No * Rows) + j] = data[j][i];
        }
    }
    output[Rows * len] = '\n';
    printf("\nEncrypted data: ");
    for (i = 0; i < Rows * len; i++) {
        printf("%c", output[i]);
    }
    printf("\n");
    return 0;
}
