#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<time.h>   
#include<ctype.h>
#include<windows.h>
#include<process.h>
#include<MMsystem.h>

//snake game specifications

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int length;
int bend_no;
int len;
char key;
void record();
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int Scoreonly();
 
struct coordinate{
    int x;
    int y;
    int direction;
};
 
typedef struct coordinate coordinate;
 
coordinate head, bend[500],food,body[30];

//calculator specifications
 

#define note "maze mat lo, enter the valid operation"

void addition();
void subtraction();
void multiplication();
void division();
void modulus();
void factorial();
void power();
void square();
void cube();
void squareroot();
void logbasee();
void logbase10();
void antilogforbasee();
void antilogforbase10();
void sine();
void cosine();
void tangent();
void sinein();
void cosinein();
void tangentin();


//unit converter

float distanceConv[] = {1.0, 1000.0, 100000.0, 0.621371192, 1093.6133, 1000000.0, 3280.8399, 39370.0787};
					//    km,      m,     cm,        miles,       yards,     mm,         feet,      inches
float massConv[] = {1.0, 1000.0, 1000000.0, 0.001, 0.00110231131, 2.20462, 0.157473044, 35.2739619};
				    // kg,   g,     mg,     tonne,     US ton,      pounds,       stones,      ounces
float volConv[] = {1.0, 1000.0, 1000000.0, 264.172052, 4166.67, 67628.0454, 219.969157, 3519.51, 56312.1043, 33814.0227};
			    //  cubic m, L,   mL, US liquid gallons, US legal cups, US tablespoons,Imperial gallons,Imperial cups,Imperial tablespoons,fluid ounces

float convertData( int,  int,  int, float );                // 1) distance, 2) mass, 3) volume

float convertData( int c,  int fromUnit,  int toUnit, float fromMagnitude)
{
	float toMagnitude;
	switch(c)
	{
		case 1:        // distance
			toMagnitude = (distanceConv[toUnit - 1] / distanceConv[fromUnit - 1]) * fromMagnitude;
			break;
		case 2:        // mass
			toMagnitude = (massConv[toUnit - 1] / massConv[fromUnit - 1]) * fromMagnitude;
			break;
		case 3:        // volume
			if(fromUnit == 0)
			{
				toMagnitude = (volConv[toUnit - 1] / volConv[9]) * fromMagnitude;
				break;
			}
			else if(toUnit == 0)
			{
				toMagnitude = (volConv[9] / volConv[fromUnit - 1]) * fromMagnitude;
				break;
			}
			else
			{
				toMagnitude = (volConv[toUnit - 1] / volConv[fromUnit - 1]) * fromMagnitude;
				break;
			}
		default:
			puts("Error! 'c' can't be other than 1, 2 or 3!");
			getch();
			
	}
	return toMagnitude;
}

void waitFor(float);

void waitFor(float timer)
{
	clock_t initialTime;
	
	initialTime = clock();
	
	while(clock() - initialTime < timer);
}


void unitsMessage(short int, short int, short int *);      // 0 -> fromUnit, 1 -> toUnit




//pacman game specification

#define H 30
#define W 60
#define gho1 5

struct coord
{
   int x;
   int y;
};

struct PacMan
{
   struct coord position;
   int vx;
   int vy;
   int food_coll;
};


struct Ghost
{
   struct coord position;
   int vx;
   int vy;
};


struct Ghost allGhosts[gho1];
struct Ghost allGhosts2[gho1];

struct PacMan myPacMan = {
                           {
                              .x = 1,
                              .y = 5,
                           },
                           .vx = 0,
                           .vy = 0,
                           .food_coll = 0,
                         };

char playfield[H][W] =
{
   { "############################################################" },
   { "#                                                          #" },
   { "#   ##################     ######    ###################   #" },
   { "#                  ####      ##     ####                   #" },
   { "#    ####   ###    ####      ##     ####    ###    ####    #" },
   { "#    ####   ###    ####    ######   ####    ###    ####    #" },
   { "#    ####                                          ####    #" },
   { "#     ##################     ##     ##################     #" },
   { "#                            ##                            #" },
   { "#   ###############   ###    ##    ###   ###############   #" },
   { "#   ###               ###          ###               ###   #" },
   { "#   ###  ###   ##########  ##  ##  ##########  ###   ###   #" },
   { "#   ###               ###          ###               ###   #" },
   { "#   ###############   ###  ##  ##  ###   ###############   #" },
   { "#                                                          #" },
   { "#   ####    ###   #######   ####   #######   ###    ####   #" },
   { "#   ####    ###   #######   ####   #######   ###    ####   #" },
   { "#   ####    ###       ###   ####   ###       ###    ####   #" },
   { "#   ####                    ####                    ####   #" },
   { "#   ####     ############          ############     ####   #" },
   { "#   ####     ###                            ###     ####   #" },
   { "#   ####     ###                            ###     ####   #" },
   { "#   ####     ##################################     ####   #" },
   { "#   ####                                            ####   #" },
   { "#   ####   #############     ##     #############   ####   #" },
   { "#   ####   #############     ##     #############   ####   #" },
   { "#   ####        ####         ##          ####       ####   #" },
   { "#               ####     ##########      ####              #" },
   { "#       ####             ##########             ####       #" },
   { "############################################################" }
};

