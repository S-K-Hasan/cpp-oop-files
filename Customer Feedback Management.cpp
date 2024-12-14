#include <iostream>
#include <string>

using namespace std;

class Feedback {
private:
    int customerID;           // Customer ID
    string feedbackDate;      // Feedback date
    int ratings[10];          // Array to store ratings (max 10 ratings)
    int ratingCount;          // Number of ratings recorded

public:
    // Constructor
    Feedback(int id, const string& date)
    {
        customerID=id;
         feedbackDate=date;
         ratingCount=0;
        for (int i=0; i<10;i++)
        {
            ratings[i]=0;
        }
    }

    void setRatings(const int newRatings[],int count)
     {
        if (count>10)
        {
            cout<<"Cannot set more than 10 ratings. Only the first 10 will be used."<<endl;
            count = 10;
        }
        for (int i =0;i<count;i++) {
            if (newRatings[i]<1||newRatings[i]>5)
            {
                cout<<"Invalid rating ("<<newRatings[i]<<") ignored."<<endl;
            }
           else
            {
                ratings[i] = newRatings[i];
                ratingCount++;
            }
        }
    }


    double computeAverageRating() const {
        if (ratingCount == 0) {
            return 0.0;
        }
        double sum=0;
        for (int i=0;i<ratingCount;i++)
        {
            sum=sum+ratings[i];
        }
        return (sum)/ratingCount;
    }


    void displayFeedback() const {
        cout << "Customer ID: "<<customerID<<endl;
        cout<< "Feedback Date: "<<feedbackDate<<endl;
        cout<< "Average Rating: "<<computeAverageRating()<<endl<<endl;
    }


    void compareWith(const Feedback& other) const {
        cout<<"Comparing feedback for Customer "<<customerID<<" and Customer "<<other.customerID<<endl;
        cout<<"Customer "<<customerID<< " - Average Rating: " << computeAverageRating()<<endl;
        cout<<"Customer "<< other.customerID<< " - Average Rating: " <<other.computeAverageRating()<<endl;

        if (computeAverageRating() > other.computeAverageRating())
        {
            cout<<"Customer "<<customerID<<" has a higher average rating."<<endl;
        }
        else if (computeAverageRating() < other.computeAverageRating())
        {
            cout<<"Customer "<<other.customerID<< " has a higher average rating."<<endl;
        }
        else
        {
            cout<<"Both customers have the same average rating."<<endl;
        }
    }
};

int main() {

    Feedback customer1(1, "2022-12-14");
    Feedback customer2(2, "2024-12-15");

    int ratings1[] = {4, 5, 3, 4};
    int ratings2[] = {5, 5, 4};

    customer1.setRatings(ratings1, 4);
    customer2.setRatings(ratings2, 3);

    customer1.displayFeedback();
    customer2.displayFeedback();


    return 0;
}


