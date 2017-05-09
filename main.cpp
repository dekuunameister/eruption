//
//  main.cpp
//  Eruption
//
//  Created by Fangbo Yuan on 5/9/17.
//  Copyright © 2017 Fangbo Yuan. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "cards.h"

using namespace std;

int main(int argc, const char * argv[]) {
    std::ios_base::sync_with_stdio(false);
    ostringstream oss;
    ostream &out = oss;
    
    Card card = Card(1, 2);
    out << "members of card" << card.affected << endl;
    
    cout << oss.str();
    return 0;
}
