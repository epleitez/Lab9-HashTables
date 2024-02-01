#include <iostream>
#include "Movies.cpp"
#include <fstream>
#include <vector>

using namespace std;

void buildFromFile(Movies listOfMovies[450], Movies listOfMoviesTwo[450],Movies listOfMoviesThree[450] );

//Hash Function Implementations
void modHashFunctionImplementation(Movies listOfMovies[450]);
void squaredHashImplementation(Movies listOfMoviesTwo[450]);
void stringHashImplementation(Movies listOfMoviesThree[450]);

void doubleHash(Movies listOfMoviesThree[450]);

void displayArray(Movies []);

//Hash Functions
int modHashFunction(int key);
int squaredHash(int key);
int stringHash(string str);


int main() {

    Movies listOfMovies[450];
    Movies listOfMoviesTwo[450];
    Movies listOfMoviesThree[450];

    buildFromFile(listOfMovies, listOfMoviesTwo, listOfMoviesThree);

    //displays all the movie objects (listOfMovies, listOfMoviesTwo, listOfMoviesThree are the same)
    //displayArray(listOfMovies);

    cout << "\nHash 1: " << endl;
    modHashFunctionImplementation(listOfMovies);

    cout << "\nHash 2: " << endl;
    squaredHashImplementation(listOfMoviesTwo);

    cout << "\nHash 3: " << endl;
    stringHashImplementation(listOfMoviesThree);

    cout << "\nDouble Hash: " << endl;
    doubleHash(listOfMoviesThree);


    return 0;
}





//--------------"bad" Hash Function----------------------
/* mod the running time by 100 to place the movie object in an index
 * @param int key is the running time mod by 100.
 */
int modHashFunction(int key){
    return key % 100;
}

//--------------"better" Hash Function--------------------
/* squared the running time and then mod by 447 to place the movie object in an index
 * 447 is the total number of movie objects.
 * @param int key is the running time squared then mod by 447
 */
int squaredHash(int key){
    key = key * key;
    key = key % 447;
    return key;
}

//--------------"best" Hash Function----------------------
/* Take the numerical value of each character in movie title, sum, and mod by 447
 * 447 is the total number of movie objects.
 * @param string str is the movie title of a movie object
 */
int stringHash(string str){
    int sum = 0;

    for(int i = 0; i < str.length(); i++){
       sum = sum + int(str[i]);
    }

    return sum % 447;

}



/* Movie objects built with data from the file "top10Movies75-19.txt"
 * uses the Movies constructor to build each Movie object from each line of data.
 * Movies listOfMovies[450] is the Array in which the movie objects are placed into.
 */
void buildFromFile(Movies listOfMovies[450], Movies listOfMoviesTwo[450],Movies listOfMoviesThree[450] ){
    //opening file
    ifstream infile ("top10Movies75-19.txt");

    //checking if file is open
    if(!infile.is_open()){
        cout << "file not open for input...program terminating" << endl;
        exit(0);
    }

    //Movie object variables
    string tempRunningTime = "";
    int runningTime = 0;
    string rating = "";
    string releaseDate = "";
    string studio = "";
    string movieTitle = "";
    string tempGrossEarnings = "";
    int grossEarnings = 0;

    //other variables
    string line = "";
    int vectorSize = 0;


    //getting the data from file
    getline(infile, line);
    while(getline(infile, line)){
        stringstream s (line);
        getline(s, tempRunningTime, ',');
        getline(s, rating, ',');
        getline(s, releaseDate, ',');
        getline(s, studio, ',');
        getline(s, movieTitle, ',');
        getline(s, tempGrossEarnings, ',');
        runningTime = stoi(tempRunningTime);
        grossEarnings = stoi(tempGrossEarnings);

        Movies m(runningTime, rating, releaseDate,
                 studio, movieTitle, grossEarnings);

        listOfMovies[vectorSize] = m;
        listOfMoviesTwo[vectorSize] = m;
        listOfMoviesThree[vectorSize] = m;

        vectorSize++;
        //cout << m.toString();
    }


    //cout << "vector size: " << vectorSize;

}

/* @param Movies listOfMovies[450] is the Array of the movie objects.
 * Takes the running time of each movie in listOfMovies[450] and it is used to get the index using modHashFunction.
 * Movie objects are then placed into new array of movie objects but with the different/new index
 */
void modHashFunctionImplementation(Movies listOfMovies[450]){

    //447 is the number of movie objects (found using vectorSize++)
    Movies newListOfMovies[450];

    int index = 0;
    int collisions = 0;
    int count = 0;

    for(int i = 0; i < 447; i++){

        index = modHashFunction(listOfMovies[i].getRunningTime());

        if(newListOfMovies[index].getRunningTime() == -1){
            newListOfMovies[index] = listOfMovies[i];
            //cout << "Index: " << index << endl;
            //cout << "Movie Title: " << newListOfMovies[index].getMovieTitle() << endl;
            //cout << "---------------------" << endl;
        }
        else{
            bool found = false;
            while(!found){
                if(index == 447){
                    index = 0;
                }
                index++;
                collisions++;
                if(newListOfMovies[index].getRunningTime() == -1){
                    found = true;
                }
            }
            newListOfMovies[index] = listOfMovies[i];
            //cout << "Index: " << index << endl;
            //cout << "Movie Title: " << newListOfMovies[index].getMovieTitle() << endl;
            //cout << "---------------------" << endl;
        }



        count++;
    }

    cout << "Number of Collisions: " << collisions << endl;

}// end modHashFunctionImplementation()


