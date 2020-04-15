#pragma once
#include "cookie.h"
#include <vector>

template <class T>
class Repository {
private:
	std::vector<T> storage;
public:
	/* Constructor & Destructor */
	Repository() {} // Defalut
	~Repository() {
		this->storage.clear();
	} // Destructor

	/* CRUD */
	virtual void addCookie(T t) { // Add element Cookie (In: object Cookie)
		this->storage.push_back(t);
	}

	virtual void updateCookie(T t) { // Update old Cookie with new Cookie (In: old object Cookie, new object Cookie)
		for (unsigned int i = 0; i < this->storage.size(); i++)
			if (this->storage[i].getID() == t.getID())
			{
				this->storage[i].setName(t.getName());
				this->storage[i].setIngr(t.getIngr());
				this->storage[i].setPrice(t.getPrice());

			}
	}
	virtual void deleteCookie(T t) { // Delete a Cookie element from storage (In: object COokie do delete)
		for (unsigned int i = 0; i < this->storage.size(); i++)
			if (this->storage[i] == t)
			{
				this->storage[i] = this->storage[this->storage.size() - 1];
				this->storage.pop_back();

			}
	}

	/* Get's */
	int getSize() { // Return size of storage (Out: size const)
		return this->storage.size();
	}
	std::vector<T> getAll() { // Returns pointer of storage (Out: storage)
		return this->storage;
	}
	
	void clear() { // Clear storage
		this->storage.clear();
	}

};