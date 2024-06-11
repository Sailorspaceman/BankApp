#include <vector>
#include "bank_app.hpp"

// get all needed inputs from user, store in class variables
void bankApp::getInput(){
    bankApp::year_input = 5; // pretend you read this from user
}

// Here is where the actual interest calculation would occur
float bankApp::calculateInterest(int year, float interest){
    return 0.1;
}

std::vector<float> bankApp::aggResult(){
    float temp_val = 0;
    for (int i = 0; i < bankApp::year_input; i ++ ){
        // calculate interest for a single year
        temp_val = calculateInterest(i, bankApp::interest_input);
        
    
        // do somethng with temp val
    }
}

int main(){
    bankApp myApp;
    std::vector<float> results = {};
    myApp.getInput();
    results = myApp.aggResult();
    //printResults(results); // TODO: add method for printing all results in table format
    return 0;
}