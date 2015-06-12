//
//  Rational.cpp
//  rec10
//
//  Created by Adam Bouzourene on 4/10/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include "Rational.h"

namespace ratio
{
    void RatioNum::normalise()
    {
        for (int i = denom * num; i > 1; i--)
        {
            if ((denom % i == 0) && (num % i == 0))
            {
                denom /= i;
                num /= i;
            }
        }
    }
    
    int RatioNum::getNum()
    {
        return num;
    }
    
    int RatioNum::getDenom()
    {
        return denom;
    }
    
    void RatioNum::setNum(int nnum)
    {
        num = nnum;
    }
    
    void RatioNum::setDenom(int ndenom)
    {
        denom = ndenom;
    }
    
    std::ostream& operator << (std::ostream& os, RatioNum& rat)
    {
        std::cout << rat.getNum() << "/" << rat.getDenom() << std::endl;
        return os;
    }
    
    std::istream& operator >> (std::istream& is, RatioNum& rat)
    {
        int n;
        int d;
        char c;
        std::cin >> n;
        std::cin >> c;
        std::cin >> d;
        rat.setNum(n);
        rat.setDenom(d);
        return is;
    }
    
    RatioNum& RatioNum::operator +=(RatioNum& rat2)
    {
        this->setNum((this->getNum() * rat2.getDenom()) + (rat2.getNum() * this->getDenom()));
        this->setDenom(this->getDenom() * rat2.getDenom());
        this->normalise();
        return *this;
    }
    
    RatioNum& operator +(RatioNum& rat1, RatioNum& rat2)
    {
        RatioNum sum(0,0);
        sum.setNum((sum.getNum() * rat2.getDenom()) + (rat2.getNum() * sum.getDenom()));
        sum.setDenom(sum.getDenom() * rat2.getDenom());
        sum.normalise();
        return sum;
    }
    
    RatioNum& RatioNum::operator =(int x)
    {
        this->setNum(x);
        this->setDenom(1);
        return *this;
    }
    
    RatioNum& RatioNum::operator ++()
    {
        this->setNum(this->getNum() + this->getDenom());
        return *this;
    }
    
    RatioNum& RatioNum::operator ++(int x)
    {
        this->setNum(this->getNum() + this->getDenom());
        return *this;
    }
    
    bool RatioNum::operator ==(RatioNum& rat2)
    {
        this->normalise();
        rat2.normalise();
        
        if (this->getNum() == rat2.getNum() && this->getDenom() == rat2.getDenom())
        {
            return true;
        }
        
        return false;
    }
    
    bool operator !=(RatioNum& rat1, RatioNum& rat2)
    {
        rat1.normalise();
        rat2.normalise();
        
        if (rat1.getNum() != rat2.getNum() || rat1.getDenom() != rat2.getDenom())
        {
            return true;
        }
        
        return false;
    }
    
    RatioNum& operator --(RatioNum& rat)
    {
        rat.setNum(rat.getNum() - rat.getDenom());
        return rat;
    }
    
    RatioNum& operator --(RatioNum& rat, int x)
    {
        rat.setNum(rat.getNum() + rat.getDenom());
        return rat;
    }
    
    bool operator ==(RatioNum& rat, int x)
    {
        if (rat.getDenom() == 1 && rat.getNum() == x)
        {
            return true;
        }
        return false;
    }
    
}