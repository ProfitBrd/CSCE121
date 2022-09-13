// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want
    double exam_uw = 0;
    double final_exam_uw = 0;
    double hw_uw = 0;
    double lw_uw = 0;
    double engagement_uw = 0;

    int exam_count = 0;
    int hw_count = 0;
    int lw_count = 0;
    int engagement_count = 0;

    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            // TODO(student:)
            exam_uw += score;
            exam_count += 1;
        } else if (category == "final-exam") {
            // TODO(student): process final score
            exam_uw += score;
            final_exam_uw = score;
            exam_count += 1;
        } else if (category == "hw") {
            // TODO(student): process hw score
            hw_uw += score;
            hw_count += 1;
        } else if (category == "lw") {
            // TODO(student): process lw score
            if (score > 1){
                lw_uw += 1;
            }
            else{
                lw_uw += score;
            }
            lw_count += 1;
        } else if (category == "engagement") {
            // TODO(student): process engagement score
            engagement_uw += score;
            engagement_count += 1;
        } else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): compute component averages
    double exam_average = 0;
    double hw_average = 0;
    double lw_average = 0;
    double engagement = 0;
    double temp = 0;
    //cout << exam_uw << endl;
    //cout << exam_count << endl;

    
    temp = exam_uw/3;

    //cout << temp << endl;
    //cout << final_exam_uw;
    //cout << hw_average << endl;
    //cout << lw_average << endl;

    if ((temp) < final_exam_uw){
        exam_average = final_exam_uw;
    }
    else{
        exam_average = exam_uw/3; //out of total exams I guess
    }

    if (hw_count != 0){   //FIXME
        hw_average = hw_uw / hw_count; //hw average
    }
    
    if (lw_count != 0){       //FIXME
        lw_average = (lw_uw / lw_count) * 100; //lw average, making out of 100
    }
    
    
    if (engagement_uw > 100){
        engagement = 100;
    }
    else{
        engagement = (engagement_uw); 
    }
    



    // TODO(student): compute weighted total of components
    double weighted_total = 0;
    weighted_total = exam_average*0.4 + hw_average*0.4 + lw_average*0.1 + engagement*0.1;

    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';
    if (weighted_total > 89.49){
        final_letter_grade = 'A';
    }
    else if (weighted_total > 79.49){
        final_letter_grade = 'B';
    }
    else if (weighted_total > 69.49){
        final_letter_grade = 'C';
    }
    else if (weighted_total > 59.49){
        final_letter_grade = 'D';
    }
    else {
        final_letter_grade = 'F';
    }

    print_results(
        exam_average, hw_average, lw_average, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
