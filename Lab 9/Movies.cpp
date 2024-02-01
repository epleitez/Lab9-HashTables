//
// Created by Emely Pleitez on 12/6/22.
//

#include "Movies.h"
#include <iostream>
#include <sstream>

using namespace std;

//default constructor
Movies::Movies() {

    runningTime = -1;
    rating = "";
    releaseDate = "";
    studio = "";
    movieTitle = "";
    grossEarnings = 0;

}

//overloaded constructor
Movies::Movies(int runningTime, string rating, string releaseDate,
              string studio, string movieTitle, int grossEarnings){

    this->runningTime = runningTime;
    this->rating = rating;
    this->releaseDate = releaseDate;
    this->studio = studio;
    this->movieTitle = movieTitle;
    this->grossEarnings = grossEarnings;

}
//Setters-----------------------------------------------------------
/* Sets the running time of the Movie to runningTime
 * @param runningTime: the new running time of this movie
 */
void Movies::setRunningTime(int runningTime) {
    this->runningTime = runningTime;
}//end setRunningTime()

void Movies::setRating(string rating){
    this->rating = rating;
}//end setRating

void Movies::setReleaseDate(string releaseDate){
    this->releaseDate = releaseDate;
}//end releaseDate

void Movies::setStudio(string studio){
    this->studio = studio;
}//end setStudio

void Movies::setMovieTitle(string movieTitle) {
    this->movieTitle = movieTitle;
}//end setMovieTitle

void Movies::setGrossEarnings(int grossEarnings) {
    this->grossEarnings = grossEarnings;
}//end setGrossEarnings

//Getters-----------------------------------------------------------
/* Returns the running time of this Movie
 * @return the running time of this Movie
 */

int Movies::getRunningTime() {
    return runningTime;
}//end getRunningTime()

string Movies::getRating() {
    return rating;
}//end getRating()

string Movies::getReleaseDate() {
    return releaseDate;
}//end getReleaseDate()

string Movies::getStudio() {
    return studio;
}//end getStudio()

string Movies::getMovieTitle() {
    return movieTitle;
}//end getMovieTitle

int Movies::getGrossEarnings() {
    return grossEarnings;
}//end grossEarnings

//toString()-----------------------------------------------------------

const string Movies::toString() const {
    ostringstream s;

    s << "Movie Title: " << movieTitle << "\n"
      << "Running Time: " << runningTime << "\n"
      << "Rating: " << rating << "\n"
      << "Release Date: " << releaseDate << "\n"
      << "Studio: " << studio << "\n"
      << "Gross Earnings: $" << grossEarnings << "\n"
      << "------------------------------------" << endl;
    return s.str();
}