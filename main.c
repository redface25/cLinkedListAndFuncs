#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>


typedef struct List {
    int val;
    struct List* next;
}List;

typedef struct BinaryTree{
    int val;

    struct BinaryTree *right;
    struct BinaryTree *left;
    

}BinaryTree;

int amt;

List *createListFromArr(int* arr){
    List *list;

    for(int i = 0; i == sizeof(arr); i++){
        list->val = arr[i];
        list = list->next;
    }

    return list;
}

List *createList(){
    int n;
    time_t t;
    List* p = NULL;
    List* head = NULL;
    List* temp = NULL;

    printf("how many time you wanna iterate: ");
    scanf("%d", &n);
    srand((unsigned) time(&t)*n);

    for(int i = 0; i < n; i++){

        temp = (List*)malloc(sizeof(List));
        temp->val = rand() % 82;
        printf("temp->val: %d\n", temp->val);
        temp->next = NULL;

        if(head == NULL){
            head = temp;
        }
        else{
            p = head;
            while(p->next != NULL){
                printf("p->val: %i\n", p->val);
                p = p->next;
            }
            p->next = temp;   
        }
    }

    printf("n val: %i\n", n);
    amt = n / 100;

    return head;
    free(head);
}

List *SortList(List *list){
    int i = 0;
    int *arr;

    List *temp = list;

    // gets the amount of items in list
    while (temp != NULL){
        temp = temp->next;
        i++;
    }

    free(temp);
    
    temp = list;

    arr = malloc(i * sizeof(int));
    
    //allocating values to array
    for(int j = 0; j == i; j++){
        arr[j] = temp->val;
        temp = temp->next;
    }
    
}

BinaryTree *createBinaryTree(int* arr, List* list){
    BinaryTree *Tree = NULL;
    int sizeOfArr = sizeof(arr);
    int* tempArr = malloc(sizeOfArr);
    int tempInt;

    
    if(arr != NULL){
        //sorts array
        for (int i = 0; i < sizeOfArr; i++) {     
            for (int j = i+1; j < sizeOfArr; j++) {     
               if(arr[i] > arr[j]) {    
                   tempInt = arr[i];    
                   arr[i] = arr[j];    
                   arr[j] = tempInt;    
               }     
            }     
        }

        int middleVal = arr[sizeOfArr / 2];

        Tree->val = middleVal;
        BinaryTree *TreeLeft = Tree->left;
        BinaryTree *TreeRight = Tree->right;

  
        for (int i = 0; i < sizeOfArr; i++){
            if(arr[i] > middleVal){
               
                TreeRight->val = arr[i];
                
                if(arr[i+1] > arr[i]){
                    TreeRight = TreeRight->right;
                }
                else{
                    TreeRight = TreeRight->left;
                }
            }

            else if(arr[i] < middleVal){
            
                TreeLeft->val = arr[i];
            
                if(arr[i+1] > arr[i]){
                    TreeLeft = TreeLeft->right;

                }
                else{
                    TreeLeft = TreeLeft->left;
                }
            }
        }
        

    }
    if(list != NULL){
        
    }
    return Tree;
}

int main(){
    List* list;
    int i = 0;

    list = createList();

    printf("amount %i\n", amt);

    printf("pointer %p\n", list);

    List *temp = list;
    while(temp != NULL){
        printf("i val: %d\n", i);
        printf("list->val val: %d\n", temp->val);
        temp = temp->next;
        i++;
    }
}