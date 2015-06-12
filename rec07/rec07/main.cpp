//
//  main.cpp
//  rec07
//
//  Created by Adam Bouzourene on 3/13/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Instrument
{
public:
    //Instrument() {}
    
    virtual void makeSound() const  = 0;
    virtual void Play() const  = 0;
private:
};
void Instrument::makeSound() const {cout << "instrument";}

class BrassInstrument : public Instrument
{
public:
    BrassInstrument(unsigned size) : size(size) {}
    
    void makeSound() const
    {
        cout << "To make a sound . . . blow on a mouthpiece of size " << size << endl;
    }
    
    virtual void Play()
    {
        
    }
protected:
    unsigned size;
};

class StringInstrument : public Instrument
{
public:
    StringInstrument(unsigned pitch) : pitch(pitch) {}
    
    void makeSound() const
    {
        cout << "To make a sound . . . bow a string with pitch " << pitch << endl;
    }
    
    virtual void Play()
    {
        
    }
protected:
    unsigned pitch;
};

class PercussionInstrument : public Instrument
{
public:
    PercussionInstrument() {}
    
    void makeSound() const
    {
        cout << "To make a sound . . . hit me!" << endl;
    }
    
    virtual void Play()
    {
        
    }
private:
    
};

class Trombone : public BrassInstrument
{
public:
    Trombone(unsigned size) : BrassInstrument(size) {}
    
    void makeSound() const
    {
        BrassInstrument::makeSound();
    }
    
    void Play() const
    {
        cout << "blat";
    }
protected:
    
};

class Trumpet : public BrassInstrument
{
public:
    Trumpet(unsigned size) : BrassInstrument(size) {}
    
    void makeSound() const
    {
        BrassInstrument::makeSound();
    }
    
    void Play() const
    {
        cout << "toot";
    }
protected:
    
};

class Cello : public StringInstrument
{
public:
    Cello(unsigned pitch) : StringInstrument(pitch) {}
    
    void makeSound() const
    {
        StringInstrument::makeSound();
    }
    
    void Play() const
    {
        cout << "squawk";
    }
protected:
    
};

class Violin : public StringInstrument
{
public:
    Violin(unsigned pitch) : StringInstrument(pitch) {}
    
    void makeSound() const
    {
        StringInstrument::makeSound();
    }
    
    void Play() const
    {
        cout << "screech";
    }
private:
    
};

class Drum : public PercussionInstrument
{
public:
    Drum() {};
    
    void makeSound() const
    {
        PercussionInstrument::makeSound();
    }
    
    void Play() const
    {
        cout << "boom";
    }
protected:
    
};

class Cymbal : public PercussionInstrument
{
public:
    Cymbal() {};
    
    void makeSound() const
    {
        PercussionInstrument::makeSound();
    }
    
    void Play() const
    {
        cout << "crash";
    }
protected:
    
};

class MILL
{
public:
    MILL() {}
    
    int receiveInstr(Instrument& inst)
    {
        //inst.makeSound();
        for (size_t x = 0; x <roster.size(); x++)
        {
            if (roster[x] == NULL)
            {
                roster[x] = &inst;
                return 0;
            }
        }
        roster.push_back(&inst);
        return 0;
    }
    
    void dailyTestPlay()
    {
        for (size_t x = 0; x < roster.size(); x++)
        {
            if (roster[x] != NULL)
                roster[x]->makeSound();
        }
    }
    
    Instrument* loanOut()
    {
        Instrument* inst;
        for (size_t x = 0; x <roster.size(); x++)
        {
            if (roster[x] != NULL)
            {
                inst = roster[x];
                roster[x] = NULL;
                return inst;
            }
        }
        return NULL;
    }
    
private:
    vector<Instrument*> roster;
};

class Musician {
public:
    Musician() : instr( NULL ) {}
    void acceptInstr( Instrument & i ) { instr = &i; }
    Instrument* giveBackInstr( ) {
        Instrument* tmp(instr);
        instr = NULL;
        return tmp;
    }
    void testPlay() const
    {
        if( instr )
            instr->makeSound();
        else
            cerr << "have no instr\n";
    }
    void play()
    {
        if( instr )
            instr->Play();
        else
            cerr << "(no noise)";
    }
private:
    Instrument* instr;
};

class Orchestra
{
public:
    Orchestra() : roster(25) {}
    
    int addPlayer(Musician& play)
    {
        bool valid = true;
        for (size_t x = 0; x <roster.size(); x++)
        {
            if (&play == roster[x])
                valid = false;
        }
        if (valid)
        {
            for (size_t x = 0; x <roster.size(); x++)
            {
                if (roster[x] == NULL)
                {
                    roster[x] = &play;
                    return 0;
                }
            }
            cerr << "Full Orchestra!" << endl;
            return 0;
        }
        else
        {
            cerr << "already inside orchestra" << endl;
            return 0;
        }
    }
    
