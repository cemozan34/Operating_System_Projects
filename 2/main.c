#include <stdio.h>
#include <stdlib.h>

// Like in Homework 1, I wrote my code in CodeBlocks IDE(Windows) and then test my code in ORACLE VM VirtualBox's Ubuntu console. And cannot find any mistake. And my gcc version __STDC_VERSION__ : 201710L . I think this is C17.
// I find the __STDC_VERSION__ value using "gcc -dM -E - < /dev/null" command.

int compare(char a[],char b[]){ // Because of preventing string.h, I wrote my compare method that compares 2 strings.
    int flag=0,i=0;  // integer variables declaration
    while(a[i]!='\0' &&b[i]!='\0')
    {
       if(a[i]!=b[i])
       {
           flag=1;
           break;
       }
       i++;
    }
    if(flag==0){
       return 1;
    }

    else{
        return 0;
    }

}
typedef struct { // I used typedef struct because I am more familier the implementation of typedef.
  size_t used; // size_t is an unsigned integral data type
  size_t size;
  char *array; // dynamic array's values store in this variable.
} Array;
void initArray(Array *a, size_t initialSize) {
  a->array = malloc(initialSize); // to reserve memory place in RAM with respect to initialSize's value which will be 5 at the beginnig.
  a->used = 0; // initially used = 0.
  a->size = initialSize; // size will be initialSize at the beginning.
}

void insertArray(Array *a, char *element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size. In this situation a->size will be doubled.
  int l = 0;
  if (a->used >= a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(char)); // realloc protects values which already placed and reserve more space.
  }
  while(element[l] != '\0'){ // checking values with respect to \0 because all strings end with \0
    a->array[a->used++] = element[l];
    l++;
  }
a->array[a->used++] = '\0'; //each string ends with \0. So I put too.

}

