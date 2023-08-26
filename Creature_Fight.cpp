

    // IBRAHIM AHMAD ---- 22i-8781 ---- SE-A ---- 


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

 //A creature is characterized by
 // its name (a constant string);
 // its level (an integer);
 // its number of health_status points (health_status status; an integer);
 // its force (an integer);
 // its position (position, also an integer; for simplicity, our game takes place in 1D).

class Creature {
protected:
    const string name;
    int level;
    int health_status;
    int force;
    int position;

public:
    Creature(const string& n, int l, int h, int f, int p = 0) : name(n), level(l), health_status(h), force(f), position(p) {}

    int getPosition() {    return this->position;   }
    string getName() { return this->name;    }
    
    bool alive() const {

        if (health_status > 0)
            return 1;
        else
            return 0;
    }

    int AttackPoints() const {
       
        if (alive() != 0)
        {
            return this->level * this->force;
        }   
        else
        {
            //cout << "CREATURE IS NO MORE" << endl;
            return 0;
        }
    }

    void Move(int d) {
        this->position += d;
    }

    void GoodBye() const {
        cout << " " << name << " " << " is no more " << endl;
    }

    void Weak(int damage) {
        if (alive()) {
            this->health_status = this->health_status - damage;
            if (!alive()) {
                this->health_status = 0;
                GoodBye();
            }
        }
    }

    void display() const {
        cout << " " << name << " " << ", level: " << " " << level << " "
             << ", health_status_status: " << " " << health_status << " " <<", force: " << " " << force << " " 
             << ", Attacking Points: " << " " << AttackPoints() << " "
             << ", position: " << " " << position << " " << endl;
    }
};

class Dragon : public Creature {
private:
    int flame_range;

public:
    Dragon(const string& n, int l, int h, int f, int r, int p = 0)
        : Creature(n, l, h, f, p), flame_range(r) {}

    void Fly(int pos) 
    {
        this->position = pos;
    }

    void BlowFlame(Creature& obj2)
    {
        if (this->alive() && obj2.alive())
        {
            if (abs(obj2.getPosition() - position) <= flame_range)
            {
                int distance = obj2.getPosition() - this->position;
                //int damage;
                //damage = this->AttackPoints() - distance;
                obj2.Weak(this->AttackPoints());
                if (!obj2.alive()) {
                    level++;
                }
                this->Weak(distance);

            }
        }
    }

};

class Ichneumon : public Creature {
private:
    int neck_length;
    int poison_dose;

public:


    Ichneumon(const string& n, int l, int h, int f, int nl, int pd, int p = 0)
        : Creature(n, l, h, f, p), neck_length(nl), poison_dose(pd) {}


    void InjectPoison(Creature& obj2)
    {
        if (this->alive() && obj2.alive() && abs(obj2.getPosition() - position) <= neck_length) {
            int damage = AttackPoints() + poison_dose;
            obj2.Weak(damage);
            if (!obj2.alive()) {
                this->level++;
            }
        }
    }
};

void Fight(Dragon& a, Ichneumon& b)
{
    b.InjectPoison(a);
    a.BlowFlame(b);
}

int main()
{

   Dragon dragon("Dragon red", 2, 10, 3, 20);
   Ichneumon  ichneumon("ichneumon evil", 2, 10, 1, 10, 1, 42);

    dragon.display();
    cout << "is preparing for fight with :" << endl;
    ichneumon.display();

    cout << endl;
    cout << "1st Fight :" << endl;
    cout << "    the creature-s are not within range, so can not Attacke." << endl;
    Fight(dragon, ichneumon);
    
    cout << "After the Fight :" << endl;
    dragon.display();
    ichneumon.display();
    
    cout << endl;
    cout << "Dragon has flown close to ichneumon :" << endl;
    dragon.Fly(ichneumon.getPosition() - 1);
    dragon.display();
    
    cout << endl;
    cout << "ichneumon moves :" << endl;
    ichneumon.Move(1);
    ichneumon.display();
    
    cout << endl;
    cout << "2nd Fight :" << endl;
    cout << ""
        << "+ ichneumon inflicts a 3-point attack on dragon\n"
        " [ level (2) * force (1) + poison (1) = 3 ] ;\n"
        "+ Dragon inflicts a 6-point attack on ichneumon\n"
        "[ level (2) * force (3) = 6 ] ;\n"
        "+ during his attack, dragon loses two additional points\n"
        "      [ corresponding to the distance between dragon and ichneumon : 43 - 41 = 2 ]." << endl;
    Fight(dragon, ichneumon);
    
    cout << "After the Fight :" << endl;
    dragon.display();
    ichneumon.display();

    cout << endl;
    cout << "Dragon moves by one step " << endl;
    dragon.Move(1);
    dragon.display();

    cout << endl;
    cout << "3rd Fight :" << endl;
    cout << "  + ichneumon inflicts a 3-point attack on dragon \n "
        "    [ level (2) * force (1) + poison (1) = 3 ] ; \n "
        "+ Dragon inflicts a 6-point attack on ichneumon \n "
        "      [ level (2) * force (3) = 6 ] ; \n"
        "+ during his attack, dragon lost 1 additional life point.\n"
        "[ corresponding to the distance between dragon and ichneumon : 43 - 42 = 1 ] ;\n"
        "+ ichneumon is defeated and the dragon rises to level 3" << endl;
    Fight(dragon, ichneumon);
    
    cout << "After the Fight :" << endl;
    dragon.display();
    ichneumon.display();

    cout << endl;
    cout << "4th Fight :" << endl;
    cout << "    when one creatures is defeated, nothing happpens" << endl;
    Fight(dragon, ichneumon);

    cout << "After the Fight :" << endl;
    dragon.display();
    ichneumon.display();
    
    
    return 0;
}
