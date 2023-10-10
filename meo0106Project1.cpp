/*
Author: Manuel Osorto ------- meo0106 -----(manuelosorto@my.unt.edu)
Instructor: Dr.Shrestha
Description: CSCE 1030.002  - - Project 1
*/
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	//for random generated seeded variables
    srand(time(NULL));

	//STEP 1 INFO 
    cout<<"+------------------------------------------------------------------+"<<endl;
	cout<<"|               Computer Science and Engineering                   |"<<endl;
	cout<<"|                CSCE 1030 - Computer Science I                    |"<<endl;
	cout<<"|         Manuel Osorto meo0106 (manuelosorto@my.unt.edu)          |"<<endl;
	cout<<"+------------------------------------------------------------------+"<<endl;

    

    //STEP 2 - points
	int points=100;

    //STEP 3 - enumeration constant
    enum Choices{displayLeft=1,displayRight=2,Guess=3,Change=4,Exit=5};

	//STEP 4 -ask the user for the player name
	cout<<"Enter name of the player:";
	string name;
	getline(cin,name);

	//if name contains special character
    for(int i=0;i<name.length();++i)
    {
    	while(!(isalpha(name.at(i))) && !(isspace(name.at(i))))
    	{
    		cout<<"Your name can only have letters and spaces. Enter again."<<endl;
			cout<<"Enter name of player:";
			getline(cin,name);
		}
    }

    //convert every initial to uppercase. everything else is lowercase
	name.at(0)=toupper(name.at(0));
	for(int i=0;i<name.length()-1;++i)
	{
		if(isspace(name.at(i)))
    	{
    		name.at(i+1)=toupper(name.at(i+1));
    	}
		else
		{
			name.at(i+1)=tolower(name.at(i+1));
		}
	}

    	//convert uppercase leters, that are not suppose to, to lowercase letters
    	/*for(int i=0;i<name.length()-1;++i)
    	{
        		if(isalpha(name.at(i)))
        		{
             			name.at(i+1)=tolower(name.at(i+1));
        		}
    	}*/  //added together
    

    //STEP 5:random integers
	int first=rand()%101+100; //dsiplayed on the left
	int second=rand()%101+100; // displayed on the right
	while(second<=first) //if second is less than first integer//which it can not be
	{
    	second=rand()%101+100;
    }

    //STEP 6: Placeholders for the random numbers if the user ask for them
    int display1=-1,display2=-1;
    //cout<<display1<<"\t"<<display2<<endl;

    
    do //STEP 9 -  loop to allow user to repeat steps 7 and 8
    {
    	//STEP 7 - Menu for the user
    	cout<<display1<<'\t'<<display2<<endl; //-1	-1 until further notice
    	cout<<"1. Display Left Number"<<endl;
    	cout<<"2. Display Right Number"<<endl;
    	cout<<"3. Guess a number in between"<<endl;
    	cout<<"4. Change numbers"<<endl;
    	cout<<"5. Quit"<<endl;
    	int userInput;
    	cout<<"What do you like to do?:"; cin>>userInput;
    	Choices choice=static_cast<Choices>(userInput);
        
        //STEP 8 - cases that the user will want
        switch(choice)
        {
        	case displayLeft: //entered 1
						if(display2>-1)
                    	{
                    		cout<<"You have already displayed the right boundary, you cannot display both."<<endl;
                    	}
                    	else
                    	{
                    		display1=first;
                    		cout<<"You will only get 1 point for guessing correctly and lose 10 for guessing incorrectly, now"<<endl;
                    	}
                    	break;
        	//-----------------------------------------------------------------------------------------------------
            case displayRight: //entered 2
						if(display1>-1)
                    	{
                        	cout<<"You have already displayed the left boundary, you cannot display both."<<endl;
                     	}
                    	else
                    	{
                    		display2=second;
                    		cout<<"You will only get 1 point for guessing correctly and lose 10 for guessing incorrectly, now"<<endl;
                    	}
                    	break;
            //-----------------------------------------------------------------------------------------------------
            case Guess: // entered 3
						int guess;
						cout<<"Enter your guess( between 100-200):";
						cin>>guess;
						if(display1>-1 || display2>-1) // if user displayed one side
						{
                        	if(guess>first && guess<second)
                    		{
                    			cout<<"You guessed correctly. You get 1 point."<<endl;
                            	points+=1;
                    			cout<<"Your remaining points="<<points<<endl;
                        	}
                    		else
                    		{
                    			cout<<"You guessed incorrectly. You lose 10 points."<<endl;
                    			points-=10;
                    			cout<<"Your remaining points="<<points<<endl;
                    		}
						}
                    	else // if user did not display anything -1	-1
                    	{
                            if(guess>first && guess<second)
                    		{
                    			cout<<"You guessed correctly. You get 5 points."<<endl;
                            	points+=5;
                    			cout<<"Your remaining points="<<points<<endl;
                    		}
                        	else
                    		{
                            	cout<<"You guessed incorrectly. You lose 5 points."<<endl;
                    			points-=5;
                    			cout<<"Your remaining points="<<points<<endl;
                    		}
                   		}	
						break;
			//-----------------------------------------------------------------------------------------------------
            case Change: //entered 4
                        first=rand()%101+100;
                     	second=rand()%101+100;
                    	while(second<=first)
                    	{
                    		second=rand()%101+100;
                    	}

                    	if(display1>-1 || display2>-1)
                    	{
                    		display1=-1;
                    		display2=-1;
                    	}
                    	points-=1;
                    	cout<<"Your remaining points="<<points<<endl;
                    	cout<<"Generating new boundaries."<<endl;
                    	break;
			//-----------------------------------------------------------------------------------------------------
        	case Exit: //entered 5
                    	cout<<"Bye "<<name<<"!!!"<<endl;
                    	cout<<"Your final points balance="<<points<<endl;
                    	return 0;
			//-----------------------------------------------------------------------------------------------------
    		default: // any other thing other than 1-5
                        cout<<"Invalid choice.\n";
                    	break;
        }
    }while(points>=0); //STEP 9 -  loop to allow user to repeat steps 7 and 8

    if(points<0) // once the user runs out of points
	{
    	cout<<"Game Over.\nHa-Ha...You ran out of points."<<endl;
    	cout<<"Bye "<<name<<" !!!"<<endl;
	}

    
	return 0;
}