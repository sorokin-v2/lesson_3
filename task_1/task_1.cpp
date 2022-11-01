#include <iostream>

class smart_array {
public:
	smart_array(const int arr_size) : size{ arr_size } {
		if (size > 0) {
			arr = new int[size];
		}
		else {
			throw std::runtime_error("Size <= 0");
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

protected:
	int* arr{ nullptr };
	int count{ 0 };
	int size{ 0 };
};


int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

