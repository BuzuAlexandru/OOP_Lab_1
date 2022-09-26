#include<stdio.h>
#include<stdlib.h>
#define MAX 7

void red();
void green();
void blue();
void purple();
void cyan();
void load_file();
void save_file();
void insert();
void delete();
void display();
void search();
void sort_queue();
void reverse();
int priority_queue();
void enqueue_pr();
void dequeue_pr();
void display_pr();
int peek();
int isFull();
int circular_queue();
void cq_insert();
void cq_delete();
void cq_display();

int queue_array[];
int rear = - 1;
int front = - 1;
int idx = -1;
char pqVal[];
int pqPriority[];
int rr = - 1;
int fr = - 1;
int queue_array_c[MAX];

//main menu
int main(){
    int choice;
    printf("\n");
    
    while (1){
        blue();printf("\n");
        printf("1. Insert element to queue (queue) \n");
        printf("2. Delete element from queue (dequeue) \n");
        printf("3. Display all elements of queue \n");
        printf("4. Open file \n");
        printf("5. Save to a file \n");
        printf("6. Search in queue \n");
        printf("7. Sort elements \n");
        printf("8. Reverse queue \n");
        printf("9. Go to priority queue menu \n");
        printf("10. Go to circular queue menu \n");
        printf("0. Quit \n");
        cyan();
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice){
        case 1: insert(); break;
        case 2: delete(); break;
        case 3: display(); break;
        case 4: load_file(); break;
        case 5: save_file(); break;
        case 6: search(); break;
        case 7: sort_queue(); break;
        case 8: reverse(); break;
        case 9: priority_queue(); break;
        case 10: circular_queue(); break;
        case 0: exit(1);
        default: red();printf("Input error. Try again. \n");
        }
        printf("\n");
    }
}

void red(){
  printf("\033[1;31m");
}

void green(){
  printf("\033[1;32m");
}

void blue(){
  printf("\033[1;34m");
}

void purple(){
  printf("\033[1;35m");
}

void cyan(){
  printf("\033[1;36m");
}

void display(){
    int i;

    if(front == - 1)
        {red();printf("Queue is empty. Try adding elements first. \n");}
    else{
        green();
        printf("Queue is : ");
        for(i = front; i <= rear; i++){
            printf("%d ", queue_array[i]);
            }
        printf("\n");
    }
}

void load_file(){
    int i = 0;
    front = 0;
    rear = -1;

    FILE *input  = fopen("input.txt", "r");

    if (input == NULL) { red(); 
        printf("Error! Could not open file\n"); 
        exit(-1);
    }
    else{green();
        printf("File uploaded successfully \n");
        while(fscanf(input, "%d ", &queue_array[i]) != EOF){
            i++;
            rear++;
        }
    }
    fclose(input);
}

void save_file() {
    int i;
    FILE *output  = fopen("ouput.txt", "w");
    freopen(NULL, "w+", output);

    if(front == - 1){red();
        printf("Queue is empty. Try adding elements first. \n");}
    else{
        for (i = front; i <= rear; i ++)
            fprintf(output, "%d ", queue_array[i]);
        fprintf(output, "%d ", queue_array[i]);
    }

    fclose(output);
    green();
    printf("Your queue was saved in ouput.txt ");
}

void insert(){
    int item;
        if(front== - 1)
            front = 0;
            green();
            printf("Insert the element in queue : ");
            scanf("%d", &item);
            rear = rear + 1;
            queue_array[rear] = item;
    }

void delete(){
    if(front == - 1 || front > rear){red();
        printf("Queue is empty. \n");
        return;
    }
    else{green();
        printf("Deleted from queue element : %d \n", queue_array[front]);
        front = front + 1;
    }
}

void search() {
    int s_el;
    int found = 0;
    green();
    printf("Search for element: ");
    scanf("%d", &s_el);

    if(front == - 1){red();
        printf("Queue is empty. \n");}
    else{
        for (int i = 0; i <= rear; i++) {
            if (queue_array[i] == s_el) 
                found = 1;
        }
        if (found == 1) {green();
            printf("Element has been found. \n");
        }
        else{red(); 
            printf("Element has not been found. \n");}
    }
}

