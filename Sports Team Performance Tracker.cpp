#include <iostream>
#include <string>

using namespace std;

class Athlete {
private:
    string name;
    string sport;
    int competitionScores[10];
    int size = 0;
    static int highestScore;

public:
    Athlete(const string& athleteName, const string& sportType)
         {
             name=athleteName;
              sport=sportType;
        }

    void recordScore(int score)
     {
        if (score<0)
        {
            cout<<"Score cannot be negative.Ignored."<<endl;
            return;
        }
        if (size>=10)
        {
            cout<<"Cannot record more than 10 scores."<<endl;
            return;
        }
        competitionScores[size++] = score;
        if(score>highestScore)
        {
            highestScore=score;
        }
     }
    double calculateAverageScore() const {
        if (size == 0)
        {
            return 0.0;
        }
        double sum = 0;
        for (int i = 0; i < size;i++)
         {
            sum=sum+competitionScores[i];
        }
        return sum/size;
    }

    static int getHighestScore()
    {
        return highestScore;
    }
    void displayInfo() const {
        cout << "Athlete: " << name<<endl;
        cout<< "Sport: " << sport<<endl;
        cout<< "Average Score: " << calculateAverageScore()<<endl<<endl;
    }
};

int Athlete::highestScore = 0;

int main() {

    Athlete athlete1("sakib","cricket");
    Athlete athlete2("tamim","cricket");


    athlete1.recordScore(85);
    athlete1.recordScore(90);
    athlete1.recordScore(78);

    athlete2.recordScore(88);
    athlete2.recordScore(95);
    athlete1.displayInfo();
    athlete2.displayInfo();

    cout << "Highest score across all athletes: " << Athlete::getHighestScore() << "\n";

    return 0;
}

