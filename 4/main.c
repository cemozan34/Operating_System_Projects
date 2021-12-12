// Cem OZAN / 250201003 - Like in Homework 1, I wrote my code in CodeBlocks IDE(Windows) and then test my code in ORACLE VM VirtualBox's Ubuntu console. And cannot find any mistake.
//And my gcc version __STDC_VERSION__ : 201710L . I think this is C17. (But not sure)
// I find the __STDC_VERSION__ value using "gcc -dM -E - < /dev/null" command.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <errno.h> // Included to test pthread_mutex_trylock()'s error message.

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct product{
	char product_name[50]; // (phone, tshirt, coke etc.)
	char product_type[30]; //(electronicDevice, clothing, market etc.)
	int price; // (can be integer between 1-1000)
}Product;

// Node structure that is used for linked list implementation.
struct node {

	Product data;
	struct node *next;
};



struct node *start = NULL; // Product1 Linked List1 starting node
struct node *start2 = NULL; // Product2 Linked List starting node
struct node *start3 = NULL; // Favories Linked List starting node

// Needed global variables for functions
struct node *current = NULL;
struct node *prev = NULL;
struct node *current2 = NULL;
struct node *prev2 = NULL;


// Declaring some of the functions that are used below not to encounter ubuntu terminal warnings
void insert_at_begin(struct product x);
void insert_at_begin2(struct product x);
void remove_data(Product data);
void remove_data2(Product data);
void traverse();
void traverse2();
void traverse3();


int count = 0; // # of elements of Product1 List
int count2 = 0; // # of elements of Product2 List
int count3 = 0; // # of elements of Favories List
int budget; // User's budget

char favoriteProductType[3][20];
Product lowerThanBudgetProducts[20]; // Array that holds data that are products that are lower or equal to budget.

void insert_at_begin3(struct product x) { // Insertion in Favories List
	struct node *t;
	t = (struct node*)malloc(sizeof(struct node));
	t->data = x;
	count3++;
	if (start3 == NULL) {
		start3 = t;
		start3->next = NULL;
		return;
	}
	t->next = start3;
	start3 = t;
}


Product traverseForThreadsAndProductList1(char* x) { // Traversing Product1 List to find a product whose product_type is equal to function parameter.
	struct node *t;
	t = start;
	if (t == NULL) {
		printf("Product1 list is empty.\n");
		exit(0);
	}
	while (t->next != NULL) {
		if((strcmp(t->data.product_type,x) == 0)){
			if(strcmp(t->data.product_type,"") != 0){
				return t->data;
			}

		}
		t = t->next;
	}
	if((strcmp(t->data.product_type,x) == 0)){
		if(strcmp(t->data.product_type,"") != 0){
				return t->data;
			}
	}
}

Product traverseForThreadsAndProductList2(char* x) { // Traversing Product2 List to find a product whose product_type is equal to function parameter.
	struct node *t;
	t = start2;
	if (t == NULL) {
		printf("Product2 list is empty.\n");
		exit(0);
	}
	while (t->next != NULL) {
		if((strcmp(t->data.product_type,x) == 0)){
			if(strcmp(t->data.product_type,"") != 0){
				return t->data;
			}
		}
		t = t->next;
	}
	if((strcmp(t->data.product_type,x) == 0)){
		if(strcmp(t->data.product_type,"") != 0){
			return t->data;
		}
	}
}

void remove_data(Product data) { // Removing product from Product1 List
	if(start==NULL) {
		printf("Product1 List not initialized\n");
		return;
	}
	current = start;
	while(current->next != NULL && strcmp(current->data.product_name,data.product_name)!=0) {
		prev = current;
		current = current->next;
	}
	if(strcmp(current->data.product_name,data.product_name)==0) {
		if((prev!= NULL) && (prev->next != NULL)){
			prev->next = prev->next->next;
			count--;
			printf("Removed product from Product1 List: %s\n",current->data.product_name);
			free(current);
		}
		else{
			count--;
			printf("Removed product from Product1 List: %s\n",current->data.product_name);
			free(current);
		}
	}
	else{
		printf("%s not found in the Product1 list.\n", data.product_name);
	}
}

