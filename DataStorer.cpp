//
//  DataStorer.cpp
//  DataStore
//
//  Created by Anusha Bangi on 3/2/20.
//  Copyright © 2020 ProjectOS. All rights reserved.
//

#include "DataStorer.hpp"
#include <iostream>

using namespace std;

class DataStore
{
private:
    vector<string> filePath;
    vector<string> iNodes;
    vector<float> computationTime;
    
public:
    
    DataStore(vector<string> fPath, vector<string> nodes, vector<float> compTime)
    {
        filePath = fPath;
        iNodes = nodes;
        computationTime = compTime;
    }
    
    void showAllData()
    {
        cout<<"\n****** File Access ******";
        for (auto x: filePath)
            cout<<"\n"<<x;
        
        cout<<"\n****** iNodes ******";
        for (auto x: iNodes)
            cout<<"\n"<<x;
        
        cout<<"\n****** Computation Time ******";
        for (auto x: computationTime)
            cout<<"\n"<<x;
    }
};
