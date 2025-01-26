#include <stdio.h>
#include <stdlib.h>

struct element {
    int x;
    int y;
    int value;
};

struct sparse {
    int rows;
    int cols;
    int num;
    struct element *ele;
};

void create(struct sparse *s) {
    printf("Enter dimensions(row col): ");
    scanf("%d %d",&s->rows,&s->cols);
    printf("Enter number of non-zero value: ");
    scanf("%d",&s->num);
    s->ele=(struct element *)malloc(s->num*sizeof(struct element));
    printf("Enter the non-zero values in format rows,col,value\n");
    for(int i=0;i<s->num;i++) {
        printf("Enter %d element: ",i+1);
        scanf("%d %d %d",&s->ele[i].x,&s->ele[i].y,&s->ele[i].value);
    }
}

struct sparse *add(const struct sparse *s1, const struct sparse *s2) {
    struct sparse *s3 = (struct sparse *) malloc(sizeof(struct sparse));
    int i=0,j=0,k=0;
    if(s1->cols!=s2->cols||s1->rows!=s2->rows) {
        printf("Sparse matrix addition is not possible");
        return NULL;
    }
    s3->rows=s1->rows;s3->cols=s1->cols;
    s3->ele=(struct element*)malloc((s1->num+s2->num)*sizeof(struct element));

    if (s3->ele == NULL) {
        printf("Memory allocation for elements failed\n");
        free(s3);
        return NULL;
    }

    while(i<s1->num&&j<s2->num) {
        //when s1 row is smaller or s2 col is smaller provided both s1 and s2 row is same
        if(s1->ele[i].x<s2->ele[j].x || ((s1->ele[i].x==s2->ele[j].x)&&(s1->ele[i].y<s2->ele[j].y))){
            s3->ele[k++]=s1->ele[i++];
        }
        //when s2 row is smaller or s2 col is smaller provided both s1 and s2 row is same
        else if(s1->ele[i].x>s2->ele[j].x || ((s1->ele[i].x==s2->ele[j].x)&&(s1->ele[i].y>s2->ele[j].y))) {
            s3->ele[k++]=s2->ele[j++];
        }
        else { //when rows and cols are same
            if(s1->ele[i].value+s2->ele[j].value!=0) {
                s3->ele[k].x = s1->ele[i].x;
                s3->ele[k].y = s1->ele[i].y;
                s3->ele[k++].value = s1->ele[i].value+s2->ele[j].value;
            }
            i++;
            j++;
        }
    }
        //remaining elements
        while (i < s1->num) {
            s3->ele[k++] = s1->ele[i++];
        }
        while (j < s2->num) {
            s3->ele[k++] = s2->ele[j++];
        }

            s3->num=k;


    return s3;

}

void display(struct sparse s) {
    int i,j,k=0;
    for(i=0;i<s.rows;i++) {
        for(j=0;j<s.cols;j++) {
            if(k<s.num&&s.ele[k].x==i&&s.ele[k].y==j) {
                printf(" %d ",s.ele[k++].value);
            }
            else {
                printf(" 0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    // struct sparse s1;
    // create(&s1);
    // printf("\nThe sparse matrix is:\n");
    // display(s1);


    struct sparse s1, s2;

    // Matrix 1: 3x3 with 4 non-zero elements
    s1.rows = 3;
    s1.cols = 3;
    s1.num = 4;
    s1.ele = (struct element *)malloc(s1.num * sizeof(struct element));
    s1.ele[0] = (struct element){0, 0, 5};  // Element at (0, 0) with value 5
    s1.ele[1] = (struct element){1, 1, 8};  // Element at (1, 1) with value 8
    s1.ele[2] = (struct element){2, 2, 3};  // Element at (2, 2) with value 3
    s1.ele[3] = (struct element){0, 2, 6};  // Element at (0, 2) with value 6

    // Matrix 2: 3x3 with 3 non-zero elements
    s2.rows = 3;
    s2.cols = 3;
    s2.num = 3;
    s2.ele = (struct element *)malloc(s2.num * sizeof(struct element));
    s2.ele[0] = (struct element){0, 0, 4};  // Element at (0, 0) with value 4
    s2.ele[1] = (struct element){1, 1, 2};  // Element at (1, 1) with value 2
    s2.ele[2] = (struct element){0, 2, 1};  // Element at (0, 2) with value 1

    // Add the matrices
    struct sparse *result = add(&s1, &s2);

    if (result == NULL) {
        printf("Matrix addition failed.\n");
        free(s1.ele);
        free(s2.ele);
        return 1;
    }

    // Print the result of the addition
    printf("Resulting Sparse Matrix:\n");
    for (int i = 0; i < result->num; i++) {
        printf("Element at (%d, %d) = %d\n", result->ele[i].x, result->ele[i].y, result->ele[i].value);
    }

    // Free allocated memory
    free(s1.ele);
    free(s2.ele);
    free(result->ele);
    free(result);

    return 0;
}
