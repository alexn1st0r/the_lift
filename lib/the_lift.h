#ifndef THE_LIFT_H_
#define THE_LIFT_H_
	
#include <iostream>
#include <vector>
#include <algorithm>

#include "floor.h"

class TheLift {
private:
	enum direction { UP, DOWN};
	direction m_dir;
	std::vector<FloorQueue> m_floors;
	std::vector<Human> m_humans;
	int nr_floors;
	int m_capacity;
	int m_current_floor;
	bool is_exit_floor() const;
	void exit_people_from_lift();
	bool is_enter_floor() const;
	void enter_people_to_lift();
	bool is_lower_call() const;
	bool is_upper_call() const;
	int get_next_floor();
public:
	TheLift (std::vector<std::vector<int>> queues, int capacity);
	~TheLift ();
	std::vector<int> get_floors_queue();
};

#endif
