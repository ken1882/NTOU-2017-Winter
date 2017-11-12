#include <cstdio>
/*
struct Pound{
    // * Constants
    static constexpr double rate_kg = 0.45359237;
    // * Instances
    static double value;
    // * Object initialization
    Pound(double n = 0){
        value = n;
    }
    // *value in kilogram
    static double to_kg(double n = value){
        return n * rate_kg;
    }
};
*/
const double rate_kg = 0.45359237;

int main(int argc, char* argv[]){
    double input;
    while(~scanf("%lf", &input)){
        //printf("%.2f\n", Pound::to_kg(input));
        printf("%.2f\n", input * rate_kg);
    }
    return 0;
}
