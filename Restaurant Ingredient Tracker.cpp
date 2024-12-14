#include <iostream>
#include <string>

using namespace std;

class Ingredient {
private:
    string name;
    string supplier;
    int dailyUsage[31]={0};
    int usageDays=0;
    static int totalUsage;

public:

    Ingredient(string ingredientName,string supplierName)
         {
              name=ingredientName;
              supplier=supplierName;
        }

    void updateUsage(int usage)
    {
        if (usage<0)
        {
            cout<<"Usage cannot be negative. Ignored."<<endl;
            return;
        }
        if (usageDays>=31)
        {
            cout <<"Usage for all days in the month has already been recorded."<<endl;
            return;
        }
        dailyUsage[usageDays++]=usage;
        totalUsage=totalUsage+usage;
    }

    int calculateMonthlyUsage() const {
        int sum=0;
        for (int i=0;i< usageDays;i++) {
            sum=sum+dailyUsage[i];
        }
        return sum;
    }
    static int getTotalUsage()
    {
        return totalUsage;
    }

    void displayInfo() const {
        cout<<"Ingredient: " <<name<<endl;
        cout<<"Supplier: "<<supplier<<endl;
        cout<<"Monthly Consumption: "<<calculateMonthlyUsage()<<" units"<<endl;
    }
};


int Ingredient::totalUsage = 0;

int main() {

    Ingredient sugar("Sugar", "Fresh Company");
    Ingredient flour("Flour", "Bashundhara Co.");

    sugar.updateUsage(20);
    sugar.updateUsage(30);
    sugar.updateUsage(20);

    flour.updateUsage(50);
    flour.updateUsage(30);

    sugar.displayInfo();
    flour.displayInfo();

    cout<<"Total usage across all ingredients: "<<Ingredient::getTotalUsage()<<" units"<<endl;

    return 0;
}

