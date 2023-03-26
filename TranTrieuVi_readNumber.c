
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct typeArr 
{
    uint8_t size;
    uint8_t *firstElem;
} typeArr;

uint8_t sizeOFnum(uint32_t number)
{
    uint8_t count = 0;
    while (number > 0)
    {
        number = number / 10;
        count++;
    }
    return count;
}

typeArr *num2arr(uint32_t number)
{
    static typeArr arr;
    uint8_t size = 0;
    uint8_t count = 0;
    size = sizeOFnum(number);
    arr.size = size;
    arr.firstElem = (uint8_t *)malloc(sizeof(uint8_t) * size);
    while (number > 0)
    {
        arr.firstElem[count] = number % 10;
        number = number / 10;
        count++;
    }
    return &arr;
}

void readUnits(uint8_t num)
{
    switch (num)
    {
    case 1:
        printf("mot ");
        break;
    case 2:
        printf("hai ");
        break;
    case 3:
        printf("ba ");
        break;
    case 4:
        printf("bon ");
        break;
    case 5:
        printf("nam ");
        break;
    case 6:
        printf("sau ");
        break;
    case 7:
        printf("bay ");
        break;
    case 8:
        printf("tam ");
        break;
    case 9:
        printf("chin ");
        break;
    default:
        break;
    }
}

void readNumber(uint8_t num, typeArr *arr)
{
    switch (num)
    {
    case 0:
        readUnits(arr->firstElem[num]);
        break;
    case 1:
    case 4:
        if(arr->firstElem[num] != 0) // Nếu số liền sau khác 0 và khác thì đọc ra số + mươi
        {
            if(arr->firstElem[num] != 1)
            {
                readUnits(arr->firstElem[num]);
                printf("muoi ");
            }
            else                    // Nếu bằng 1 thì đọc là mười.
                printf("muoif ");
        }
        else                        // Nếu bằng 0 thì đọc là linh
        {
            if((arr->firstElem[num-1] != 0) && (arr->firstElem[num+1] != 0))
            {
                printf("linh ");
            }
        }
        break;
    case 2:
    case 5:
        if(arr->firstElem[num] != 0) // Nếu khác 0 thì đọc ra số + trăm
        {
            readUnits(arr->firstElem[num]);
            printf("tram ");
        }
        break;
    case 3:
        if((arr->firstElem[num+1] || arr->firstElem[num+2] || arr->firstElem[num]) != 0) // Nếu 3 số liền trước khác 0 thì bỏ qua
        {                                                                              
            if(arr->firstElem[num] != 0)
            {
                readUnits(arr->firstElem[num]);
            }
            printf("nghin ");
        }     
        break;
    case 6:
        if(arr->firstElem[num] != 0) // Nếu khác 0 thì in số + triệu
        {
            readUnits(arr->firstElem[num]);
            printf("trieu ");
        }
        break;
    default:
        break;
    }
}

int main(int argc, char const *argv[])
{
    typeArr *arr = num2arr(2103506);
    for(int i = arr->size - 1; i >= 0; i--)
    {
        readNumber(i,arr);
    }  
    return 0;
}
