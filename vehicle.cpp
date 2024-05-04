// vehicle.cpp
/*
 * Author: Josiah Andrews
 * Created: 5/3/2024
 * Description:
 */

#include <iostream>


// base class
class Vehicle
{
    /******************** DATA MEMBERS************************/
protected:
    // protected members
    std::string m_name;    // Name of vehicle
    int m_speed;           // current speed of vehicle
    bool m_moving = false; // is the vehicle moving or not
        int m_max_speed; // maximum speed of vehicle

public:
    bool still_running = true;
    // public member functions
    // parameter based constructor
    Vehicle(std::string name, int max_speed, int speed)
    {
        m_name = name;
        m_max_speed = max_speed;
        m_speed = speed;
    }

    // TODO: Create methods that do something

    void accelerate() // speed up
    {
        if (m_moving == true)
        {
            if (m_speed + 50 <= m_max_speed)
            {
                m_speed += 50;
                std::cout << "Your vehicle has sped up" << std::endl;
            }
            else
            {
                m_speed = m_max_speed;
                std::cout << "Your vehicle is at maximum speed" << std::endl;
            }
        } 
        else
        {
           std::cout << "Your vehicle needs to take off first" << std::endl; 
        }
    }

    void decelerate() // slow down
    {
        if (m_moving == true)
        {
            if (m_speed - 50 <= 0)
            {
                m_speed = 0;
                std::cout << "Your vehicle is stopped" << std::endl;
            }
            else
            {
                m_speed -= 50;
                std::cout << "Your vehicle has slowed down" << std::endl;
            }
        }
        else
        {
            std::cout << "Your vehicle needs to take off first" << std::endl;
        }
    }

    void takeoff() // start vehicle movement
    {
        if (m_moving == false){
            m_moving = true;
            m_speed = 50;
            std::cout << "Your vehicle has started moving at 50 speed" << std::endl;
        }
    }

    void stop_vehicle() // stop vehicle
    {
        if (m_moving == true){
            m_moving = false;
            m_speed = 0;
            std::cout << "Your vehicle has stopped and is turned off" << std::endl;
        }
    }

    void exit() // exit program
    {
        std::cout << "Thanks for using your vehicle! " << std::endl;
        still_running = false;
    }

    virtual void print_title() = 0;
    void print_title(){
        std::cout << "+---------------------------------+" << std::endl;
        std::cout << "|     Standard Vehicle Title      |"<< std::endl;
        std::cout << "+---------------------------------+" << std::endl;
    }

    virtual void show_options() = 0;
    void show_options(){
        char a;     // get input from user
        std::cout << "(T)ake off | (A)ccelerate | (D)ecelerate | (S)top | E(x)it >>";
        std::cin >> a;
        
        if(a=='t'){
            takeoff();
        } else if (a=='a')
        {
            accelerate();
        } else if (a=='d')
        {
            decelerate();
        } else if (a=='s')
        {
            stop_vehicle();
        } else if (a=='x')
        {
            exit();
        }
        
        
        
        
    }

    // TODO: Create getters and setters
    std::string name()
    {
        return m_name;
    }

    int speed()
    {
        return m_speed;
    }

    int max_speed()
    {
        return m_max_speed;
    }

    void name(std::string name)
    {
        m_name = name;
    }

    void speed(int speed)
    {
        m_speed = speed;
    }

};

// TODO: Derived class 1
class Boulder : public Vehicle{
    public:
    /*********************PUBLIC MEMBER FUNCTIONS*******************/
    Boulder(std::string name, int speed, int max_speed) : Vehicle(name, speed, max_speed){}

    // Create new method
    void fall_off()
    {
        std::cout << "You fell off of the boulder and died" << std::endl;
        still_running = false;
    }

    // override methods
    void accelerate() // speed up
    {
        if (m_moving == true)
        {
            if (m_speed + 100 <= m_max_speed)
            {
                m_speed += 100;
                std::cout << "Your boulder keeps going faster and faster" << std::endl;
            }
            else
            {
                m_speed = m_max_speed;
                std::cout << "Your boulder is at terminal velocity" << std::endl;
            }
        } 
        else
        {
           std::cout << "Your boulder can really only move if it's going downhill" << std::endl; 
        }
    }