/* @param Movies listOfMoviesTwo[450] is the Array of the movie objects.
 * Takes the running time of each movie in listOfMoviesTwo[450] and it is used to get the index using squaredHash.
 * Movie objects are then placed into new array of movie objects but with the different/new index
 */
void squaredHashImplementation(Movies listOfMoviesTwo[450]){
    //447 is the number of movie objects (found using vectorSize++)
    Movies newListOfMovies[450];

    int index = 0;
    int collisions = 0;

    for(int i = 0; i < 447; i++){

        index = squaredHash(listOfMoviesTwo[i].getRunningTime());

        if(newListOfMovies[index].getRunningTime() == -1){
            newListOfMovies[index] = listOfMoviesTwo[i];
            //cout << "Index: " << index << endl;
            //cout << "Movie Title: " << newListOfMovies[index].getMovieTitle() << endl;
            //cout << "---------------------" << endl;
        }
        else{
            bool found = false;
            while(!found){
                if(index == 447){
                    index = 0;
                }
                index++;
                collisions++;
                if(newListOfMovies[index].getRunningTime() == -1){
                    found = true;
                    //cout << "Index: " << index << endl;
                    //cout << "Movie Title: " << newListOfMovies[index].getMovieTitle() << endl;
                    //cout << "---------------------" << endl;
                }
            }
            newListOfMovies[index] = listOfMoviesTwo[i];
        }

    }

    cout << "Number of Collisions: " << collisions << endl;

}// end squaredHashImplementation()

/* @param Movies listOfMoviesThree[450] is the Array of the movie objects.
 * Takes the movie title of each movie in listOfMoviesThree[450] and it is used to get the index using stringHash.
 * Movie objects are then placed into new array of movie objects but with the different/new index
 */
void stringHashImplementation(Movies listOfMoviesThree[450]){
    //447 is the number of movie objects (found using vectorSize++)
    Movies newListOfMovies[450];

    int index = 0;
    int collisions = 0;

    for(int i = 0; i < 447; i++){

        index = stringHash(listOfMoviesThree[i].getMovieTitle());

        if(newListOfMovies[index].getRunningTime() == -1){
            newListOfMovies[index] = listOfMoviesThree[i];
            //cout << "Index: " << index << endl;
            //cout << "Movie Title: " << newListOfMovies[index].getMovieTitle() << endl;
            //cout << "---------------------" << endl;
        }
        else{
            bool found = false;
            while(!found){
                if(index == 447){
                    index = 0;
                }
                index++;
                collisions++;
                if(newListOfMovies[index].getRunningTime() == -1){
                    found = true;
                    //cout << "Index: " << index << endl;
                    //cout << "Movie Title: " << newListOfMovies[index].getMovieTitle() << endl;
                    //cout << "---------------------" << endl;
                }
            }
            newListOfMovies[index] = listOfMoviesThree[i];
        }

    }

    cout << "Number of Collisions: " << collisions << endl;
}//end stringHashImplementation()


/* @param Movies listOfMoviesThree[450] is the Array of the movie objects.
 * Takes the running time of each movie in listOfMoviesThree[450] and it is used to get the index using modHashFunction.
 * If the index has already been taken by another movie option then...
 * Takes the movie title of each movie in listOfMoviesThree[450] and it is used to get the index using stringHash.
 * Movie objects are then placed into new array of movie objects but with the different/new index
 */
void doubleHash(Movies listOfMoviesThree[450]){
    //447 is the number of movie objects (found using vectorSize++)
    Movies newListOfMovies[450];

    int index = 0;
    int collisions = 0;


    for(int i = 0; i < 447; i++){

        index = modHashFunction(listOfMoviesThree[i].getRunningTime());

        if(newListOfMovies[index].getRunningTime() == -1){
            newListOfMovies[index] = listOfMoviesThree[i];
        }
        else{
            index = stringHash(listOfMoviesThree[i].getMovieTitle());
            bool found = false;
            while(!found){
                if(index == 447){
                    index = 0;
                }
                index++;
                collisions++;
                if(newListOfMovies[index].getRunningTime() == -1){
                    found = true;
                }
            }
            newListOfMovies[index] = listOfMoviesThree[i];
        }

    }

    cout << "Number of Collisions: " << collisions << endl;



}//end doubleHash()

void displayArray(Movies listOfMovies[450]){

    for (int i = 0; i < 447; i++){
        cout << listOfMovies[i].toString() << endl;
    }

}








