#pragma once

class Application
{
public:
    // Move Semantics: Move semantics allow the transfer of resources (like dynamically allocated memory) from one object to another without unnecessary copying.
	// Move Constructor: A move constructor is a special member function that enables the efficient transfer of resources during object initialization or assignment.
    Application(const Application&) = delete;
    Application(Application&&) = delete;
};
