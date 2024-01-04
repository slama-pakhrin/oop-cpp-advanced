/****************************************************
Workshop 8 

Name : Salon Lama Pakhrin
Email : slama-pakhrin@myseneca.ca
ID : 160535217
Date: Nov 15

I have done all the coding by myself and only
copied the code that my professor provided to 
complete my workshops and assignments.

****************************************************/

#include <memory>
#include <utility>
#include "DataBase.h"
#include "Profile.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
	DataBase<Profile> excludeRaw(const DataBase<Profile> &allProfiles, const DataBase<Profile> &bannedProfiles)
	{
		DataBase<Profile> result;

		for (size_t i = 0; i < allProfiles.size(); ++i)
		{
			const Profile &profile = allProfiles[i];
			bool isBanned = false;

			for (size_t j = 0; j < bannedProfiles.size() && !isBanned; ++j)
			{
				const Profile &bannedProfile = bannedProfiles[j];
				if (profile.m_age == bannedProfile.m_age &&
					profile.m_name.first_name == bannedProfile.m_name.first_name &&
					profile.m_name.last_name == bannedProfile.m_name.last_name)
				{
					isBanned = true;
				}
			}

			if (!isBanned)
			{
				Profile *new_profile = new Profile(profile.m_name, profile.m_address, profile.m_age);
				try
				{
					new_profile->validateAddress();
					result += *new_profile;
					delete new_profile;
				}
				catch (const std::runtime_error &e)
				{
					delete new_profile;
					throw std::string("*** Invalid Address ***");
				}
			}
		}

		return result;
	}

	DataBase<Profile> excludeSmart(const DataBase<Profile> &allProfiles, const DataBase<Profile> &bannedProfiles)
	{
		DataBase<Profile> result;
		for (size_t i = 0; i < allProfiles.size(); ++i)
		{
			const Profile &profile = allProfiles[i];
			bool isBanned = false;

			for (size_t j = 0; j < bannedProfiles.size() && !isBanned; ++j)
			{
				const Profile &bannedProfile = bannedProfiles[j];
				if (profile.m_age == bannedProfile.m_age &&
					profile.m_name.first_name == bannedProfile.m_name.first_name &&
					profile.m_name.last_name == bannedProfile.m_name.last_name)
				{
					isBanned = true;
				}
			}

			if (!isBanned)
			{
				std::unique_ptr<Profile> new_profile(new Profile(profile.m_name, profile.m_address, profile.m_age));
				try
				{
					new_profile->validateAddress();
					result += std::move(new_profile);
				}
				catch (const std::runtime_error &)
				{
					throw std::string("*** Invalid Address ***");
				}
			}
		}
		return result;
	}
}