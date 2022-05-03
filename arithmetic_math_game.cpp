#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

void play();
void instructions();

int main(){
	//random no generation
	srand( (unsigned)time(NULL) );

	char option;

	do{
		system("cls");
		cout<<"-----------------------------------"<<endl;
		cout<<"           MATHS GAME			  "<<endl;
		cout<<"-----------------------------------"<<endl<<endl;
		cout<<"1. Play"<<endl;
		cout<<"2. Instructions"<<endl;
		cout<<"3. Exit"<<endl<<endl;
		cout<<"Choose Option (1-3):";
		cin>>option;

		switch(option){
			case '1':
				play();
				break;
			case '2':
				instructions();
				break;
		}
	}while(option != '3');

	return 0;
}

void play(){
	 int level, limit;
	 char option;

	 system("cls");
	 cout<<"-----------------------------------"<<endl;
	 cout<<"|      ARITHMETIC MATH GAME	      |"<<endl;
	 cout<<"-----------------------------------"<<endl<<endl;
	 cout<<"1. EASY"<<endl;
	 cout<<"2. MEDIUM"<<endl;
	 cout<<"3. HARD"<<endl;
	 cout<<"4. Back to Menu"<<endl<<endl;
	 cout<<"Choose Option (1-4):";
	 cin>>option;

	 switch(option){
		case '1': limit = 20; break;
		case '2': limit = 100; break;
		case '3': limit = 1000; break;
		case '4': break;
	 }

	 float q1, q2, ans, correctAns;
	 int correctNo = 0, totalNo;
	 char operation;
	 cout<<"Enter the total number of questions: ";
	 cin>>totalNo;

	 if( option != '4' ){
		 for(int i=0; i<totalNo; i++){
		 	q1 = rand()%limit;
		 	q2 = rand()%limit;

		 	int tmpOp = rand()%5;
		 	if(tmpOp>2 && q1<q2) tmpOp= rand()%3; // if the value of tmpOP is 3 or 4 then they will
                //perform devision and if q1 is less than q2 hence the operations
                // will be changed to + or - or *
	 		switch(tmpOp){
			      case 0: operation = '+'; break;
				  case 1: operation = '-'; break;
				  case 2: operation = '*'; break;
				  case 3: operation = '/';break;
				  case 4: operation = '%';break;
	 		}

		 	cout<<"("<<(i+1)<<"). ";
		 	cout<<q1<<" "<<operation<<" "<<q2<<" = ";

			cin>> ans;

			switch(operation){
			      case '+': correctAns = q1 + q2; break;
				  case '-': correctAns = q1 - q2; break;
				  case '*': correctAns = q1 * q2; break;
				  case '/': correctAns = q1 / q2; break;
				  case '%': correctAns =(int) q1 % (int)q2; break;
	 		}

			if( correctAns == ans ){
				correctNo++;
				cout<<"correct."<<endl<<endl;
			}
			else{
				cout<<"wrong"<<endl;
		 		cout<<q1<<" "<<operation<<" "<<q2<<" = ";
			 	cout<<correctAns<<endl<<endl;
			}
		 }

		 cout<<"Total: "<<totalNo<<endl;
		 cout<<"Correct: "<<correctNo<<endl<<endl;

		 cout<<"Press any key to continue..."<<endl;
		 getch();
	 }
}

void instructions(){
	system("cls");//clears system screen
	cout<<"-----------------------------------"<<endl;
	cout<<"|         Instructions			 |"<<endl;
	cout<<"-----------------------------------"<<endl<<endl;
	cout<<"1. This game contains basic arithmetic problems"<<endl;
	cout<<"2. Each correct answer will yeild to 1 Point"<<endl;
	cout<<"3. Total questions will be 5 "<<endl;
	cout<<"4. To win, you need 3 or more correct answers"<<endl;
	cout<<endl;

	cout<<"Press any key to continue..."<<endl;
	getch();
}
