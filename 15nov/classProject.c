#include <stdio.h>
int main() {
    char choice;
    int quantity;
    int price = 0;
    int totalCost = 0;
    char continueOrder;

      printf("Mama CAS Restaurant Menu\\n");
      printf("Press P for Poundo Yam/Edinkaiko Soup ---- N3200\n");
      printf("Press F for Fried Rice & Chicken ---- N3000\n");
      printf("Press A for Amala & Ewedu Soup ---- N2500\n");
      printf("Press E for Eba and Egusi Soup ---- N2000\n");
      printf("Press W for White Rice and Stew ---- N2500\n");
      printf("Press Q to exit\n");

    do{

      printf("Input your choice");
      scanf(" %c", &choice);
      printf("Input the quantity you want\n");
      scanf("%d", &quantity);


      switch (choice) {
        case 'P':
        case 'p' :{
            price = 3200; 
            break;
          
        } 
        case 'F':
        case 'f':{
            price = 3000;
            break;
          
        } 
        case 'A' : 
        case 'a':{
            price = 2500;
            break;
          
        } 
        case 'E':
        case 'e':{
            price = 2000;
            break;
        } 
        case 'W':
        case 'w':{
            price = 2500;
            break;
          
        } 
        case 'Q':
        case 'q':{
            return 1;
        }
        
        default:
            printf("Invalid input type.\n");
            continue;

    }
    totalCost += price * quantity;
        printf("Do you want to order another item? (Y/N): ");
        scanf(" %c", &continueOrder);

    } while (continueOrder == 'Y' || continueOrder == 'y');

    printf("Total cost for your order: N%d\n", totalCost);

    return 0;
    

}