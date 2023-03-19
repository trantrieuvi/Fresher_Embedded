#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <vector>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <algorithm>
#include <fstream>

#define  _CRT_SECURE_NO_WARNINGS
#define inputScore(subject,stud, name_score)                            \
        while (1)                                                  \
        {                                                          \
            printf("%s score: ", subject);                         \
            scanf("%lf", &stud.name_score);                        \
            if((stud.name_score < 10) && (stud.name_score >= 0))   \
            {                                                      \
                break;                                             \
            }                                                      \
            printf("Wrong score. Enter again!\n");                 \
        }
using namespace std;

void pressExit();
enum state
{
	addStudent = 1,
	updateStudent,
	deleteStudent,
	searchStudent,
	sortByGPA,
	sortByname,
	showList,
	saveList,
}state;

class student
{
	public:
		student();
		uint16_t ID;
		char f_name[20];
		char gender[6];
		uint8_t age;
		double math_score;
		double physics_score;
		double chemistry_score;
		double average_score;
		char performance[9]; // Academic Performance
		static bool compare_GPA(const student & lStudent, const student & rStudent)
        {return (lStudent.average_score < rStudent.average_score);}
		static bool compare_name(const student & lStudent, const student & rStudent)
        {return (strcmp(lStudent.f_name, rStudent.f_name) < 0);}
};


 
student::student()
{
	static uint16_t ID = 100;
	student::ID = ID;
	ID++;
}

class menu
{
	public:
		menu();
		vector<student> Database;
		void add_student();
		void show_list();
		void update_student();
		void delete_student();
		void search_by_name();
		void sort_by_GPA();
		void sort_by_name();
		void save_list(const char filename[20]);
        void u_exit(uint8_t &exit_state);
};

menu::menu()
{
	uint8_t option = 255;
	menu:
    system("cls");
	printf("\t\t\tSTUDENT MANAGEMENT SYSTEM\n");
	printf("\t\t\t-------------------------\n");
	printf("1. Add Student\n");
	printf("2. Update Information Of Student By ID\n");
	printf("3. Delete Student By ID\n");
	printf("4. Search Student By Name\n");
	printf("5. Sort Student By GPA\n");
	printf("6. Sort Student By Name\n");
	printf("7. Show List Of Students\n");
	printf("8. Save file\n");
	printf("\t\t\t-------------------------\n");
	printf("Enter your choice: ");

	scanf("%d", &option);
	uint8_t exit_state = 10;
	switch (option)
	{      
	case addStudent:
        do
        {
            add_student();
            u_exit(exit_state);
        } while (exit_state == 1);
        goto menu;
		break;
	case updateStudent:
		do
        {
            update_student();
            u_exit(exit_state);
        } while (exit_state == 1);
        goto menu;
		break;
	case deleteStudent:
		do
        {
            delete_student();
            u_exit(exit_state);
        } while (exit_state == 1);
        goto menu;
		break;
	case searchStudent:
        search_by_name();
		goto menu;
		break;
	case sortByGPA:
		sort_by_GPA();
		goto menu;
		break;
	case sortByname:
		sort_by_name();
		goto menu;
		break;
	case showList:
		show_list();
		goto menu;
		break;
	case saveList:
		save_list("Student.txt");
		goto menu;
		break;
	default:
		system("cls");
		printf("Please chose invalid option!\n");
		pressExit();
		goto menu;
		break;
	}
	system("cls");
}

void menu::add_student(void)
{
	student stud;
	system("cls");
	printf("\t\t\tADD STUDENT\n");
	printf("\t\t\t-----------\n");
	printf("Full name: ");
	scanf("\n");
	scanf("%[^\n]s%s", stud.f_name);
	printf("Age: ");
	scanf("%d", &stud.age);
	printf("Gender (Male/Female): ");
	scanf("%s", stud.gender);

    inputScore("Math",stud,math_score);
    inputScore("Physics",stud,physics_score);
    inputScore("Chemistry",stud,chemistry_score);

    stud.average_score = (stud.math_score + stud.physics_score + stud.chemistry_score)/3;

    if(stud.average_score >= 8)
    {
        strcpy(stud.performance,"Excellent");
    }
    else if( stud.average_score >= 6.5)
    {
        strcpy(stud.performance,"Good");
    }
    else if( stud.average_score >= 5)
    {
        strcpy(stud.performance,"Average");
    }
    else strcpy(stud.performance,"Poor");

    Database.push_back(stud);
}

void menu::show_list()
{
	system("cls");
	printf("\t\t\tSHOW LIST OF STUDENTS\n");
	printf("\t\t\t---------------------\n");
	printf("STT ID Name Age Gender AverageScore Performance\n");
    for(uint8_t i = 0; i < Database.size(); i++)
	{	
		printf("%d.  %d %s  %d  %s   %0.2f         %s\n",i,Database[i].ID, Database[i].f_name, Database[i].age, Database[i].gender, Database[i].average_score, Database[i].performance);
	}
    pressExit();
}