void remove_data2(Product data) { // Removing product from Product2 List
	if(start2==NULL) {
		printf("Product2 List not initialized\n");
		return;
	}
	current2 = start2;
	while(current2->next != NULL && strcmp(current2->data.product_name,data.product_name)!=0) {
		prev2 = current2;
		current2 = current2->next;
	}
	if(strcmp(current2->data.product_name,data.product_name) == 0) {
		if((prev2!= NULL) && (prev2->next != NULL)){
			prev2->next = prev2->next->next;
			count2--;
			printf("Removed product from Product2 List: %s\n",current2->data.product_name);
			free(current2);
		}
		else{
			count2--;
			printf("Removed product from Product2 List: %s\n",current2->data.product_name);
			free(current2);
		}
	}
	else{
		printf("%s not found in the Product2 list.\n", data.product_name);
	}
}

void traverseLowerThanBudget(int budget){ // Function that traverses Favories List to display products that are affordable for the user
	int l = 0;
	struct node *t;
	t = start3;
	if (t == NULL) {
		printf("Favories is empty.\n");
		return;
	}
	printf("C\n");
	while (t->next != NULL) {
		if(t->data.price <= budget){
			printf("l: %d",l);
			if(l<20){
				lowerThanBudgetProducts[l] = t->data;
				l++;
			}
		}
		t = t->next;
	}

	if(l<20){
		if(t->data.price <= budget){
			lowerThanBudgetProducts[l] = t->data;
		}
	}
	for(int k = 0 ; k < 20 ; k++){
		if(strcmp(lowerThanBudgetProducts[k].product_name,"") != 0){
			printf("You can buy these product:%s\n",lowerThanBudgetProducts[k].product_name);
		}
	}
}

void* cutAndPaste(void* arg){ // Cutting products from Product1 and Product2 List and Paste them to the Favories List and delete these items from theirs previous list.
		int* core = (int*)arg;
		srand(time(0));
		while(count > 0 || count2 > 0){
				if(pthread_mutex_trylock(&mutex) == 0){
					printf("Type 1 thread is performing core:%d\n",*core);
					int num = (rand() % (2)) + 1; // 1-2. Choosing randomly a list. If num == 1 Product1 List, num == 2 Product2 List
					int num2 = (rand() % (3)); // 0-2. Choosing randomly a product_type. If num2 == 0 market, num2 == 1 electronic, num2 == 2 clothing
					if(num ==1){
						if(count == 0){
							printf("Product 1 List is empty\n");
							pthread_mutex_unlock(&mutex);
						}
						else{
							printf("favoriteProductType: %s\n",favoriteProductType[num2]);
							Product randomProduct1 = traverseForThreadsAndProductList1(favoriteProductType[num2]);
							printf("randomProduct1: %s\n",randomProduct1.product_name);
							insert_at_begin3(randomProduct1);
							remove_data(randomProduct1);
							pthread_mutex_unlock(&mutex);
						}
					}
					else{
						if(count2 ==0){
							printf("Product2 list is empty\n");
							pthread_mutex_unlock(&mutex);
						}
						else{
							printf("favoriteProductType: %s\n",favoriteProductType[num2]);
							Product randomProduct2 = traverseForThreadsAndProductList2(favoriteProductType[num2]); // Bu satırda patlıyor.
							printf("randomProduct2: %s\n",randomProduct2.product_name);
							insert_at_begin3(randomProduct2);
							remove_data2(randomProduct2);
							pthread_mutex_unlock(&mutex);
						}
					}
					printf("Type 1 thread is not performing core:%d\n",*core);
				}
		}
		pthread_exit(NULL);
}

