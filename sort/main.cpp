#include <iostream>
#include <thread>
#include <vector>

using vector = std::vector<int>;


vector fast_sort(vector &v)
{
	vector lv; // left v 
	vector rv;	// right v
	int pivot = (v.size() - 1) / 2;
	
	for(int i = 0; i < v.size(); ++i)
	{
		if (pivot == i)
		{
			continue;
		}
		
		int curr = v[i];
		if (curr >= v[pivot]){
			rv.push_back(curr);
		}
		else {
			lv.push_back(curr);
		}
	}	

	lv = fast_sort(lv);
	rv = fast_sort(rv);

	lv.push_back(v[pivot]);
	lv.insert(lv.end(), rv.begin(), rv.end());
	
	return lv;
}

void print_vector(const vector &v)
{
	for(const auto& num : v){
		std::cout << num << " ";
	}

	std::cout << std::endl;

}


int main()
{
	std::vector v = {11, 12, 1, 4, 5, 6, 3};
	//std::thread t1();
	//std::thread t2();
	fast_sort(v);	
	print_vector(v);
//	t1.join();
//	t2.join();

	return 0;
}
