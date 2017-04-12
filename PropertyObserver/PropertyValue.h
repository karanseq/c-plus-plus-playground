//
//  PropertyValue.h
//  
//
//  Created by Karan Sequeira on 02/10/15.
//  Copyright (c) 2015 __MyCompanyName__. All rights reserved.
//

#ifndef _PropertyValue_h
#define _PropertyValue_h

#include <vector>

class PropertyValue;        // forward declaration

class PropertyValueListener
{
public:
    virtual ~PropertyValueListener();
    virtual void OnPropertyValueChange(const PropertyValue*) = 0;
};

class PropertyValue
{
public:
    PropertyValue();
    PropertyValue(int value) : value_(value) { listeners_.clear(); }
    virtual ~PropertyValue();
    
protected:
    int value_;
    std::vector<PropertyValueListener*> listeners_;
};

#endif
