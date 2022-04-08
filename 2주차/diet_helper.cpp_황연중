#include <iostream>
using namespace std;

float BMR_calc(int age, float height, float weight){
	
	//Use Harris-Benedict Equation
	return 66+13.7*weight+5*height-6.8*age;
}
	
	

void nutri_calc(float BMR,int level, int purp){
	float calo;
	int prot,carb,fat,chicken_b,s_potato,almon;
	
	if (level==1) calo=1.2*BMR;
	else if (level==2) calo=1.35*BMR;
	else calo=1.6*BMR;
	
	cout<<"\nYOUR BMR:"<<BMR<<endl;
	cout<<"YOUR MAINTENANCE CALORIES:"<<calo<<endl;
	
	//if you want lose weight -500 calrories, gain weigt +50 calories
	if (purp==1) calo=calo-500;
	else if (purp==3) calo=calo+500;
	
	//protein:carbs:fat = 3:5:2
	prot=int(calo*0.3/4);
	carb=int(calo*0.5/4);
	fat=int(calo*0.2/9);
	
	chicken_b=int(prot*100/24);
	s_potato=int(carb*100/37);
	almon=int(fat*100/50);	
	
	cout<<"\nYOU NEED PROTEIN "<<prot<<"g (chicken breast:"<<chicken_b<<"g)"<<endl;
	cout<<"YOU NEED CARBS "<<carb<<"g (sweet potato:"<<	s_potato<<"g)"<<endl;
	cout<<"YOU NEED FATS "<<fat<<"g (almond:"<<almon<<"g)"<<endl;
}

int main() {
	
	int age,level, purp;
	float height,weight,BMR;
	
	cout<< "ENTER YOUR AGE:";
	cin>> age;
	cout<< "ENTER YOUR HEIGHT:";
	cin>> height;	
	cout<< "ENTER YOUR WEIGHT:";
	cin>> weight;	
	cout<< "ENTER YOUR ACTIVITY LEVEL(SEDENTARY:1, LIGHT EXERCISE:2, HEAVY EXERCISE:3):";
	cin>> level;	
	cout<< "ENTER YOUR PURPOSE(CUTTING:1, MAINTENANCE:2, BULK UP:3):";
	cin>> purp;	
	
	BMR=BMR_calc(age,height,weight);
	
	nutri_calc(BMR,level,purp);
	
	
	
	return 0;
}
