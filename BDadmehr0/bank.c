#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void handle_login(string username, string password, string username2, string password2);
void handle_account(string login_name);

int main() {
    srand(time(0));

    while (true) {
        // Register two users
        string username = get_string("Enter first username: ");
        string password = get_string("Enter first password: ");

        string username2 = get_string("Enter second username: ");
        string password2 = get_string("Enter second password: ");

        printf("User 1: %s | Password: %s\n", username, password);
        printf("User 2: %s | Password: %s\n", username2, password2);

        // Start login and account handling
        handle_login(username, password, username2, password2);
    }
}

void handle_login(string username, string password, string username2, string password2) {
    while (true) {
        // Get login credentials
        string login_name = get_string("Please enter your username: ");
        string login_password = get_string("Please enter your password: ");

        // Validate credentials
        if (strcmp(login_name, username) == 0 && strcmp(login_password, password) == 0) {
            printf("Hello %s, you logged in!\n", login_name);
        } else if (strcmp(login_name, username2) == 0 && strcmp(login_password, password2) == 0) {
            printf("Hello %s, you logged in!\n", login_name);
        } else {
            printf("Username or password is incorrect.\n");
            continue; // Ask for login credentials again
        }

        // Handle account after successful login
        handle_account(login_name);

        // Ask if the user wants to log in again or log out
        string log_option = get_string("Do you want to login again (1) or logout (2)? ");

        if (strcmp(log_option, "2") == 0) {
            break; // Logout
        } else {
            printf("Logging in again...\n");
        }
    }
}

void handle_account(string login_name) {
    // Ask where the user wants to go
    string account_choice = get_string("Where do you want to go, %s?\nYour own money (1), or your girlfriend's (2): ", login_name);

    if (strcmp(account_choice, "1") == 0) {
        // Random money for user
        int random_money = rand() % 100;
        printf("You have %d tooman.\n", random_money);

        if (random_money > 50) {
            printf("Go buy a Titab!\n");
        } else {
            printf("Go work, poor soul!\n");
        }
    } else if (strcmp(account_choice, "2") == 0) {
        // Random number of girlfriends
        int random_girlfriends = rand() % 1000;
        printf("You have %d girlfriends.\n", random_girlfriends);

        if (random_girlfriends > 100) {
            printf("You're unlucky!\n");
        }
    } else {
        printf("Invalid choice.\n");
    }
}
