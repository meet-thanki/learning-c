#include <stdio.h>
#include <string.h>

// struct padding concepts
/* Impact of struct padding:
1. Padding helps program run faster.
2. It makes structs bigger than expected.
3. Reordering members usually reduces the total size.
*/

struct Example{
    // char a;
    // int b;
    // char c;

    int b; // Solution: Group the members of large types first.
    char a;
    char c;
};

union UExample{
    int b;
    char a;
    char c;
};

int main(){
    // printf("Size of struct: %zu", sizeof(struct Example)); // size of struct Example should have been 6 bytes, but the output is 12 due to struct padding.

    printf("Size of struct after changing the order: %zu", sizeof(struct Example)); // output: 8 bytes
    printf("\nSize of union is: %zu", sizeof(union UExample)); // output: 4 bytes which is that due to the size of largest datatype int. 
    //Note: Union does not have padding between its members
    return 0;

}