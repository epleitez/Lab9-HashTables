//
// Created by Emely Pleitez on 12/6/22.
//

#ifndef LAB_9_MOVIES_H
#define LAB_9_MOVIES_H

using namespace std;

class Movies {
private:

    //attributes
    int runningTime;
    string rating;
    string releaseDate;
    string studio;
    string movieTitle;
    int grossEarnings;


public:

    //constructors
    Movies();
    Movies(int runningTime, string rating, string releaseDate,
          string studio, string movieTitle, int grossEarnings);

    //setters
    void setRunningTime(int);
    void setRating(string);
    void setReleaseDate(string);
    void setStudio(string);
    void setMovieTitle(string);
    void setGrossEarnings(int);

    //getters
    int getRunningTime();
    string getRating();
    string getReleaseDate();
    string getStudio();
    string getMovieTitle();
    int getGrossEarnings();

    const string toString() const;

};


#endif //LAB_9_MOVIES_H
