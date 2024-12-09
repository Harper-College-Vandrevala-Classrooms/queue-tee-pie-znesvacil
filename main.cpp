//
//  main.cpp
//  Queue-tee pie
//
//  Created by Zachary Nesvacil on 12/8/24.
//

#include <iostream>

using namespace std;

class Cutie {
private:
    string description;
    int cuteness_rating;
public:
    Cutie() : description(""), cuteness_rating(0) {}
    
    Cutie(string d, int r)
    {
        description = d;
        cuteness_rating = r;
    }
    
    string getDescription()
    {
        return description;
    }
    
    int getRating()
    {
        return cuteness_rating;
    }
};

class QueueTees {
private:
    static const int MaxSize = 10; //Small size for purposes of testing
    Cutie CutieArray[MaxSize];
    Cutie *CutiePointer = CutieArray;
    int CutieSize = 0;
    
public:
    QueueTees() : CutieSize(0) {}
    
    void size()
    {
        cout << CutieSize << endl;
    }
    
    void enqueue(Cutie cutie)
    {
        if (CutieSize < MaxSize) {
            *CutiePointer = cutie; // Sets the pointed value of the array to the pushed Dish object
            CutiePointer++; // Moves the pointer one to the right
            CutieSize++;
        }
        else {
            cout << "You cannot add any more cuties!" << endl;
        }
    }
    
    void dequeue()
    {
        if (CutieSize > 0) {
            Cutie firstCutie = CutieArray[0];
            for (int i = 1; i < CutieSize; i++) {
                Cutie currentCutie = CutieArray[i];
                CutieArray[i-1] = currentCutie;
            }
            CutiePointer--; // Moves the pointer one to the left
            CutieSize--;
            cout << "Description: " << firstCutie.getDescription() << endl;
            cout << "Cuteness Rating: " << firstCutie.getRating() << endl;
        }
        else {
            cout << "There are no cuties in the queue." << endl;
        }
    }
    
};

int main() {
    Cutie puppy = Cutie("A little puppy with big, sad eyes", 11);
    Cutie kitty = Cutie("A silly little kitty who likes to walk on your keyboard", 9);
    Cutie parrot = Cutie("A loud bird who can be a bit rude but a lot funny", 6);
    
    // Create a queue data structure
    QueueTees queue;

    // The size of the queue should equal zero since there are no objects in it
    queue.size();

    // Should give an error
    queue.dequeue();
    
    // Add the cuties to the queue
    queue.enqueue(puppy);
    queue.enqueue(kitty);
    queue.enqueue(parrot);

    // The size of the queue should equal three since there are three objects in it
    queue.size();

    // The first dequeue should return the puppy
    queue.dequeue();

    // The second dequeue should return the kitty
    queue.dequeue();

    // The first dequeue should return the parrot
    queue.dequeue();
    
    queue.enqueue(puppy);
    queue.enqueue(puppy);
    queue.enqueue(puppy);
    queue.enqueue(puppy);
    queue.enqueue(puppy);
    queue.enqueue(puppy);
    queue.enqueue(puppy);
    queue.enqueue(puppy);
    queue.enqueue(puppy);
    queue.enqueue(puppy); // This should be the last one added
    queue.enqueue(puppy); // This should give an error
    queue.size(); // This should be 10, not 11
    
    
    return 0;
}
