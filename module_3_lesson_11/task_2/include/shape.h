#pragma once

class Shape
{ 
protected:
    struct BoundingBoxDimensions
    {
	    double width;
	    double height;
    };

public:
    virtual double calculateSquare() = 0;
    
    virtual BoundingBoxDimensions calculateDimensions() = 0;
    
    virtual std::string defineType() = 0;
};