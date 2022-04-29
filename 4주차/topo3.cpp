#include <iostream>
#include <cstring>

using namespace std;

class Employee{

private:
	char name[100];

public:
	Employee(const char * name){
	   
    	strcpy(this->name, name);// name(뒤)에 있는 문자열을 복사해서 앞의 name 에 저장
	}

	virtual int GetPay() const =0;
	virtual void ShowSalary() const =0;

    void YourName() const{
		cout<<"Your name is "<<name<<endl;
	}

};



class Fulltime : public Employee{
    
private:
	int salary;
	
public:
	Fulltime(const char * name, int money) : Employee(name), salary(money){ }

	int GetPay() const{
		return salary;
	}

	void ShowSalary() const{
		YourName();
		cout<<"Your salary is "<<GetPay()<<endl<<endl;
	}

};


class PartTime : public Employee{
private:
	int work_hour;
	int pay_per;

public:
	PartTime(const char * name, int pay) : Employee(name),work_hour(0), pay_per(pay){ }

	void Worktime_receive(int time){
		work_hour+=time;
	}

	int GetPay() const{
		return work_hour * pay_per;
	}

	void ShowSalary() const{
		YourName();
		cout<<"Yoursalary is "<<GetPay()<<endl<<endl;
	}

};



class Programmer : public Fulltime{

	int result;
	double bonus;

public:
	Programmer(const char * name, int money, double times) : Fulltime(name, money), result(0), bonus(times){ }

	void Addresult(int effort){
		result+=effort;
	}

	int GetPay() const{
		return Fulltime::GetPay() + (int)(result * bonus);
	}

	void ShowSalary() const{
		YourName();
		cout<<"Your salary is "<<GetPay()<<endl<<endl;
	}

};

class Management{
    
private:
	Employee * employee_list[50];
	int employee_num;

public:
	Management() : employee_num(0){ }

	void AddEmployee(Employee * eee){
		 employee_list[employee_num++]=eee;
	}
	
	void TotalSalary() const{
		int sum=0;
		cout<<"Total salary is "<<sum<<endl;
	}

};


int main(void){

	Fulltime ft("suzy", 100);
	ft.ShowSalary();

	Programmer pg("IU", 150, 0.2);
	pg.Addresult(50);
	pg.ShowSalary();

//  PartTime * partime = new PartTime("CL", 500);
//	Management mgt;
//	mgt.AddEmployee(partime);
//	mgt.TotalSalary();

} 



