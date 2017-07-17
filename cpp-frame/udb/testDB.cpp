#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <chrono>
#include <unistd.h>

#include "uTransactionDatabase.h"
#include "uAlgoFramework.h"
#include "uTidset.h"

using namespace std;

string getFilepath(char filename[]) {

	char path[1000];
	memset(path, '\0', 1000);

	getcwd(path, 1000);
	realpath(filename, path); 

	return string(path);

}

int main(int argc, char const *argv[]) {

	 string filepath = getFilepath("../../datasets/uncertainSample.txt");

	// chrono::system_clock::time_point tp1 = chrono::system_clock::now();
	
	 uTransactionDatabase * database = new uTransactionDatabase();
	 database->loadFile(filepath);

	 database->printVerticalDatabase();
	 delete database;
	// chrono::system_clock::time_point tp2 = chrono::system_clock::now();
	
	// if(argc != 2) {
	// 	cout << "Too few or too many arguments. Aborting ...\n";
	// }
	// else {
	// 	uAlgoFramework * algo = new uAlgoFramework(atoi(argv[1]));		
	// 	algo->runAlgo("out.put", database, 0.1);
	
	// 	delete algo;
	// }

	// chrono::system_clock::time_point tp3 = chrono::system_clock::now();

	// chrono::duration<double> diff1 = tp2 - tp1;
	// chrono::duration<double> diff2 = tp3 - tp2;

	// cout << " Time taken to the database: " << diff1.count() << " s\n";
	// cout << " Time taken to run the algorithm: " << diff2.count() << " s\n\n" << endl;

//	uTidset * set = new uTidset();
//	set->insert(1, 0.01);
//	set->insert(1,0.02);
//	set->insert(2,0.02);
//	set->insert(3,0.02);
//	set->insert(4,0.02);
//	set->print();

}