Product traverseForThreadsAndProductListForType2(int x){ // Traversing the Product2 List to find a product whose index is equal to given parameter.
	struct node *t;
	int cc = 0;
	t = start2;
	if (t == NULL) {
		printf("Linked list is empty.\n");
		exit(0);
	}
	while (t->next != NULL) {
		if(cc == x){

			return t->data;
		}
		cc++;
		t = t->next;
	}
}

Product traverseForThreadsAndProductListForType1(int x){ // Traversing the Product1 List to find a product whose index is equal to given parameter.
	struct node *t;
	int cc = 0;
	t = start;

	if (t == NULL) {
		printf("Linked list is empty.\n");
		exit(0);
	}
	while (t->next != NULL) {
		if(cc == x){
			return t->data;
		}
		cc++;
		t = t->next;
	}
}

Product traverseForThreadsAndProductListForType3(int x){ // Traversing the Favories List to find a product whose index is equal to given parameter.
	struct node *t;
	int cc = 0;
	t = start3;
	if (t == NULL) {
		printf("Linked list is empty.\n");
		exit(0);
	}
	while (t->next != NULL) {
		if(cc == x){
			return t->data;
		}
		cc++;
		t = t->next;
	}
}

void* priceIncrease(void* arg){ // Price Increasing function that randomly increase product prices in lists.
	srand(time(0));
	while(count > 0 || count2 > 0){
		if(pthread_mutex_trylock(&mutex) == 0){
			printf("Type 2 thread performing\n");
			int num = (rand() % (3 - 1 + 1)) + 1; //selecting which product list I will use. (Product1 or Product2 or Favories List)
			if(num ==1){
				if(count ==0){
					printf("No product left in Product1 list\n");
				}
				else{
					int randomProductNumberForProductList11 = (rand() % (count - 1 + 1)) + 1;
					Product randomProduct1 = traverseForThreadsAndProductListForType1(randomProductNumberForProductList11);
					printf("%s's previous price:%d \n",randomProduct1.product_name,randomProduct1.price);
					Product* randomProduct1Pointer = &randomProduct1;
					randomProduct1Pointer->price += randomProduct1Pointer->price / 5;
					printf("%s's recent price:%d \n",randomProduct1.product_name,randomProduct1.price);
					printf("Type 2 thread is not performing\n");
				}
			}
			else if(num ==2){
				if(count2 == 0){
					printf("No product left in Product2 list\n");
				}
				else{
					int randomProductNumberForProductList21 = (rand() % (count2 - 1 + 1)) + 1;
					Product randomProduct2 = traverseForThreadsAndProductListForType2(randomProductNumberForProductList21);
					printf("%s's previous price:%d \n",randomProduct2.product_name,randomProduct2.price);
					Product* randomProduct2Pointer = &randomProduct2;
					randomProduct2Pointer->price += randomProduct2Pointer->price / 5;
					printf("%s's recent price:%d \n",randomProduct2.product_name,randomProduct2.price);
					printf("Type 2 thread is not performing\n");
				}
			}
			else{
				if(count3 == 0){
					printf("There is no product in favories list\n");
				}
				else{
					int randomProductNumberForProductList31 = (rand() % (count3 - 1 + 1)) + 1;
					Product randomProduct3 = traverseForThreadsAndProductListForType3(randomProductNumberForProductList31);
					printf("%s's previous price:%d \n",randomProduct3.product_name,randomProduct3.price);
					Product* randomProduct3Pointer = &randomProduct3;
					randomProduct3Pointer->price += randomProduct3Pointer->price / 5;
					printf("%s's recent price:%d \n",randomProduct3.product_name,randomProduct3.price);
					printf("Type 2 thread is not performing\n");
				}
			}
			pthread_mutex_unlock(&mutex);
		}
	}
		pthread_exit(NULL);
}
void* productOffering(void* arg) // Thread function that offers products whose prices are lower or equal to the user's budget.
{
	while(count > 0 || count2 > 0){
	 	if(pthread_mutex_trylock(&mutex) == 0){
	 		printf("Type 3 thread is performing\n");
			traverseLowerThanBudget(budget);
			printf("Type 3 thread is not performing\n");
			pthread_mutex_unlock(&mutex);
	 	}
	}
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	//Creating products
	Product product1; strcpy(product1.product_name,"phone"); strcpy(product1.product_type,"electronic"),product1.price=500;
	Product product2; strcpy(product2.product_name,"tshirt"); strcpy(product2.product_type,"clothing"),product2.price=10;
	Product product3; strcpy(product3.product_name,"coke"); strcpy(product3.product_type,"market"),product3.price=5;
	Product product4; strcpy(product4.product_name,"pasta"); strcpy(product4.product_type,"market"),product4.price=8;
	Product product5; strcpy(product5.product_name,"laptop"); strcpy(product5.product_type,"electronic"),product5.price=950;
	Product product6; strcpy(product6.product_name,"camera"); strcpy(product6.product_type,"electronic"),product6.price=400;
	Product product7; strcpy(product7.product_name,"pants"); strcpy(product7.product_type,"clothing"),product7.price=20;
	Product product8; strcpy(product8.product_name,"shoe"); strcpy(product8.product_type,"clothing"),product8.price=200;
	Product product9; strcpy(product9.product_name,"sneaker"); strcpy(product9.product_type,"clothing"),product9.price=150;
	Product product10; strcpy(product10.product_name,"keyboard"); strcpy(product10.product_type,"electronic"),product10.price=120;
	Product product11; strcpy(product11.product_name,"mouse"); strcpy(product11.product_type,"electronic"),product11.price=75;
	Product product12; strcpy(product12.product_name,"watch"); strcpy(product12.product_type,"electronic"),product12.price=770;
	Product product13; strcpy(product13.product_name,"coat"); strcpy(product13.product_type,"clothing"),product13.price=220;
	Product product14; strcpy(product14.product_name,"dishwasher"); strcpy(product14.product_type,"electronic"),product14.price=550;
	Product product15; strcpy(product15.product_name,"shorts"); strcpy(product15.product_type,"clothing"),product15.price=15;
	Product product16; strcpy(product16.product_name,"speaker"); strcpy(product16.product_type,"electronic"),product16.price=210;
	Product product17; strcpy(product17.product_name,"bread"); strcpy(product17.product_type,"market"),product17.price=2;
	Product product18; strcpy(product18.product_name,"cheese"); strcpy(product18.product_type,"market"),product18.price=7;
	Product product19; strcpy(product19.product_name,"milk"); strcpy(product19.product_type,"market"),product19.price=4;
	Product product20; strcpy(product20.product_name,"oat"); strcpy(product20.product_type,"market"),product20.price=11;

	//Inserting the products to the Product1 List
	for(int i = 0 ; i < 10 ; i++){
		switch (i){

				case 0: insert_at_begin(product1);
                               break;
				case 1: insert_at_begin(product2);
                               break;
                       	case 2: insert_at_begin(product3);
                               break;
                               case 3: insert_at_begin(product4);
                               break;
                               case 4: insert_at_begin(product5);
                               break;
                               case 5: insert_at_begin(product6);
                               break;
                               case 6: insert_at_begin(product7);
                               break;
                               case 7: insert_at_begin(product8);
                               break;
                               case 8: insert_at_begin(product9);
                               break;
                               case 9: insert_at_begin(product10);
                               break;
                               default: printf("Nothing added");
		}
	}

	//Inserting the products to the Product2 List
	for(int i = 10 ; i < 20 ; i++){
		switch (i){
				case 10: insert_at_begin2(product11);
                               break;
				case 11: insert_at_begin2(product12);
                               break;
                       	case 12: insert_at_begin2(product13);
                               break;
                               case 13: insert_at_begin2(product14);
                               break;
                               case 14: insert_at_begin2(product15);
                               break;
                               case 15: insert_at_begin2(product16);
                               break;
                               case 16: insert_at_begin2(product17);
                               break;
                               case 17: insert_at_begin2(product18);
                               break;
                               case 18: insert_at_begin2(product19);
                               break;
                               case 19: insert_at_begin2(product20);
                               break;
                               default: printf("Nothing added");
		}
	}


	printf("Products1:\n");
	traverse();
	printf("Products2:\n");
	traverse2();
	printf("Favories:\n");
	traverse3();

	char productType[10];

	for(int i = 0; i < 3; i++) {
 	printf("Please enter favorite product types (in lower case):");
		scanf("%s", productType);
		strcpy(favoriteProductType[i],productType);
	}

	printf("Enter budget:");
	scanf("%d", &budget);


	pthread_t threads[4];
	int* p1 = malloc(sizeof(int));
	int* p2 = malloc(sizeof(int));
	*p1=1;
	*p2=2;

	//Creating threads
	pthread_create(&threads[0], NULL, cutAndPaste, p1);
	pthread_create(&threads[1], NULL, cutAndPaste, p2);
	pthread_create(&threads[2], NULL, priceIncrease, NULL);
	pthread_create(&threads[3], NULL, productOffering, NULL);
	srand(time(0));

	// joining all threads
	for (int i = 0; i < 4; i++){
		pthread_join(threads[i], NULL);
	}
	return 0;
}