    void play()
    {
        for (size_t x = 0; x < roster.size(); x++)
        {
            if (roster[x] != NULL)
            {
                roster[x]->play();
            }
        }
        cout << endl;
    }
    
private:
    vector<Musician*> roster;
};


int main()
{
    
    //Part One
    /*
    // The initialization phase
        
        Drum drum;
        Cello cello(673);
        Cymbal cymbal;
        Trombone tbone( 4 );
        Trumpet trpt( 12 ) ;
        Violin violin( 567 ) ;
        
        MILL mill;
        mill.receiveInstr( trpt );
        mill.receiveInstr( violin );
        mill.receiveInstr( tbone );
        mill.receiveInstr( drum );
        mill.receiveInstr( cello );
        mill.receiveInstr( cymbal );
        
        Musician bob;
        Musician sue;
        Musician mary;
        Musician ralph;
        Musician jody;
        Musician morgan;
        
        Orchestra orch;
    
        // THE SCENARIO
        
        //Bob joins the orchestra without an instrument.
        orch.addPlayer(bob);
        
        //The orchestra performs
        cout << "orch performs\n";
        orch.play();
        
        //Sue gets an instrument from the MIL2 and joins the orchestra.
        sue.acceptInstr( *mill.loanOut() );
        orch.addPlayer(sue);
        
        //Ralph gets an instrument from the MIL2.
        ralph.acceptInstr( *mill.loanOut() );
        
        //Mary gets an instrument from the MIL2 and joins the orchestra.
        mary.acceptInstr( *mill.loanOut() );
        orch.addPlayer(mary);
        
        //Ralph returns his instrument to the MIL2.
        mill.receiveInstr( *ralph.giveBackInstr() );
        
        //Jody gets an instrument from the MIL2 and joins the orchestra.
        jody.acceptInstr( *mill.loanOut() );
        orch.addPlayer(jody);
        
        // morgan gets an instrument from the MIL2
        morgan.acceptInstr( *mill.loanOut() );
        
        //The orchestra performs.
        cout << "orch performs\n";
        orch.play();
        
        //Ralph joins the orchestra.
        orch.addPlayer(ralph);
        
        //The orchestra performs.
        cout << "orch performs\n";
        orch.play();
        
        // bob gets an instrument from the MIL2
        bob.acceptInstr( *mill.loanOut() );
        
        // ralph gets an instrument from the MIL2
        ralph.acceptInstr( *mill.loanOut() );
        
        //The orchestra performs.
        cout << "orch performs\n";
        orch.play();
        
        //Morgan joins the orchestra.
        orch.addPlayer(morgan);
        
        //The orchestra performs.
        cout << "orch performs\n";
        orch.play();
        return 0;
    */
    
    
    //Part Two
    
    /*
    cout << "Define some instruments ----------------------------------------\n";
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone( 4 );
    Trumpet trpt( 12 ) ;
    Violin violin( 567 ) ;
    
    // use the debugger to look at the mill
    cout << "Define the MILL ------------------------------------------------\n";
    MILL mill;
    
    cout << "Put the instruments into the MILL ------------------------------\n";
    mill.receiveInstr( trpt );
    mill.receiveInstr( violin );
    mill.receiveInstr( tbone );
    mill.receiveInstr( drum );
    mill.receiveInstr( cello );
    mill.receiveInstr( cymbal );
    
    cout << "Daily test -----------------------------------------------------\n";
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
    
    cout << "Define some Musicians-------------------------------------------\n";
    Musician j;
    Musician jj;
    Musician q;
    
    cout << "TESTING: q.acceptInstr( *mill.loanOut() );-----------------------\n";
    q.testPlay();
    cout << endl;
    q.acceptInstr( *mill.loanOut() );
    cout << endl;
    q.testPlay();
    cout << endl;
    cout << "dailyTestPlay()" << endl;
     mill.dailyTestPlay();
    
    cout << endl << endl;
    
    q.testPlay();
    cout << endl;
    mill.receiveInstr( *q.giveBackInstr() );
    j.acceptInstr( *mill.loanOut() );
    q.acceptInstr( *mill.loanOut() );
    cout << endl;
    q.testPlay();
    cout << endl;
    j.testPlay();
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    
    cout << "TESTING: mill.receiveInstr( *q.giveBackInstr() ); -------------\n";
    
    // fifth
    mill.receiveInstr( *q.giveBackInstr() );
    cout << "TESTING: mill.receiveInstr( *j.giveBackInstr() ); -------------\n";
    mill.receiveInstr( *j.giveBackInstr() );
    
    
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
    
    cout << endl;
     */
}