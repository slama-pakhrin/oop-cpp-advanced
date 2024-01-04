/****************************************************
Workshop 9

Name : Salon Lama Pakhrin
Email : slama-pakhrin@myseneca.ca
ID : 160535217
Date: Nov 24

I have done all the coding by myself and only
copied the code that my professor provided to 
complete my workshops and assignments.

****************************************************/



#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <thread>
#include "process_data.h"

namespace sdds
{

	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {
			avg += arr[i];
		}
		avg /= divisor;
	}


	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}

	  
	ProcessData::ProcessData(const std::string& filename, int n_threads) {  
	


		std::ifstream file(filename, std::ios::binary);

		if (!file.is_open()) {
			throw std::runtime_error("Error opening file");
		}

		file.read(reinterpret_cast<char*>(&total_items), sizeof(int));
		data = new int[total_items];
		file.read(reinterpret_cast<char*>(data), total_items * sizeof(int));
		file.close();



		std::cout << "Item's count in file '"<< filename << "': " << total_items << std::endl;
		std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
		          << data[total_items - 3] << ", " << data[total_items - 2] << ", "
		          << data[total_items - 1] << "]" << std::endl;

		
		num_threads = n_threads; 
		averages = new double[num_threads] {};
		variances = new double[num_threads] {};
		p_indices = new int[num_threads+1] {};
		for (int i = 0; i < num_threads; i++)
			p_indices[i] = i * (total_items / num_threads);
		p_indices[num_threads] = total_items;
	}
	ProcessData::~ProcessData() {
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}

	ProcessData::operator bool() const {
		return total_items > 0 && data;
	}



	int ProcessData::operator()(const std::string& target_file, double& avg, double& var) {
		std::vector<double> avgFactors(std::thread::hardware_concurrency());
		std::vector<double> varFactors(std::thread::hardware_concurrency());
		
		std::vector<std::thread> avgThreads;
		size_t partitionSize = total_items / avgFactors.size();
		std::vector<size_t> p_indices(avgFactors.size() + 1);

		for (size_t i = 0; i < p_indices.size(); ++i) {
			p_indices[i] = i * partitionSize;
		}

		for (size_t i = 0; i < avgFactors.size(); ++i) {
			avgThreads.emplace_back(std::bind(computeAvgFactor, data + p_indices[i], partitionSize,
				total_items, std::ref(avgFactors[i])));
		}

		for (auto& thread : avgThreads) {
			thread.join();
		}

		avg = 0.0;
		for (const auto& factor : avgFactors) {
			avg += factor;
		}

		std::vector<std::thread> varThreads;
		for (size_t i = 0; i < varFactors.size(); ++i) {
			varThreads.emplace_back(std::bind(computeVarFactor, data + p_indices[i], partitionSize,
				total_items, avg, std::ref(varFactors[i])));
		}

		for (auto& thread : varThreads) {
			thread.join();
		}

		var = 0.0;
		for (const auto& factor : varFactors) {
			var += factor;
		}

		std::ofstream file(target_file, std::ios::binary);

		if (!file.is_open()) {
			std::cerr << "Error opening target file" << std::endl;
			return 1;
		}

		file.write(reinterpret_cast<const char*>(&total_items), sizeof(int));
		file.write(reinterpret_cast<const char*>(data), total_items * sizeof(int));

		file.close();

		return 0;
	}
}
