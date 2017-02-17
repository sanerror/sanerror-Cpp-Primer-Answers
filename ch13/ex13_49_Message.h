#ifndef EX13_49_MESSAGE_H
#define EX13_49_MESSAGE_H

#include <iostream>
#include <set>

class Folder;

class Message {
	friend class Folder; // ???
	friend void swap(Message &lhs, Message &rhs);
public:
	explicit Message(const std::string &str = "") :
		contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	void move_Folders(Message *m);
	Message(Message&&);
	Message& operator=(Message&&);
	~Message();

	void save(Folder&);
	void remove(Folder&);
	void debug_print();
private:
	std::string contents;
	std::set<Folder*> folders;

	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void add_Fldr(Folder *f) { folders.insert(f); }
	void rem_Fldr(Folder *f) { folders.erase(f); }
};

void swap(Message &lhs, Message &rhs);

class Folder {
	friend class Message;
	friend void swap(Message &lhs, Message &rhs);
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();

	void debug_print();
private:
	std::set<Message*> messages;

	void Folder::add_to_Messages(const Folder &f);
	void Folder::remove_from_Messages();
	void Folder::addMsg(Message *m) { messages.insert(m); }
	void Folder::remMsg(Message *m) { messages.erase(m); }
};

#endif