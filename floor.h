#ifndef FLOOR_H_
#define FLOOR_H_

#include <iostream>
#include <vector>

#include "human.h"

class FloorQueue {
private:
	std::vector<Human> m_humans;
	std::vector<Human> m_humans_up;
	std::vector<Human> m_humans_down;
	int m_floor;
public:
	FloorQueue (std::vector<int> humans, int floor);
	~FloorQueue ();
	inline bool all_up() { return !m_humans_up.empty() && m_humans_down.empty(); };
	inline bool all_down() { return m_humans_up.empty() && !m_humans_down.empty(); };
	inline bool is_up() { return !m_humans_up.empty(); };
	inline bool is_down() { return !m_humans_down.empty(); };
	inline int get_humans_queue_size() { return m_humans.size(); };
	inline int get_humans_up_queue_size() { return m_humans_up.size(); };
	inline int get_humans_down_queue_size() { return m_humans_down.size(); };
	inline bool is_empty() const { return m_humans.empty(); };
	std::vector<Human> get_human_queue(int nm);
	std::vector<Human> get_human_queue_up(int nm);
	std::vector<Human> get_human_queue_down(int nm);
};
	
#endif
