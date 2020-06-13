#include <iostream>

 
using namespace std;


	bool validateInput(char);
	int checkAnswer();
	void getIncorrectlyAnswerQuestions();
     void getOutput(int);
     
     
const int number_question =5 ;
const int passing_score = 3;

char CorrectAnswer [] = {'B','D','C','A','B','D','C','A', 'B','D','C','A','B','D','C','A','B','D','C','A'};

int IncorrectlyAnswerQustion[number_question] ;
char User_Answer[number_question];

int main(){
 
     int correctAnswerCounter =0 ;
 	 for(int i =0; i <number_question ;i++){
 	 	
 	 	// get input here 
 	 	do{
 	 		cout << "Please enter your answer for a question " << i + 1 << " " ;
 	 		cin >> User_Answer[i] ;
		  }while(!validateInput(User_Answer[i]));
	  }
	  correctAnswerCounter = checkAnswer();
	 // just to makesure that we are doing the 
	 
	 if(correctAnswerCounter < number_question) {
	 	
	 	getIncorrectlyAnswerQuestions();
	  	
	  }
}

void getOutput(int counter) {
	cout << " \n You have " << (counter >= passing_score ? "PASSED " : "FAILED") << " The test " << endl;
	cout << "You have answer " << counter << " Correctly and " << ( number_question - counter ) << " Incorrectly " << endl;
	
	// if some asnswer were wronge , output what the answer was wronge and which number is not 
	if(counter < number_question  ){
		cout << " The following questions were answered incorrectly :\n " ;
		for(int i =0 ; i< number_question- counter ;i++) {
			cout << "Question number " << (IncorrectlyAnswerQustion [i] +1 ) << ". Correct answer was " << CorrectAnswer [IncorrectlyAnswerQustion [i]] << " You answer " << User_Answer[IncorrectlyAnswerQustion [i]] << endl;
		}
	}
}
void getIncorrectlyAnswerQuestions(){ 
    // this is an indirectly wronge answer array 

	int counter = 0;
	for(int i =0 ; i < number_question ;i++) {
		if(CorrectAnswer[i] != toupper(User_Answer[i])){
			IncorrectlyAnswerQustion[counter] =1 ; 
			counter++;
		}
	}

}
bool validateInput(char answer ){
	// only a,b,c,d,valid input 
	
	if(toupper(answer) != 'A' && toupper(answer) != 'B' && toupper(answer) != 'C' && toupper(answer) !='D'){
		
		cout << "\n Inlvide input " ;
		return false;
	}
	return true;
}

int checkAnswer(){
	int counter =0 ;
	for(int i =0 ; i<number_question ; i++){
		if( toupper(User_Answer[i] )== CorrectAnswer[i]){
			counter++;
		}
		return counter;
	}
	
}



