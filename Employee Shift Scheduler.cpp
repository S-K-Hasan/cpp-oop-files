#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int shifts[30];
    int totalHours;
    static int allTotal;
  public:
    Employee( string employeeName, int shift[])
     {
        name = employeeName;
        totalHours = 0;
        for (int i=0;i<30;i++)
        {
            shifts[i]=shift[i];
            totalHours= totalHours+shift[i];
        }
     }

    void ChangeShift(int day)
     {
        if (day>=1&&day<=30)
         {
            if(shifts[day-1]>=8)
            {
                shifts[day-1]=6;
                totalHours= totalHours-2;
                cout<<"Your shift converted to night shift for day: "<<day<<endl;
            }
            else if(shifts[day-1]==6)
            {
                shifts[day-1]=8;
                totalHours= totalHours+2;
                cout<<"Your shift changed to day shift on day: "<<day<<endl;
            }
            else
            {
                cout<<"No valid shift data for day: "<<day<<endl;
            }
        }
        else
        {
            cout<<"Invalid day."<<endl;
        }
    }
    int getTotalHours() const
    {
        return totalHours;
    }

    static int computeTotalHours(Employee employees[],int size)
    {

        for (int i = 0; i < size; i++)
        {
            allTotal += employees[i].getTotalHours();
        }
        return allTotal;
    }
    void displayDetails() const {
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Total Hours Worked: "<<totalHours<<endl;
    }
};

int Employee::allTotal = 0;

int main() {

    int shifts1[30]={8,8,8,8,8,0,0,8,8,8,8,8,0,0,0,8,8,8,8,0,0,8,8,8,8,8,0,0,8,8};
    int shifts2[30]={8,8,8,8,8,0,0,8,8,8,8,8,0,0,6,8,8,8,8,0,0,8,8,8,8,8,0,0,8,8};

    Employee emp1("Shanto", shifts1);
    Employee emp2("Hasan", shifts2);

    Employee employees[2] = {emp1, emp2};
    emp1.ChangeShift(15);

    for (int i = 0; i < 2; i++)
    {
        employees[i].displayDetails();
    }

    int totalHours = Employee::computeTotalHours(employees, 2);
    cout<<"Total Hours Worked by All Employees: "<<totalHours<<endl;

    return 0;
}