    void decelerate() // slow down
    {
        if (m_moving == true)
        {
            std::cout << "There isn't really much you can do to slow down your boulder" << std::endl;
        }
        else
        {
            std::cout << "your boulder needs a hill first" << std::endl;
        }
    }

    void takeoff() // start vehicle movement
    {
        if (m_moving == false){
            m_moving = true;
            m_speed = 100;
            std::cout << "You found a hill to roll your boulder down" << std::endl;
        }
    }

    void stop_vehicle() // stop vehicle
    {
        if (m_moving == true){
            m_moving = false;
            m_speed = 0;
            std::cout << "You got to the bottom of the hill and your boulder crashed" << std::endl;
        }
    }

    void exit() // exit program
    {
        std::cout << "Thanks for using your boulder! " << std::endl;
        still_running = false;
    }

    void print_title(){
        std::cout << "+--------------------------------+" << std::endl;
        std::cout << "|     Bob's Boulder Rolling      |"<< std::endl;
        std::cout << "+--------------------------------+" << std::endl;
    }

    void show_options(){
        char a;     // get input from user
        std::cout << "(T)ake off | (A)ccelerate | (D)ecelerate | (S)top | E(x)it  | (F)all off >>";
        std::cin >> a;
        if(a=='t'){
            takeoff();
        } else if (a=='a')
        {
            accelerate();
        } else if (a=='d')
        {
            decelerate();
        } else if (a=='s')
        {
            stop_vehicle();
        } else if (a=='x')
        {
            exit();
        } else if (a=='f')
        {
            fall_off();
        }
    }

};

// TODO: Derived class 2
class Airplane : public Vehicle{
    public:
    /*********************PUBLIC MEMBER FUNCTIONS*******************/
    Airplane(std::string name, int speed, int max_speed) : Vehicle(name, speed, max_speed){}

    // Create new method
    void fall_off()
    {
        std::cout << "You fell out of the airplane and died" << std::endl;
        still_running = false;
    }

    // override methods
    void accelerate() // speed up
    {
        if (m_moving == true)
        {
            if (m_speed + 100 <= m_max_speed)
            {
                m_speed += 100;
                std::cout << "Your Airplane sped up" << std::endl;
            }
            else
            {
                m_speed = m_max_speed;
                std::cout << "Your Airplane is at maximum velocity" << std::endl;
            }
        } 
        else
        {
           std::cout << "Your airplane needs to take off in order to speed up" << std::endl; 
        }
    }

    void decelerate() // slow down
    {
        if (m_moving == true)
        {
            if (m_speed - 50 <= 0)
            {
                m_speed = 0;
                std::cout << "Your Airplane is stopped" << std::endl;
            }
            else
            {
                m_speed -= 50;
                std::cout << "Your Airplane has slowed down" << std::endl;
            }
        }
        else
        {
            std::cout << "Your Airplane needs to take off first" << std::endl;
        }
    }

    void takeoff() // start vehicle movement
    {
        if (m_moving == false){
            m_moving = true;
            m_speed = 100;
            std::cout << "Your airplane took off into the sky" << std::endl;
        }
    }

    void stop_vehicle() // stop vehicle
    {
        if (m_moving == true){
            m_moving = false;
            m_speed = 0;
            std::cout << "Your airplane got to the airport and landed" << std::endl;
        }
    }

    void exit() // exit program
    {
        std::cout << "Thanks for flying with us! " << std::endl;
        still_running = false;
    }

    void print_title(){
        std::cout << "+---------------------------------+" << std::endl;
        std::cout << "|     Bob's Airplane Service      |"<< std::endl;
        std::cout << "+---------------------------------+" << std::endl;
    }

    void show_options(){
        char a;     // get input from user
        std::cout << "(T)ake off | (A)ccelerate | (D)ecelerate | (S)top | E(x)it  | (F)all off >>";
        std::cin >> a;
        if(a=='t'){
            takeoff();
        } else if (a=='a')
        {
            accelerate();
        } else if (a=='d')
        {
            decelerate();
        } else if (a=='s')
        {
            stop_vehicle();
        } else if (a=='x')
        {
            exit();
        } else if (a=='f')
        {
            fall_off();
        }
    }

};