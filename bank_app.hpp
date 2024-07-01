// jonathon johnson
// 6/12/24
//bank app


#ifndef BANK_APP_HPP
#define BANK_APP_HPP


#include <vector>

class bankApp{
    public:
        bankApp(double q_intdeposit, double q_monthlydeposit, double q_yearlyinterest, int q_year);
        // get all inputs from user store in class attributes
        std::tuple<double, double, double, int> getInput();
        void getInput();

        // take a year and interest rate and return the result for 1 year
        float calculateInterest();

        // this one takes all years, runs a loop, and calls calculateInterest
        // on each year
        std::vector<float> aggResult();
    private:
       double w_intdeposit;
       double w_intstart;
       double w_monthlydeposit;
       double w_yearlyinterest;
       int w_year;

};

#endif