//
//  main.cpp
//  DataStore
//
//  Created by Anusha Bangi on 3/2/20.
//  Copyright © 2020 ProjectOS. All rights reserved.
//

#include <iostream>
#include <vector>
#include "DataStorer.cpp"
int main(int argc, const char * argv[]) {
    
    // Initialization
    vector<string> fileAccess;
    vector<string> iNodes;
    vector<float> computationTime;
    
    //Test fileAccess
    fileAccess.push_back("/home/group1");
    fileAccess.push_back("/home/anusha");
    
    //Test iNodes
    iNodes.push_back("Test Node1");
    iNodes.push_back("Test Node2");

    //Test computationTime
    computationTime.push_back(19.0);
    computationTime.push_back(20.0);
    
    DataStore d(fileAccess, iNodes, computationTime);
    
    //showData
    d.showAllData();
    
    return 0;
}
