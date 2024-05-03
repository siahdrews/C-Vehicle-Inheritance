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

private:
    // private members
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

    virtual void accelerate() = 0;
    void accelerate() // speed up
    {
        if (m_moving == true)
        {
            if (m_speed + 50 <= m_max_speed)
            {
                m_speed += 50;
                std::cout << "Your " << m_name << " has sped up" << std::endl;
            }
            else
            {
                m_speed = m_max_speed;
                std::cout << "Your " << m_name << " is at maximum speed" << std::endl;
            }
        } 
        else
        {
           std::cout << "Your " << m_name << " needs to take off first" << std::endl; 
        }
    }

    virtual void decelerate() = 0;
    void decelerate() // slow down
    {
        if (m_moving == true)
        {
            if (m_speed - 50 <= 0)
            {
                m_speed = 0;
                std::cout << "Your " << m_name << " is stopped" << std::endl;
            }
            else
            {
                m_speed -= 50;
                std::cout << "Your " << m_name << " has slowed down" << std::endl;
            }
        }
        else
        {
            std::cout << "Your " << m_name << " needs to take off first" << std::endl;
        }
    }

    virtual void takeoff() = 0;
    void takeoff() // start vehicle movement
    {
        if (m_moving == false){
            m_moving = true;
            m_speed = 50;
            std::cout << "Your " << m_name << " has started moving at 50 speed" << std::endl;
        }
    }

    virtual void stop_vehicle() = 0;
    void stop_vehicle() // stop vehicle
    {
        if (m_moving == true){
            m_moving = false;
            m_speed = 0;
            std::cout << "Your " << m_name << " has stopped and is turned off" << std::endl;
        }
    }

    virtual void exit() = 0;
    void exit() // exit program
    {
        std::cout << "Thanks for using your " << m_name << "! " << std::endl;
        still_running = false;
    }

    virtual void print_title() = 0;
    void print_title(){
        std::cout << "+---------------------------------+" << std::endl;
        std::cout << "|     Standard Vehicle Title      |"<< std::endl;
        std::cout << "+---------------------------------+" << std::endl;
    }

    virtual char show_options() = 0;
    char show_options(){
        char a;     // get input from user
        std::cout << "(T)ake off | (A)ccelerate | (D)ecelerate | (S)top | E(x)it >>";
        std::cin >> a;
        return a;   // return input
    }

    // TODO: Create getters and setters
};

// TODO: Derived class 1

// TODO: Derived class 2