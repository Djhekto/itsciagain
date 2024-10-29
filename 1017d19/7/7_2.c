/*7. Программа — «архиватор» фаилов.
Написать две функции: archive_s(s,t) и extract_s(s,t), параметр
s - исходныи фаил, t - фаил в которои требуется получить
результат. 
archive_s(s,t) 
Последовательность из n одинаковых символов первого фаила
переносится во второи как 2 баита:  баит, содержащии значение n
и баит, содержащии код символа. Например, последовательность
bbbbbb (занимает 6 баитов) должна быть заменена на 6b (2
баита), последовательность a заменяется на 1а. Повторяющиеся
последовательности из более, чем 255 баитов поделить на
несколько подпоследовательностеи. 
extract_s(s,t) — обратная операция
Сравнить размеры фаилов, привести пример, когда «архивация»
уменьшает размер фаила, и когда происходит увеличение размера.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void archive1(char* filename1, char*  filename2 );
void archive(char* filename1, char*  filename2 );
void extract_s(char* filename1, char* filename2);


int main(){
    archive1("7_2.in", "7_2.out" );
    archive("7_2.in", "7_2.bin" );
    extract_s("7_2.bin", " 7_2.binout.txt");

    return 0;
}

void archive(char* filename1, char* filename2) {
    FILE *fp_in, *fp_out;
    char buffer[1000];
    char count = 1;
    short first_line = 1;
    int len;

    if ((fp_in = fopen(filename1, "r")) == NULL) { printf("Error opening input file\n"); return;}

    if ((fp_out = fopen(filename2, "wb")) == NULL) { printf("Error opening output file\n"); fclose(fp_in); return; }

    while (fgets(buffer, sizeof(buffer), fp_in)) {//postro4no
        len = strlen(buffer);

        // Remove \n na next stroky
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[--len] = '\0';
        }

        for (int i = 0; i < len; ++i) {
            if (i < len - 1 && buffer[i] == buffer[i + 1]) {
                count++;
                continue;//count bykv until end of line that is copied to buf
            }
            if (!first_line || (count != 1 && buffer[i] != '\0')) {
                fwrite(&count, sizeof(char), 1, fp_out);//chislo mozet bit1 1+ symbolom
                fwrite(&buffer[i], sizeof(char), 1, fp_out);
                //fputc(buffer[i], fp_out);
            }
            count = 1;
            
        }
        first_line = 0;
    }//while end

    fclose(fp_in);
    fclose(fp_out);
}

void extract_s(char* filename1, char* filename2) {
    FILE *fp_in, *fp_out;
    char count;
    char symbol;

    if ((fp_in = fopen(filename1, "rb")) == NULL) { printf("Error opening input file\n"); return; }
    
    if ((fp_out = fopen(filename2, "w")) == NULL) { printf("Error opening output file\n"); fclose(fp_in); return;}
    
    while (fread(&count, sizeof(char), 1, fp_in) == 1 && fread(&symbol, sizeof(char), 1, fp_in) == 1) {
        //for (int i = 0; i < atoi(count); ++i) {
        for (int i = 0; i < count; ++i) {
            fputc(symbol, fp_out);
        }
    }
    
    fclose(fp_in);
    fclose(fp_out);
}

void archive1(char* filename1, char* filename2) {
    FILE *fp_in, *fp_out;
    char buffer[1000];
    int count = 1;
    int first_line = 1;
    int len;

    if ((fp_in = fopen(filename1, "r")) == NULL) {
        printf("Error opening input file\n");
        return;
    }

    if ((fp_out = fopen(filename2, "w")) == NULL) {
        printf("Error opening output file\n");
        fclose(fp_in);
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp_in)) {
        len = strlen(buffer);

        // Remove \n
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[--len] = '\0';
        }

        for (int i = 0; i < len; ++i) {
            if (i < len - 1 && buffer[i] == buffer[i + 1]) {
                count++;
            } else {
                if (!first_line || (count != 1 && buffer[i] != '\0')) {
                    fprintf(fp_out, "%d%c", count, buffer[i]);
                }
                count = 1;
            }
        }

        first_line = 0;
    }//while end

    fclose(fp_in);
    fclose(fp_out);
}