void showMainMenu(){ //Showing main menu.

    printf("----MAIN MENU----\n");
    printf("1- Buy a Product\n");
    printf("2- List all products\n");
    printf("3- Shopping Summary\n");
    printf("4- Exit\n");
    printf("-----------------\n");

}
typedef struct{ // product's attributes are defined here.

    char *productName;
    double price;
    int quantity;


}Product;
int main()
{
    showMainMenu();

    Product* ptr; // To give the product's values to them I used same pointer for each product.

    // Creating products as an object.
    Product bread;
    Product egg;
    Product pasta;
    Product fish;
    Product milk;
    Product waterSmall;
    Product handSanitizer;
    Product toothPaste;
    Product pizza;
    Product chocolate;

    // Implementations of products while using pointer.
    ptr = &bread;

    ptr->price = 3.5;
    bread.productName = "Bread";
    ptr->quantity = 10;

    ptr = &egg;

    ptr->price = 2.82;
    egg.productName = "Egg";
    ptr->quantity = 30;


    ptr = &pasta;

    ptr->price = 2.79;
    pasta.productName = "Pasta";
    ptr->quantity = 15;


    ptr = &fish;

    ptr->price = 15.98;
    fish.productName = "Fish";
    ptr->quantity = 25;


    ptr = &milk;

    ptr->price = 10.26;
    milk.productName = "Milk";
    ptr->quantity = 10;

    ptr = &waterSmall;

    ptr->price = 1.55;
    waterSmall.productName = "Water Small";
    ptr->quantity = 35;


    ptr = &handSanitizer;

    ptr->price = 20.55;
    handSanitizer.productName = "Hand Sanitizer";
    ptr->quantity = 20;


    ptr = &toothPaste;

    ptr->price = 10.83;
    toothPaste.productName = "Toothpaste";
    ptr->quantity = 15;


    ptr = &pizza;

    ptr->price = 15.30;
    pizza.productName = "Pizza";
    ptr->quantity = 10;


    ptr = &chocolate;

    ptr->price = 5.21;
    chocolate.productName = "Chocolate";
    ptr->quantity = 40;

    Product productArray[10] = {bread,egg,pasta,fish,milk,waterSmall,handSanitizer,toothPaste,pizza,chocolate}; // Adding products to the array which type is Product too.
    int choice;
    char productName[50];
    int quantity;
    Array dynamicArray; // Creating dynamicArray.
    initArray(&dynamicArray,5); //Initially 5 bytes.
    while(1){


        printf("Enter the choice:");
        scanf("%d",&choice); // Taking choice input.
        if(choice == 1){ // If user enters 1 program takes product name and quantity from user and update quantity of the product which is taken from user if the user enters valid amount of quantity.
            printf("Name of product:");
            scanf("%s",productName); // Taking product name input.

            if(compare(productName,"Fish") || compare(productName,"fish")){ // There is two different types of writing product name because I wanted to protect program from any misunderstanding just in case.
                printf("Quantity of product:");
                scanf("%d",&quantity); // Taking quantity input of the product.
                if (quantity <= fish.quantity){
                    insertArray(&dynamicArray,"fish"); // Inserting product to the dynamic array with using insertArray method that I implement above.
                    printf("You bought %d Fish\n",quantity);
                    fish.quantity -= quantity; // Decreasing of the quantity of the product with respect to user quantity input.
                }
                else{
                    printf("There is not enough Fish\n");
                }
            }

            else if(compare(productName,"Egg") || compare(productName,"egg")){ // There is two different types of writing product name because I wanted to protect program from any misunderstanding just in case.
;
                printf("Quantity of product:");
                scanf("%d",&quantity); // Taking quantity input of the product.
                if (quantity <= egg.quantity){
                        insertArray(&dynamicArray,"egg"); // Inserting product to the dynamic array with using insertArray method that I implement above.
                    printf("You bought %d Egg\n",quantity);
                    egg.quantity -= quantity; // Decreasing of the quantity of the product with respect to user quantity input.
                }
                else{
                    printf("There is not enough Egg\n");
                }
            }

            else if(compare(productName,"Pasta") || compare(productName,"pasta")){ // There is two different types of writing product name because I wanted to protect program from any misunderstanding just in case.

                printf("Quantity of product:");
                scanf("%d",&quantity); // Taking quantity input of the product.
                if (quantity <= pasta.quantity){
                        insertArray(&dynamicArray,"pasta"); // Inserting product to the dynamic array with using insertArray method that I implement above.
                    printf("You bought %d Pasta\n",quantity);
                    pasta.quantity -= quantity; // Decreasing of the quantity of the product with respect to user quantity input.
                }
                else{
                    printf("There is not enough Pasta\n");
                }
            }

            else if(compare(productName,"bread") || compare(productName,"Bread")){ // There is two different types of writing product name because I wanted to protect program from any misunderstanding just in case.

                printf("Quantity of product:");
                scanf("%d",&quantity); // Taking quantity input of the product.
                if (quantity <= bread.quantity){
                        insertArray(&dynamicArray,"bread"); // Inserting product to the dynamic array with using insertArray method that I implement above.
                    printf("You bought %d Bread\n",quantity);
                    bread.quantity -= quantity; // Decreasing of the quantity of the product with respect to user quantity input.
                }
                else{
                    printf("There is not enough Bread\n");
                }
            }

            else if(compare(productName,"Milk") || compare(productName,"milk")){ // There is two different types of writing product name because I wanted to protect program from any misunderstanding just in case.

                printf("Quantity of product:");
                scanf("%d",&quantity); // Taking quantity input of the product.
                if (quantity <= milk.quantity){
                        insertArray(&dynamicArray,"milk"); // Inserting product to the dynamic array with using insertArray method that I implement above.
                    printf("You bought %d Milk\n",quantity);
                    milk.quantity -= quantity; // Decreasing of the quantity of the product with respect to user quantity input.
                }
                else{
                    printf("There is not enough Milk\n");
                }
            }

            else if(compare(productName,"Water Small") || compare(productName,"water small")){ // There is two different types of writing product name because I wanted to protect program from any misunderstanding just in case.

                printf("Quantity of product:");
                scanf("%d",&quantity); // Taking quantity input of the product.
                if (quantity <= waterSmall.quantity){
                        insertArray(&dynamicArray,"water small"); // Inserting product to the dynamic array with using insertArray method that I implement above.
                    printf("You bought %d Water Small\n",quantity);
                    waterSmall.quantity -= quantity; // Decreasing of the quantity of the product with respect to user quantity input.
                }
                else{
                    printf("There is not enough Water Small\n");
                }
            }

            else if(compare(productName,"Hand Sanitizer") || compare(productName,"hand sanitizer")){ // There is two different types of writing product name because I wanted to protect program from any misunderstanding just in case.

                printf("Quantity of product:");
                scanf("%d",&quantity); // Taking quantity input of the product.
                if (quantity <= handSanitizer.quantity){
                        insertArray(&dynamicArray,"hand sanitizer"); // Inserting product to the dynamic array with using insertArray method that I implement above.
                    printf("You bought %d Hand Sanitizer\n",quantity);
                    handSanitizer.quantity -= quantity; // Decreasing of the quantity of the product with respect to user quantity input.
                }
                else{
                    printf("There is not enough Hand Sanitizer\n");
                }
            }

            else if(compare(productName,"Toothpaste") || compare(productName,"toothpaste")){ // There is two different types of writing product name because I wanted to protect program from any misunderstanding just in case.

                printf("Quantity of product:");
                scanf("%d",&quantity); // Taking quantity input of the product.
                if (quantity <= toothPaste.quantity){
                        insertArray(&dynamicArray,"toothpaste"); // Inserting product to the dynamic array with using insertArray method that I implement above.
                    printf("You bought %d Toothpaste\n",quantity);
                    toothPaste.quantity -= quantity; // Decreasing of the quantity of the product with respect to user quantity input.
                }
                else{
                    printf("There is not enough Toothpaste\n");
                }
            }

            else if(compare(productName,"pizza") || compare(productName,"Pizza")){ // There is two different types of writing product name because I wanted to protect program from any misunderstanding just in case.

                printf("Quantity of product:");
                scanf("%d",&quantity); // Taking quantity input of the product.
                if (quantity <= pizza.quantity){
                        insertArray(&dynamicArray,"pizza"); // Inserting product to the dynamic array with using insertArray method that I implement above.
                    printf("You bought %d Pizza\n",quantity);
                    pizza.quantity -= quantity; // Decreasing of the quantity of the product with respect to user quantity input.
                }
                else{
                    printf("There is not enough Pizza\n");
                }
            }

            else if(compare(productName,"chocolate") || compare(productName,"Chocolate")){ // There is two different types of writing product name because I wanted to protect program from any misunderstanding just in case.

                printf("Quantity of product:");
                scanf("%d",&quantity); // Taking quantity input of the product.
                if (quantity <= chocolate.quantity){
                        insertArray(&dynamicArray,"chocolate"); // Inserting product to the dynamic array with using insertArray method that I implement above.
                    printf("You bought %d Chocolate\n",quantity);
                    chocolate.quantity -= quantity; // Decreasing of the quantity of the product with respect to user quantity input.
                }
                else{
                    printf("There is not enough Chocolate\n");
                }
            }
            else{ // Checking if the user enter valid product name.
                printf("Product not found\n");
            }
        }
        else if (choice == 2){ // If user enters 2 program lists all the products with their current quantities.

            printf("------Product List------\n");
            for (int k = 0 ; k < 10 ; k++){
                if(productArray[k].productName=="Fish"){
                    printf("Product name:%s, Unit price:%.2f, Quantity:%d \n",fish.productName,fish.price,fish.quantity);
                }
                if(productArray[k].productName=="Bread"){
                    printf("Product name:%s, Unit price:%.2f, Quantity:%d \n",bread.productName,bread.price,bread.quantity);
                }
                if(productArray[k].productName=="Egg"){
                    printf("Product name:%s, Unit price:%.2f, Quantity:%d \n",egg.productName,egg.price,egg.quantity);
                }
                if(productArray[k].productName=="Pasta"){
                    printf("Product name:%s, Unit price:%.2f, Quantity:%d \n",pasta.productName,pasta.price,pasta.quantity);
                }
                if(productArray[k].productName=="Milk"){
                    printf("Product name:%s, Unit price:%.2f, Quantity:%d \n",milk.productName,milk.price,milk.quantity);
                }
                if(productArray[k].productName=="Water Small"){
                    printf("Product name:%s, Unit price:%.2f, Quantity:%d \n",waterSmall.productName,waterSmall.price,waterSmall.quantity);
                }
                if(productArray[k].productName=="Hand Sanitizer"){
                    printf("Product name:%s, Unit price:%.2f, Quantity:%d \n",handSanitizer.productName,handSanitizer.price,handSanitizer.quantity);
                }
                if(productArray[k].productName=="Toothpaste"){
                    printf("Product name:%s, Unit price:%.2f, Quantity:%d \n",toothPaste.productName,toothPaste.price,toothPaste.quantity);
                }
                if(productArray[k].productName=="Pizza"){
                    printf("Product name:%s, Unit price:%.2f, Quantity:%d \n",pizza.productName,pizza.price,pizza.quantity);
                }
                if(productArray[k].productName=="Chocolate"){
                    printf("Product name:%s, Unit price:%.2f, Quantity:%d \n",chocolate.productName,chocolate.price,chocolate.quantity);
                }

            }
        }
        else if (choice == 3){ // If user enters 3 as input, program shows shopping summary while using dynamicArray object.
            double totalPrice = 0;
            printf("-------Shopping Summary------\n");
            for (int k = 0 ; k < dynamicArray.used ; k++){
                while(1){
                    if(dynamicArray.array[k] == 'f'){

                        printf("Product name: Fish, Unit price: 15.98, Quantity:%d\n",(25-fish.quantity));
                        totalPrice += fish.price * (25-fish.quantity); // Calculating total price of the shopping.
                        k +=4; // Increasing k with respect to product name's char number to get next char which is right after the \0.
                        break;
                    }
                    else if(dynamicArray.array[k] == 'b'){

                        printf("Product name: Bread, Unit price: 3.5, Quantity:%d\n",(10-bread.quantity));
                        totalPrice += bread.price * (10-bread.quantity); // Calculating total price of the shopping.
                        k+=5; // Increasing k with respect to product name's char number to get next char which is right after the \0.
                        break;
                    }
                    else if(dynamicArray.array[k]=='p' && dynamicArray.array[k+1]=='a'){

                        printf("Product name: Pasta, Unit price: 2.79, Quantity:%d\n",(15-pasta.quantity));
                        totalPrice += 2.79 * (15-pasta.quantity); // Calculating total price of the shopping.
                        k+=5; // Increasing k with respect to product name's char number to get next char which is right after the \0.
                        break;
                    }
                    else if(dynamicArray.array[k]=='e'){

                        printf("Product name: Egg, Unit price: 2.82, Quantity:%d\n",(30-egg.quantity));
                        totalPrice += 2.82 * (30-egg.quantity); // Calculating total price of the shopping.
                        k+=3; // Increasing k with respect to product name's char number to get next char which is right after the \0.
                        break;
                    }
                    else if(dynamicArray.array[k]=='m'){

                        printf("Product name: Milk, Unit price: 10.26, Quantity:%d\n",(10-milk.quantity));
                        totalPrice += 10.26 * (10-milk.quantity); // Calculating total price of the shopping.
                        k+=4; // Increasing k with respect to product name's char number to get next char which is right after the \0.
                        break;
                    }
                    else if(dynamicArray.array[k]=='w'){

                        printf("Product name: Water Small, Unit price: 1.55, Quantity:%d\n",(35-waterSmall.quantity));
                        totalPrice += 1.55 * (35-waterSmall.quantity); // Calculating total price of the shopping.
                        k+=11; // Increasing k with respect to product name's char number to get next char which is right after the \0.
                        break;
                    }
                    else if(dynamicArray.array[k]=='h'){

                        printf("Product name: Hand Sanitizer, Unit price: 20.55, Quantity:%d\n",(20-handSanitizer.quantity));
                        totalPrice += 20.55 * (20-handSanitizer.quantity); // Calculating total price of the shopping.
                        k+=14; // Increasing k with respect to product name's char number to get next char which is right after the \0.
                        break;
                    }
                    else if(dynamicArray.array[k] == 't'){

                        printf("Product name: Toothpaste, Unit price: 10.83, Quantity:%d\n",(10-toothPaste.quantity));
                        totalPrice += 10.83 * (15-toothPaste.quantity); // Calculating total price of the shopping.
                        k+=10; // Increasing k with respect to product name's char number to get next char which is right after the \0.
                        break;
                    }
                    else if(dynamicArray.array[k] == 'p' && dynamicArray.array[k+1] == 'i'){

                        printf("Product name: Pizza, Unit price: 15.30, Quantity:%d\n",(10-pizza.quantity));
                        totalPrice += 15.30 * (10-pizza.quantity); // Calculating total price of the shopping.
                        k+=5; // Increasing k with respect to product name's char number to get next char which is right after the \0.
                        break;
                    }
                    else if(dynamicArray.array[k] == 'c'){

                        printf("Product name: Chocolate, Unit price: 5.21, Quantity:%d\n",(40-chocolate.quantity));
                        totalPrice += 5.21 * (40-chocolate.quantity); // Calculating total price of the shopping.
                        k+=9; // Increasing k with respect to product name's char number to get next char which is right after the \0.
                        break;
                    }
                }

            }

            printf("---------------------\n");
            printf("Total price: %.2f\n",totalPrice);
        }
        else{
            break;
        }
    }
}
