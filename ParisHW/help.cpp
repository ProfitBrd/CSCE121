    string fileName;
    string yeet;
    string nextLine = "";
    
    string name;
    string country;
    int number;
    double time;
    try{
    cout << "Enter File Name: " << endl;
    cin >> fileName;
    fileName = "bad_missing01.txt";
    ifstream infs(fileName);
    if (infs.is_open()){
        //infs >> time >> country >> number >> name;
        
	    getline(infs, nextLine);
	    if (nextLine.length() == 1){ //if nextline is empty
		    throw std::domain_error("File missing data");
	    }
    }
    cout << "HELP ME "  << nextLine << "HEllo1" << endl;
    
    }
    catch (...){
        cout << "Invalid_file" << endl; 
    }