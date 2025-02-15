#pragma once

class Talent
{
public:
    virtual void showTalent() = 0; 
};

class Swimming : public Talent
{
public:
    virtual void showTalent();
};

class Dancing : public Talent
{
public:
    virtual void showTalent();
};

class Counting : public Talent
{
public:
    virtual void showTalent();
};