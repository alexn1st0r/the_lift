#include "the_lift.h"

TheLift::TheLift (std::vector<std::vector<int>> queues, int capacity)
{
	m_capacity = capacity;
	nr_floors = queues.size();
	m_current_floor = 0;
	m_dir = UP;

	for (int fl = 0; fl < nr_floors; fl++) {
		FloorQueue floor(queues[fl], fl);
		m_floors.push_back(floor);
	}
}

TheLift::~TheLift ()
{
	std::vector<FloorQueue>::iterator it;

	it = m_floors.begin();
	while (it != m_floors.end()) {
		m_floors.erase(it);
		if (m_floors.empty())
			break;
	}

	m_capacity = 0;
	nr_floors = 0;

}

bool TheLift::is_exit_floor() const
{
	for (int i = 0; i < m_humans.size(); i++)
		if(m_humans[i].is_target_floor(m_current_floor))
			return true;

	return false;
}

void TheLift::exit_people_from_lift()
{
	auto it = m_humans.begin();

	while (it != m_humans.end()) {
		if((*it).is_target_floor(m_current_floor)) {
			m_humans.erase(it);
			if (m_humans.empty())
				break;
		} else 
			it++;
	}
}

bool TheLift::is_enter_floor() const
{
	return m_humans.size() < m_capacity;
}

void TheLift::enter_people_to_lift()
{
	if ((m_dir == UP && m_floors[m_current_floor].is_up()) ||
	    (m_dir == DOWN && !m_floors[m_current_floor].is_down()))
	{
		int hqs = m_floors[m_current_floor].get_humans_up_queue_size();

		if(hqs > m_capacity - m_humans.size() )
			hqs = m_capacity - m_humans.size();

		std::vector<Human> hq = m_floors[m_current_floor].get_human_queue_up(hqs);
		for (int i = 0; i < hq.size(); i++) {
			m_humans.push_back(hq[i]);
		}
	} else if ((m_dir == DOWN && m_floors[m_current_floor].is_down()) ||
		   (m_dir == UP && !m_floors[m_current_floor].is_up()))
	{
		int hqs = m_floors[m_current_floor].get_humans_down_queue_size();

		if(hqs > m_capacity - m_humans.size() )
			hqs = m_capacity - m_humans.size();

		std::vector<Human> hq = m_floors[m_current_floor].get_human_queue_down(hqs);
		for (int i = 0; i < hq.size(); i++) {
			m_humans.push_back(hq[i]);
		}
	}
}

bool TheLift::is_upper_call() const
{
	for (int fl = m_current_floor+1; fl < nr_floors; fl++) {
		if(!m_floors[fl].is_empty())
			return true;
		for (int hm = 0; hm < m_humans.size(); hm++)
			if(m_humans[hm].is_target_floor(fl))
				return true;
	}

	return false;
}


bool TheLift::is_lower_call() const
{
	for (int fl = m_current_floor-1; fl >= 0; fl--) {
		if(!m_floors[fl].is_empty())
			return true;
		for (int hm = 0; hm < m_humans.size(); hm++)
			if(m_humans[hm].is_target_floor(fl))
				return true;
	}

	return false;
}

int TheLift::get_next_floor()
{
	int ret = -1;
	if (m_dir == UP) {
		for (; m_current_floor < nr_floors; m_current_floor++) {
			if(is_exit_floor()) {
				exit_people_from_lift();
				ret = m_current_floor;
			}

			FloorQueue floor = m_floors[m_current_floor];
			if (floor.is_empty()) {
				if (ret > -1) 
					break;
				continue;
			}

			if (floor.all_down()) {
				if (m_current_floor < nr_floors-1)
					if(is_upper_call())
						if (ret > -1)
							return ret;
						else
							continue;
				else
					m_dir = DOWN;
			}

			if (is_enter_floor()) {
				enter_people_to_lift();
				ret = m_current_floor;
				break;
			} else if(floor.is_up()){
				ret = m_current_floor;
			}
			if (ret > -1)
				break;
		}
		if (m_current_floor == nr_floors) {
			m_dir = DOWN;
			--m_current_floor;
		} else if (!is_upper_call() && is_lower_call()) {
			m_dir = DOWN;
			--m_current_floor;
		}
		if (m_dir == UP)
			++m_current_floor;
	} else {
		for (; m_current_floor >= 0; --m_current_floor) {
			if(is_exit_floor()) {
				exit_people_from_lift();
				ret = m_current_floor;
			}

			FloorQueue floor = m_floors[m_current_floor];
			if (floor.is_empty()) {
				if (ret > -1) 
					break;
				continue;
			}

			if (floor.all_up()) {
				if (m_current_floor > 0)
					if(is_lower_call())
						if (ret > -1)
							return ret;
						else
							continue;
				else
					m_dir = UP;
			}

			if (is_enter_floor()) {
				enter_people_to_lift();
				ret = m_current_floor;
				if (m_dir == UP)
					++m_current_floor;
				else if (m_dir == DOWN && m_current_floor > 0) {
					--m_current_floor;
				}
				if (ret == nr_floors -1) {
					ret = -1;
					continue;
				}
			} else if(floor.is_down()){
				ret = m_current_floor;
				m_current_floor--;
			}

			if (ret > -1)
				break;
		}
		if (m_current_floor == 0 && is_upper_call()) {
			m_dir = UP;
		} else if (!is_lower_call() && is_upper_call()) {
			m_dir = UP;
		}
	}

	return ret;
}

std::vector<int> TheLift::get_floors_queue()
{
	std::vector<int> result;

	for (int floor = 0; floor > -1; floor = get_next_floor()) {
		result.push_back(floor);
	}
	if (result.back() !=0 )
		result.push_back(0);
	if (result.size() > 1) {
		auto last = std::unique(result.begin(), result.end());
		result.erase(last, result.end());
	}

	return result;
}