void menu::update_student()
{
	uint16_t temp_ID;
	uint8_t u_state;
	bool u_check;
	system("cls");
	printf("\t\t\tUPDATE STUDENT\n");
	printf("\t\t\t--------------\n");
	printf("Enter ID of student: ");
	scanf("%d", &temp_ID);
	for(uint8_t i = 0; i < Database.size(); i++)
	{
		if(temp_ID == Database[i].ID)
		{
			u_check = true;
			ud_menu:
			printf("1. Update Full Name\n");
			printf("2. Update Age\n");
			printf("3. Update Gender\n");
			printf("4. Update Math Score\n");
			printf("5. Update Physics Score\n");
			printf("6. Update Chemistry Score\n");
			printf("Enter your choice: ");

			scanf("%d", &u_state);

			switch (u_state)
			{
			case 1:
				printf("Enter Full Name:");
				scanf("\n");
				scanf("%[^\n]s", Database[i].f_name);
				break;
			case 2:
				printf("Enter Age:");
				scanf("%d", &Database[i].age);
				break;
			case 3:
				printf("Enter Gender: ");
				scanf("%s", Database[i].gender);
				break;
			case 4:
				inputScore("Math",Database[i],math_score);
				break;
			case 5:
				inputScore("Physics",Database[i],physics_score);
				break;
			case 6:
				inputScore("Chemistry",Database[i],chemistry_score);
				break;
			default:
				printf("Please chose invalid option!\n");
				goto ud_menu;
				break;
			}
			 Database[i].average_score = (Database[i].math_score + Database[i].physics_score + Database[i].chemistry_score)/3;
			printf("Updated.\n");
			break;
		}
	}
	if(u_check == false)
	{
		printf("\n");
		printf("No students found!\n");
	}
}

void menu::delete_student()
{
	uint16_t temp_ID;
	bool d_check;
	system("cls");
	printf("\t\t\tDELETE STUDENT\n");
	printf("\t\t\t--------------\n");
	printf("Enter ID of student: ");
	scanf("%d", &temp_ID);
	for(int8_t i = 0; i < Database.size(); i++)
	{
		if(temp_ID == Database[i].ID)
		{
			d_check = true;
			Database.erase(Database.begin() + i);
			printf("Deleted student %d", temp_ID);
		}
	}
	if(d_check == false)
	{
		printf("\n");
		printf("No students found!\n");
	}
}

void menu::search_by_name()
{
	char *temp_name;
	bool check;
	system("cls");
	printf("\t\t\tSEARCH STUDENTS BY NAME\n");
	printf("\t\t\t-----------------------\n");
	printf("Enter name: ");
	scanf("%s",temp_name);
	for(uint8_t i = 0; i < Database.size(); i++)
	{
		if(strstr(Database[i].f_name,temp_name))
		{
			check = true; 
			printf("%d. %d %s %0.2f %s\n",i,Database[i].ID, Database[i].f_name, Database[i].average_score, Database[i].performance);
		}
	}
	if(check ==  false)
	{	
		printf("\n");
		printf(" No students found.\n");
	}
	pressExit();
}

void menu::sort_by_GPA()
{
	sort(Database.begin(), Database.end(), student::compare_GPA);
	show_list();
}
void menu::sort_by_name()
{
	sort(Database.begin(), Database.end(), student::compare_name);
	show_list();
}

void menu::save_list(const char filename[20])
{
	ofstream outfile(filename);

    if (outfile.is_open())
    {
		outfile << "ID,First Name,Gender,Age,Math Score,Physics Score,Chemistry Score,Average Score,Performance\n";
        for (uint8_t i = 0; i <  Database.size(); i++)
        {
            outfile << Database[i].ID << "," << Database[i].f_name << "," << Database[i].gender << ","
                    << static_cast<int>(Database[i].age) << "," << Database[i].math_score << ","
                    << Database[i].physics_score << "," << Database[i].chemistry_score << ","
                    << Database[i].average_score << "," << Database[i].performance << endl;
        }
        outfile.close();
        printf("Saved");
    }
    else
    {
        printf("Failed save");
    }
	pressExit();
}

void pressExit()
{
    printf("Press any key to exit..");
    getch();
} 

void menu::u_exit(uint8_t &e_state)
{
	uint8_t temp_state;
    printf("\n1. Continue\n");
    printf("Another number to exit: ");
    scanf("%d", &e_state);
}


int main(int argc, char const *argv[])
{
    while (1)
    {
        menu mn;
    }

	return 0;
}