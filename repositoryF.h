#pragma once
#include "cookie.h"
#include "repository.h"
#include <vector>

template <class T>
class RepositoryF: public Repository<T> {
private:
	string fileName;
public:
	/* Constructor & Destructor */
	RepositoryF() {} // Defalut
	RepositoryF(string file) { // By given fileName (In: fileName) 
		this->fileName = file;
		this->loadFile();
	}

	~RepositoryF() {} // Destructor

	/* CRUD */
	void addCookie(T t) { // Add element Cookie (In: object Cookie)
		Repository<T>::addCookie(t);
	}

	void updateCookie(T t) { // Update old Cookie with new Cookie (In: old object Cookie, new object Cookie)
		Repository<T>::updateCookie(t);
		this->saveFile();
	}

	void deleteCookie(T t) { // Delete a Cookie element from storage (In: object COokie do delete)
		Repository<T>::deleteCookie(t);
		this->saveFile();
	}

	/* Get's */
	int getSize() { // Return size of storage (Out: size const)
		return Repository<T>::getSize();
	}

	std::vector<T> getAll() { // Returns pointer of storage (Out: storage)
		return Repository<T>::getAll();
	}

	/* File operations */
	void saveFile() { // Save data
		if (this->fileName.size() > 0)
		{
			ofstream f(this->fileName);
			for (int i = 0; i < Repository<T>::getSize(); i++)
			{
				f << Repository<T>::getAll()[i];
			}
			f.close();
		}
	}

	void loadFile() { // Load data
		if (this->fileName.size() > 0)
		{
			Repository<T>::clear();
			ifstream f(this->fileName);
			int ID;
			string name;
			string ingr;
			double price;
			while (!f.eof())
			{
				f >> ID >> name >> ingr >> price;
				if (name.size() > 0)
				{
					Repository<T>::addCookie(Cookie(ID, name, ingr, price));
				}
			}
			f.close();
		}
	}
};