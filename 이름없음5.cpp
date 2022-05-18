#include <iostream>
#include <cstring>
using namespace std;
namespace RISK_LEVEL
{
	enums( RISK_A=30, RISK_B=20, RISK_C=10);
}

class Employee
{
private:
	char name[100];
public:
	Employee(char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const { return 0;}
	virtual void ShowSalaryInfo() const {}
	
};

class FullTimeWorker: public Employee
{
private:
	int salary;
public:
	FullTimeWorker(char* name, int salary)
		: Employee(name), salary(salary) {}
	virtual int GetPay() const
	{
		return salary;
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}
};

class PartTimeWorker: public Employee
{
private:
	int payToHour;
	int workTime;
public:
	PartTimeWorker(char* name, int payToHour)
		: Employee(name), payToHour(payToHour), workTime(0) {}
	virtual int GetPay() const
	{
		return payToHour * workTime;
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}
	void AddWorkTime(int time)
	{
		workTime+=time;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {}
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for(int i = 0 ; i < empNum ; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const
	{
		int sum = 0 ;
		for(int i = 0 ; i < empNum ; i++)
			sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for(int i = 0 ; i < empNum ; i++)
			delete empList[i];
	}
};

class SalesWorker : public FullTimeWorker{
	private:
		int salesResult;
		int ratio;
	public:
		SalesWorker(char* name, int salary, double ratio):
		FullTimeWorker(name,salary),ratio(ratio),salesResult(0){}
		virtual int Getpay() const
		{
			return FullTimeWorker::GetPay()+salesResult*ratio;
		}
		virtual void ShowSalesWorkerInfo() const
		{
			cout<<"salary :  "<< GetPay()<<endl;
			
		}
		void AddSalesResult(int result){
			salesResult+= result;
		}
	};
	
	class int ForeignSalesWorker: public SalesWorker{
		private:
			int risklevel;
		public:
			ForeignSalesWorker(char* name, int salary, double ratio,int risklevel):
			SalesWorker(name,salary,ratio),risklevel(risklevel){}
			int GetRiskPay(){
				return int(SalesWorker::Getpay()*risklevel/100.0)
			}
			virtual int Getpay() const
			{
				
				return SalesWorker::Getpay() + GetRiskPay();
			}
			virtual void ShowSalaryInfo() const
   			{
      			ShowYourName();
      			cout << "salary: " << GetPay() << endl;
      			cout << "risk pay : " << GetRiskPay() << endl;
      			cout << "total pay : " << GetPay() << endl << endl;
  			}   
			
			
		
	};
	

int main(void)
{
    EmployeeHandler handler;
    
    ForeignSalesWorker* fsw1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fsw1->AddSalesResult(7000);
    handler.AddEmployee(fsw1);
    
    ForeignSalesWorker* fsw2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fsw2->AddSalesResult(7000);
    handler.AddEmployee(fsw2);
    
    ForeignSalesWorker* fsw3 = new ForeignSalesWorker("Park", 1000, 0.1, RISK_LEVEL::RISK_C);
    fsw3->AddSalesResult(7000);
    handler.AddEmployee(fsw3);
    
    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();
    
    return 0;
}
