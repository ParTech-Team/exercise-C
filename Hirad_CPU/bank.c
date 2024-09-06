#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    while(true)
    {
        string username=get_string("your name: ");
        string password=get_string("your password: ");

        printf("your name is %s and your pass is %s\n ",username,password);

        string username2=get_string("your name: ");
        string password2=get_string("your password: ");

        printf("your name is %s and your pass is %s\n ",username2,password2);

        srand(time(0));

        while(true)
        {
            string login_name=get_string("please enter your name: ");
            string login_password=get_string("please enter your pass: ");

            if(strcmp(login_name,username)==0 && strcmp(login_password,password)==0)
            {
                printf("hello %s you logged in\n ",login_name);


            }
            else if(strcmp(login_name,username2)==0 && strcmp(login_password,password2)==0)
            {
                printf("hello %s you logges in\n ",login_name);
            }
            else
            {
                printf("password or username is wrong\n");
            }

            string account=get_string("where do you want to go %s?\n your own money=1,your girlfriends=2: ",login_name);

            if(strcmp(account,"1")==0)
            {
                int random_money=rand() %100;

                printf("you have %i tooman\n ",random_money);

                if(random_money>50)
                {
                    printf("boro titab bekhar\n");
                }
                else
                {
                    printf("boro kar kon badbakht\n");
                }
            }
            else if(strcmp(account,"2")==0)
            {
                int random_girlfriends=rand() %1000;

                printf("you have %i girlfriends\n ",random_girlfriends);

                if(random_girlfriends>100)
                {
                    printf("havale badbakht\n");
                }

            }

            string log=get_string("do you want to login again=1 or logout=2? ");

            if(strcmp(log,"1")==0)
            {
                printf("you logged in again\n");
            }
            else if(strcmp(log,"2")==0)
            {
                break;
            }


        }
    }
}
