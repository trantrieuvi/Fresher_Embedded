#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <conio.h> // getch()

#define __bool_true_false_are_defined   1

class Phone 
{
    private:
        uint8_t id;
        char phoneName[20];
        char manufacturer[20];
        double phonePrice;

    public:
        Phone(const char name[], const char manufacturer[], double price);

        uint8_t getId();
        const char* getName() const;
        const char* getManufacturer() const;
        double getPrice() const;

        void setName(const char phoneName[]);
        void setManufacturer(const char manufacturer[]);
        void setPrice(double price);
};

Phone::Phone(const char inName[], const char inManufacturer[], double inPrice)
{
    static uint8_t l_id = 100;
    id = l_id;
    l_id++;
    strcpy(phoneName, inName);
    strcpy(manufacturer, inManufacturer);
    phonePrice = inPrice;
}

uint8_t Phone::getId()
{
    return this->id;
}

const char *Phone::getName() const
{
    return phoneName;
}

const char* Phone::getManufacturer() const
{
    return manufacturer;
}

double Phone::getPrice() const
{
    return phonePrice;
}

void Phone::setName(const char inName[])
{
    strcpy(phoneName, inName);
}

void Phone::setManufacturer(const char inManufacturer[])
{
    strcpy(manufacturer, inManufacturer);
}

void Phone::setPrice(double inPrice)
{
    phonePrice = inPrice;
}

class ManagePhone
{
    private:
        enum state
        {
            add = 1,
            del,
            edit,
            show,
        }state;
        std::vector<Phone>Database;
        uint8_t checkExitId(uint8_t id);
    public:
        ManagePhone();
        void addPhone();
        void delPhone();
        void editPhone(uint8_t inID);
        void showListPhone();
        void mainMenu();
        uint8_t editMenu();
};

ManagePhone::ManagePhone()
{
    mainMenu();
}

uint8_t ManagePhone::checkExitId(uint8_t id)
{
    for(uint8_t i = 0; i <  Database.size(); i++)
    {
        if(id == Database[i].getId());
        {
            return 1;
        }
    }
    return 0;
}

void ManagePhone::mainMenu()
{

    while (true)
    {
        uint8_t choice;
        printf("1. Add Phone\n");
        printf("2. Delete Phone\n");
        printf("3. Edit Phone\n");
        printf("4. Show List of Phone\n");
        printf("Please enter your choice: ");
        fflush(stdin);
        scanf("%d", &choice);
        
        switch (choice)
        {
        case add:
            printf("---------Add\n");
            addPhone();
            break;
        case del:
            printf("---------Del\n");
            delPhone();
            break;
        case edit:
            printf("---------Edit\n");
            uint8_t inID;
            printf("Enter phone ID: ");
            scanf(" %d", &inID);
            editPhone(inID);
            break;
        case show:
            printf("---------Show\n");
            showListPhone();
            break;
        default:
            printf("Your choice: %d", choice);
            printf("Invalid input, please try again.\n");
            continue;
        }
    }
    
}

void ManagePhone::addPhone()
{
    char phoneName[20];
    char manufacturer[20];
    double phonePrice;
    char key;
    do
    {
        printf("Enter Name: ");
        scanf("%s", phoneName);

        printf("Enter Manufacturer: ");
        scanf("%s", manufacturer);

        printf("Enter Price: ");
        scanf("%d", &phonePrice);

        Phone newPhone(phoneName, manufacturer, phonePrice);
        Database.push_back(newPhone);

        printf("Do you want to add another phone? (y/n): ");
        scanf(" %c",&key);
    } while(key == 'y');
}

void ManagePhone::delPhone()
{
    char key;
    bool check = false;
    do
    {
        uint8_t inID;
        printf("Enter phone ID: ");
        fflush(stdin);
        scanf("%d", &inID);
        for(uint8_t i = 0; i <  Database.size(); i++)
        {
            if(inID == Database[i].getId())
            {
                printf("Vo"); 
                check = true;
                Database.erase(Database.begin() + inID-100);
                printf("Done delete");         
            }
        }
        if(check ==  false) printf("No students found!");

        printf("Do you want to delete another phone? (y/n): ");
        scanf(" %c",&key);
    } while(key == 'y');
}

void ManagePhone::editPhone(uint8_t  inID)
{
    char key;
    bool e_check =  1;
    uint8_t state = 0;
    do
    {
        for(uint8_t i = 0; i <  Database.size(); i++)
        {
            if(inID == Database[i].getId())
            {

                e_check = true;
                printf("Chekc: %d", e_check);
                printf("1. Edit name\n");
                printf("2. Edit manufacturer\n");
                printf("3. Edit price\n");
                printf("Enter your choice: ");
                fflush(stdin);
                scanf_s("%d", &state);
                    switch (state)
                    {
                        case 1:
                            char tempName[20];
                            printf("Enter new name: ");
                            scanf("%s", tempName);
                            Database[inID-100].setName(tempName);
                            break;
                        default:
                            break;
                    }
                    break;
            }
        }
        if(e_check == false) printf("No students found!");

        printf("Do you want to edit another phone? (y/n): ");
        fflush(stdin);
        scanf(" %c",&key);
    } while(key == 'y');
}

void ManagePhone::showListPhone()
{
    if(Database.empty())
    {
        printf("Empty list.\n");
    }
    else
    {
        for(uint8_t i = 0; i < Database.size(); i++)
        {
            printf("%d %s %s %d\n",Database[i].getId(), Database[i].getName(), Database[i].getManufacturer(), Database[i].getPrice());
        }
    }

    printf("Press any key to exit..");
    getch();
}

int main(int argc, char const *argv[])
{
    ManagePhone mn;
}
