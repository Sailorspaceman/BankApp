// jonathon johnson
// 6/12/24
//bank app

#include <vector>
#include <iostream>
#include <numeric>
#include <sstream>

#include "bank_app.hpp"

// get all needed inputs from user, store in class variables
bankApp::bankApp(double q_intdeposit, double q_monthlydeposit, double q_yearlyinterest, int q_year){
    this->w_intdeposit = q_intdeposit;
    this->w_intstart = q_intdeposit;
    this->w_monthlydeposit = q_monthlydeposit;
    this->w_yearlyinterest = q_yearlyinterest;
    this->w_year = q_year;
}
// get all needed inputs from user
// return values to bankApp function
std::tuple<double, double, double, int> bankApp::getInput(){
    //display text in header
    const std::string header_display = ("***************************************\n************* Data Input *************");
    double intdeposit = 0;
	double monthlydeposit = 0;
	double yearlyinterest = 0;
	int years = 0;
    
    std::cout << header_display;

    //loop while getting inputs
    while(true){
        std::cout << "Initial Investment Amount: ";
        std::cin >> intdeposit;
        if (intdeposit >= 0) break;
        std::cout << "Invalid amount. Must be greater than 0. Please enter a valid number.\n";
        }
    while(true){
        std::cout << "Monthly Deposit: ";
        std::cin >> monthlydeposit;
        if (monthlydeposit >= 0) break;
        std::cout << "Invalid amount. Must be greater than 0. Please enter a valid number.\n";
    }
    while(true){
        std::cout << "Annual Interest: ";
        std::cin >> yearlyinterest;
        if (yearlyinterest >= 0) break;
        std::cout << "Invalid amount. Must be greater than 0. Please enter a valid number.\n";
    }
    while(true){
        std::cout << "Number of Years: ";
        std::cin >> years;
        if (years >= 0) break;
        std::cout << "Invalid amount. Must be greater than 0. Please enter a valid number.\n";
    }

        return {intdeposit, monthlydeposit, yearlyinterest, years};
    }

// Here is where the actual interest calculation would occur
float bankApp::calculateInterest(){
    double yearendinterest = 0.0;
    double yearendbalance = 0.0;
    double this->w_intdeposit = deposit;
    double monthlydeposit = 0.0;
    double temp_val = 0.0;
    double monthlyinterest;
    //balance and interest without monthly deposits and loop to display results
    std::cout << "                Balance and interest without montly deposits                  \n";
    std::cout << "******************************************************************************\n";
    std::cout << "Year                   Year End Balance                      Year End Interest\n";
    for(int i = 1; i <= this->w_year; ++i ) {
        yearendinterest = (deposit * (this->w_yearlyinterest/100));
        yearendbalance = yearendinterst + deposit;
        deposit = yearendbalance;
        std::cout << i << "                         $" << std::fixed << setprecison(2) << yearendbalance << "                         $" << yearendinterest << std::endl;
    }
    // balance and interest with montly deposits and loop to display results
    std::cout << "                Balance and interest montly deposits                          \n";
    std::cout << "******************************************************************************\n";
    std::cout << "Year                   Year End Balance                      Year End Interest\n";
    deposit = this->w_intstart;
    for(int i = 1; i <= (this->w_year * 12); ++i){
        double yearlyinterest = 0.0;
        for(int j = 1; j <= 12; ++j){
            deposit = this->w_monthlydeposit;
            double monthlyinterest = deposit * ((w_yearlyinterest / 100) / 12);
            deposit += monthlyinterest;
            yearlyinterest += monthlyinterest;
        }
        std::cout << i << "                         $" << std::fixed << std::setpersison(2) << deposit << "                         $" << yearlyinterst << std::endl;

    }
}

//store all values to be called again whne looking for yearly results
std::vector<float> bankApp::aggResult(){
    std:: vector<float> yearlyinterest;
    double totalamount = this->w_intdeposit;

    for(int year = 1; year <= this->w_year; ++year){
        double yearstartamount = totalamount;
        for(int month = 1; month <= 12; ++month){
            totalamount += this->w_monthlydeposit;
            double monthlyinterest = totalamount * ((w_yearlyinterest / 100)/12);
            totalamount += monthlyinterest;
            
        }
        
        double yearlyAccruedInterest = totalAmount - yearStartAmount - (monthlyDeposit * 12);
        yearlyInterest.push_back(yearlyAccruedInterest);
    }
    return yearlyinterest;
    }
}

//main function
int main(){
    double intdeposit, monthlydeposit, yearlyinterest;
    int years;
    // backup instance with initial values
    bankApp myApp(0, 0, 0, 0);

    std::tie(intdeposit, monthlydeposit, yearlyinterest, years) = myApp.getInput();

    //updating back up with user values
    myApp = bankApp(intdeposit, monthlydeposit, yearlyinterest, years);

     // Calculate and print the results
    std::vector<std::tuple<int, double, double>> results = myApp.calculateAndDisplayResults();

    // Print detailed results
    std::cout << "Detailed results for each year:\n";
    for (const auto& result : results) {
        int year;
        double yearEndBalance, yearEndInterest;
        std::tie(year, yearEndBalance, yearEndInterest) = result;
        std::cout << "Year " << year << ": Year End Balance = $" << std::fixed << std::setprecision(2) << yearEndBalance
                  << ", Year End Interest = $" << yearEndInterest << std::endl;
    }

    return 0;
}