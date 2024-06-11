#include <vector>

class bankApp{
    public:
        // get all inputs from user store in class attributes
        void getInput();

        // take a year and interest rate and return the result for 1 year
        float calculateInterest(int year, float interest);

        // this one takes all years, runs a loop, and calls calculateInterest
        // on each year
        std::vector<float> aggResult();
    private:
        int year_input = 0;
        float interest_input = 0.0;
};