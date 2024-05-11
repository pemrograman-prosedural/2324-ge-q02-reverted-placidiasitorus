// 12S23022 -   Placidia Sitorus
// 112S23025 - Alif Aflah Suedi

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int argc, char **argv)
{
    struct dorm_t *dorms = malloc(120 * sizeof(struct dorm_t));
    struct student_t *students = malloc(120 * sizeof(struct student_t));
    char masukan[100];
    char id[12];
    char nama_siswa[30];
    char tahun[5];
    char nama_asrama[15];
    unsigned short kapasitas;
    char *kata; 
    int index_siswa, index_asrama;
    int jumlah_siswa = 0, jumlah_asrama = 0;

    do
    {
        printf("> ");
        fflush(stdout);
        
        if (fgets(masukan, sizeof(masukan), stdin) == NULL)
            break;

        masukan[strcspn(masukan, "\n")] = '\0'; // Menghilangkan newline jika ada
        
        kata = strtok(masukan, "#");
        if (kata == NULL)
            continue;

        if (strcmp(kata, "tambah-siswa") == 0)
        {
            kata = strtok(NULL, "#");
            if (kata == NULL)
                continue;
            strcpy(id, kata);
            
            kata = strtok(NULL, "#");
            if (kata == NULL)
                continue;
            strcpy(nama_siswa, kata);
            
            kata = strtok(NULL, "#");
            if (kata == NULL)
                continue;
            strcpy(tahun, kata);
            
            kata = strtok(NULL, "#");
            if (kata == NULL)
                continue;
            
            enum gender_t jenis_kelamin;
            if (strcmp(kata, "laki-laki") == 0)
                jenis_kelamin = GENDER_MALE;
            else if (strcmp(kata, "perempuan") == 0)
                jenis_kelamin = GENDER_FEMALE;
            else
                continue; // Jenis kelamin tidak valid
            
            students[jumlah_siswa++] = create_student(id, nama_siswa, tahun, jenis_kelamin);
        }
        else if (strcmp(kata, "kosongkan-asrama") == 0)
        {
            kata = strtok(NULL, "#");
            if (kata == NULL)
                continue;
            strcpy(nama_asrama, kata);
            
            for (int i = 0; i < jumlah_asrama; i++)
            {
                if (strcmp(dorms[i].name, nama_asrama) == 0)
                {
                    for (int j = 0; j < jumlah_siswa; j++)
                    {
                        if (students[j].dorm != NULL && strcmp(students[j].dorm->name, nama_asrama) == 0)
                            unassign_student(&students[j], &dorms[i]);
                    }
                    break;
                }
            }
        }
        // Tambahkan logika untuk perintah-perintah lainnya
        
    } while (strcmp(masukan, "---") != 0);

    free(students);
    free(dorms);
    return 0;
}