void insert_at_begin(struct product x) { // Function that inserts product to he Product1 List
	struct node *t;
	t = (struct node*)malloc(sizeof(struct node));
	t->data = x;
	count++;
	if (start == NULL) {
		start = t;
		start->next = NULL;
		return;
	}
	t->next = start;
	start = t;
}

void insert_at_begin2(struct product x) { // Function that inserts product to he Product2 List
	struct node *t;

	t = (struct node*)malloc(sizeof(struct node));
	t->data = x;
	count2++;
	if (start2 == NULL) {
		start2 = t;
		start2->next = NULL;
		return;
	}
	t->next = start2;
	start2 = t;
}


void traverse() { // Printing the products in Product1 List
	struct node *t;
	t = start;
	if (t == NULL) {
		printf("Product1 list is empty.\n");
		return;
	}
	if(count <0){
		printf("Product1 list is empty\n");
	}
	else{
		printf("There are %d elements in Product1 list.\n", count);

		while (t->next != NULL) {
			printf("Product_name: %s, product_type: %s, price: %d\n", t->data.product_name,t->data.product_type,t->data.price);
			t = t->next;
		}
		printf("Product_name: %s, product_type: %s, price: %d\n", t->data.product_name,t->data.product_type,t->data.price); // Print last node
	}

}

void traverse2() { // Printing the products in Product2 List
	struct node *t;
	t = start2;
	if (t == NULL) {
		printf("Product2 list is empty.\n");
		return;
	}
	if(count2 <0){
		printf("Product2 list is empty\n");
	}
	else{
		printf("There are %d elements in Product2 list.\n", count2);
		while (t->next != NULL) {
			printf("Product_name: %s, product_type: %s, price: %d\n", t->data.product_name,t->data.product_type,t->data.price);
			t = t->next;
		}
		printf("Product_name: %s, product_type: %s, price: %d\n", t->data.product_name,t->data.product_type,t->data.price); // Print last node
	}
}
void traverse3() { // Printing the products in Favories List
	struct node *t;
	t = start3;
	if (t == NULL) {
		printf("...........EMPTY...........\n");
		return;
	}
	while (t->next != NULL) {
		printf("Product_name: %s, product_type: %s, price: %d\n", t->data.product_name,t->data.product_type,t->data.price);
		t = t->next;
	}
	printf("Product_name: %s, product_type: %s, price: %d\n", t->data.product_name,t->data.product_type,t->data.price); // Print last node
}
