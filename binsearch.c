#include <stdio.h>

int* binsearch(int* p, int num, int des);

int main(void){
    int arr[] = {1,2,3,4,5,7,8,9,10,11,15,19,}; // destination array
    printf("Please enter the des num: ");       // destination number
    int des;
    scanf("%d", &des);
    int* desptr = binsearch(arr, 12, des);
    if(desptr == NULL){
        printf("the des is not in the array\n");
    } else {
        printf("the des pointer is %p\nthe num is %d\n", desptr, *desptr);
    }
    return 0;
}
int* binsearch(int* p, int num, int des)
{
    if(*p > des || *(p + num -1) < des){
        return NULL;
    }
    int low = 0;
    int high = num;
    int medium = (low + high) / 2;
    while(1){
        if(des == *(p + medium)){           // if equal , return the selective pointer
            return p + medium;
        } else if(des < *(p + medium) && high - low > 1){   // if high - low > 1, not found, return NULL
                high = medium;
        } else if(des > *(p + medium) && high - low > 1){
            low = medium;
        } else {
            return NULL;
        }
        medium = (low + high) / 2;
    }
}
