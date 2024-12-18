#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void inserStart(Node**head, int value){
    Node *newNode = createNode(value);
    newNode->next = *head;
    if (*head!= NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
};

void insertEnd(Node **head, int value)
{
    Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node **head, int position, int value){
    if (position == 1)
    {
        inserStart(head, value);
        return;
    }
    Node *newNode = createNode(value);
    Node *temp = *head;
    int i;
    for ( i = 1; i < position - 1 && temp!= NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Vi tri %d khong co node.\n", position);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next!= NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteNodeAtStart(Node **head){
    if (*head == NULL)
    {
        printf("Danh sach rong.\n");
        return;
    }
    Node *temp = *head;
    *head = temp->next;
    if (*head!= NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteNodeAtEnd(Node **head){
    if (*head == NULL)
    {
        printf("Danh sach rong.\n");
        return;
    }
    Node *temp = *head;
    while (temp->next->next!= NULL)
    {
        temp = temp->next;
    }
    Node *delNode = temp->next;
    temp->next = NULL;
    free(delNode);
}

void deleteNodeAtValueRandom(Node **head, int value){
    Node *temp = *head;
    while (temp!= NULL && temp->data!= value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Khong tim thay node co gia tri %d.\n", value);
        return;
    }
    if (temp->prev!= NULL)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next!= NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void printReverse(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sach rong.\n");
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Danh sach duoc duyet theo thu tu tu cuoi den dau: \n");
    printf("NULL");
    while (temp != NULL)
    {
        printf(" <--> %d ", temp->data);
        temp = temp->prev;
    }
    printf(" <--> NULL \n");
}

void printList(Node* head) {
	if(head == NULL){
		printf("Danh sach rong. \n");
		return;
	}
    Node* temp = head;
    printf("Danh sach duoc duyet theo thu tu tu dau den cuoi : \n");
    printf("NULL");
    while (temp != NULL) {
        printf(" <--> %d", temp->data);
        temp = temp->next;
    }
    printf(" <--> NULL\n");
}

int main()
{
    Node *head = NULL;
    int choice,value,position;

     insertEnd(&head, 10);
     insertEnd(&head, 26);
     insertEnd(&head, 32);
     insertEnd(&head, 41);


    do{
        printf("\n");
        printf("----------------MENU----------------\n");
        printf("1. Them phan tu vao dau danh sach.\n");
        printf("2. Them phan tu vao cuoi danh sach.\n");
        printf("3. Chen phan tu vao vi tri cu the. \n");
        printf("4. Xoa phan tu dau danh sach.\n");
        printf("5. Xoa phan tu cuoi danh sach.\n");
        printf("6. Xoa phan tu theo gia tri.\n");
        printf("7. Duyet danh sach tu dau den cuoi.\n");
        printf("8. Duyet danh sach tu cuoi den dau.\n");
        printf("9. Thoat. \n");
        printf("Chon: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("vui long nhap phan tu \n");
            scanf("%d", &value);
            inserStart(&head,value);
            break;
        case 2:
            printf("vui long nhap phan tu de them vo cuoi : .\n");
            scanf("%d", &value);
            insertEnd(&head, value);
            break;
        case 3:
            printf("vui long nhap vi tri can them : \n");
            scanf("%d", &position);
            printf("Vui long nhap phan tu can them : \n");
            scanf("%d", &value);
            insertAtPosition(&head, position, value);
            break;
        case 4:
            deleteNodeAtStart(&head);
            printf("ban da xoa thanh cong gia tri cua phan tu dau .\n");
            break;
        case 5:
            deleteNodeAtEnd(&head);
            printf("ban da xoa thanh cong gia tri cua phan tu cuoi");
			break;
        case 6:
            printf("vui long nhap gia tri can xoa : ");
            scanf("%d", &value);
			deleteNodeAtValueRandom(&head,value);
            break;
        case 7:
        	printf("danh sach duoc duyet tu dau den cuoi la : \n");
        	printList(head);
            break;
        case 8:
        	printf("danh sach duoc duyet tu cuoi den dau la : \n");
        	printReverse(head);
            break;
        case 9:
            printf("thoat");
            exit(1);
            break;
        default:
            printf("Lua chon khong hop le.\n");
            break;
        }
    }while(1);
    return 0;
}
