#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

using vector = std::vector<int>;


vector fast_sort(const vector &v)
{
	if(v.size() <= 1)
	{
		return v;
	}

	vector lv, rv; // left v, right v
	size_t pivot = (v.size() - 1) / 2;
	
	for(size_t i = 0; i < v.size(); ++i)
	{
		if (pivot == i)
		{
			continue;
		}
		
		auto curr = v[i];
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

vector bubble_sort(const vector& v)
{
	vector res = v;
	for (size_t i = 0; i < res.size(); ++i)
	{
		for (size_t j = 0; j < res.size() - i - 1; ++j)
		{
			if (res[j] > res[j + 1]){
				
				std::swap(res[j], res[j + 1]);	
				/* int temp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = temp; */
			}
		}
	}

	return res;
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
	vector v = {11, 12, 1, 4, 5, 6, 3};
	std::thread t1([&v](){
		vector fast_v = fast_sort(v);
		print_vector(fast_v);
	});

	std::thread t2([&v](){
		vector bub_v = bubble_sort(v);
		print_vector(bub_v);
	});
	
	t1.join();
	t2.join();

	return 0;
}
