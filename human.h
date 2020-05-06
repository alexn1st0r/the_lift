#ifndef HUMAN_H_
#define HUMAN_H_
	
class Human {
private:
	bool m_up;
	bool m_down;
	int m_target_floor;
public:
	Human (int tfloor, bool up = false, bool down = false) {
		m_target_floor = tfloor;
		m_up = up;
		m_down = down;
	};
	Human (int tfloor, bool up = true) {
		m_target_floor = tfloor;
		m_up = up;
		m_down = !up;
	};
	inline int get_target_floor() const { return m_target_floor; };
	inline bool is_target_floor(int fl) const { return fl == m_target_floor; };
	inline bool is_up() const { return m_up; };
	inline bool is_down() const { return m_down; };
};

#endif
