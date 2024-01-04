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

#ifndef SDDS_PROCESSDATA_H
#define SDDS_PROCESSDATA_H

#include<string>

namespace sdds {
	void computeAvgFactor(const int* arr, int size, int divisor, double& avg);
	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var);

	class ProcessData {
		int total_items{};
		int* data{};
		
		int num_threads{ 0 }; 
		double* averages{ nullptr }; 
		double* variances{ nullptr }; 
		int* p_indices{ nullptr }; 
	public:
		ProcessData(const std::string& input_file, int n_threads);
		ProcessData(const ProcessData&) = delete;
		ProcessData& operator=(const ProcessData&) = delete;
		~ProcessData();
		operator bool() const;
		int operator()(const std::string& target_file, double& avg, double& var);
	};
}

#endif
