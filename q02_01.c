// 12S23022 -   Placidia Sitorus
// 112S23025 - Alif Aflah Suedi

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv)
{
    struct dorm_t *dorms = malloc(120 * sizeof(struct dorm_t));
    struct student_t *students = malloc(120 * sizeof(struct student_t));
    char masukan[100];
    char id[12];
    char student_name[30];
    char year[5];
    char dorm_name[15];
    unsigned short capacity;
    char *kata;
    int index_student, index_dorm;
    int x = 0, f = 0;
    return 0;

    do
    {
        fflush(stdin);
        masukan[0] = '\0';
        int c = 0;
        while (1)
        {
            char x = getchar();
            if (x == '\r')
            {
                continue;
            }
            if (x == '\n')
            {
                break;
            }
            masukan[c] = x;
            masukan[++c] = '\0';
        }

        kata = strtok(masukan, "#");
        if(strcmp(kata, "---") == 0)
        {
            break;
        } 
        else if (strcmp(kata, "student-add")==0)
        {
            kata = strtok(NULL, "#");
            strcpy(id, kata);
            kata = strtok(NULL, "#");
            strcpy(student_name, kata);
            kata = strtok(NULL, "#");
            strcpy(year, kata);
            kata = strtok(NULL, "#");
            if (strcmp(kata, "male") == 0)
            {
                students[x] = create_student(id, student_name, year, GENDER_MALE);
            } 
            else if (strcmp(kata, "female") == 0)
            {
                students[x] = create_student(id, student_name, year, GENDER_FEMALE);
            }
            x++;
        } 
        else if (strcmp(kata, "student-print-all") == 0) 
        {
            print_students(students, x);
        } 
        else if (strcmp(kata, "student-print-all-detail") == 0) 
        {
            print_students_detail(students, x);
        } 
        else if (strcmp(kata, "dorm-print-all-detail") == 0) 
        {
            print_dorm(dorms, f);
        } 
        else if (strcmp(masukan, "dorm-add") == 0)
        {
            kata = strtok(NULL, "#");
            strcpy(dorm_name, kata);
            kata = strtok(NULL, "#");
            capacity = atoi(kata);
            kata = strtok(NULL, "#");

            if (strcmp(kata, "male")==0)
            {
                dorms[f] = create_dorm(dorm_name, capacity, GENDER_MALE);
            } 
            else if (strcmp(kata, "female")==0)
            {
                dorms[f] = create_dorm(dorm_name, capacity, GENDER_FEMALE);
            }
            f++;
        } 
        else if (strcmp(kata, "assign-student")==0) 
        {
            kata = strtok(NULL, "#");
            strcpy(id, kata);
            kata = strtok(NULL, "#");
            strcpy(dorm_name, kata);
            index_student = -1;
            index_dorm = -1;

            for (int i = 0; i < x; i++)
            {
                if(strcmp(students[i].id, id)==0)
                {
                    index_student = i;
                    break;
                }
            }
            for (int i = 0; i < x; i++)
            {
                if(strcmp(dorms[i].name, dorm_name)==0)
                {
                    index_dorm = i;
                    break;
                }
            }
            if (index_student!=-1 && index_dorm!=-1)
            {
                assign_student(&students[index_student], &dorms[index_dorm], id, dorm_name);
            }
        } 
        else if (strcmp(kata, "move-student") == 0) 
        {
            kata = strtok(NULL, "#");
            strcpy(id, kata);
            kata = strtok(NULL, "#");
            strcpy(dorm_name, kata);
            index_student = -1;
            index_dorm = -1;

            for (int i = 0; i < x; i++)
            {
                if(strcmp(students[i].id, id) == 0)
                {
                    index_student = i;
                    break;
                }
            }
            for (int i = 0; i < f; i++)
            {
                if(strcmp(dorms[i].name, dorm_name) == 0)
                {
                    index_dorm = i;
                    break;
                }
            }
            if (index_student != -1 && index_dorm != -1)
            {
                if (students[index_student].dorm == NULL)
                {
                    assign_student(&students[index_student], &dorms[index_dorm], id, dorm_name);
                }
                 else 
                 {
                    for (int i = 0; i < f; i++)
                    {
                        if(strcmp(students[index_student].dorm->name, dorms[i].name)==0)
                        {
                            move_student(&students[index_student], &dorms[index_dorm], &dorms[i], id, dorm_name);
                            break;
                        }
                    }
                }
            }
        } 
        else if (strcmp(kata, "dorm-empty")==0)
        {
            kata = strtok(NULL, "#");
            strcpy(dorm_name, kata);
            index_dorm = -1;
            for (int i = 0; i < f; i++)
            {
                if(strcmp(dorms[i].name, dorm_name)==0)
                {
                    index_dorm = i;
                    break;
                }
            }
            if (index_dorm !=-1)
            {
                for (int i = 0; i < x; i++)
                {
                    if (students[i].dorm==NULL){
                        continue;
                    } else if(strcmp(students[i].dorm->name, dorms[index_dorm].name)==0){
                        unassign_student(&students[i], &dorms[index_dorm]);
                    }
                }
            }
        }
    } while (1 == 1);
    free(students);
    free(dorms);
    return 0;
}