//
//  Rational.h
//  rec10
//
//  Created by Adam Bouzourene on 4/10/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#ifndef __rec10__Rational__
#define __rec10__Rational__

#include <iostream>
#include <string>
#include <vector>

namespace ratio
{
    class RatioNum
    {
    private:
        int num;
        int denom;
    public:
        RatioNum();
        RatioNum(int num) : num(num), denom(1) {}
        RatioNum(int num, int denom) : num(num), denom(denom) {}
        
        void normalise();
        
        int getNum();
        
        int getDenom();
        
        void setNum(int nnum);
        
        void setDenom(int ndenom);
        
        RatioNum& operator +=(RatioNum& rat2);
        
        bool operator ==(RatioNum& rat2);
        
        RatioNum& operator =(int x);
        
        RatioNum& operator ++();
        RatioNum& operator ++(int x);
        
    };
    RatioNum& operator --(RatioNum& rat);
    RatioNum& operator --(RatioNum& rat, int x);
    bool operator ==(RatioNum& rat, int x);
    bool operator !=(RatioNum& rat1, RatioNum& rat2);
    std::ostream& operator << (std::ostream& os, const RatioNum& rat);
    std::istream& operator >> (std::istream& is, RatioNum& rat);
    RatioNum& operator +(RatioNum& rat1, RatioNum& rat2);
}

#endif /* defined(__rec10__Rational__) */
