#include <stdio.h>
#include <string.h>
#include "dorm.h"
#include "gender.h"

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{
    struct dorm_t dorm_;
    strcpy (dorm_.name, _name);
    dorm_.capacity = _capacity;
    dorm_.gender = _gender;
    dorm_.residents_num = 0;

    return dorm_;
}

void print_dorm(struct dorm_t *_dorm, int jumlah)
{
    char dorm_gender[10] = "";

    for(int x = 1; x < jumlah + 1; ++x)
    {
        if(_dorm[x].gender == 0)
        {
            strcpy(dorm_gender, "male");
            printf("%s|%d|%s\n", _dorm[x].name, _dorm[x].capacity, dorm_gender);
        }
        else if(_dorm[x].gender == 1)
        {
            strcpy(dorm_gender, "female");
            printf("%s|%d|%s\n", _dorm[x].name, _dorm[x].capacity, dorm_gender);
        }
    }
}

void print_dorm_detail(struct dorm_t *_dorm, int jumlah)
{
    char dorm_gender[10] = "";

    for(int x = 1; x < jumlah + 1; ++x)
    {
        if(_dorm[x].gender == 0)
        {
            strcpy(dorm_gender, "male");
            printf("%s|%d|%s|%d\n", _dorm[x].name, _dorm[x].capacity, dorm_gender, _dorm[x].residents_num);
        }
        else if(_dorm[x].gender == 1)
        {
            strcpy(dorm_gender, "female");
            printf("%s|%d|%s|%d\n", _dorm[x].name, _dorm[x].capacity, dorm_gender, _dorm[x].residents_num);
        }
    }
}