void sort_queue(){
    int temp;

    if(front == - 1){red();
        printf("Queue is empty \n");}
    else{
        for (int i = front; i <= rear; ++i) {
            for (int j = i + 1; j <= rear; ++j) {
                if (queue_array[i] > queue_array[j]) {
                    temp = queue_array[i];
                    queue_array[i] = queue_array[j];
                    queue_array[j] = temp;
                }
            }
        }
        display();
        green();
        printf("The queue is now sorted. \n");
    }  
}
void reverse() {
    int temp;
    int i, j;
    if(front == - 1){red();
        printf("Queue is empty \n");}
    else {
        for(i = front, j = rear; i < j; i++, j--){
            temp = queue_array[i];
            queue_array[i] = queue_array[j];
            queue_array[j] = temp;
	    }   
        display();
        green();
        printf("The queue is now reversed.\n");
    }
}

// priority queue menu
int priority_queue(){
    int choice;

    while (1){
        blue();
        printf("\n");
        printf("PRIORITY QUEUE MENU\n");
        printf("1. Insert element to priority queue (queue) \n");
        printf("2. Delete element from priority queue (dequeue) \n");
        printf("3. Display all elements \n");
        printf("4. Show the element with the highest priority \n");
        printf("5. Return to main menu \n");
        printf("0. Exit the program \n");
        cyan();
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice){
        case 1: enqueue_pr(); break;
        case 2: dequeue_pr(); break;
        case 3: display_pr(); break;
        case 4: green();printf("Element with the highest priority is "); peek(); break;
        case 5: main();
        case 0: exit(1);
        default: red();printf("Input error. Try again. \n");
        }
        printf("\n");
    }
}

// Insert the element in maintaining items in sorted order of their priority
void enqueue_pr()
{
        int priority;
        char data;
        int t_priority;
        char t_data;
        green();
        printf("Insert the element in priority queue (nr and priority separated by space): ");
        scanf("\n%c %d", &data, &priority);
        // first item being entered
        if(idx == -1){
            idx++; // increase the index
            pqVal[idx] = data;
            pqPriority[idx] = priority;
        }
        else{
             // Increase the index
            idx++;
            pqVal[idx] = data;
            pqPriority[idx] = priority;            
            // in reverse order
            for(int i = 0; i <= idx;i++){
                for(int j = i+1; j <= idx;j++){
                    if(pqPriority[j] >= pqPriority[i]){
                        t_data = pqVal[i];
                        t_priority = pqPriority[i];
                        pqVal[i]= pqVal[j];
                        pqPriority[i]=pqPriority[j];
                        pqVal[j] = t_data;
                        pqPriority[j] = t_priority;
                    }
                }
                
            }
        }

    }

void dequeue_pr()
{
        peek();
        idx--;
        green();
        printf(" is the deleted element\n");
        
}
void display_pr(){
    if (idx == -1)
        {printf("Queue is empty.");}
    for (int i = 0; i <= idx; i++) {
        printf("(%c, %d)\n",pqVal[i], pqPriority[i]);
    } 
}

int peek()
{
    green();
    printf("(%c, %d)",pqVal[idx], pqPriority[idx]);
    return idx;
}


// circular queue menu
int circular_queue(){
    int choice;

    while (1){
        printf("\n");
        blue();
        printf("CIRCULAR QUEUE MENU\n");
        printf("\n");
        printf("1. Insert element to circular queue (queue) \n");
        printf("2. Delete element from circular queue (dequeue) \n");
        printf("3. Display all elements \n");
        printf("4. Return to main menu \n");
        printf("0. Exit the program \n");
        cyan();
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice){
        case 1: cq_insert(); break;
        case 2: cq_delete(); break;
        case 3: cq_display(); break;
        case 4: main(); break;
        case 0: exit(1);
        default: red();printf("Input error. Try again. \n");
        }
        printf("\n");
    }
}

void cq_insert(){
    int item;
    if ((fr == rr + 1) || (fr == 0 && rr == MAX - 1)){
        red();printf("Queue is full \n");}
    else {
        if (fr == -1) 
            fr = 0;
            green();
            printf("Insert the element in queue : ");
            scanf("%d", &item);
            rr = (rr + 1) % MAX;
            queue_array_c[rr] = item;
    }
}

void cq_delete(){
    if (fr == -1) {red();
        printf("Queue is empty \n");
    } 
    else {
        if (fr == rr) {
            fr = -1;
            rr = -1;
        } 
        else {green();
            printf("Element deleted from queue is : %d \n", queue_array_c[fr]);
            fr = (fr + 1) % MAX;
        }
    }
}

void cq_display(){
    int i;
    if (fr== -1){red();
        printf("Queue is empty \n");}
    else {
        green();
        printf("Queue is : \n");
        for (i = fr; i != rr; i = (i + 1) % MAX) {
            printf("%d ", queue_array_c[i]);
        }
        printf("%d ", queue_array_c[i]);
    }
}