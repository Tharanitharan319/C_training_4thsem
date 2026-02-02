#include <stdio.h>

int main() {
    int lang;
    printf("Choose your language\n");
    printf("Press 1 for Tamil\n");
    printf("Press 2 for English\n");
    printf("Press 3 for Hindi\n");
    scanf("%d", &lang);
switch(lang){
      case 1:
    printf("You're selected tamil\n");
    break;
      case 2:
    printf("You're selected English\n");
    break;
      case 3:
    printf("You're selected Hindi\n");
    break;
default:
    printf("Please select a valid number\n");
    break;
}
 

    return 0;
}