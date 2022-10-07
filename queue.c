#include<stdio.h>
#include<stdlib.h>

int* queue;
int rear=-1,front=-1, n=0, qType;

int isEmpty()
{
    if(front==-1 || front==rear+1)
        return 1;
    else
        return 0;
}

void display() {
    int i;
    if (isEmpty()) 
    {
        printf("\nThe queue is empty\n");
        return;
    }
    printf("\n\n");
    for (i = front; i <= rear; i++)
        printf("%d  ", queue[i]);
    printf("\n");
}

void enqueue(int nr)
{
    if(front==-1) front=0;
    rear=rear+1;
    queue[rear]=nr;
}

void dequeue()
{
    int nr;
    if(isEmpty())
    {
        printf("Queue is empty. Could not perform operation\n");
        return;
    }

    nr=queue[front];
    for(int i=front;i<rear;i++)
        queue[i]=queue[i+1];

    queue[rear]=0;
    rear--;

    printf("Element deleted from queue is : %d\n", nr);
}

void searchQueue(int nr)
{
    int i, count=0;
    for(i=front;i<=rear;i++)
    {
        if(queue[i]==nr)
        {
            printf("\nElement found at position %d\n",i+1);
            count++;
        }
    }
    if(count>0) return;
    printf("\nElement not found\n");
    return;
}

void sortQueue()
{
    int i,j,temp;
    for(i=front;i<=rear;i++)
    {
        for(j=i+1;j<=rear;j++)
        {
            if(queue[i]>queue[j])
            {
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }
}

void reverseQueue()
{
    int i,temp;
    for(i=front;i<=rear/2;i++)
    {     
        temp=queue[i];
        queue[i]=queue[rear-i];
        queue[rear-i]=temp; 
    }
}

void enqueuePriority(int nr)
{
    int i;

    if(front==-1)
        front=0;
    if(rear==-1)
    {
        rear=0;
        queue[rear]=nr;
    }
    else
    {
        for(i=rear;i>=front;i--)
        {
            if(nr>queue[i])
                queue[i+1]=queue[i];
            else
                break;
        }
        queue[i+1]=nr;
        rear++;
    }
}

void enqueueCircular(int nr)
{
    if(front==-1)
        front=0;
    if(rear==n-1)
        rear=0;
    else
        rear=rear+1;
    queue[rear]=nr;
}

void loadQueue()
{
    FILE *save;
    char a;
    int i=0;

    save=fopen("savefile.txt","r");

    if(save==NULL)
    {
        printf("Could not access file.");
        return;
    }

    if((a=fgetc(save)) != EOF) n = a -'0';

    queue=realloc(queue, n*sizeof(int));

    while((a=fgetc(save))!= EOF)
    {
        if(qType==1)
        enqueue(a-'0');
        else if(qType==2)
        enqueuePriority(a-'0');
        else if(qType==3)
        enqueueCircular(a-'0');
    }

    fclose(save);
    printf("Loaded queue from file.\n");
}

void saveQueue()
{
    FILE *save;
    int i;

    save=fopen("savefile.txt","w");

    if(save==NULL)
    {
        printf("Could not access file.");
    }

    fprintf(save,"%d",n);

    for(i=front;i<=rear;i++){
        fputc(queue[i]+'0',save);
    }

    fclose(save);
    printf("Queue has been saved.\n");
}

void menu()
{
    
}

int main ()
{
    system("clear");

    queue=(int*)malloc(n*sizeof(int));

    int option, nr;

    printf("\nChoose type of queue you want to work with:\n"
            "(1) Regular queue (2) Priority queue (3) Circular queue (0) Exit\n"
            "Enter your choice: ");
    while(1)
    {
        scanf("%d", &qType);
        if(qType == 0) exit(0);
        if(qType == 1 || qType == 2 || qType == 3) {break;}
        else printf("Choose a valid option: ");
    }
    if(qType == 1 || qType == 3)
        while(1)
        {
            printf("\n(1) Enqueue (2) Dequeue (3) Search (4) Sort (5) Reverse (6) Display "
                    "\n(7) Save (8) Load (0) Exit "
                    "\nEnter your choice : ");
            scanf("%d",&option);
            switch(option)
            {
                case 1:
                    printf("\nInput the element you want inserted into the queue : ");
                    n++;
                    queue=realloc(queue,n*sizeof(int));
                    scanf("%d",&nr);
                    if(qType == 1)enqueue(nr);
                    else enqueueCircular(nr);
                    break;
                case 2:
                    dequeue();
                    n--;
                    queue=realloc(queue,n*sizeof(int));
                    break;
                case 3:
                    printf("\nInput the element you are searching for : ");
                    scanf("%d",&nr);
                    searchQueue(nr);
                    break;
                case 4:
                    sortQueue();
                    printf("\nSorted Queue is : ");
                    display();
                    break;
                case 5:
                    reverseQueue();
                    printf("\nReversed queue is : ");
                    display();
                    break;
                case 6:
                    printf("\nThe elements of the current queue are : ");
                    display();
                    break;
                case 7:
                    saveQueue();
                    break;
                case 8:
                    printf("\nCurrent queue will be deleted.\n");
                    free(queue);
                    queue=(int*)malloc(n*sizeof(int));
                    loadQueue();
                    break;
                case 0:
                    free(queue);
                    exit(0);
                default:
                    printf("\nChoose a valid option: \n");
                    break;
            }
        }
        else 
            while(1)
        {
            printf("\n(1) Enqueue (2) Dequeue (3) Search (4) Display (5) Save (6) Load (0) Exit"
                    "\nEnter your choice : ");
            scanf("%d",&option);
            switch(option)
            {
                case 1:
                    printf("\nInput the element you want inserted into the queue : ");
                    n++;
                    queue=realloc(queue,n*sizeof(int));
                    scanf("%d",&nr);
                    enqueuePriority(nr);
                    break;
                case 2:
                    dequeue();
                    n--;
                    queue=realloc(queue,n*sizeof(int));
                    break;
                case 3:
                    printf("\nInput the element you are searching for : ");
                    scanf("%d",&nr);
                    searchQueue(nr);
                    break;
                case 4:
                    printf("\nThe elements of the current queue are : ");
                    display();
                    break;
                case 5:
                    saveQueue();
                    break;
                case 6:
                    printf("\nCurrent queue will be deleted.\n");
                    free(queue);
                    queue=(int*)malloc(n*sizeof(int));
                    loadQueue();
                    break;
                case 0:
                    free(queue);
                    exit(0);
                default:
                    printf("\nChoose a valid option: \n");
                    break;
            }
        }
}