#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char username[20];
    char password[20];
} User;

User users[100];
int numUsers = 0;

void registerUser() {
    if (numUsers >= 100) {
        printf("Maximum number of users reached.\n");
        return;
    }

    User newUser;
    printf(" username: ");
    scanf("%s", newUser.username);

    printf(" password: ");
    scanf("%s", newUser.password);

    users[numUsers] = newUser;
    numUsers++;

    printf("Registration successful.\n");
}

void loginUser() {
    char username[20];
    char password[20];

    printf(" username: ");
    scanf("%s", username);

    printf(" password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Logined \n");
            return;
        }
    }

    printf("Please Try Correct Password .\n");
}

int main() {
    int key;

    while (1) {
        printf("Enter 1 for Register\n");
        printf("Enter 2 Login\n");
        printf("Enter your choice: ");
        scanf("%d", &key);

        switch (key) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }
}