main()
{
    char io[100];
    int choice;

    //bmi cal
    float weight=0.0;//in kg
    float height=0.0;//in cm
    float BMI=0.0;

    //stop&timer
    int h=0,m=0,s=0,ms=0;
    char ch;

    //unit coverter
    char userInput;
	short int c;
	short int fromUnit, toUnit;
	float fromMagnitude, toMagnitude;

    //RRCE chatbot
    int selection1,selection2;

    quit:

    system("cls");
    printf("\n\t\t\t\tWelcome to AI chatbot. My name is IO.\n");
    while(1)
   {
       gets(strlwr(io));
       //intro1
       if(strcmp(io,"hi")==0)
       {
           printf("Hello Master!!!\n");
       }
       //intro2
        else if(strcmp(io,"hello")==0)
       {
           printf("Hello Master!!!\n");
       }
       //extro1
       else if(strcmp(io,"end")==0)
       {
            system("cls");
           printf("OK Bye!!!\n");
           sleep(2);
           exit(0);
       }
       //extro2
       else if(strcmp(io,"close")==0)
       {
            system("cls");
           printf("OK Bye!!!\n");
           sleep(2);
           exit(0);
       }
       //extro3
       else if(strcmp(io,"exit")==0)
       {
            system("cls");
           printf("OK Bye!!!\n");
           sleep(2);
           exit(0);
       }
       //browser opening
       else if(strcmp(io,"open browser")==0)
       {
           printf("Opening chrome browser!\n");
           system("start chrome");
       }
       //chrome opening
        else if(strcmp(io,"open chrome")==0)
       {
           printf("Opening chrome browser!\n");
           system("start chrome");
       }
       //edge opening
        else if(strcmp(io,"open edge")==0)
       {
           printf("Opening edge browser!\n");
           system("start microsoftedge");
       }
       //purpose
       else if(strcmp(io,"what can you do?")==0)
       {
           printf("I'm an ai chat bot,I can chat with you,I can help you with this computer,I can do some of your things\n");
           printf("Ask me!!!\n");
       }
       //youtube opening
       else if(strcmp(io,"open youtube")==0)
       {
           printf("Opening youtube");
           system("start http:\\youtube.com");
       }
       //music1
       else if(strcmp(io,"play music")==0)
       {
           printf("Opening spotify to play music!!!\n");
           system("start spotify");
       }
       //music2
       else if(strcmp(io,"open spotify")==0)
       {
           printf("Opening spotify to play music!!!\n");
           system("start spotify");
       }
       //notepad opening
        else if(strcmp(io,"open notepad")==0)
       {
           printf("Opening Notepad!!!\n");
           system("start notepad");
       }
       //mail opening
        else if(strcmp(io,"open mail")==0)
       {
           printf("Opening mails!!!\n");
           system("start https://mail.google.com/mail/u/0/?tab=rm&ogbl#inbox");
       }
       //google maps opening
        else if(strcmp(io,"open maps")==0)
       {
           printf("Opening maps!!!\n");
           system("start https://www.google.co.in/maps?hl=en&tab=rl");
       }
       //skype opening
        else if(strcmp(io,"open skype")==0)
       {
           printf("Opening Skype!!!\n");
           system("start skype");
       }
       //google opening
        else if(strcmp(io,"open google")==0)
       {
           printf("Opening google!!!\n");
           system("start http:\\www.google.com");
       }
       //google images opening
       else if(strcmp(io,"open google images")==0)
       {
           printf("Opening google images!!!\n");
           system("start https://www.google.co.in/imghp?hl=en&tab=ri&ogbl");
       }
       //google calender opening
       else if(strcmp(io,"open calender")==0)
       {
           printf("Opening calender!!!\n");
           system("start https://calendar.google.com/calendar/u/0/r?tab=rc&pli=1");
       }
       //locate rrce
       else if(strcmp(io,"locate our college")==0)
       {
           printf("Locating RRCE!!!\n");
           system("start https://earth.google.com/web/@12.88677085,77.44953948,760.25799539a,49.42584241d,35y,47.94842902h,59.40729109t,0r");
       }
       //rrce webpage
       else if(strcmp(io,"rrce")==0)
       {
           printf("Opening RRCE webpage!!!\n");
           system("start https://www.rrce.org");
       }

       //clock
       else if(strcmp(io,"what is the time?")==0)
       {
           time_t s, val = 1;
            struct tm* current_time;
        
            // time in seconds
            s = time(NULL);
        
            // to get current time
            current_time = localtime(&s);
        
            // print time in minutes,
            // hours and seconds
            printf("%02d:%02d:%02d",
                current_time->tm_hour,
                current_time->tm_min,
                current_time->tm_sec);
       }
       
       //stopwatch and timer
       if(strcmp(io,"open stopwatch and timer")==0)
       {
         printf("Enter your choice \n PRESS 'a' FOR STOPWATCH \n PRESS 'b' FOR COUNTDOWN\n");
            scanf("%c",&ch);
            switch(ch)
            {
                case 'a':
                    while(TRUE) //or we can write 1 instead of TRUE
                    {
                        printf("       \r %2d : %2d : %2d : %2d",h,m,s,ms);//here \r is used to update the value in a single line
                        ms++;
                        Sleep(10) ;//it is approximately 1 millisecond
                        if(ms==100)
                        {
                            s++;
                            ms=0;
                        }
                        if(s==59)
                        {
                            m++;
                            s=0;
                            ms=0;
                        }
                        if(m==59)
                        {
                            h++;
                            m=0;
                            s=0;
                            ms=0;
                        }
                        if(h==24)
                        {
                            h=0;
                            m=0;
                            s=0;
                            ms=0;
                        }
                        
                    }
                    break;
                    case 'b':
                        printf("Enter the time in HH::MM::SS(using space):\n");
                        scanf("%d%d%d",&h,&m,&s);
                        while(1) //here we used 1
                        {
                            printf("      \r%d:%d:%d",h,m,s);
                            Sleep(1000); //it is approximately 1 second
                            if(s!=0)
                            {
                                s--;
                            }
                            if(s==0 && m!=0)
                            {
                                s=59;
                                m--;
                            }
                            if(s==0 && m==0 && h!=0)
                            {
                                h--;
                                m=59;
                                s=59;
                            }
                            if(h==0 && m==0 && s==0)
                            {
                                exit(0);
                            }
                        }
            }
       }
       
       //calculator
       else if(strcmp(io,"open calculator")==0)
       {
           printf("\t\tWelcome to the scientific calculator!!\n\n");
            printf("\n******* Press 0 to quit the program ********\n");
            printf("Enter 1 for Addition \n");
            printf("Enter 2 for Subtraction \n");
            printf("Enter 3 for Multiplication \n");
            printf("Enter 4 for Division \n");
            printf("Enter 5 for Modulus\n");
            printf("Enter 6 for Power \n");
            printf("Enter 7 for Factorial \n");
            printf("Enter 8  for square \n");
            printf("Enter 9  for cube \n");
            printf("Enter 10 for squareroot\n");
            printf("Enter 11 for log to the base e\n");
            printf("Enter 12 for log to the base 10\n");
            printf("Enter 13 for antilog for the base e\n");
            printf("Enter 14 for antilog to the base 10\n");
            printf("Enter 15 for sine function\n");
            printf("Enter 16 for cosine function\n");
            printf("Enter 17 for tangent function\n");
            printf("Enter 18 for sine inverse function\n");
            printf("Enter 19 for cosine inverse function\n");
            printf("Enter 20 for tangent inverse function\n");
            
            while(1)
            {    
                printf("\n\nEnter the operation you want to do: ");
                
                scanf("%d",&choice);
                        
                switch(choice)
                {
                            case 1:
                                addition();
                                break;
                            case 2:
                                subtraction();
                                break;
                            case 3:
                                multiplication();
                                break;
                            case 4:
                                division();
                                break;
                            case 5:
                                modulus();
                                break;
                            case 6:
                                power();
                                break;
                            case 7:
                                factorial();
                                break;
                            case 8:
                                square();
                                break;
                            case 9:
                                cube();
                                break;
                            case 10:
                                squareroot();
                                break;
                            case 11:
                                logbasee();
                                break; 
                            case 12:
                                logbase10();
                                break; 
                            case 13:
                                antilogforbasee();
                                break; 
                            case 14:
                                antilogforbase10();
                                break; 
                            case 15:
                                sine();
                                break;
                            case 16:
                                cosine();
                                break;
                            case 17:
                                tangent();
                                break; 
                            case 18:
                                sinein();
                                break;
                            case 19:
                                cosinein();
                                break;
                            case 20:
                                tangentin();
                                break;                                   
                            case 0:
                                exit(0);
                            default:
                                printf("\n********** %s ***********\n",note);
                }
            
            }
       }
       //unit converter
       else if(strcmp(io,"open unit converter")==0)
       {
           printf("Opening unit converter!!!!\n");
           while(1)
            {
                system("cls");
                printf("Hey there! Welcome to Unit Converter!\n");
                printf("Please press the Number Key according to the option you want to go with.\n");

                puts("1) Distance Converter");
                puts("2) Mass Converter");
                puts("3) Volume Converter");
                puts("Q) Quit to Desktop");

                while(1)
                {
                    userInput = getch();

                    if(userInput == '1')
                    {
                       system("cls");
                        c = 1;
                        break;
                    }
                    else if(userInput == '2')
                    {
                       system("cls");
                        c = 2;
                        break;
                    }
                    else if(userInput == '3')
                    {
                        system("cls");
                        c = 3;
                        break;
                    }
                    else if(userInput == 'Q' || userInput == 'q')
                        exit(0);
                }

                unitsMessage(c, 0, &fromUnit);     // taking 'From' unit from the user
                unitsMessage(c, 1, &toUnit);       // taking 'To' unit from the user
                
                printf("Enter Magnitude ");
                switch(c)
                {
                    case 1:
                        switch(fromUnit)
                        {
                            case 1:
                                printf("(in km):\n");
                                break;
                            case 2:
                                printf("(in m):\n");
                                break;
                            case 3:
                                printf("(in cm):\n");
                                break;
                            case 4:
                                printf("(in miles):\n");
                                break;
                            case 5:
                                printf("(in yards):\n");
                                break;
                            case 6:
                                printf("(in mm):\n");
                                break;
                            case 7:
                                printf("(in feet):\n");
                                break;
                            case 8:
                                printf("(in inches):\n");
                                break;
                            default:
                                printf("(in ?)\n");
                                break;
                        }
                        break;
                    case 2:
                        switch(fromUnit)
                        {
                            case 1:
                                printf("(in kg):\n");
                                break;
                            case 2:
                                printf("(in g):\n");
                                break;
                            case 3:
                                printf("(in mg):\n");
                                break;
                            case 4:
                                printf("(in tonne):\n");
                                break;
                            case 5:
                                printf("(in US ton):\n");
                                break;
                            case 6:
                                printf("(in pounds):\n");
                                break;
                            case 7:
                                printf("(in stones):\n");
                                break;
                            case 8:
                                printf("(in ounces):\n");
                                break;
                            default:
                                printf("(in ?)\n");
                                break;
                        }
                        break;
                    case 3:
                        switch(fromUnit)
                        {
                            case 1:
                                printf("(in cubic m):\n");
                                break;
                            case 2:
                                printf("(in L):\n");
                                break;
                            case 3:
                                printf("(in mL):\n");
                                break;
                            case 4:
                                printf("(in US liquid gallons):\n");
                                break;
                            case 5:
                                printf("(in US legal cups):\n");
                                break;
                            case 6:
                                printf("(in US tablespoons):\n");
                                break;
                            case 7:
                                printf("(in Imperial gallons):\n");
                                break;
                            case 8:
                                printf("(in Imperial cups):\n");
                                break;
                            case 9:
                                printf("(in Imperial tablespoons):\n");
                                break;
                            case 0:
                                printf("(in fluid ounces):\n");
                                break;
                            default:
                                printf("(in ?)\n");
                                break;
                        }
                        break;
                }
                scanf("%f", &fromMagnitude);
                
                toMagnitude = convertData(c, fromUnit, toUnit, fromMagnitude);
                printf("Magnitude in ");
                switch(c)
                {
                    case 1:
                        switch(toUnit)
                        {
                            case 1:
                                printf("km:\n");
                                break;
                            case 2:
                                printf("m:\n");
                                break;
                            case 3:
                                printf("cm:\n");
                                break;
                            case 4:
                                printf("miles:\n");
                                break;
                            case 5:
                                printf("yards:\n");
                                break;
                            case 6:
                                printf("mm:\n");
                                break;
                            case 7:
                                printf("feet:\n");
                                break;
                            case 8:
                                printf("inches:\n");
                                break;
                            default:
                                printf("?\n");
                                break;
                        }
                        break;
                    case 2:
                        switch(toUnit)
                        {
                            case 1:
                                printf("kg:\n");
                                break;
                            case 2:
                                printf("g:\n");
                                break;
                            case 3:
                                printf("mg:\n");
                                break;
                            case 4:
                                printf("tonne:\n");
                                break;
                            case 5:
                                printf("US ton:\n");
                                break;
                            case 6:
                                printf("pounds:\n");
                                break;
                            case 7:
                                printf("stones:\n");
                                break;
                            case 8:
                                printf("ounces:\n");
                                break;
                            default:
                                printf("?\n");
                                break;
                        }
                        break;
                    case 3:
                        switch(toUnit)
                        {
                            case 1:
                                printf("cubic m:\n");
                                break;
                            case 2:
                                printf("L:\n");
                                break;
                            case 3:
                                printf("mL:\n");
                                break;
                            case 4:
                                printf("US liquid gallons:\n");
                                break;
                            case 5:
                                printf("US legal cups:\n");
                                break;
                            case 6:
                                printf("US tablespoons:\n");
                                break;
                            case 7:
                                printf("Imperial gallons:\n");
                                break;
                            case 8:
                                printf("Imperial cups:\n");
                                break;
                            case 9:
                                printf("Imperial tablespoons:\n");
                                break;
                            case 0:
                                printf("fluid ounces:\n");
                                break;
                            default:
                                printf("?\n");
                                break;
                        }
                        break;
                }
                printf("%f", toMagnitude);
                sleep(5);
            }    
       }
       //snake game
        else if(strcmp(io,"open snake game")==0) 
        {
            printf("Opening snake game!!!\n");

            char key;
 
            Print();
        
            system("cls");
        
            load();
        
            length=5;
        
            head.x=25;
        
            head.y=20;
        
            head.direction=RIGHT;
        
            Boarder();
        
            Food(); //to generate food coordinates initially
        
            life=3; //number of extra lives
        
            bend[0]=head;
        
            Move();   //initialing initial bend coordinate
 
        }

        //bmi calculator
        else if(strcmp(io,"open bmi calculator")==0)
        {
            system("cls");
            printf("\t\t\t\tBMI Calculator\n");
            printf("Please enter your weight in kg:\n");
            scanf("%f",&weight);
            weight=weight*2.205;
            printf("\nPlease enter your height in cm:\n");
            scanf("%f",&height);
            height=height*0.394;
            BMI= (weight*703)/(height*height);
            if(BMI<=18.5)
            {
                printf("\nYou are underweight.Eat protien rich food to gain weight.\n");
            }
            else if(18.5<BMI<=24.9)
            {
                printf("You are normal. Continue your diet.\n");
            }
            else if(24.9<BMI<=29.9)
            {
                printf("You are overweight. Consume fibre rich food.\n");
            }
            else if(BMI>29.9)
            {
                printf("You are Obese.\n");
            }
            else
            {
                printf("Ok Bye.......!");
                sleep(3);
                exit(0);
            }
        }
        
        //pacman game
        else if(strcmp(io,"open pacman game")==0)
        {
           printf("Opening pacman game!!!\n");
            system("cls");
            hidecursor();
            initialize();
            
            while (1)
            {
                user_input();
                move_figures();
                display();
                show_playfield();
                check_coll();
                Sleep( 10/ 30 );
                set_cursor_position(0,0);
            }
        }

        //RRCE chatbot

        else if(strcmp(io,"open rrce chatbot")==0)
        {
            system("cls");
            while(1)
            { 
                exit1:
                printf("\n\t\t\tWelcome to RRCE chatbot\n");
                printf("How may I help you?(select the corresponding number to your query)\n");
                printf("1. Know about RRCE.\n2. Locate RRCE.\n3. For further information.\n4. Quit.\n");
                scanf("%d",&selection1);
                switch(selection1)
                {
                    case 1:
                    {
                        system("cls");
                        printf("* RRCE stands for RAJARAJESHWARI COLLEGE OF ENGINEERING\n\n");
                        printf("* Principal of RRCE-Dr.T.Chandrashekar\n\n");
                        printf("* RRCE was started in 2006\n\n");
                        printf("* Landmark for RRCE-14,Ramohalli Cross,Kumbalgodu,Mysore Rd,Bengaluru,Karnataka 56007\n\n");
                        printf("* RRCE is managed by-Moogambigai Charitable and Education Trust..\n\n");
                        printf("* Chairman of RRCE-Dr.AC.Shanmugan & Vice chairman of RRCE-Sri.Arunkumar\n\n");
                        printf("* RRCE offers following Undergraduate engineering cources:\n1. Artificial intelligence and machine learning.\n2. Robotics and Automation.\n3. Computer science and engineering.\n4. Electronics and communication engineering.\n5. Electronics and electrical engineering.\n6. Mechanical engineering.\n7. Information science and engineering.\n8. Civil engineering.\n\n");
                        printf("* All cources offered are affiliated to Vishveswaraya Technical University , Belagavi,\n\n");
                        printf("* To know more about each branch,select the corresponding number to your query \n");
                        printf("1. AI&ML.\n2.Robotics and Automation.\n3. CSE.\n4. ISE.\n5. ECE.\n6. EEE.\n7. ME.\n8. CE.\n9. exit.\n");
                        scanf("%d",&selection2);
                        switch(selection2)
                        {
                            case 1:
                            {
                                system("cls");
                                printf("\n\t\t\tARTIFICIAL INTELLIGENCE AND MACHINE LEARNING.\n\n\n");
                                printf("* Artificial Intelligence (AI) refers to the development of computer systems that are able to perform tasks traditionally limited to human intelligence, such as decision-making and speech recognition. Machine Learning (ML) enables the computers to learn and adapt without being explicitly programmed.\n\n");
                                printf("* The Department of Artificial Intelligence and Machine learning is starting its endeavor from academic year 2020-21, and currently admissions are open in UG stream for the same. This program encourages diversified applications of AI and ML in different fields of computer science and information technology As a need of the day, this course targets different AI and ML applications in the field of Internet of Things (IoT), Robotics, Data Science, Computer Networks and Network Security. Students will be exposed to present world technologies with smart competency of digital world which intern student will have wide opportunity to work under premium industries and companies, or student can also have exposure to entrepreneurship as well.\n\n");
                                printf("* Cource glance:\n1.Machine Learning\n2.Deep Learning\n3.Natural Language Processing\n4.Vision &Speech Recognition\n5.Artificial Neural Network\n6.Expert Systems and Fuzzy Logic\n7.Data Science");
                                printf("* The Head Of The Department is Professor Rajesh K S.\n\n");
                                break;
                            }
                            case 2:
                            {
                                system("cls");
                                printf("\n\t\t\tROBOTICS AND AUTOMATION.\n\n\n");
                                printf("* Robotics and Automation program is aimed at the Plan, Design, Construct, Operate and effective & independent usage of robotic devices. It is learned further the utilization of the computer systems required for its control, a sensor element, feedback, and information processing of Robotics and Automation devices.\n\n");
                                printf("* This course aims to provide the students with project-based learning, project planning, probe learning, students will discover the processes and skills required to design, fabricate, interface, install, and troubleshooting industrial robots and automation systems of physical robot devices that they will control or automate the manufacturing devices, householding equipment’s, medical equipment’s, space equipment’s, etc. Students are given a chance to explore the design of automation systems, portable mobile robotics, and animatronics or simulation of traditional, modern robotics devices. In addition, students will also enhance the computational thinking and coding skills necessary to control their robotic or automated devices.\n\n");
                                printf("* The Head Of The Department is \n\n");
                                break;
                            }
                            case 3:
                            {
                                system("cls");
                                printf("\n\t\t\tCOMPUTER SCIENCE AND ENGINEERING.\n\n\n");
                                printf("* Today computer industry needs adaptable people who are equally at home presenting business solutions to senior management as finding the fault in a piece of code. This course is ideal for those who see their initial career in a wide-ranging role. Work should include IT consultancy, IT support, analyst, programmer, hardware engineer, network and system administrator etc.\n\n");
                                printf("* The programme is designed such that a student can complete it based on advanced coursework alone. However, the students are given the option to concentrate on a problem by substituting some of the courses with equivalent project work. CSE is also having well established Center Of excellence (CoE) in the field of IoT. Currently there is a prolonged growing market for professionals possessing a clear overview of current information and communication networks capabilities, standards and trends, along with a firm grasp of specifics in areas ranging from data network protocols to network security issues.\n\n");
                                printf("* The Head Of The Department is Professor Dr Usha S.\n\n");
                                break;
                            }
                            case 4:
                            {
                                system("cls");
                                printf("\n\t\t\tINFORMATION SCIENCE AND ENGINEERING.\n\n\n");
                                printf("* The Information Science program, prepares the student to design and manage computerized data processing and decision support. The program is technically oriented emphasizing the design and implementation aspects of large scale information systems as well as the more traditional, managerial and organizational issues. It also balances development of systems engineering skills with learning to deliver reliable systems on time and within a specified budget.\n\n");
                                printf("* To Develop a Center of Excellence to offer broad need based Curricula, Innovative Teaching and Research in the field of Information Science and Engineering and to Produce Competent and Self disciplined Information Technology Professionals.\n\n");
                                printf("* The Head Of The Department is Professor Dr J Amutharaj.\n\n");
                                break;
                            }
                            case 5:
                            {
                                system("cls");
                                printf("\n\t\t\tELECTRONICS AND COMMUNICATION ENGINEERING.\n\n\n");
                                printf("*  The objective of the Department is to develop professionals having good skills, self-learning ability and confidence to support and contribute to the growth of relevant industries. The students have strong base in basic science, mathematics and inter disciplinary engineering subjects. The students are also exposed to important subjects and advances that are being made in this rapidly changing field and provided opportunities to gain vital practical experience. Project based learning is been given much weightage. Theoretical Knowledge is supplemented with ability to analyze, design and provide technical solutions that have real life value.\n\n");
                                printf("* The Head Of The Department is professor Dr L Rangaih.\n\n");
                                break;
                            }
                            case 6:
                            {
                                system("cls");
                                printf("\n\t\t\tELECTRONICS AND ELECTRICAL ENGINEERING.\n\n\n");
                                printf("* Introducing value-based education and State-of-the-Art infrastructure facilities within the parameters of ethics.Interacting with industries and institutions to upgrade knowledge and understand current requirements and trends in technologies.Enhancing the research-oriented activities in socially prominent areas.Building up the overall career through impressive extra-academic activities.\n\n");
                                printf("* To be a leading Department to produce remarkable Electrical and Electronics Engineering scholars for the betterment of the society.\n\n");
                                printf("* The Head Of The Department is Professor Dr N Saravanan.\n\n");
                                break;
                            }
                            case 7:
                            {
                                system("cls");
                                printf("\n\t\t\tMECHANICAL ENGINEERING.\n\n\n");
                                printf("* Mechanical Engineers experience interesting and active career opportunities. . . their application fields and job functions may change from time to time and they may assume managerial responsibilities as they gain maturity and experience. Many Mechanical Engineers also discover that their analytical background and creative problem solving abilities are the keys to success in other fields and this provides them with a valuable degree of mobility.\n\n");
                                printf("* Within a span of 15 years, the department has reached ‘Center of Excellence in TOYOTA, ALTAIR HyperWorks, Center for Research on Automated Machining & Robotics and having an MOU with several industries, attaining good academic results, conducting several International webinars, National webinars, seminars, conferences, workshops, Industrial visits, FDPs, Industry – Institute Interactions at State & National levels. Currently, the Department offers Doctoral Degree by Research Program in addition to UG program affiliated to Visvesvaraya Technological University (VTU) Belgaum, Karnataka”.\n\n");
                                printf("* The Head Of The Department is Professor Dr Ramesh C.\n\n");
                                break;
                            }
                            case 8:
                            {
                                system("cls");
                                printf("\n\t\t\tCIVIL ENGINEERING.\n\n\n");
                                printf("* Civil engineers conceive and manage the physical infrastructure and environmental protection systems of our society. They design, plan, construct and manage physical facilities, including roadways, dams, buildings and pipelines. They may own a construction firm, be a partner in a consulting company, or work for a government agency or corporation. They can find work anywhere in the world, because there are needs for physical facilities everywhere.\n\n");
                                printf("* Civil engineering is the oldest engineering discipline after military engineering, and it was defined to distinguish non-military engineering from military engineering. It is traditionally broken into several sub-disciplines including environmental engineering, geotechnical engineering, structural engineering, transportation engineering, municipal or urban engineering, water resources engineering, materials engineering, coastal engineering, surveying, and construction engineering.\n\n");
                                printf("* Department of CIVIL was established in 2009 with an intake of 60 and the intake was increase to 120 in the year 2014.Department has well qualified faculty to handle the specialized subjects and laboratories. All laboratories are well equipped and maintained as per the VTU curriculum.\n\n");
                                printf("* The Head Of The Department is Professor Dr Ramesh V.\n\n");
                                break;
                            }
                            case 9:
                            {
                                goto exit1;
                            }
                            default:
                            printf("\n\n\t\t\t\t\t****************###*******************");
                        }
                        break;
                    } 
                    case 2:
                    {
                        system("cls");
                        printf("LOCATING RAJARAJESHWARI COLLEGE OF ENGINEERING ON GOOGLE MAPS......!\n\n");
                        system("start  https://www.google.co.in/maps/place/Rajarajeswari+College+of+Engineering/@12.8866843,77.4474117,17z/data=!3m1!4b1!4m5!3m4!1s0x3bae38bc2bb37a81:0xcef960a370d38901!8m2!3d12.8866791!4d77.4496004?hl=en");
                        break;
                    }
                    case 3:
                    {
                        system("cls");
                        printf("FOR FURTHER INFO , OPRNING RRCE OFFICIAL WEBSITE...!\n\n");
                        system("start http://www.rrce.org");
                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        printf("\n\n\n\t\t\t\t\tOK BYE....!!!");
                        sleep(3);
                        goto quit;
                    }
                    default:
                    printf("\n\n\t\t\t\t\t****************###********************");   
                }
            }
        }
        else 
        {
            printf("OOPS ...! \nPlease check your message.\n");
        }
    }
   return 0;
}

