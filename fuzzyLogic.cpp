#include <iostream>
#include <cmath>

using namespace std;

void startup();
void endLine( float output_number);
float getRequest();
float getNumber( string valueName );
float fuzzyLogic( float request, float number_01, float number_02, float number_03 );

int main()
{
    
    float module_01, module_02, module_03;
    float input_number, output_number;

    startup();

    module_01 = getNumber("1");
    module_02 = getNumber("2");
    module_03 = getNumber("3");

    input_number = getRequest();

    output_number = fuzzyLogic(
        input_number, 
        module_01, 
        module_02, 
        module_03
    );

    endLine(output_number);
    
    return 0;
}

// just startup text
void startup() { 
    system("clear");
    cout << "================================================================" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "     This \"Fuzzy Logic\" It's consisting of three number       " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "================================================================" << endl;
    cout << endl;
}

// A function for get logic numbers
float getNumber( string valueName ) {
    float input;
    cout << "Please insert Number \"" << valueName << "\" of logic : ";
    cin >> input; return input;
}

float getRequest() {
    float input;
    cout << endl << "Please enter the number you want to calculate : ";
    cin >> input; return input;
}

// Fuzzy Logic function
float fuzzyLogic(
    float request,
    float number_01,
    float number_02,
    float number_03
) {
    if ( request <= number_01 ) return 0;
    if ( request >= number_03 ) return 1;
    if ( number_01 <= request <= number_02 ) {
        return 2 * pow((request - number_01 / number_03 - request), 2);
    }
    if ( number_02 <= request <= number_03 ) {
        return 1 - 2 * pow((request - number_01 / number_03 - request), 2);
    }
    return 0;
}

// Endline text
void endLine( float output_number) { 
    cout << endl;
    cout << "================================================================" << endl << endl;
    cout << "                   Final Result : " << output_number              << endl << endl;
    cout << "================================================================" << endl << endl;
}
