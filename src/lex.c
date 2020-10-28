#include "../inc/lex.h"

int lex(char token[MAXLEN])
{

	char c;
	int state,input,i;

	int mat[5][7]={
		{0,1,2,DASHTK,NATK,EOFTK,NATK}, //starting point state
		{E1,1,E1,E1,E1,E1,E1}, //function state
		{E2,E2,2,E2,3,E2,E2}, //int number state
		{E3,E3,3,E3,E3,E3,E3}, //real number state
		{DASHTK,DASHTK,DASHTK,DASHTK,DASHTK,DASHTK,DASHTK}, //dash state
	};


	state=0; //initial state - first row
	i=0;     //token string index

	while(state>=0 && state<10){ //final states starting after 10

		c=getc(mfile); //read next character from file

		if(isspace(c)){
			input=0;
		}else if(isalpha(c)){
			input=1;
		}else if(isdigit(c)){
			input=2;
		}else if(c=='-'){
			input=3;
		}else if(c=='.'){
			input=4;
		}else if(c==EOF){
			input=5;
		}else{
			input=6;
		}

		state=mat[state][input]; //next state transition
		token[i]=c; //add character to token string
		i++;
		if(state==0) i=0;  //while i am in state 0 i dont save anything
	}
	token[i]='\0';

	if(state==E1 || state==E2 || state==E3){
		ungetc(c,mfile); //return the last read character to the file
		token[i-1]='\0'; //renew the array
	}

	//final states
	if(state==E1){
		if(strcmp(token,"num")==0) return NUMTK;
		if(strcmp(token,"array")==0) return ARRAYTK;
		if(strcmp(token,"add")==0) return ADDTK;
		if(strcmp(token,"sub")==0)	return SUBTK;
		if(strcmp(token,"mult")==0) return MULTTK;
		if(strcmp(token,"pow")==0) return POWTK;
		if(strcmp(token,"med")==0) return MEDTK;
		if(strcmp(token,"mean")==0) return MEANTK;
		if(strcmp(token,"max")==0) return MAXTK;
		if(strcmp(token,"min")==0) return MINTK;
		if(strcmp(token,"bp")==0) return BPTK;
		if(strcmp(token,"extract")==0) return EXTRACTTK;
	}
	else if(state==E2){ //int
		return E2;
	}
	else if(state==E3){ //real
		return E3;
	}

	return state;
}
