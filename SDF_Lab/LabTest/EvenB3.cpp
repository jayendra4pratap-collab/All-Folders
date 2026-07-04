#include <iostream>
#include <cstring>
using namespace std;

class MoviesCollection
{

    struct movies
    {
        char *title;
        int year;
        float rating;
    };
    movies *movy;

    int capacity;
    int count;

public:
    
    MoviesCollection(int cap)
    {
        capacity=cap;
        movy = new movies[capacity];
        count = 0;
        cout << "MovieCollection created with capacity " << capacity << endl;
    }
    ~MoviesCollection()
    {
        for (int i = 0; i < count; i++) {
            delete[] movy[i].title;
        }
        delete[] movy;
        cout << "MovieCollection destroyed, memory freed\n";
    }
    
    bool addMovie(const char *title, int year, float rating)
    {
        if (capacity >= count)
        {
            movy[count].title = new char [strlen(title)+1];
            strcpy(movy[count].title, title);
            
            movy[count].year = year;
            movy[count].rating = rating;
            cout << "Movie added successfully" << endl;
            count++;
            return true;
        }
        
            cout << "Space not available" << endl;
        return false;
    }

    void showAll() const
    {
        if (count == 0) {
            cout << "No movies in the collection\n";
            return;
        }
         cout << "\n--- Movie List ---\n";
        for (int i = 0; i < count; i++) {
        cout << "Title : " << movy[i].title << endl;
        cout << "Year: " << movy[i].year<< endl;
        cout << "Rating : " << movy[i].rating << endl;
        }
    }

    void showBest() const{

         if (count == 0) {
            cout << "No movies available\n";
            return;
        }

        int index,max=0;
        for(int i=0;i<count;i++)
        {
            if(movy[i].rating > max)
            {
                max=movy[i].rating;
                index=i;
            }
             cout << "Highest Rating Movie is : " << movy[index].title << endl;
        }
    }
};

int main()
{
    cout<<"Enter max number of the movies ";
    int n;
    cin>>n;
    cin.ignore();
    MoviesCollection *collection = new MoviesCollection(n);
    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add a movie\n";
        cout << "2. Show all movies\n";
        cout << "3. Show best rated movie\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            char title[100];
            int year;
            float rating;

            cout << "Enter movie title: ";
            cin.getline(title, 100);
            cout << "Enter release year: ";
            cin >> year;
            cout << "Enter rating (0.0 - 10.0): ";
            cin >> rating;
            cin.ignore();

            collection->addMovie(title, year, rating);
            break;
        }

        case 2:
            collection->showAll();
            break;

        case 3:
            collection->showBest();
            break;

        case 4:
            delete collection;   // delete dynamic object
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);


    return 0;
}