//calculator udf
void addition()
{
    printf("Enter the numbers you want to add: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("The sum of a and b is %d\n",a+b);
}
void subtraction()
{
    printf("Enter the numbers you want to subtract: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("The subtraction of a and b is %d\n",a-b);
}
void multiplication()
{
    printf("Enter the numbers you want to multiply: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("The multiplication of a and b is %d\n",a*b);
}
void division()
{
    printf("Enter the numbers you want to divide: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("The division of a and b is %f\n",(float)a/(float)b);
}
void modulus()
{
    printf("Enter the numbers you want to find modulus of: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("The modulus of a and b is %d\n",a%b);
}
void factorial()
{
    int n,factorial;
    printf("Enter the number you want the factorial of: ");
    scanf("%d",&n);
    factorial=1;
    for(int i=1;i<=n;i++){
        factorial=factorial*i; // factorial*=i;
    }
    printf("\nFactorial of %d is %d",n,factorial);
}
void power()
{
    double b;
    double p;
    printf("Enter the base and the power: ");
    scanf("%lf%lf",&b,&p);
    double e=pow(b,p);
    printf("The power is %lf",e);
}
void square()
{
    double b;
    printf("Enter the number you want the square of: ");
    scanf("%lf",&b);
    double p=pow(b,2);
    printf("The square of %lf is %lf",b,p);
}
void cube()
{
    double b;
    printf("Enter the number you want the cube of: ");
    scanf("%lf",&b);
    double p=pow(b,3);
    printf("The cube of %lf is %lf",b,p);
}
void squareroot()
{
    double b;
    printf("Enter the number you want the square root of : ");
    scanf("%lf",&b);
    double s = sqrt(b);
    printf("The square root of %lf is %lf",b,s);
}
void logbasee()
{
    double b;
    printf("Enter the number you want to find log for the base e of : ");
    scanf("%lf",&b);
    double s = log(b);
    printf("The log for base e of %lf is %lf",b,s);
}
void logbase10()
{
    double b;
    printf("Enter the number you want to find the log for the base 10 of : ");
    scanf("%lf",&b);
    double s = log10(b);
    printf("The log for the base 10 of %lf is %lf",b,s);
}
void antilogforbasee()
{
    double b;
    printf("Enter the number you want to find the antilog for the base e of : ");
    scanf("%lf",&b);
    double s = pow(2.71828182845,b);
    printf("The antilog for the base e of %lf is %lf",b,s);
}
void antilogforbase10()
{
    double b;
    printf("Enter the number you want to find the antilog for the base 10 of : ");
    scanf("%lf",&b);
    double s = pow(10,b);
    printf("The antilog for the base 10 of %lf is %lf",b,s);
}
void sine()
{
    double b;
    printf("Enter the number you want the sine of : ");
    scanf("%lf",&b);
    double s = sin(b);
    printf("The sine of %lf is %lf",b,s);
}
void cosine()
{
    double b;
    printf("Enter the number you want the cosine of : ");
    scanf("%lf",&b);
    double s = cos(b);
    printf("The cosine of %lf is %lf",b,s);
}
void tangent()
{
    double b;
    printf("Enter the number you want the tangent of : ");
    scanf("%lf",&b);
    double s = tan(b);
    printf("The tangent of %lf is %lf",b,s);
}
void sinein()
{
    double b;
    printf("Enter the number you want the sine inverse of : ");
    scanf("%lf",&b);
    double s = asin(b);
    printf("The sine inverse of %lf is %lf",b,s);
}
void cosinein()
{
    double b;
    printf("Enter the number you want the cosine inverse of : ");
    scanf("%lf",&b);
    double s = acos(b);
    printf("The cosine inverse of %lf is %lf",b,s);
}
void tangentin()
{
    double b;
    printf("Enter the number you want the tangent inverse of : ");
    scanf("%lf",&b);
    double s = atan(b);
    printf("The tangent inverse of %lf is %lf",b,s);
}












//snake game udf

void Move()
{
    int a,i;
 
    do{
 
        Food();
        fflush(stdin);
 
        len=0;
 
        for(i=0;i<30;i++)
 
        {
 
            body[i].x=0;
 
            body[i].y=0;
 
            if(i==length)
 
            break;
 
        }
 
        Delay(length);
 
        Boarder();
 
        if(head.direction==RIGHT)
 
            Right();
 
        else if(head.direction==LEFT)
 
            Left();
 
        else if(head.direction==DOWN)
 
            Down();
 
        else if(head.direction==UP)
 
            Up();
 
        ExitGame();
 
    }while(!kbhit());
 
    a=getch();
 
    if(a==27)
 
    {
 
        system("cls");
 
        exit(0);
 
    }
    key=getch();
 
    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))
 
    {
 
        bend_no++;
 
        bend[bend_no]=head;
 
        head.direction=key;
 
        if(key==UP)
 
            head.y--;
 
        if(key==DOWN)
 
            head.y++;
 
        if(key==RIGHT)
 
            head.x++;
 
        if(key==LEFT)
 
            head.x--;
 
        Move();
 
    }
 
    else if(key==27)
 
    {
 
        system("cls");
 
        exit(0);
 
    }
 
    else
 
    {
 
        printf("\a");
 
        Move();
 
    }
}
 
void gotoxy(int x, int y)
{
 
 COORD coord;
 
 coord.X = x;
 
 coord.Y = y;
 
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
 
}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
 }
void load(){
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1;r<=20;r++){
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",177);}
    getch();
}
void Down()
{
    int i;
    for(i=0;i<=(head.y-bend[bend_no].y)&&len<length;i++)
    {
        GotoXY(head.x,head.y-i);
        {
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y++;
}
void Delay(long double k)
{
    Score();
    long double i;
    for(i=0;i<=(10000000);i++);
}
void ExitGame()
{
    int i,check=0;
    for(i=4;i<length;i++)   //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    //check's value increases as the coordinates of head is equal to any other body coordinate
        }
        if(i==length||check!=0)
            break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0)
    {
        life--;
        if(life>=0)
        {
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            Move();
        }
        else
        {
            system("cls");
            printf("All lives completed\nBetter Luck Next Time!!!\nPress any key to quit the game\n");
            record();
            exit(0);
        }
    }
}
void Food()
{
    if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
 
            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}
void Left()
{
    int i;
    for(i=0;i<=(bend[bend_no].x-head.x)&&len<length;i++)
    {
        GotoXY((head.x+i),head.y);
       {
                if(len==0)
                    printf("<");
                else
                    printf("*");
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend();
    if(!kbhit())
        head.x--;
 
}
void Right()
{
    int i;
    for(i=0;i<=(head.x-bend[bend_no].x)&&len<length;i++)
    {
        //GotoXY((head.x-i),head.y);
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");
            else
                printf("*");
        }
        /*body[len].x=head.x-i;
        body[len].y=head.y;*/
        len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}
void Bend()
{
    int i,j,diff;
    for(i=bend_no;i>=0&&len<length;i--)
    {
            if(bend[i].x==bend[i-1].x)
            {
                diff=bend[i].y-bend[i-1].y;
                if(diff<0)
                    for(j=1;j<=(-diff);j++)
                    {
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y+j;
                        GotoXY(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
                else if(diff>0)
                    for(j=1;j<=diff;j++)
                    {
                        /*GotoXY(bend[i].x,(bend[i].y-j));
                        printf("*");*/
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y-j;
                        GotoXY(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
            }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1;j<=(-diff)&&len<length;j++)
                {
                    /*GotoXY((bend[i].x+j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                        printf("*");
                   len++;
                   if(len==length)
                           break;
               }
           else if(diff>0)
               for(j=1;j<=diff&&len<length;j++)
               {
                   /*GotoXY((bend[i].x-j),bend[i].y);
                   printf("*");*/
                   body[len].x=bend[i].x-j;
                   body[len].y=bend[i].y;
                   GotoXY(body[len].x,body[len].y);
                       printf("*");
                   len++;
                   if(len==length)
                       break;
               }
       }
   }
}
void Boarder()
{
   system("cls");
   int i;
   GotoXY(food.x,food.y);   /*displaying food*/
       printf("F");
   for(i=10;i<71;i++)
   {
       GotoXY(i,10);
           printf("!");
       GotoXY(i,30);
           printf("!");
   }
   for(i=10;i<31;i++)
   {
       GotoXY(10,i);
           printf("!");
       GotoXY(70,i);
       printf("!");
   }
}
void Print()
{
   //GotoXY(10,12);
   printf("\tWelcome to the mini Snake game.(press any key to continue)\n");
  getch();
   system("cls");
   printf("\tGame instructions:\n");
   printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
   printf("\n\nPress any key to play game...");
   if(getch()==27)
   exit(0);
}
void record(){
   char plname[20],nplname[20],cha,c;
   int i,j,px;
   FILE *info;
   info=fopen("record.txt","a+");
   getch();
   system("cls");
   printf("Enter your name\n");
   scanf("%[^\n]",plname);
   //************************
   for(j=0;plname[j]!='\0';j++){ //to convert the first letter after space to capital
   nplname[0]=toupper(plname[0]);
   if(plname[j-1]==' '){
   nplname[j]=toupper(plname[j]);
   nplname[j-1]=plname[j-1];}
   else nplname[j]=plname[j];
   }
   nplname[j]='\0';
   //*****************************
   //sdfprintf(info,"\t\t\tPlayers List\n");
   fprintf(info,"Player Name :%s\n",nplname);
    //for date and time
 
   time_t mytime;
  mytime = time(NULL);
  fprintf(info,"Played Date:%s",ctime(&mytime));
     //**************************
     fprintf(info,"Score:%d\n",px=Scoreonly());//call score to display score
     //fprintf(info,"\nLevel:%d\n",10);//call level to display level
   for(i=0;i<=50;i++)
   fprintf(info,"%c",'_');
   fprintf(info,"\n");
   fclose(info);
   printf("wanna see past records press 'y'\n");
   cha=getch();
   system("cls");
   if(cha=='y'){
   info=fopen("record.txt","r");
   do{
       putchar(c=getc(info));
       }while(c!=EOF);}
     fclose(info);
}
int Score()
{
   int score;
   GotoXY(20,8);
   score=length-5;
   printf("SCORE : %d",(length-5));
   score=length-5;
   GotoXY(50,8);
   printf("Life : %d",life);
   return score;
}
int Scoreonly()
{
int score=Score();
system("cls");
return score;
}
void Up()
{
   int i;
   for(i=0;i<=(bend[bend_no].y-head.y)&&len<length;i++)
   {
       GotoXY(head.x,head.y+i);
       {
           if(len==0)
               printf("^");
           else
               printf("*");
       }
       body[len].x=head.x;
       body[len].y=head.y+i;
       len++;
   }
   Bend();
   if(!kbhit())
       head.y--;
}



//pacman game udf


void display();
void SetColor(int ForgC);
//
void initialize()
{
   // 1. replace each empty field in the playfield with a food field
   int i;

   for(i = 0; i < H; i++)
   {
       int j;
      for( j = 0; j < W; j++)
      {
         if (playfield[i][j]==' ')
            playfield[i][j] = '.';
      }
   }

   // 2. initialize all ghosts

   for ( i = 0; i <gho1; i++)
   {
      allGhosts[i].vx = 0;
      allGhosts[i].vy = 0;
      // try to find a (x,y) coordinate randomly where a food piece is
      int x,y;
      do
     {
         x = 1 + rand() % (W-1);
         y = 1 + rand() % (H-1);

     } while (playfield[y][x] != '.');
      allGhosts[i].position.x = x;
      allGhosts[i].position.y = y;
      playfield[y][x] = '%';

   }
     for ( i = 0; i < gho1; i++)
   {
      allGhosts2[i].vx = 0;
      allGhosts2[i].vy = 0;
      // try to find a (x,y) coordinate randomly where a food piece is
      int x,y;
      do
     {
         x = 1 + rand() % (W-1);
         y = 1 + rand() % (H-1);

     } while (playfield[y][x] != '.');
      allGhosts2[i].position.x = x;
      allGhosts2[i].position.y = y;
      playfield[y][x] = '%';

   }



}

//
void user_input()
{
   if (_kbhit())
   {
      char c1 = _getch();

      if (c1 == -32)
      {
         char c2 = _getch();

         myPacMan.vx = 0;
         myPacMan.vy = 0;
         int i;
         for(i=0;i<gho1;i++)
        {
             allGhosts[i].vx=0;
             allGhosts[i].vy=0;
             allGhosts2[i].vx=0;
             allGhosts2[i].vy=0;

        }

         switch (c2)
         {
            case 72: myPacMan.vy = -1; break; // cursor up
            case 80: myPacMan.vy = +1; break; // cursor down
            case 75: myPacMan.vx = -1; break; // cursor left
            case 77: myPacMan.vx = +1; break; // cursor right
         }
         for(i=0;i<gho1;i++)
         {
             allGhosts[i].vx=+1;
             allGhosts[i].vy=+1;
             allGhosts2[i].vx=0;
             allGhosts2[i].vy=+1;
         }
      }




   }

}
void display()
{
    SetColor(1);
printf("                                        _______   ______    _____   ___      ___   ______   ___       \n");
printf("                                       ||     || ||    ||  ||      ||  |    |  || ||    || ||  |    ||\n");
printf("                                       ||     || ||    ||  ||      ||   |  |   || ||    || ||   |   ||\n");
printf("                                       ||_____|| ||____||  ||      ||    ||    || ||____|| ||    |  ||\n");
printf("                                       ||        ||    ||  ||      ||          || ||    || ||     | ||\n");
printf("                                       ||        ||    ||  ||____  ||          || ||    || ||      |||\n");
SetColor(15);
}

//swaroop
void move_figures()
{
   // 1. delete PacMan from old position
   playfield[myPacMan.position.y][myPacMan.position.x] = ' ';
   int i;
   for(i=0;i<gho1;i++)
   {
       playfield[allGhosts[i].position.y][allGhosts[i].position.x] = ' ';
        playfield[allGhosts2[i].position.y][allGhosts2[i].position.x] = ' ';
   }

   // 2. compute new desired coordinate (nx,ny)
   int nx = myPacMan.vx + myPacMan.position.x;
   int ny = myPacMan.vy + myPacMan.position.y;
   int mx[5];
   int my[5];
   int mx1[5];
   int my1[5];
 for(i=0;i<gho1;i++)
   {
        mx[i] = allGhosts[i].vx + allGhosts[i].position.x;
        my[i] = allGhosts[i].vy + allGhosts[i].position.y;
        mx1[i] = allGhosts2[i].vx + allGhosts2[i].position.x;
        my1[i] = allGhosts2[i].vy + allGhosts2[i].position.y;
   }
   // 3. test whether there is a wall at (nx,ny)
   if (playfield[ny][nx] == '#')
   {
      myPacMan.vx = 0;
      myPacMan.vy = 0;
   }
   for(i=0;i<gho1;i++)
   {

   if(playfield[my[i]][mx[i]]=='#')
      {
          if(allGhosts[i].vx>0 || allGhosts[i].vy>0)
          {

                allGhosts[i].vx=-1;
                allGhosts[i].vy=-1;
            }
            else
            {
                allGhosts[i].vx=+1;
                allGhosts[i].vy=+1;
            }
      }
    if(playfield[my1[i]][mx1[i]]=='#')
    {
        if(allGhosts2[i].vy<0)
          {

                allGhosts2[i].vx=0;
                allGhosts2[i].vy=+1;
            }
            else
            {
                allGhosts2[i].vx=0;
                allGhosts2[i].vy=-1;
            }
    }



}



   // 4. update PacMan's coordinate

   myPacMan.position.x += myPacMan.vx;
   myPacMan.position.y += myPacMan.vy;
    for(i=0;i<gho1;i++)
      {
          allGhosts[i].position.x+=allGhosts[i].vx;
          allGhosts[i].position.y+=allGhosts[i].vy;
          allGhosts2[i].position.x+=allGhosts2[i].vx;
          allGhosts2[i].position.y+=allGhosts2[i].vy;

      }

   // 5. check for a food piece at the new location
   if (playfield[ny][nx] == '.')
   {
      myPacMan.food_coll++;
   }
   for(i=0;i<gho1;i++)

   {

    if(playfield[my[i]][mx[i]] == '.')
    {

            playfield[my[i]-allGhosts[i].vy][mx[i]-allGhosts[i].vx]='.';
    }
    if(playfield[my1[i]][mx1[i]] == '.')
    {

            playfield[my1[i]-allGhosts2[i].vy][mx1[i]-allGhosts2[i].vx]='.';
    }
    }


   // 6. put PacMan back again to playfield

   playfield[myPacMan.position.y][myPacMan.position.x] = '@';
    for(i=0;i<gho1;i++)
    {
        playfield[allGhosts[i].position.y][allGhosts[i].position.x]='%';
        playfield[allGhosts2[i].position.y][allGhosts2[i].position.x]='%';
    }

}

void show_playfield()
{
    int i;
   for ( i = 0; i < H; i++)
   {
       printf("                                       ");
       int j;
      for ( j = 0; j < W; j++)
      {
          if(playfield[i][j]=='.')
          {
              SetColor(4);
            printf("%c", playfield[i][j]);
                SetColor(15);
          }
            else if(playfield[i][j]=='%')
            {
                SetColor(9);
                printf("%c", playfield[i][j]);
                SetColor(15);
            }
            else if(playfield[i][j]=='@')
            {
                SetColor(14);
                printf("%c", playfield[i][j]);
                SetColor(15);
            }
            else
            {
                printf("%c", playfield[i][j]);
            }
      }
      printf("\n");
   }

   printf("                                       Score: %d\n", myPacMan.food_coll);
}
void check_coll()
{
    int i=0;
     for(i=0;i<gho1;i++)
   {
       if((allGhosts[i].position.x==myPacMan.position.x && allGhosts[i].position.y==myPacMan.position.y) || (allGhosts2[i].position.x==myPacMan.position.x && allGhosts2[i].position.y==myPacMan.position.y))
        {
            system("cls");
            display();
            printf("\n\n\n");
            printf("     \t\t\t\t\t\t\t\t\tYOUR SCORE IS:%d",myPacMan.food_coll);
            
            getchar();
            exit(0);
        }
        if(myPacMan.food_coll>=250)
        {
            system("cls");
            display();
            printf("\n\n\n");
            printf("     \t\t\t\t\t\t\t\tYOUR SCORE IS:%d",myPacMan.food_coll);
            
            getchar();
            exit(0);
            }
   }
}

//
void set_cursor_position(int x, int y)
{
   //Initialize the coordinates
   COORD coord = { x, y };
   //Set the position
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

} // set_cursor_position


void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


//unit converter udf

void unitsMessage(short int c, short int unit, short int *u)
{
	int userInput;
	if(unit == 0)
		printf("Choose 'From' Unit:\n");
	else
		printf("Choose 'To' Unit:\n");

	switch(c)
	{
		case 1:
			puts("1) Kilometers (km)");
			puts("2) Meters (m)");
			puts("3) Centimeters (cm)");
			puts("4) Miles");
			puts("5) Yards");
			puts("6) Milimeters (mm)");
			puts("7) Feet");
			puts("8) Inches");
			break;
		case 2:
			puts("1) Kilograms (kg)");
			puts("2) Grams (g)");
			puts("3) Miligrams (mg)");
			puts("4) Tonne");
			puts("5) US Ton");
			puts("6) Pounds");
			puts("7) Stones");
			puts("8) Ounces");
			break;
		case 3:
			puts("1) Cubic Meters");
			puts("2) Litres (L)");
			puts("3) Mililitres (mL)");
			puts("4) US Liquid Gallons");
			puts("5) US Legal Cups");
			puts("6) US Tablespoons");
			puts("7) Imperial Gallons");
			puts("8) Imperial Cups");
			puts("9) Imperial Tablespoons");
			puts("0) Fluid Ounces");
			break;
	}
	
	while(1)
	{
		userInput = getch();
		
		if(userInput == '1')
		{
			system("cls");
			*u = 1;
			break;
		}
		else if(userInput == '2')
		{
			system("cls");
			*u = 2;
			break;
		}
		else if(userInput == '3')
		{
			system("cls");
			*u = 3;
			break;
		}
		else if(userInput == '4')
		{
			system("cls");
			*u = 4;
			break;
		}
		else if(userInput == '5')
		{
			system("cls");
			*u = 5;
			break;
		}
		else if(userInput == '6')
		{
			system("cls");
			*u = 6;
			break;
		}
		else if(userInput == '7')
		{
			system("cls");
			*u = 7;
			break;
		}
		else if(userInput == '8')
		{
			system("cls");
			*u = 8;
			break;
		}
		else if(userInput == '9')
		{
			system("cls");
			*u = 9;
			break;
		}
		else if(userInput == '0')
		{
			system("cls");
			*u = 0;
			break;
		}
	}
}

