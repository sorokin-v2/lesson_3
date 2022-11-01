
#include <iostream>
#include <utility>

class smart_array {
public:
	smart_array(const int arr_size) : size{ arr_size } {
		if (size > 0) {
			arr = new int[size];
		}
		else {
			throw std::runtime_error("Size < 0");
		}
	};

	~smart_array() {
		delete[] arr;
	}

	void add_element(const int new_element) {
		if (count < size) {
			arr[count++] = new_element;
		}
		else {
			throw std::runtime_error("Out of range");
		}
	}

	int get_element(const int index) {
		if (index < size) {
			return arr[index];
		}
		else {
			throw std::runtime_error("Out of range");
		}
	}

	smart_array& operator= (smart_array const& rhs) {
		if (this != &rhs) {
			delete[] arr;
			arr = new int[rhs.size];
			for (int i = 0; i < rhs.size; ++i) {
				this->arr[i] = rhs.arr[i];
			}
			this->size = rhs.size;
			this->count = rhs.count;
		}
		return *this;
	}


protected:
	int* arr{ nullptr };
	int count{ 0 };
	int size{ 0 };
};

int main()
{
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

	arr = new_array;
}