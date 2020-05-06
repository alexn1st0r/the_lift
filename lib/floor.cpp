#include "floor.h"


FloorQueue::FloorQueue(std::vector<int> humans, int floor)
{
	m_floor = floor;
	for (int hm = 0; hm < humans.size(); hm++) {
		Human human(humans[hm], humans[hm] > m_floor, humans[hm] < m_floor); 

		m_humans.push_back(human);
		if (human.is_up())
			m_humans_up.push_back(human);
		if (human.is_down())
			m_humans_down.push_back(human);
	}
}

FloorQueue::~FloorQueue()
{
	std::vector<Human>::iterator it;

	it = m_humans_up.begin();
	while (it != m_humans_up.end()) {
		m_humans_up.erase(it);
		if (m_humans_up.empty())
			break;
	}

	it = m_humans_down.begin();
	while (it != m_humans_down.end()) {
		m_humans_down.erase(it);
		if (m_humans_down.empty())
			break;
	}

	it = m_humans.begin();
	while (it != m_humans.end()) {
		m_humans.erase(it);
		if (m_humans.empty())
			break;
	}
}

std::vector<Human> FloorQueue::get_human_queue(int nm)
{
	std::vector<Human> result;
	for (int i = 0; i < nm; i++) {
		result.push_back(m_humans[i]);
	}

	for (int i = 0; i < nm; i++) {
		if (m_humans.empty()) {
			continue;
		}

		if (m_humans[0].is_up()) {
			m_humans_up.erase(m_humans_up.begin());
		}
		if (m_humans[0].is_down()) {
			m_humans_down.erase(m_humans_down.begin());
		}
		m_humans.erase(m_humans.begin());
	}

	return result;
}

std::vector<Human> FloorQueue::get_human_queue_up(int nm)
{
	std::vector<Human>::iterator it;
	std::vector<Human> result;
	int i = 0;

	for (int i = 0; i < nm && i < m_humans_up.size(); i++) {
		result.push_back(m_humans_up[i]);
	}


	it = m_humans_up.begin();
	while (it != m_humans_up.end() && i++ < nm) {
		m_humans_up.erase(it);
		if (m_humans_up.empty())
			break;
	}

	i = 0;
	it = m_humans.begin();
	while (it != m_humans.end() && i < nm) {
		if ((*it).is_up()) {
			m_humans.erase(it);
			if (m_humans.empty())
				break;
			i++;
		} else {
			it++;
		}
	}

	return result;
}

std::vector<Human> FloorQueue::get_human_queue_down(int nm)
{
	std::vector<Human>::iterator it;
	std::vector<Human> result;
	int i = 0;

	for (int i = 0; i < nm && i < m_humans_down.size(); i++) {
		result.push_back(m_humans_down[i]);
	}


	it = m_humans_down.begin();
	while (it != m_humans_down.end() && i++ < nm) {
		m_humans_down.erase(it);
		if (m_humans_down.empty())
			break;
	}

	i = 0;
	it = m_humans.begin();
	while (it != m_humans.end() && i < nm) {
		if ((*it).is_down()) {
			m_humans.erase(it);
			if (m_humans.empty())
				break;
			i++;
		} else {
			it++;
		}
	}

	return result;
}
